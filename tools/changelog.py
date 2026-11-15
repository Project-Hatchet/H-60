#!/usr/bin/env python3
"""
changelog.py - changelog fragments: one small file per PR instead of every PR
editing the top of CHANGELOG-DEV.md (two open PRs always conflicted there, and
a branch cut before the cycle header was retitled conflicted on the header too).

    changelog/<pr-number>-<slug>.md      one or more "- bullet" lines, player-facing

    python tools/changelog.py lint                        every fragment is well-formed
    python tools/changelog.py check --base Main           this branch touched addons/ => it added a fragment
    python tools/changelog.py check --changed-files -     same test, changed paths on stdin (CI: gh pr diff)
    python tools/changelog.py render [--ref <git ref>]    the pending bullets as changelog lines
    python tools/changelog.py assemble --version 0.8.0 [--delete]
                                                          fold them into the top of CHANGELOG-DEV.md

Lifecycle: a PR adds its fragment. Dev builds render the fragments pending at
the built ref for the Workshop note and DEVBUILD.md. The release PR runs
`assemble --version X.Y.Z --delete`, which writes them under **X.Y.Z** in
CHANGELOG-DEV.md and removes the files. Nothing else writes that file on Main,
so nothing conflicts in it any more. PRs labeled "Release Notes: Ignore" are
exempt from `check` (CI passes --allow for them).
"""

import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FRAGMENT_DIR = "changelog"
CHANGELOG = "CHANGELOG-DEV.md"
IGNORE_LABEL = "Release Notes: Ignore"
BULLET_RE = re.compile(r"^\s*[-*]\s+(.*\S)\s*$")
HEADER_RE = re.compile(r"^\s*\*\*(.+?)\*\*\s*$")
NUMBER_RE = re.compile(r"^(\d+)")


def _git(*args):
    r = subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True, encoding="utf-8")
    if r.returncode != 0:
        sys.exit(f"git {' '.join(args)} failed:\n{r.stderr.strip()}")
    return r.stdout


def is_fragment(path):
    name = os.path.basename(path)
    return (path.replace("\\", "/").startswith(FRAGMENT_DIR + "/")
            and name.lower().endswith(".md") and name.lower() != "readme.md")


def _sort_key(name):
    m = NUMBER_RE.match(name)
    return (int(m.group(1)) if m else 10 ** 9, name.lower())


def fragments(ref=None):
    """[(name, text)] of the fragments in the working tree, or at a git ref, in assembly order."""
    out = []
    if ref:
        names = [p for p in _git("ls-tree", "-r", "--name-only", ref, "--", FRAGMENT_DIR).splitlines()
                 if is_fragment(p)]
        for p in sorted(names, key=lambda p: _sort_key(os.path.basename(p))):
            out.append((os.path.basename(p), _git("show", f"{ref}:{p}")))
    else:
        d = os.path.join(ROOT, FRAGMENT_DIR)
        if os.path.isdir(d):
            for name in sorted(os.listdir(d), key=_sort_key):
                p = os.path.join(d, name)
                if os.path.isfile(p) and is_fragment(FRAGMENT_DIR + "/" + name):
                    with open(p, "rb") as fh:
                        out.append((name, fh.read().decode("utf-8-sig", "replace")))
    return out


def parse(name, text):
    """([bullets], [errors]) for one fragment: bullets only, no headers, not empty."""
    bullets, errors = [], []
    for i, line in enumerate(text.splitlines(), 1):
        if not line.strip():
            continue
        if "<<<<<<<" in line or ">>>>>>>" in line:
            errors.append(f"{name}:{i}: conflict marker")
            continue
        if HEADER_RE.match(line) or line.lstrip().startswith("#"):
            errors.append(f"{name}:{i}: no headers in a fragment - the version header is written at release time")
            continue
        m = BULLET_RE.match(line)
        if not m:
            errors.append(f"{name}:{i}: every line must be a '- ' bullet (one change per bullet, player-facing)")
            continue
        bullets.append(m.group(1))
    if not bullets and not errors:
        errors.append(f"{name}: empty fragment")
    return bullets, errors


def lint_errors(ref=None):
    errors = []
    for name, text in fragments(ref):
        errors += parse(name, text)[1]
    return errors


def pending_bullets(ref=None):
    out = []
    for name, text in fragments(ref):
        out += parse(name, text)[0]
    return out


def render(ref=None):
    return "".join(f" - {b}\n" for b in pending_bullets(ref))


def assemble(version, delete=False, changelog=None):
    """Fold the working-tree fragments into CHANGELOG-DEV.md under <version>.

    If the top block is **Unreleased** or already this cycle's number (same
    X.Y.Z), the bullets join it at its top; otherwise a new **<version>** block
    is opened above everything. Returns the number of bullets folded in
    (0 = no fragments, file untouched)."""
    frags = fragments()
    bullets = []
    for name, text in frags:
        b, errors = parse(name, text)
        if errors:
            sys.exit("\n".join(errors))
        bullets += b
    if not bullets:
        return 0
    path = os.path.join(ROOT, changelog or CHANGELOG)
    with open(path, "rb") as fh:
        raw = fh.read()
    nl = "\r\n" if b"\r\n" in raw else "\n"
    lines = raw.decode("utf-8").split(nl)
    new_lines = [f" - {b}" for b in bullets]

    top = next((i for i, l in enumerate(lines) if HEADER_RE.match(l)), None)
    header = HEADER_RE.match(lines[top]).group(1).strip() if top is not None else None
    same_cycle = header is not None and (
        header.lower() == "unreleased" or header.split(".")[:3] == version.split(".")[:3])
    if same_cycle:
        at = top + 1
        if at < len(lines) and not lines[at].strip():
            at += 1  # keep the blank line under the header
        lines[at:at] = new_lines
    else:
        at = top if top is not None else 0
        lines[at:at] = [f"**{version}**", ""] + new_lines + [""]
    with open(path, "wb") as fh:
        fh.write(nl.join(lines).encode("utf-8"))
    if delete:
        for name, _ in frags:
            os.remove(os.path.join(ROOT, FRAGMENT_DIR, name))
    return len(bullets)


def changed_files(args):
    if args.changed_files:
        src = sys.stdin if args.changed_files == "-" else open(args.changed_files, encoding="utf-8")
        with src:
            return [l.strip() for l in src if l.strip()]
    return [l.strip() for l in _git("diff", "--name-only", f"{args.base}...HEAD").splitlines() if l.strip()]


def cmd_check(args):
    errors = lint_errors()
    files = changed_files(args)
    touches_addons = [f for f in files if f.replace("\\", "/").startswith("addons/")]
    adds_fragment = [f for f in files if is_fragment(f)]
    if touches_addons and not adds_fragment and not args.allow:
        errors.append(
            f"{len(touches_addons)} file(s) under addons/ changed but no changelog fragment was added. "
            f"Add {FRAGMENT_DIR}/<pr-number>-<slug>.md with a player-facing '- ' bullet per change "
            f"(see {FRAGMENT_DIR}/README.md), or label the PR '{IGNORE_LABEL}' if players will not notice it.")
    for e in errors:
        print("FAIL " + e)
    if not errors:
        why = ("fragment present: " + ", ".join(adds_fragment) if adds_fragment
               else "exempt" if args.allow and touches_addons else "no addon changes")
        print(f"ok   changelog ({why})")
    return 1 if errors else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("lint", help="every fragment is well-formed")
    c = sub.add_parser("check", help="lint + a branch that changed addons/ added a fragment")
    g = c.add_mutually_exclusive_group(required=True)
    g.add_argument("--base", help="git ref the branch will merge into (Main)")
    g.add_argument("--changed-files", help="file listing the changed paths, or - for stdin")
    c.add_argument("--allow", action="store_true", help=f"the PR is labeled '{IGNORE_LABEL}': no fragment required")
    r = sub.add_parser("render", help="pending bullets as changelog lines")
    r.add_argument("--ref", help="read the fragments at this git ref instead of the working tree")
    a = sub.add_parser("assemble", help="fold the pending fragments into CHANGELOG-DEV.md")
    a.add_argument("--version", required=True, help="block to write them under, e.g. 0.8.0")
    a.add_argument("--delete", action="store_true", help="remove the fragment files afterwards (the release PR does)")
    args = ap.parse_args()

    if args.cmd == "lint":
        errors = lint_errors()
        for e in errors:
            print("FAIL " + e)
        print(f"{'FAILED' if errors else 'ok'}: {len(fragments())} fragment(s)")
        return 1 if errors else 0
    if args.cmd == "check":
        return cmd_check(args)
    if args.cmd == "render":
        sys.stdout.write(render(args.ref))
        return 0
    if args.cmd == "assemble":
        n = assemble(args.version, delete=args.delete)
        print(f"folded {n} bullet(s) into {CHANGELOG} under {args.version}" if n
              else "no pending fragments - nothing to do")
        return 0


if __name__ == "__main__":
    sys.exit(main())
