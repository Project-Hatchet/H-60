"""
push_dev.py - build the mod from a named git ref and upload it to the
Steam Workshop DEVELOPMENT BRANCH item.

    python tools/push_dev.py --branch <ref> --note "what changed"
    python tools/push_dev.py --branch <ref> --note-file notes.txt
    python tools/push_dev.py --branch <ref> --note-from-changelog --bump           # usual dev push: 0.7.9.1 -> 0.7.9.2
    python tools/push_dev.py --branch <ref> --note-from-changelog --version 0.7.9.1  # first push of a new cycle
    python tools/push_dev.py --branch <ref> --note-from-changelog --bump --preview-note  # print the note and exit
    python tools/push_dev.py --branch <ref> --note "..." --dry-run                  # build + verify, no upload

What it does, in order:
  1. refuses to run on a dirty working tree
  2. checks out <ref> (and returns to the previous checkout afterwards)
  3. with --bump/--version: stamps the new version into
     addons/main/script_version.hpp, retitles the **Unreleased** block at
     the top of CHANGELOG-DEV.md to that version, and commits both on <ref>
     - so the in-game version, the changelog and the Workshop note agree
  4. wipes the AddonBuilder sync mirror (%TEMP%\\z\\vtx) - it syncs
     additively, so files deleted from the source otherwise ship again
  5. runs `scons all`, writes a Development-branch mod.cpp, and verifies
     every addon folder produced a fresh PBO
  6. shows a summary and asks for confirmation (skip with --yes)
  7. uploads release/@H-60 with PublisherCmd, which uses the Steam client
     already logged in on this machine - no credentials are stored anywhere

Versioning: Stable is X.Y.Z; Dev builds carry the NEXT Stable's number with
the build digit counting up per push (0.7.9.1, 0.7.9.2 ...). Start a cycle
with --version, continue it with --bump. Promotion to Stable is manual.

Deliberately DEV-ONLY: the Stable item is not known to this script.
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
import winreg
from pathlib import Path

DEV_WORKSHOP_ID = "3071155671"  # Hatchet H-60 pack - Development branch
ISSUE_URL = "https://github.com/Project-Hatchet/H-60/issues/"
MOD_FOLDER = Path("release") / "@H-60"
PBO_PREFIX = "hct_h60_"
MOD_ROOT_FILES = ["meta.cpp", "logo_vtx_ca.paa", "logo_vtx_small_ca.paa"]
VERSION_FILE = "addons/main/script_version.hpp"
CHANGELOG = "CHANGELOG-DEV.md"
TESTING_LABEL = "Ready for Testing"  # the devbuild branch = Main + PRs wearing this label
DEV_MOD_CPP = """name = "H-60 pack - Development branch";
picture = "logo_vtx_ca.paa";
actionName = "Guide";
action = "https://uh-60m.gitbook.io/workspace/guides/getting-started";
description = "H-60 pack - Development branch";
logo = "logo_vtx_ca.paa";
logoOver = "logo_vtx_ca.paa";
tooltip = "H-60 pack - Development branch";
tooltipOwned = "H-60 pack - Development branch Owned";
overview = "H-60 pack - Development branch";
author = "Project Hatchet Studios";
overviewPicture = "logo_vtx_ca.paa";
"""

REPO = Path(__file__).resolve().parent.parent


def die(msg, code=1):
    print(f"\npush_dev: {msg}", file=sys.stderr)
    sys.exit(code)


def run(cmd, **kw):
    return subprocess.run(cmd, cwd=REPO, text=True, capture_output=True, **kw)


def git(*args):
    r = run(["git", *args])
    if r.returncode != 0:
        die(f"git {' '.join(args)} failed:\n{r.stderr.strip()}")
    return r.stdout.strip()


def a3tools_path():
    with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r"SOFTWARE\Bohemia Interactive\Arma 3 Tools") as key:
        return Path(winreg.QueryValueEx(key, "path")[0])


def publisher_cmd():
    exe = a3tools_path() / "Publisher" / "PublisherCmd.exe"
    if not exe.exists():
        die(f"PublisherCmd.exe not found at {exe}")
    return exe


# --- change note -----------------------------------------------------------

def show_file(ref, path):
    """Contents of a file at a git ref, without checking it out."""
    r = run(["git", "show", f"{ref}:{path}"])
    if r.returncode != 0:
        die(f"{path} not found at {ref}")
    return r.stdout


def linkify(text):
    """#123 -> BBCode link to the GitHub issue/PR."""
    return re.sub(r"#(\d{2,5})\b", lambda m: f"[url={ISSUE_URL}{m.group(1)}]#{m.group(1)}[/url]", text)


HEADER_RE = re.compile(r"^\s*\*\*(.+?)\*\*\s*$")
BULLET_RE = re.compile(r"^\s*-\s+(.*\S)")


def top_block(changelog_text):
    """(header, [bullets]) of the first version block in CHANGELOG-DEV.md."""
    header, items = None, []
    for line in changelog_text.splitlines():
        h = HEADER_RE.match(line)
        if h:
            if header is not None:
                break
            header = h.group(1).strip()
            continue
        b = BULLET_RE.match(line)
        if b and header is not None:
            items.append(b.group(1).strip())
    if header is None or not items:
        die(f"could not find a version block with bullets at the top of {CHANGELOG}")
    return header, items


def parse_version(hpp_text):
    nums = {k: int(v) for k, v in re.findall(r"#define\s+(MAJOR|MINOR|PATCHLVL|BUILD)\s+(\d+)", hpp_text)}
    if len(nums) != 4:
        die(f"{VERSION_FILE} does not define MAJOR/MINOR/PATCHLVL/BUILD")
    return (nums["MAJOR"], nums["MINOR"], nums["PATCHLVL"], nums["BUILD"])


def fmt_version(v):
    return ".".join(str(n) for n in v)


def target_version(ref, args):
    """The version this push will carry: explicit --version, --bump of the ref's version, or the ref's version as-is."""
    current = parse_version(show_file(ref, VERSION_FILE))
    if args.version:
        parts = args.version.split(".")
        if len(parts) != 4 or not all(p.isdigit() for p in parts):
            die("--version must look like 0.7.9.1")
        return tuple(int(p) for p in parts), True
    if args.bump:
        return (*current[:3], current[3] + 1), True
    return current, False


def changelog_note(ref, version):
    """Top block of CHANGELOG-DEV.md at <ref>, rendered as a Steam BBCode change note under <version>."""
    header, items = top_block(show_file(ref, CHANGELOG))
    if header.lower() == "unreleased" and version is None:
        die("the top changelog block is **Unreleased** - pass --bump or --version to stamp it, "
            "or --note to bypass the changelog")
    label = fmt_version(version) if version else header
    out = [
        f"[h1]Dev build {label}[/h1]",
        f"[i]{ref}[/i]",
        "[list]",
        *[f"[*]{linkify(item)}" for item in items],
        "[/list]",
    ]
    return "\n".join(out)


def add_build_code(note, ref, sha):
    """Append the build code to the note's branch stamp line, so the Workshop
    note identifies the exact commit that was built (a --bump/--version stamp
    commit moves the branch, so this must run AFTER stamping)."""
    return note.replace(f"[i]{ref}[/i]", f"[i]{ref} @ {sha}[/i]", 1)


def gh(*args):
    exe = shutil.which("gh") or r"C:\Program Files\GitHub CLI\gh.exe"
    r = run([exe, *args])
    if r.returncode != 0:
        die(f"gh {' '.join(args)} failed:\n{r.stderr.strip()}")
    return r.stdout


def prs_note(ref, version):
    """Change note for a devbuild push: the open PRs labeled Ready for Testing.

    That label list is exactly what the devbuild branch is generated from, so
    the Workshop note tells testers precisely which PRs they are testing and
    where to report findings."""
    import json
    prs = json.loads(gh("pr", "list", "--state", "open", "--label", TESTING_LABEL,
                        "--json", "number,title"))
    if not prs:
        die(f"no open PRs carry the '{TESTING_LABEL}' label - nothing to list in the note")
    label = fmt_version(version) if version else fmt_version(parse_version(show_file(ref, VERSION_FILE)))
    out = [
        f"[h1]Dev build {label}[/h1]",
        f"[i]{ref}[/i]",
        "This test build contains the following changes under test - please report findings on the matching PR:",
        "[list]",
        *[f"[*]{linkify('#' + str(p['number']))} - {p['title']}" for p in sorted(prs, key=lambda p: p["number"])],
        "[/list]",
    ]
    return "\n".join(out)


def write_version_file(version):
    hpp = REPO / VERSION_FILE
    hpp_text = hpp.read_text(encoding="utf-8")
    nl = "\r\n" if "\r\n" in hpp_text else "\n"
    hpp.write_text(nl.join([f"#define MAJOR {version[0]}", f"#define MINOR {version[1]}",
                            f"#define PATCHLVL {version[2]}", f"#define BUILD {version[3]}", ""]), encoding="utf-8")


def stamp_version(version):
    """On the checked-out branch: write the version, retitle the Unreleased block, commit both."""
    label = fmt_version(version)
    write_version_file(version)

    cl = REPO / CHANGELOG
    text = cl.read_text(encoding="utf-8")
    header, _ = top_block(text)
    if header.lower() == "unreleased":
        text = re.sub(r"^(\s*)\*\*Unreleased\*\*", lambda m: f"{m.group(1)}**{label}**", text, count=1, flags=re.M | re.I)
        cl.write_text(text, encoding="utf-8")
    elif header != label:
        die(f"top changelog block is **{header}**, expected **Unreleased** (or **{label}** to re-push)")

    if git("status", "--porcelain"):
        git("add", VERSION_FILE, CHANGELOG)
        git("commit", "-q", "-m", f"Dev build {label}")
        print(f"  stamped {label} into {VERSION_FILE} and {CHANGELOG} (committed on the branch)")
    else:
        print(f"  {label} already stamped, nothing to commit")


# --- build -----------------------------------------------------------------

def wipe_mirror():
    mirror = Path(os.environ["TEMP"]) / "z" / "vtx"
    if mirror.exists():
        shutil.rmtree(mirror)
        print(f"  wiped AddonBuilder mirror {mirror}")


def build():
    addons_dir = REPO / "addons"
    expected = sorted(p.name for p in addons_dir.iterdir() if p.is_dir())
    out = REPO / MOD_FOLDER / "addons"
    out.mkdir(parents=True, exist_ok=True)
    for f in MOD_ROOT_FILES:
        src = REPO / f
        if src.exists():
            shutil.copy2(src, REPO / MOD_FOLDER / f)
    # the repo's mod.cpp is the Stable one; the Dev item gets its own name in the launcher
    (REPO / MOD_FOLDER / "mod.cpp").write_text(DEV_MOD_CPP, encoding="utf-8")

    started = time.time()
    print(f"  building {len(expected)} addons with scons (this takes a few minutes)...")
    r = subprocess.run(["scons", "all"], cwd=REPO, text=True, capture_output=True)
    if r.returncode != 0:
        print(r.stdout[-3000:])
        die(f"scons failed:\n{r.stderr[-2000:]}")

    problems = []
    total = 0
    for name in expected:
        pbo = out / f"{PBO_PREFIX}{name}.pbo"
        if not pbo.exists():
            problems.append(f"missing {pbo.name}")
        elif pbo.stat().st_mtime < started:
            problems.append(f"stale {pbo.name} (not rebuilt)")
        elif pbo.stat().st_size == 0:
            problems.append(f"empty {pbo.name}")
        else:
            total += pbo.stat().st_size
    stray = [p.name for p in out.glob("*.pbo") if not p.name.startswith(PBO_PREFIX)]
    if stray:
        problems.append(f"unprefixed leftovers in output: {', '.join(stray)}")
    if problems:
        die("build verification failed:\n  " + "\n  ".join(problems))
    return len(expected), total


# --- main ------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--branch", required=True, help="git ref to build (branch, tag, or sha)")
    note = ap.add_mutually_exclusive_group(required=True)
    note.add_argument("--note", help="Workshop change note text")
    note.add_argument("--note-file", help="file containing the change note")
    note.add_argument("--note-from-changelog", action="store_true",
                      help="build the note from the top version block of CHANGELOG-DEV.md at <ref>")
    note.add_argument("--note-from-prs", action="store_true",
                      help=f"build the note from the open PRs labeled '{TESTING_LABEL}' (for devbuild pushes)")
    ver = ap.add_mutually_exclusive_group()
    ver.add_argument("--bump", action="store_true", help="increment the build digit of the version on <ref> and stamp it")
    ver.add_argument("--version", help="stamp this exact version (e.g. 0.7.9.1) - use for the first push of a cycle")
    ap.add_argument("--no-commit", action="store_true",
                    help="stamp the version into the build only, committing nothing - required for pushing the "
                         "regenerated devbuild branch, where commits would be wiped on the next rebuild")
    ap.add_argument("--preview-note", action="store_true", help="print the change note and exit (no build, no upload)")
    ap.add_argument("--dry-run", action="store_true", help="build and verify, skip the upload")
    ap.add_argument("--yes", action="store_true", help="skip the confirmation prompt")
    ap.add_argument("--skip-build", action="store_true", help="upload whatever is in release/@H-60 (no checkout/build)")
    args = ap.parse_args()

    git("rev-parse", "--verify", f"{args.branch}^{{commit}}")
    version, stamp = target_version(args.branch, args)
    if stamp and args.skip_build:
        die("--bump/--version need a checkout to stamp the branch; drop --skip-build")
    if args.no_commit and not args.version:
        die("--no-commit needs an explicit --version: nothing is committed, so --bump would "
            "have no stamped base to count from")

    if args.note_from_changelog:
        note_text = changelog_note(args.branch, version if stamp else None)
    elif args.note_from_prs:
        note_text = prs_note(args.branch, version if stamp else None)
    elif args.note is not None:
        note_text = args.note
    else:
        note_text = Path(args.note_file).read_text(encoding="utf-8")
    if not note_text.strip():
        die("the change note is empty - describe what changed")
    if args.preview_note:
        # pre-stamp preview: shows the ref's current tip; a --bump/--version
        # push will show the stamp commit's code instead
        print(add_build_code(note_text, args.branch, git("rev-parse", "--short", args.branch)))
        return

    if not args.skip_build:
        if git("status", "--porcelain"):
            die("working tree is not clean - commit or stash first")
        previous = git("rev-parse", "--abbrev-ref", "HEAD")
        if previous == "HEAD":
            previous = git("rev-parse", "HEAD")
        print(f"checking out {args.branch} (will return to {previous})")
        git("checkout", "-q", args.branch)
        try:
            if stamp:
                if args.no_commit:
                    write_version_file(version)
                    print(f"  stamped {fmt_version(version)} into {VERSION_FILE} (build-time only, nothing committed)")
                else:
                    stamp_version(version)
            sha = git("rev-parse", "--short", "HEAD")
            wipe_mirror()
            count, total = build()
        finally:
            if stamp and args.no_commit:
                git("checkout", "-q", "--", VERSION_FILE)
            git("checkout", "-q", previous)
    else:
        sha = "(skip-build)"
        out = REPO / MOD_FOLDER / "addons"
        pbos = list(out.glob(f"{PBO_PREFIX}*.pbo"))
        count, total = len(pbos), sum(p.stat().st_size for p in pbos)

    note_sha = sha if sha != "(skip-build)" else git("rev-parse", "--short", args.branch)
    note_text = add_build_code(note_text, args.branch, note_sha)

    print("\n=== Dev Branch push summary ===")
    print(f"  ref:      {args.branch} @ {sha}")
    print(f"  version:  {fmt_version(version)}{'  (stamped)' if stamp else ''}")
    print(f"  content:  {REPO / MOD_FOLDER}  ({count} PBOs, {total / 1e6:,.0f} MB)")
    print(f"  item:     https://steamcommunity.com/sharedfiles/filedetails/?id={DEV_WORKSHOP_ID}")
    print("  note:")
    for line in note_text.strip().splitlines():
        print(f"    {line}")

    if args.dry_run:
        print("\ndry run - build verified, nothing uploaded.")
        return

    if not args.yes:
        answer = input("\nUpload to the Workshop DEV branch? [y/N] ").strip().lower()
        if answer != "y":
            die("aborted, nothing uploaded", 0)

    exe = publisher_cmd()
    with tempfile.NamedTemporaryFile("w", suffix=".txt", delete=False, encoding="utf-8") as tmp:
        tmp.write(note_text)
        note_path = tmp.name
    try:
        r = subprocess.run(
            [str(exe), "update", f"/id:{DEV_WORKSHOP_ID}", f"/changeNoteFile:{note_path}",
             f"/path:{REPO / MOD_FOLDER}", "/nologo"],
            cwd=REPO, text=True, capture_output=True,
        )
    finally:
        os.unlink(note_path)
    print(r.stdout)
    if r.returncode != 0:
        die(f"PublisherCmd failed (exit {r.returncode}):\n{r.stderr}")

    log = REPO / "release" / "push_dev.log"
    with log.open("a", encoding="utf-8") as f:
        f.write(f"{time.strftime('%Y-%m-%d %H:%M')}  {args.branch}@{sha}  {count} PBOs  {note_text.strip().splitlines()[0]}\n")
    print("uploaded to the Workshop Dev branch.")


if __name__ == "__main__":
    main()
