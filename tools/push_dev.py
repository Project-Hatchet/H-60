"""
push_dev.py - build the mod from a named git ref and upload it to the
Steam Workshop DEVELOPMENT BRANCH item.

    python tools/push_dev.py --branch <ref> --note "what changed"
    python tools/push_dev.py --branch <ref> --note-file notes.txt
    python tools/push_dev.py --branch <ref> --note "..." --dry-run   # build + verify, no upload

What it does, in order:
  1. refuses to run on a dirty working tree
  2. checks out <ref> (and returns to the previous checkout afterwards)
  3. wipes the AddonBuilder sync mirror (%TEMP%\\z\\vtx) - it syncs
     additively, so files deleted from the source otherwise ship again
  4. runs `scons all` and verifies every addon folder produced a fresh PBO
  5. shows a summary and asks for confirmation (skip with --yes)
  6. uploads release/@H-60 with PublisherCmd, which uses the Steam client
     already logged in on this machine - no credentials are stored anywhere

Deliberately DEV-ONLY: the Stable item is not known to this script.
Promoting to Stable stays a manual, human act.
"""

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
import time
import winreg
from pathlib import Path

DEV_WORKSHOP_ID = "3071155671"  # Hatchet H-60 pack - Development branch
MOD_FOLDER = Path("release") / "@H-60"
PBO_PREFIX = "hct_h60_"
MOD_ROOT_FILES = ["mod.cpp", "meta.cpp", "logo_vtx_ca.paa", "logo_vtx_small_ca.paa"]

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


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--branch", required=True, help="git ref to build (branch, tag, or sha)")
    note = ap.add_mutually_exclusive_group(required=True)
    note.add_argument("--note", help="Workshop change note text")
    note.add_argument("--note-file", help="file containing the change note")
    ap.add_argument("--dry-run", action="store_true", help="build and verify, skip the upload")
    ap.add_argument("--yes", action="store_true", help="skip the confirmation prompt")
    ap.add_argument("--skip-build", action="store_true", help="upload whatever is in release/@H-60 (no checkout/build)")
    args = ap.parse_args()

    note_text = args.note if args.note is not None else Path(args.note_file).read_text(encoding="utf-8")
    if not note_text.strip():
        die("the change note is empty - describe what changed")

    if not args.skip_build:
        if git("status", "--porcelain"):
            die("working tree is not clean - commit or stash first")
        previous = git("rev-parse", "--abbrev-ref", "HEAD")
        if previous == "HEAD":
            previous = git("rev-parse", "HEAD")
        git("rev-parse", "--verify", f"{args.branch}^{{commit}}")
        print(f"checking out {args.branch} (will return to {previous})")
        git("checkout", "-q", args.branch)
        try:
            sha = git("rev-parse", "--short", "HEAD")
            wipe_mirror()
            count, total = build()
        finally:
            git("checkout", "-q", previous)
    else:
        sha = "(skip-build)"
        out = REPO / MOD_FOLDER / "addons"
        pbos = list(out.glob(f"{PBO_PREFIX}*.pbo"))
        count, total = len(pbos), sum(p.stat().st_size for p in pbos)

    print("\n=== Dev Branch push summary ===")
    print(f"  ref:      {args.branch} @ {sha}")
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
