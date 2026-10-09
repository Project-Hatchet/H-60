#!/usr/bin/env python3
"""
compare_dumps.py - compare two config-dump captures by VALUE, tolerating the ways two
rapifiers may legitimately serialise the same value (Phase 3 · WP0).

    python tools/config_dump/compare_dumps.py <dumpDirA> <dumpDirB> [--verbose]

Phase 1 compared dumps with `git diff --no-index`, which is exact. The scons -> HEMTT
migration needs a value comparison instead, because the two toolchains store the same
config differently and the engine resolves both to the same thing:

  * Addon Builder's CfgConvert keeps unquoted arithmetic as a STRING ("160/256"); HEMTT
    evaluates it to a NUMBER (0.625). Both read back as 0.625 where the engine wants a
    number, but the dump tags them T and N.
  * Arma's preprocessor parenthesises substituted macro arguments ("((3+0.2)-0.1)"),
    HEMTT does not ("(3+0.2-0.1)"), and the two insert whitespace differently around
    expanded ARR_n() macros. MFD condition strings and SQF code strings therefore differ
    textually while meaning the same.

Normalisation, per value:
  N              compared as floats
  T              outer quotes stripped; pure arithmetic is evaluated to a number;
                 expressions over userN variables are compared by evaluating both sides
                 at a fixed set of sample values; other strings compare whitespace-insensitively
  A              parsed as a nested array; each element normalised as above
  inherits /     compared exactly (class structure is never a rapifier matter)
  classOrder

Every line that still differs after normalisation is a real content difference and is
listed; the exit code is 1 if any exist. Lines present on one side only are listed too.
"""

import ast
import os
import re
import sys

NUM_RE = re.compile(r"^[-+]?(\d+\.?\d*|\.\d+)([eE][-+]?\d+)?$")
ARITH_RE = re.compile(r"^[\d\s.+\-*/()]+$")
EXPR_RE = re.compile(r"^[\w\s.+\-*/()<>=!&|]+$")
SAMPLES = [0, 1, 2, 3, 5, 7.5, 10, 31, 32, 95, 101, 107, -1, 0.5, 144, 1000]

_ALLOWED = (ast.Expression, ast.BinOp, ast.UnaryOp, ast.Compare, ast.Constant, ast.Name,
            ast.Add, ast.Sub, ast.Mult, ast.Div, ast.USub, ast.UAdd, ast.Lt, ast.Gt, ast.LtE,
            ast.GtE, ast.Eq, ast.NotEq, ast.BoolOp, ast.And, ast.Or, ast.Load)


def _safe_eval(expr, names):
    tree = ast.parse(expr, mode="eval")
    for node in ast.walk(tree):
        if not isinstance(node, _ALLOWED):
            raise ValueError(type(node).__name__)
    def ev(n):
        if isinstance(n, ast.Expression): return ev(n.body)
        if isinstance(n, ast.Constant): return float(n.value)
        if isinstance(n, ast.Name):
            if n.id in names: return float(names[n.id])
            raise ValueError(n.id)
        if isinstance(n, ast.UnaryOp):
            v = ev(n.operand); return -v if isinstance(n.op, ast.USub) else v
        if isinstance(n, ast.BinOp):
            a, b = ev(n.left), ev(n.right)
            if isinstance(n.op, ast.Add): return a + b
            if isinstance(n.op, ast.Sub): return a - b
            if isinstance(n.op, ast.Mult): return a * b
            if isinstance(n.op, ast.Div): return a / b if b != 0 else float("inf")
        if isinstance(n, ast.Compare):
            left = ev(n.left); result = 1.0
            for op, comp in zip(n.ops, n.comparators):
                right = ev(comp)
                ok = {ast.Lt: left < right, ast.Gt: left > right, ast.LtE: left <= right,
                      ast.GtE: left >= right, ast.Eq: left == right, ast.NotEq: left != right}[type(op)]
                result = result * (1.0 if ok else 0.0); left = right
            return result
        raise ValueError("unsupported")
    return ev(tree)


def _sqf_to_py_expr(s):
    # Arma expressions use the same operators as Python for what configs contain; '==' stays,
    # '!=' stays, boolean and/or words are not used in config conditions.
    return s


class Norm:
    """A normalised value with an equality that knows about the tolerated differences."""
    __slots__ = ("kind", "value", "raw")

    def __init__(self, kind, value, raw):
        self.kind, self.value, self.raw = kind, value, raw

    def __eq__(self, other):
        if not isinstance(other, Norm): return False
        a, b = self.value, other.value
        if isinstance(a, float) and isinstance(b, float):
            return abs(a - b) <= 1e-6 * max(1.0, abs(a), abs(b))
        if isinstance(a, list) and isinstance(b, list):
            return len(a) == len(b) and all(x == y for x, y in zip(a, b))
        if isinstance(a, str) and isinstance(b, str):
            if a == b: return True
            ca, cb = re.sub(r"\s+", "", a), re.sub(r"\s+", "", b)
            if ca == cb: return True
            # expression equivalence over userN / pylonN style variables
            if EXPR_RE.match(a) and EXPR_RE.match(b):
                names = sorted(set(re.findall(r"\b[A-Za-z_]\w*\b", a + " " + b)))
                try:
                    for k, sample in enumerate(SAMPLES):
                        env = {n: SAMPLES[(k + i) % len(SAMPLES)] for i, n in enumerate(names)}
                        va, vb = _safe_eval(a, env), _safe_eval(b, env)
                        if abs(va - vb) > 1e-6 * max(1.0, abs(va), abs(vb)): return False
                    return True
                except Exception:
                    return False
            return False
        return False


def norm_scalar(text):
    """A single dump value (N or T) or an array element -> Norm."""
    t = text.strip()
    if len(t) >= 2 and t[0] == '"' and t[-1] == '"':
        inner = t[1:-1].replace('""', '"')
        if NUM_RE.match(inner.strip()):
            return Norm("num", float(inner), text)
        if ARITH_RE.match(inner) and any(c.isdigit() for c in inner):
            try: return Norm("num", float(_safe_eval(inner, {})), text)
            except Exception: pass
        return Norm("str", inner, text)
    if NUM_RE.match(t):
        return Norm("num", float(t), text)
    return Norm("str", t, text)


def parse_array(text):
    """SQF `str getArray` output -> nested python list of Norm. Falls back to one string."""
    s = text.strip()
    pos = 0
    def parse():
        nonlocal pos
        while pos < len(s) and s[pos] in " \t": pos += 1
        if s[pos] == "[":
            pos += 1; out = []
            while True:
                while pos < len(s) and s[pos] in " \t,": pos += 1
                if s[pos] == "]": pos += 1; return out
                out.append(parse())
        if s[pos] == '"':
            j = pos + 1
            while True:
                j = s.index('"', j)
                if j + 1 < len(s) and s[j + 1] == '"': j += 2; continue
                break
            tok = s[pos:j + 1]; pos = j + 1
            return norm_scalar(tok)
        j = pos
        while j < len(s) and s[j] not in ",]": j += 1
        tok = s[pos:j]; pos = j
        return norm_scalar(tok)
    try:
        v = parse()
        return Norm("arr", v if isinstance(v, list) else [v], text)
    except Exception:
        return Norm("str", s, text)


def load_dump(folder):
    """{(file, path, kind, name): Norm-or-raw}"""
    out = {}
    for fn in sorted(os.listdir(folder)):
        if not fn.endswith(".txt"): continue
        with open(os.path.join(folder, fn), encoding="utf-8", errors="replace") as fh:
            for line in fh:
                line = line.rstrip("\r\n")
                if not line: continue
                parts = line.split("|", 4)
                if len(parts) < 5: continue
                root, path, kind, name, value = parts
                key = (fn, path, kind, name)
                if kind == "N": val = Norm("num", float(value) if NUM_RE.match(value.strip()) else value, value)
                elif kind == "T": val = norm_scalar(value)
                elif kind == "A": val = parse_array(value)
                else: val = Norm("exact", value, value)
                out[key] = val
    return out


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    verbose = "--verbose" in sys.argv
    if len(args) != 2:
        print(__doc__); return 2
    a, b = load_dump(args[0]), load_dump(args[1])
    # keys are compared ignoring the N/T kind tag, since "160/256" (T) and 0.625 (N) are one value
    def strip_kind(k): return (k[0], k[1], "V" if k[2] in ("N", "T") else k[2], k[3])
    ka = {strip_kind(k): (k, v) for k, v in a.items()}
    kb = {strip_kind(k): (k, v) for k, v in b.items()}
    only_a = sorted(set(ka) - set(kb)); only_b = sorted(set(kb) - set(ka))
    same = equiv = diff = 0; diffs = []
    for k in sorted(set(ka) & set(kb)):
        (ra, va), (rb, vb) = ka[k], kb[k]
        if va.raw == vb.raw: same += 1
        elif va == vb: equiv += 1
        else: diff += 1; diffs.append((k, va.raw, vb.raw))
    print(f"compared {same + equiv + diff} values: {same} identical, {equiv} equivalent after normalisation, {diff} DIFFERENT")
    print(f"only in A: {len(only_a)}   only in B: {len(only_b)}")
    for k, ra, rb in diffs[:400 if not verbose else None]:
        print(f"DIFF {k[0]} | {k[1]} | {k[3]}\n     A: {ra[:160]}\n     B: {rb[:160]}")
    for k in only_a[:100]: print(f"ONLY-A {k[0]} | {k[1]} | {k[2]} {k[3]}")
    for k in only_b[:100]: print(f"ONLY-B {k[0]} | {k[1]} | {k[2]} {k[3]}")
    return 1 if (diff or only_a or only_b) else 0


if __name__ == "__main__":
    sys.exit(main())
