"""
build_stable.py - build the UNSIGNED Stable package for a release ref with HEMTT
and hand it to the folder Riverman signs and uploads from.

    python tools/build_stable.py --branch release/0.8.0
    python tools/build_stable.py --branch Main --dest D:\\somewhere\\0.8.0

What it does, in order:
  1. refuses to run on a dirty working tree, and refuses a local branch that
     differs from origin (same guard as push_dev.py)
  2. checks out <ref> (and returns to the previous checkout afterwards)
  3. runs `hemtt release` - unsigned and archived per .hemtt/project.toml;
     the version is read from addons/main/script_version.hpp at <ref>, so a
     Stable build needs the release PR merged first (BUILD must be 0)
  4. verifies: 25 fresh PBOs, every PBO header stamped with that version,
     no .bisign (signing is done by hand), the repo-root Stable mod.cpp
  5. copies the mod folder to <dest>\\@H-60 and the versioned zip beside it,
     then prints the signing checklist

Deliberately does NOT sign and does NOT upload. The Stable Workshop item is
updated by hand after DSSignFile signing (per-release key pair).
"""

import argparse
import os
import re
import shutil
import struct
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
VERSION_FILE = "addons/main/script_version.hpp"
HEMTT_OUT = REPO / ".hemttout" / "release"
ZIPS = REPO / "releases"
DEFAULT_DEST_ROOT = Path(os.environ.get("USERPROFILE", "")) / "OneDrive" / "Documents" / "Hatchet" / "H-60" / "Releases" / "Stable Branch"
PBO_PREFIX = "hct_"


def die(msg, code=1):
    print(f"\nbuild_stable: {msg}", file=sys.stderr)
    sys.exit(code)


def run(cmd, **kw):
    return subprocess.run(cmd, cwd=REPO, text=True, capture_output=True, **kw)


def git(*args):
    r = run(["git", *args])
    if r.returncode != 0:
        die(f"git {' '.join(args)} failed:\n{r.stderr.strip()}")
    return r.stdout.strip()


def hemtt_exe():
    found = shutil.which("hemtt")
    if found:
        return Path(found)
    pkgs = Path(os.environ.get("LOCALAPPDATA", "")) / "Microsoft" / "WinGet" / "Packages"
    for cand in sorted(pkgs.glob("BrettMayson.HEMTT_*/hemtt.exe")):
        return cand
    die("hemtt not found - install it (winget install BrettMayson.HEMTT) or put it on PATH")


def ensure_matches_origin(ref):
    if run(["git", "show-ref", "--verify", "--quiet", f"refs/heads/{ref}"]).returncode != 0:
        return
    if run(["git", "ls-remote", "--exit-code", "--heads", "origin", ref]).returncode != 0:
        return
    git("fetch", "-q", "origin", ref)
    local, remote = git("rev-parse", ref), git("rev-parse", "FETCH_HEAD")
    if local != remote:
        die(f"local {ref} is at {local[:7]} but origin/{ref} is at {remote[:7]} - "
            f"update it first:  git fetch -f origin {ref}:{ref}")


def parse_version(hpp_text):
    nums = {k: int(v) for k, v in re.findall(r"#define\s+(MAJOR|MINOR|PATCHLVL|BUILD)\s+(\d+)", hpp_text)}
    if len(nums) != 4:
        die(f"{VERSION_FILE} does not define MAJOR/MINOR/PATCHLVL/BUILD")
    return (nums["MAJOR"], nums["MINOR"], nums["PATCHLVL"], nums["BUILD"])


def pbo_header_props(path):
    """{property: value} from the PBO's leading 'sreV' header entry."""
    with open(path, "rb") as fh:
        buf = fh.read(4096)
    pos = buf.index(b"\x00", 0) + 1  # empty filename
    packing = struct.unpack_from("<I", buf, pos)[0]
    pos += 20
    props = {}
    if packing != 0x56657273:
        return props
    while True:
        end = buf.index(b"\x00", pos)
        key = buf[pos:end]
        pos = end + 1
        if key == b"":
            break
        end = buf.index(b"\x00", pos)
        props[key.decode("utf-8", "replace").lower()] = buf[pos:end].decode("utf-8", "replace")
        pos = end + 1
    return props


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--branch", required=True, help="git ref to build (the merged release branch, or Main after the release PR)")
    ap.add_argument("--dest", help=f"destination folder; default {DEFAULT_DEST_ROOT}\\<version>")
    ap.add_argument("--force", action="store_true", help="overwrite an existing destination")
    ap.add_argument("--allow-build-digit", action="store_true", help="accept a version whose BUILD digit is not 0")
    args = ap.parse_args()

    git("rev-parse", "--verify", f"{args.branch}^{{commit}}")
    if git("status", "--porcelain"):
        die("working tree is not clean - commit or stash first")
    ensure_matches_origin(args.branch)

    r = run(["git", "show", f"{args.branch}:{VERSION_FILE}"])
    if r.returncode != 0:
        die(f"{VERSION_FILE} not found at {args.branch}")
    version = parse_version(r.stdout)
    label = ".".join(str(n) for n in version)
    if version[3] != 0 and not args.allow_build_digit:
        die(f"{args.branch} carries {label}: a Stable is X.Y.Z.0 - merge the release PR first "
            f"(or pass --allow-build-digit for a one-off)")

    dest = Path(args.dest) if args.dest else DEFAULT_DEST_ROOT / ".".join(str(n) for n in version[:3])
    mod_dest = dest / "@H-60"
    if mod_dest.exists() and not args.force:
        die(f"{mod_dest} already exists - pass --force to replace it")

    previous = git("rev-parse", "--abbrev-ref", "HEAD")
    if previous == "HEAD":
        previous = git("rev-parse", "HEAD")
    print(f"checking out {args.branch} (will return to {previous})")
    git("checkout", "-q", args.branch)
    try:
        sha = git("rev-parse", "--short", "HEAD")
        hemtt = hemtt_exe()
        started = time.time()
        print(f"  hemtt release for {label} ({hemtt})...")
        shutil.rmtree(REPO / ".hemttout", ignore_errors=True)
        shutil.rmtree(ZIPS, ignore_errors=True)
        r = subprocess.run([str(hemtt), "release"], cwd=REPO, text=True, capture_output=True)
        if r.returncode != 0:
            print(r.stdout[-3000:])
            die(f"hemtt release failed:\n{r.stderr[-2000:]}")
    finally:
        git("checkout", "-q", previous)

    # --- verification ---------------------------------------------------
    expected = sorted(p.name for p in (REPO / "addons").iterdir() if p.is_dir())
    pbos = sorted((HEMTT_OUT / "addons").glob("*.pbo"))
    problems = []
    if len(pbos) != len(expected):
        problems.append(f"{len(pbos)} PBOs for {len(expected)} addon folders")
    total = 0
    for pbo in pbos:
        props = pbo_header_props(pbo)
        if not pbo.name.startswith(PBO_PREFIX):
            problems.append(f"unexpected name {pbo.name}")
        if pbo.stat().st_mtime < started or pbo.stat().st_size == 0:
            problems.append(f"stale or empty {pbo.name}")
        if props.get("version") != label:
            problems.append(f"{pbo.name} header version is {props.get('version')!r}, expected {label}")
        total += pbo.stat().st_size
    if list((HEMTT_OUT / "addons").glob("*.bisign")):
        problems.append("output already contains .bisign files - signing is done by hand, check [hemtt.release] sign")
    modcpp = (HEMTT_OUT / "mod.cpp").read_text(encoding="utf-8") if (HEMTT_OUT / "mod.cpp").exists() else ""
    if modcpp != (REPO / "mod.cpp").read_text(encoding="utf-8"):
        problems.append("mod.cpp in the output is not the repo-root Stable one")
    zips = sorted(ZIPS.glob(f"*-{label}.zip"))
    if not zips:
        problems.append(f"no versioned zip in {ZIPS}")
    if problems:
        die("verification failed:\n  " + "\n  ".join(problems))

    # --- hand-off ---------------------------------------------------------
    dest.mkdir(parents=True, exist_ok=True)
    if mod_dest.exists():
        shutil.rmtree(mod_dest)
    shutil.copytree(HEMTT_OUT, mod_dest)
    shutil.copy2(zips[0], dest / zips[0].name)

    print("\n=== Stable package ready (UNSIGNED) ===")
    print(f"  ref:      {args.branch} @ {sha}")
    print(f"  version:  {label}  (every PBO header checked)")
    print(f"  folder:   {mod_dest}  ({len(pbos)} PBOs, {total / 1e6:,.0f} MB)")
    print(f"  zip:      {dest / zips[0].name}")
    print("\nNext, by hand:")
    print("  1. DSSignFile: new key pair for this release, sign every PBO in addons\\, put the .bikey in @H-60\\keys\\")
    print("  2. Upload the signed @H-60 to the Stable Workshop item (by hand, on purpose)")
    print("  3. Publish the GitHub release from the Release Drafter draft; attach the zip if wanted")


if __name__ == "__main__":
    main()
