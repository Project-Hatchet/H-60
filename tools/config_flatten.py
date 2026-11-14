#!/usr/bin/env python3
"""
config_flatten.py - offline, inheritance-resolved config dump of a HEMTT build.

The in-game harness (tools/config_dump) is the authority, but it needs Arma
running. This tool gives a fast offline proxy for restructure work: it merges
every PBO's config.bin in load order, resolves inheritance the way the engine
does (case-insensitive names, parent looked up in the enclosing class, then its
base chain, then outer scopes), and writes one file per class with every
effective property, name-sorted, plus a `classOrder` line in merge order.

Only content the mod itself ships is resolved. A base class that lives in
vanilla/CBA/ACE/HeliSim shows up as `__base = <name> (external)` and contributes
nothing. That is identical on both sides of a restructure, so diffs stay
meaningful.

    python tools/config_flatten.py dump <build_dir> <out_dir>
    python tools/config_flatten.py compare <out_dirA> <out_dirB> [--ignore-patches]

<build_dir> is a HEMTT output folder (e.g. .hemttout/build) containing addons/*.pbo.
Requires `hemtt` on PATH (used to extract and derapify config.bin).

Load order: PBOs sorted by filename (case-insensitive), then stably sorted so
every addon loads after its requiredAddons. That matches the engine closely
enough for single-owner config; a collision whose winner depends on tie order
shows up as a diff, which is the point.
"""

import argparse
import difflib
import json
import os
import shutil
import subprocess
import sys
import tempfile

ROOT_PREFIXES = ("cfg", "extended_", "rsc")


# --- extraction ----------------------------------------------------------------

def load_build(build_dir):
    addons_dir = os.path.join(build_dir, "addons")
    pbos = sorted((f for f in os.listdir(addons_dir) if f.lower().endswith(".pbo")), key=str.lower)
    tmp = tempfile.mkdtemp(prefix="cfgflat_")
    configs = []
    try:
        for pbo in pbos:
            binp = os.path.join(tmp, pbo + ".bin")
            jsp = os.path.join(tmp, pbo + ".json")
            r = subprocess.run(["hemtt", "utils", "pbo", "extract", os.path.join(addons_dir, pbo), "config.bin", binp],
                               capture_output=True, text=True)
            if r.returncode != 0 or not os.path.exists(binp):
                print(f"skip {pbo}: no config.bin", file=sys.stderr)
                continue
            r = subprocess.run(["hemtt", "utils", "config", "derapify", "-f", "json", binp, jsp],
                               capture_output=True, text=True)
            if r.returncode != 0:
                sys.exit(f"derapify failed for {pbo}: {r.stderr}")
            with open(jsp, encoding="utf-8") as fh:
                configs.append((pbo, json.load(fh)))
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    return order_configs(configs)


def order_configs(configs):
    """Stable topological sort on CfgPatches requiredAddons."""
    patches_of = {}
    for pbo, cfg in configs:
        names = [k.lower() for k in (cfg.get("CfgPatches") or {}).keys()]
        patches_of[pbo] = names
    provided = {n: pbo for pbo, names in patches_of.items() for n in names}
    deps = {}
    for pbo, cfg in configs:
        req = set()
        for body in (cfg.get("CfgPatches") or {}).values():
            for dep in (body or {}).get("requiredAddons", []) or []:
                p = provided.get(str(dep).lower())
                if p and p != pbo:
                    req.add(p)
        deps[pbo] = req
    done, out = set(), []
    pending = [pbo for pbo, _ in configs]
    by_name = dict(configs)
    while pending:
        progressed = False
        for pbo in list(pending):
            if deps[pbo] <= done:
                out.append((pbo, by_name[pbo]))
                done.add(pbo)
                pending.remove(pbo)
                progressed = True
                break
        if not progressed:
            print(f"dependency cycle among {pending}; appending in name order", file=sys.stderr)
            out.extend((p, by_name[p]) for p in pending)
            break
    return out


# --- model -----------------------------------------------------------------------

class Node:
    __slots__ = ("name", "base", "entries", "defined", "outer", "_eff", "_busy")

    def __init__(self, name, outer):
        self.name = name
        self.base = None
        self.entries = {}          # lower name -> Node | ("v", display, value)
        self.defined = False
        self.outer = outer
        self._eff = None
        self._busy = False


def merge(node, body):
    for key, val in body.items():
        if key == "__parent":
            continue
        low = key.lower()
        cur = node.entries.get(low)
        if val is None:                                   # class X;  (extern)
            if not isinstance(cur, Node):
                node.entries[low] = Node(key, node)
        elif isinstance(val, dict):                       # class X[: Y] { ... }
            if not isinstance(cur, Node):
                cur = Node(key, node)
                node.entries[low] = cur
            cur.base = val.get("__parent")                # re-open without base drops it (engine rule)
            cur.defined = True
            merge(cur, val)
        else:
            node.entries[low] = ("v", key, val)


def ancestors(node):
    out = set()
    while node is not None:
        out.add(id(node))
        node = node.outer
    return out


def member(node, low, banned, depth=0):
    if node is None or depth > 64:
        return None
    e = node.entries.get(low)
    if isinstance(e, Node) and id(e) not in banned:
        return e
    return member(resolve_base(node), low, banned, depth + 1)


_BASE_CACHE = {}


def resolve_base(node):
    """Engine lookup: enclosing class (own + inherited members), then outer scopes.
    A class can never derive from itself or one of its own ancestors; when the
    real target is external (vanilla), returning None is the honest answer."""
    if not node.base:
        return None
    key = id(node)
    if key in _BASE_CACHE:
        return _BASE_CACHE[key]
    _BASE_CACHE[key] = None                      # cycle guard while resolving
    low = node.base.lower()
    banned = ancestors(node)
    scope = node.outer
    found = None
    while scope is not None:
        found = member(scope, low, banned)
        if found is not None:
            break
        scope = scope.outer
    _BASE_CACHE[key] = found
    return found


def effective(node):
    """Ordered dict lower -> entry, inherited entries first (overrides keep position)."""
    if node._eff is not None:
        return node._eff
    if node._busy:
        return {}
    node._busy = True
    eff = {}
    base = resolve_base(node)
    if base is not None:
        eff.update(effective(base))
    for low, e in node.entries.items():
        eff[low] = e
    node._busy = False
    node._eff = eff
    return eff


def fmt(val):
    return json.dumps(val, ensure_ascii=False, sort_keys=True)


def dump_node(node, path, out, stack=None):
    stack = stack or set()
    if id(node) in stack or path.count(">>") > 40:
        out.append(f"{path} __cycle")
        return
    stack = stack | {id(node)}
    base = resolve_base(node)
    if node.base:
        out.append(f"{path} __base = {node.base}{'' if base is not None else ' (external)'}")
    if not node.defined and base is None:
        out.append(f"{path} __extern")
    eff = effective(node)
    leaves = sorted(((e[1], e[2]) for e in eff.values() if not isinstance(e, Node)), key=lambda t: t[0].lower())
    for name, val in leaves:
        out.append(f"{path}>>{name} = {fmt(val)}")
    kids = [e for e in eff.values() if isinstance(e, Node)]
    if kids:
        out.append(f"{path} classOrder = {fmt([k.name for k in kids])}")
    for k in sorted(kids, key=lambda n: n.name.lower()):
        dump_node(k, f"{path}>>{k.name}", out, stack)


def is_root(name):
    low = name.lower()
    return low.startswith(ROOT_PREFIXES)


def safe(name):
    return "".join(c if c.isalnum() or c in "_-." else "_" for c in name)


def cmd_dump(args):
    configs = load_build(args.build_dir)
    root = Node("", None)
    order = []
    for pbo, cfg in configs:
        order.append(pbo)
        merge(root, cfg)
    if os.path.isdir(args.out_dir):
        shutil.rmtree(args.out_dir)
    os.makedirs(args.out_dir)
    with open(os.path.join(args.out_dir, "_load_order.txt"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(order) + "\n")
    count = 0
    for top in root.entries.values():
        if not isinstance(top, Node) or not top.defined:
            continue
        if is_root(top.name):
            for cls in top.entries.values():
                if isinstance(cls, Node) and cls.defined:
                    lines = []
                    dump_node(cls, f"{top.name}>>{cls.name}", lines)
                    write(args.out_dir, f"{safe(top.name)}.{safe(cls.name)}.txt", lines)
                    count += 1
            leaves = [f"{top.name}>>{e[1]} = {fmt(e[2])}" for e in top.entries.values() if not isinstance(e, Node)]
            if leaves:
                write(args.out_dir, f"{safe(top.name)}._leaves.txt", sorted(leaves, key=str.lower))
        else:
            lines = []
            dump_node(top, top.name, lines)
            write(args.out_dir, f"_top.{safe(top.name)}.txt", lines)
            count += 1
    print(f"{len(order)} configs merged, {count} class files written to {args.out_dir}")


def write(out_dir, fname, lines):
    path = os.path.join(out_dir, fname.lower())
    mode = "a" if os.path.exists(path) else "w"   # case-insensitive filesystem collisions append
    with open(path, mode, encoding="utf-8") as fh:
        fh.write("\n".join(lines) + "\n")


def cmd_compare(args):
    a_files = {f for f in os.listdir(args.a) if not f.startswith("_load_order")}
    b_files = {f for f in os.listdir(args.b) if not f.startswith("_load_order")}
    skip = (lambda f: f.startswith("cfgpatches.")) if args.ignore_patches else (lambda f: False)
    diffs = 0
    for f in sorted(a_files - b_files):
        if not skip(f):
            print(f"ONLY IN A: {f}"); diffs += 1
    for f in sorted(b_files - a_files):
        if not skip(f):
            print(f"ONLY IN B: {f}"); diffs += 1
    for f in sorted(a_files & b_files):
        if skip(f):
            continue
        with open(os.path.join(args.a, f), encoding="utf-8") as fh:
            la = fh.read().splitlines()
        with open(os.path.join(args.b, f), encoding="utf-8") as fh:
            lb = fh.read().splitlines()
        if la != lb:
            diffs += 1
            print(f"=== DIFF {f}")
            for line in difflib.unified_diff(la, lb, "A", "B", n=0, lineterm=""):
                if not line.startswith(("---", "+++")):
                    print("   " + line[:400])
    print(f"\n{diffs} differing file(s)")
    return 1 if diffs else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("dump"); d.add_argument("build_dir"); d.add_argument("out_dir")
    c = sub.add_parser("compare"); c.add_argument("a"); c.add_argument("b")
    c.add_argument("--ignore-patches", action="store_true", help="skip CfgPatches files")
    args = ap.parse_args()
    if args.cmd == "dump":
        cmd_dump(args)
    else:
        sys.exit(cmd_compare(args))


if __name__ == "__main__":
    main()
