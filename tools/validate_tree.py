#!/usr/bin/env python3
"""
validate_tree.py - structural checks on addons/ that a Linux runner can enforce
(Phase 3 · WP4d). Every check here passes on the tree the day it is wired; a
check that would fail the tree is added only together with the fix.

    python tools/validate_tree.py            # all checks, exit 1 on any failure
    python tools/validate_tree.py --list     # names of the checks
    python tools/validate_tree.py --only include-case,bom

Checks
  include-case     every #include resolves to an existing file with the exact
                   case on disk (Windows hid 12 of these for years; Linux does not)
  empty-files      no empty or whitespace-only source files
  bom              no UTF-8 byte-order marks (Arma's preprocessor chokes on them
                   in included files)
  prep-parity      every PREP(x) in an XEH_PREP.hpp has functions/fnc_x.sqf, and
                   every functions/fnc_*.sqf in a PREP addon is PREP'd
  addon-layout     every addon folder has config.cpp, $PBOPREFIX$ and addon.toml
  hemtt-portable   the rules learned in the HEMTT migration: no unquoted config
                   expression using an SQF function (HEMTT evaluates it wrongly at
                   build time), no square-bracket arrays (CfgConvert stored them as
                   strings), no ';' after #include
  changelog-fragments
                   every changelog/*.md fragment is bullets only (tools/changelog.py)
  orphan-headers   REPORT ONLY: .hpp/.inc.sqf files nothing includes
"""

import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDONS = os.path.join(ROOT, "addons")
INCLUDE_DIR = os.path.join(ROOT, "include")
SOURCE_EXT = (".hpp", ".cpp", ".h", ".sqf", ".cfg", ".ext", ".rvmat", ".xml")
INCLUDE_RE = re.compile(r'^\s*#include\s+"([^"]+)"(\s*;)?', re.M)

sys.dont_write_bytecode = True  # no __pycache__ in tools/ from a local run
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import changelog as changelog_fragments  # noqa: E402  (tools/changelog.py)

_listing_cache = {}


def listing(d):
    if d not in _listing_cache:
        try:
            _listing_cache[d] = set(os.listdir(d))
        except OSError:
            _listing_cache[d] = set()
    return _listing_cache[d]


def exact_case_exists(abs_path):
    rel = os.path.relpath(abs_path, ROOT)
    cur = ROOT
    for part in rel.split(os.sep):
        if part in ("", "."):
            continue
        if part not in listing(cur):
            return False
        cur = os.path.join(cur, part)
    return True


def source_files():
    for dp, dn, fn in os.walk(ADDONS):
        for f in fn:
            if f.lower().endswith(SOURCE_EXT):
                yield os.path.join(dp, f)


def read(path):
    with open(path, "rb") as fh:
        return fh.read()


_prefix_map = None


def prefix_map():
    """{lower-case $PBOPREFIX$ parts tuple: addon folder}. Folder names are decoupled
    from the shipped prefix (z\\vtx\\addons\\<x>), so includes resolve through it."""
    global _prefix_map
    if _prefix_map is None:
        _prefix_map = {}
        for addon in os.listdir(ADDONS):
            pf = os.path.join(ADDONS, addon, "$PBOPREFIX$")
            if os.path.isfile(pf):
                val = read(pf).decode("utf-8", "replace").strip().strip("\\")
                _prefix_map[tuple(p.lower() for p in val.split("\\") if p)] = addon
    return _prefix_map


def resolve_include(src_dir, target):
    # Arma paths are written with backslashes; on Linux they must become real separators
    t = target.replace("\\", os.sep).replace("/", os.sep)
    if t.startswith(os.sep):
        parts = t.strip(os.sep).split(os.sep)
        low = tuple(p.lower() for p in parts)
        for pre, addon in prefix_map().items():
            if low[:len(pre)] == pre:
                return os.path.join(ADDONS, addon, *parts[len(pre):])
        return os.path.join(INCLUDE_DIR, *parts)
    cand = os.path.join(src_dir, t)
    if not os.path.exists(cand) and os.path.exists(os.path.join(INCLUDE_DIR, t)):
        return os.path.join(INCLUDE_DIR, t)
    return cand


# --- checks (each returns a list of failure strings) ------------------------

def check_include_case():
    fails = []
    for path in source_files():
        if not path.lower().endswith((".hpp", ".cpp", ".h", ".sqf", ".cfg")):
            continue
        text = read(path).decode("utf-8", "replace")
        for m in INCLUDE_RE.finditer(text):
            cand = resolve_include(os.path.dirname(path), m.group(1))
            rel = os.path.relpath(path, ROOT)
            if not os.path.exists(cand):
                fails.append(f"{rel}: #include \"{m.group(1)}\" -> file not found")
            elif not exact_case_exists(os.path.abspath(cand)):
                fails.append(f"{rel}: #include \"{m.group(1)}\" differs in case from the file on disk")
    return fails


def check_empty_files():
    fails = []
    for path in source_files():
        if not read(path).strip():
            fails.append(f"{os.path.relpath(path, ROOT)}: empty file")
    return fails


def check_bom():
    fails = []
    for path in source_files():
        if read(path).startswith(b"\xef\xbb\xbf"):
            fails.append(f"{os.path.relpath(path, ROOT)}: UTF-8 BOM")
    return fails


PREP_RE = re.compile(r"\bPREP(?:_RECOMPILE)?\s*\(\s*([A-Za-z0-9_]+)\s*\)")


def check_prep_parity():
    fails = []
    for addon in sorted(os.listdir(ADDONS)):
        prep = os.path.join(ADDONS, addon, "XEH_PREP.hpp")
        funcs = os.path.join(ADDONS, addon, "functions")
        if not os.path.isfile(prep):
            continue
        names = set(PREP_RE.findall(COMMENT_RE.sub("", read(prep).decode("utf-8", "replace"))))
        on_disk = {f[4:-4] for f in listing(funcs) if f.startswith("fnc_") and f.endswith(".sqf")} if os.path.isdir(funcs) else set()
        for n in sorted(names - on_disk):
            fails.append(f"addons/{addon}: PREP({n}) but functions/fnc_{n}.sqf does not exist")
        for n in sorted(on_disk - names):
            fails.append(f"addons/{addon}: functions/fnc_{n}.sqf is not PREP'd in XEH_PREP.hpp")
    return fails


def check_addon_layout():
    fails = []
    for addon in sorted(os.listdir(ADDONS)):
        d = os.path.join(ADDONS, addon)
        if not os.path.isdir(d):
            continue
        for required in ("config.cpp", "$PBOPREFIX$", "addon.toml"):
            if required not in listing(d):
                fails.append(f"addons/{addon}: missing {required}")
    return fails


TRIG_RE = re.compile(r"\b(sin|cos|tan|atan|atan2|sqrt|abs|exp|log|ln|round|floor|ceil)\b")
STRING_RE = re.compile(r'"(?:[^"]|"")*"')
COMMENT_RE = re.compile(r"//.*?$|/\*.*?\*/", re.S | re.M)


def check_hemtt_portable():
    fails = []
    for path in source_files():
        if not path.lower().endswith((".hpp", ".cpp")):
            continue
        rel = os.path.relpath(path, ROOT)
        text = read(path).decode("utf-8", "replace")
        for m in re.finditer(r'#include\s+"[^"]*"\s*;', text):
            fails.append(f"{rel}: ';' after #include (HEMTT rejects it)")
        stripped = COMMENT_RE.sub("", text)
        for i, line in enumerate(stripped.split("\n"), 1):
            if line.lstrip().startswith("#"):
                # macro bodies are checked where they expand; the QUOTE()d trig
                # macros keep their bare _EXPR forms for composition
                continue
            code = STRING_RE.sub('""', line)
            if TRIG_RE.search(code) and "=" in code:
                fails.append(f"{rel}:{i}: unquoted SQF function in a config value - HEMTT evaluates it at build time with the wrong semantics; QUOTE() it")
            if re.search(r"=\s*\{\s*\[", code):
                fails.append(f"{rel}:{i}: square-bracket array in a config value - CfgConvert shipped it as strings, HEMTT rejects it; use braces")
    return fails


def report_orphan_headers():
    included = set()
    for path in source_files():
        if not path.lower().endswith((".hpp", ".cpp", ".h", ".sqf", ".cfg")):
            continue
        text = read(path).decode("utf-8", "replace")
        for m in INCLUDE_RE.finditer(text):
            cand = resolve_include(os.path.dirname(path), m.group(1))
            included.add(os.path.normcase(os.path.abspath(cand)))
    orphans = []
    for path in source_files():
        low = path.lower()
        if not (low.endswith(".hpp") or low.endswith(".inc.sqf")):
            continue
        if os.path.normcase(os.path.abspath(path)) not in included:
            orphans.append(os.path.relpath(path, ROOT))
    return orphans


# --- variant layering --------------------------------------------------------
# The pack is layered: main -> common base (h60_config + uh60 assets) -> systems ->
# variant PBOs (leaves) -> HeliSim pack and optional compat. A variant's classes are declared and
# configured only inside its own PBO; systems talk to variants through the base
# class and hct_trait_* config, never by name.

VARIANT_ADDONS = {"uh60m", "s70i", "hh60", "mh60m", "mh60s"}
# optional compat addons may re-open variants (they load after them), and so may the
# HeliSim pack: HeliSim Core's pack template keeps every BMKHS_HeliSim declaration in
# the pack, so it re-opens each variant for its seats and loads after them
COMPAT_ADDONS = {"h60_acre", "h60_aar", "h60_air_control", "h60_compat_vtx", "h60_helisim"}
VARIANT_DECL_RE = re.compile(r"^\s*class\s+(hct_\w+)\s*:\s*hct_H60_base\b", re.M | re.I)
LINE_COMMENT_RE = re.compile(r"//[^\n]*")
BLOCK_COMMENT_RE = re.compile(r"/\*.*?\*/", re.S)


def variant_classes():
    names = set()
    for addon in VARIANT_ADDONS:
        d = os.path.join(ADDONS, addon)
        for dp, dn, fn in os.walk(d):
            for f in fn:
                if f.lower().endswith((".hpp", ".cpp")):
                    text = read(os.path.join(dp, f)).decode("utf-8", "replace")
                    names.update(n.lower() for n in VARIANT_DECL_RE.findall(text))
    return names


def strip_comments(text):
    return LINE_COMMENT_RE.sub("", BLOCK_COMMENT_RE.sub("", text))


def check_variant_layering():
    fails = []
    variants = variant_classes()
    if not variants:
        return ["no variant classes found in " + ", ".join(sorted(VARIANT_ADDONS))]
    class_re = re.compile(r"\bclass\s+(" + "|".join(sorted(variants)) + r")\b", re.I)
    literal_re = re.compile(r'"(' + "|".join(sorted(variants)) + r')"', re.I)
    for path in source_files():
        rel = os.path.relpath(path, ROOT)
        addon = rel.split(os.sep)[1]
        if addon in VARIANT_ADDONS:
            continue
        low = path.lower()
        text = strip_comments(read(path).decode("utf-8", "replace"))
        if low.endswith((".hpp", ".cpp")) and addon not in COMPAT_ADDONS:
            for m in class_re.finditer(text):
                fails.append(f"{rel}: declares variant class {m.group(1)} outside its variant PBO")
        if low.endswith(".sqf"):
            for m in literal_re.finditer(text):
                fails.append(f"{rel}: hard-coded variant classname \"{m.group(1)}\" - use a hct_trait_* (GET_TRAIT/HAS_TRAIT)")
    return fails


CHECKS = [
    ("include-case", check_include_case),
    ("empty-files", check_empty_files),
    ("bom", check_bom),
    ("prep-parity", check_prep_parity),
    ("addon-layout", check_addon_layout),
    ("hemtt-portable", check_hemtt_portable),
    ("variant-layering", check_variant_layering),
    ("changelog-fragments", changelog_fragments.lint_errors),
]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--only", help="comma-separated check names")
    ap.add_argument("--no-report", action="store_true", help="skip the report-only sections")
    args = ap.parse_args()
    if args.list:
        for name, _ in CHECKS:
            print(name)
        print("orphan-headers (report only)")
        return 0
    wanted = set(args.only.split(",")) if args.only else None
    failed = 0
    for name, fn in CHECKS:
        if wanted and name not in wanted:
            continue
        fails = fn()
        print(f"{'FAIL' if fails else 'ok  '} {name}" + (f"  ({len(fails)})" if fails else ""))
        for f in fails[:200]:
            print(f"       {f}")
        failed += len(fails)
    if not args.no_report and (not wanted or "orphan-headers" in wanted):
        orphans = report_orphan_headers()
        print(f"info orphan-headers  ({len(orphans)} not included by anything; report only)")
        for o in orphans[:60]:
            print(f"       {o}")
    print(f"\n{'FAILED' if failed else 'PASSED'}: {failed} problem(s)")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
