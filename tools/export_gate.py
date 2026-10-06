r"""
export_gate.py - validate (and optionally patch) a fresh vtx_uh60 MLOD export
before binarizing. Born from the 2026-09-19/20 "blotchy tail" hunt: the
Blender exporter silently breaks four things on every export, and one more
(seat UV smear) intermittently. Mirrors the MH-47 team's post-export ritual
for the same exporter family (their L05 law).

    python tools/export_gate.py <export.p3d>                # check only
    python tools/export_gate.py <export.p3d> --fix <out.p3d>  # check + patch

CHECKS (F = auto-fixable with --fix):
  1F. point flags: exporter stamps 0x2000000 on every vertex (healthy = 0x0;
      known-good hidden verts 0x1000000 are preserved)
  2F. Geometry-LOD named properties: prefershadowvolume=1 +
      sbsource='shadowvolume ' dropped, canocclude flipped to 0
      -> missing = the engine shadow-buffers from the open visual mesh:
      angle-dependent glossy/grey self-shadow patches
  3F. markings baked texture: scene bakes a3 empty_ca.paa; must be
      markings_ca.paa or binarize classifies the decal section OPAQUE
      (grey quads over the boom, "blotchy tail", all variants)
  4.  MFOS seat UV smear (2026-09-06 incident, live in the scene): mfos_co
      faces with UV set 0 outside [0,1] -> chrome/mirror seats. NOT
      auto-fixable here; re-fix the scene or transplant UVs from the master.
  5.  aft proxies present: cargo03.026/.027 (>= 10 refs each)
  6.  cross-addon material refs: everything outside z\vtx\addons\uh60\ must
      be seeded into the binarize scratch (z\vtx\addons\mh60m\data set)

Exit code 0 = pass (or all fixable issues fixed), 1 = failures remain.
"""
import argparse
import collections
import re
import struct
import sys

MARKINGS_BAD = b'a3\\ui_f\\data\\igui\\cfg\\targeting\\empty_ca.paa'
MARKINGS_GOOD = b'z\\vtx\\addons\\uh60\\data\\exterior\\markings\\markings_ca.paa'
GEO_PROPS = [(b'prefershadowvolume', b'1'), (b'sbsource', b'shadowvolume ')]


def read_asciiz(d, o):
    e = d.index(b'\x00', o)
    return d[o:e], e + 1


def walk(d):
    """Yield per-LOD: (lod_start, npts, nnorm, nfaces, faces_start, tagg_start, lod_end, res)."""
    assert d[:4] == b'MLOD', 'not an MLOD p3d'
    n_lods = struct.unpack_from('<I', d, 8)[0]
    o = 12
    for li in range(n_lods):
        assert d[o:o+4] == b'P3DM', f'LOD {li} misaligned'
        npts, nnorm, nfaces = struct.unpack_from('<III', d, o + 12)
        faces_start = o + 28 + npts * 16 + nnorm * 12
        p = faces_start
        for i in range(nfaces):
            p += 4 + 64 + 4
            _, p = read_asciiz(d, p)
            _, p = read_asciiz(d, p)
        assert d[p:p+4] == b'TAGG'
        tagg_start = p + 4
        q = tagg_start
        while True:
            q += 1
            name, q = read_asciiz(d, q)
            ln = struct.unpack_from('<I', d, q)[0]; q += 4
            q += ln
            if name == b'#EndOfFile#':
                break
        res = struct.unpack_from('<f', d, q)[0]
        yield li, o, npts, nnorm, nfaces, faces_start, tagg_start, q + 4, res
        o = q + 4


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('p3d')
    ap.add_argument('--fix', metavar='OUT', help='write a patched copy')
    args = ap.parse_args()
    d = bytearray(open(args.p3d, 'rb').read())
    failures = []
    fixed = []

    lods = list(walk(bytes(d)))
    print(f'{args.p3d}: {len(lods)} LODs, {len(d):,} bytes')

    # --- 1: point flags ---------------------------------------------------
    stamped = 0
    for li, o, npts, *_ in lods:
        for i in range(npts):
            off = o + 28 + i * 16 + 12
            fl = struct.unpack_from('<I', d, off)[0]
            if fl & 0x2000000:
                stamped += 1
                if args.fix:
                    struct.pack_into('<I', d, off, fl & ~0x2000000)
    if stamped:
        (fixed if args.fix else failures).append(f'point flags: {stamped:,} verts stamped 0x2000000')

    # --- 2: geometry props (+ 3 markings) via tagg walk -------------------
    geo_missing = []
    geo_insert_at = None
    canocc_at = None
    for li, o, npts, nnorm, nfaces, faces_start, tagg_start, lod_end, res in lods:
        if abs(res - 1e13) > 1e10:
            continue
        have = {}
        q = tagg_start
        while True:
            q += 1
            name, q = read_asciiz(bytes(d), q)
            ln = struct.unpack_from('<I', d, q)[0]; q += 4
            pay = q
            q += ln
            if name == b'#EndOfFile#':
                break
            if name == b'#Property#' and ln == 128:
                k = bytes(d[pay:pay+64]).split(b'\x00')[0]
                have[k] = pay + 64
        for k, v in GEO_PROPS:
            if k not in have:
                geo_missing.append(k.decode())
        if b'canocclude' in have and d[have[b'canocclude']:have[b'canocclude']+2] == b'0\x00':
            geo_missing.append('canocclude=0')
            canocc_at = have[b'canocclude']
        geo_insert_at = tagg_start
    if geo_missing:
        if args.fix:
            if canocc_at is not None:
                d[canocc_at:canocc_at+1] = b'1'
            ins = b''
            for k, v in GEO_PROPS:
                if k.decode() in geo_missing:
                    ins += (b'\x01' + b'#Property#\x00' + struct.pack('<I', 128)
                            + k.ljust(64, b'\x00') + v.ljust(64, b'\x00'))
            d[geo_insert_at:geo_insert_at] = ins
            fixed.append(f'geometry props: {", ".join(geo_missing)}')
        else:
            failures.append(f'geometry props missing/wrong: {", ".join(geo_missing)}')

    # re-walk after possible insertion
    lods = list(walk(bytes(d)))

    # --- 3: markings baked texture (rebuild pass if fixing) ---------------
    bad_markings = bytes(d).lower().count(MARKINGS_BAD.lower())
    if bad_markings:
        if args.fix:
            src = bytes(d)
            out = [src[:12]]
            o = 12
            for li, lo, npts, nnorm, nfaces, faces_start, tagg_start, lod_end, res in lods:
                out.append(src[lo:faces_start])
                p = faces_start
                for i in range(nfaces):
                    rs = p
                    p += 4 + 64 + 4
                    tex, p = read_asciiz(src, p)
                    mat, p = read_asciiz(src, p)
                    if tex.lower() == MARKINGS_BAD.lower():
                        out.append(src[rs:rs+72] + MARKINGS_GOOD + b'\x00' + mat + b'\x00')
                    else:
                        out.append(src[rs:p])
                out.append(src[p:lod_end])
                o = lod_end
            d = bytearray(b''.join(out))
            fixed.append(f'markings baked texture: {bad_markings} empty_ca faces -> markings_ca')
            lods = list(walk(bytes(d)))
        else:
            failures.append(f'markings baked texture: {bad_markings} faces baked empty_ca (opaque decal layer)')

    # --- 4: seat UV smear (check only) ------------------------------------
    smeared = total = 0
    src = bytes(d)
    for li, o, npts, nnorm, nfaces, faces_start, *_ in lods:
        p = faces_start
        for i in range(nfaces):
            nverts = struct.unpack_from('<I', src, p)[0]
            uvs = [struct.unpack_from('<ff', src, p + 4 + v * 16 + 8) for v in range(nverts)]
            p += 4 + 64 + 4
            tex, p = read_asciiz(src, p)
            _, p = read_asciiz(src, p)
            if b'mfos' in tex.lower():
                for (u, v) in uvs:
                    total += 1
                    if not (-0.1 <= u <= 1.1) or not (-0.1 <= v <= 1.1):
                        smeared += 1
    if total and smeared / total > 0.005:
        failures.append(f'MFOS seat UV SMEAR: {smeared:,}/{total:,} verts outside 0..1 - '
                        'NOT auto-fixable; fix the Blender scene or transplant from the master')

    # --- 5: proxies --------------------------------------------------------
    for pr in (b'cargo03.026', b'cargo03.027'):
        n = src.count(pr)
        if n < 10:
            failures.append(f'aft proxy {pr.decode()}: only {n} refs (expect >= 10)')

    # --- 6: cross-addon refs ----------------------------------------------
    ext = collections.Counter(
        m.group(0).lower() for m in
        re.finditer(rb'[ -~]{4,260}?\.(?:paa|rvmat)', src, re.IGNORECASE)
        if not m.group(0).lower().startswith((b'z\\vtx\\addons\\uh60\\', b'a3\\', b'#')))
    if ext:
        print('cross-addon refs (seed these into the binarize scratch):')
        for k in sorted(ext):
            print(f'   {k.decode()}')

    if args.fix and fixed:
        open(args.fix, 'wb').write(d)
        print(f'PATCHED -> {args.fix} ({len(d):,} bytes)')
        for f in fixed:
            print(f'   fixed: {f}')
    for f in failures:
        print(f'FAIL: {f}')
    if not failures and not (fixed and not args.fix):
        print('GATE: PASS' + (' (after fixes)' if fixed else ''))
    sys.exit(1 if failures else 0)


if __name__ == '__main__':
    main()
