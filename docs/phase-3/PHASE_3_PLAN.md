# H-60 Phase 3 — Build System: HEMTT Migration + Real CI

**Prepared:** 2026-10-09 · **Status:** planned, not started. Main is `d73d3bc` (HeliSim #632 + the scons junction fix #648); Phase 2 is complete; every branch cuts from Main again.
**Prerequisites met:** Phase 2 left the tree Linux-buildable — 627 `#include` lines, 0 case-broken, 0 unresolved, 0 BOM files (scan of 2026-10-09). The scons CI job is green again since #648.
**Reader copy:** none yet; render a plain-English PDF beside this file when the phase ships (same convention as `phase-2/`).

---

## 1. Objective

Replace the SCons + Addon Builder + `print.exe` build with HEMTT, so that the mod builds identically on Windows and on a Linux CI runner, with lints on every push, and so that the devbuild pipeline, Workshop pushes and Stable releases all run off the same tool. Nothing about the mod's behavior changes in this phase; the proof is a build-for-build comparison, not a play test.

The migration is **staged and reversible**: SCons stays in the tree and in CI until the HEMTT output has been proven equivalent on the same commit and one tester wave has flown a HEMTT devbuild. 0.8 Stable ships from whichever pipeline is proven when it is time to ship.

## 2. Target end-state

| Today | After Phase 3 |
|---|---|
| `SConstruct` + `tools/build.json` + `tools/buildExtIncludes.txt`, Windows-only, Arma 3 Tools download secret in CI, fork PRs cannot build | `.hemtt/project.toml` + per-addon `addon.toml` where needed; `hemtt build` on `ubuntu-latest`, no secrets, fork PRs get CI |
| Binarization disabled via the `print.exe` hack; configs rapified by Addon Builder; rvmats shipped as text | `hemtt build --no-bin`: configs and rvmats rapified by HEMTT, p3ds (already ODOL) copied through; SQF compiled to bytecode |
| Version in `addons/main/script_version.hpp`, injected into the PBO header by a hand-written `stampPboVersion` | Same file, read natively by HEMTT (`MAJOR/MINOR/PATCHLVL/BUILD`); HEMTT writes the `version`, `hemtt` and `git` header properties itself |
| PBO names `hct_h60_<folder>.pbo` from a string in `SConstruct` and in `push_dev.py` | `hct_<folder>.pbo` straight from HEMTT's `prefix = "hct"` after the folder renames (§6); no hook; `push_dev.py` reads the names from the output folder |
| `validate` CI job commented out, referencing three scripts that do not exist | `hemtt check --pedantic` + the ported validators (`tools/`) as a real job |
| `push_dev.py` runs `scons all` into `release/@H-60`, which never prunes PBOs of deleted addons | `push_dev.py` runs `hemtt build` into a clean `.hemttout/build`, copies to the mod folder, uploads |
| Stable: unsigned package built locally, Riverman signs with DSSignFile, uploads by hand | Stable: `hemtt release --no-sign` produces the unsigned `@H-60` + zip; Riverman signs with DSSignFile and uploads by hand, as today (ruled) |
| Developers test with `scons symlinks` (junctions into the Arma folder) | `hemtt dev` / `hemtt launch` profiles (`.hemtt/launch.toml`) |

## 3. What the references tell us

- **HeliSim Core** (Brad): `project.toml` with `prefix`/`mainprefix`, explicit `[version]`, `[files] include`, a commented-out dev-only `exclude = ["**/*.sqfc"]` switch for file patching, `ignore_pboprefix = true`, a `version_files.rhai` pre-build hook, permissive `lints.toml`. Brad builds Core and the Apache with HEMTT and is the natural reviewer of our `project.toml`.
- **AH-64D**: the only reference with the full set — `[rapify] enabled = false` on exactly one addon (the MPD, because `__EVAL` with `cos`/`sin` is beyond HEMTT's preprocessor), a `post_build` + `archive` hook pair that renames PBOs and `.bisign` files, a `pre_release` guard that refuses to ship while the `.sqfc` exclude is active, `launch.toml` profiles (`minimal` / `normal` / `profiling`), a Python naming validator in CI.
- **Hatchet Interaction Framework** (our own team): already builds with HEMTT on `ubuntu-latest` with `arma-actions/hemtt@v1`, renames `.hemttout/build` to `@hct` and uploads it as the artifact, and runs the **same devbuild bot** as the H-60 — so the H-60 is the last Hatchet project still on SCons.
- **The abandoned 2025 attempt** (`origin/hemtt-gh-action`, one commit, June 2025): a copied-from-ZEN `hemtt.yml` plus a `hemtt.toml` in the long-dead HEMTT 0.x format (`[scripts.version_set]`, sed-stamping `mod.cpp`). Nothing in it is reusable; delete the branch and the `.gitignore` / `.vscode/sqfvm-lsp/ls-ignore.txt` remnants with WP2.

## 4. Facts established for this plan (2026-10-09)

Verified in the tree and against the HEMTT 1.22 docs; the scouting pass (WP1) confirms the ones marked *expect*.

- **Version is already a single source.** HEMTT reads `addons/main/script_version.hpp` by default and accepts `PATCHLVL` as the patch macro. The devbuild bot stamps that same file on the generated branch, so devbuild versions flow through unchanged. The HEMTT-built framework PBO carries `version`, `hemtt` and `git` header properties; our scons PBO carries only `version` — `stampPboVersion` and its SHA-1 rewrite can be deleted outright. The master plan's 3.1 item (`BUILDHASH`/`RELEASENAME` retirement) is already done: the file is four `#define`s.
- **Preprocessor escapes are smaller than feared.** Exactly one live `__EVAL` site exists: `H60_SFX/config.cpp` (`__EVAL(0.75*NUM)`, plain arithmetic — *expect* HEMTT handles it). The eight `__EXEC(vtx_x = 1.45 + random 0.05;)` lines in `uh60_mfd/config/MFD/pages/eicas_bones.hpp` sit inside a `/* … */` block (lines 10–61) and are dead text that both preprocessors strip; the block (and a second one at lines 132–164) is a WP2b deletion candidate, not an escape. No addon is expected to need `[rapify] enabled = false`. The `BMKHS_CONTROL` redefinition in `uh60_helisim/config/CfgUserActions.hpp` is a functional override (it routes to `vtx_uh60_helisim_fnc_cockpitBind`), not just an Addon Builder workaround, and stays. `uh60_anvishud` and `uh60_fms` use no `__EVAL` at all.
- **Packing differs by default.** Addon Builder packs only the extensions in `buildExtIncludes.txt`; HEMTT packs everything. Files in `addons/` outside that list today: 13 `.png`, 4 `.tga`, `addons/main/README.md`. `project.toml` needs a matching `[files] exclude` or the PBO manifests will not match.
- **`$PBOPREFIX$` files are the prefix that ships.** Verified in HEMTT's `pboprefix` module: the file's value is used as the PBO prefix; the project `prefix`/`mainprefix` only feed a *warning* when the file differs from `z\<prefix>\addons\<folder>`, and `ignore_pboprefix = true` silences it. The AH-64D ships that way (`$PBOPREFIX$` = `fza_ah64_mpd`, project prefix `fza_ah64`). So the files stay exactly as they are (`z\vtx\addons\...`), the project prefix can be `hct`, and folder names are decoupled from every baked path — which is what makes §6 possible. The three folders whose file differs from the folder only in case (`UH60`, `MH60M`, `MH60S`) stop being a question once the folders are lower-cased; `HH60`'s file lacks a trailing newline (harmless).
- **The vendored Core headers resolve natively.** `include/bmkhs_helisim`, `include/x/cba`, `include/z/ace` is HEMTT's own `include/` convention; the `SConstruct` copy-into-`build\` step disappears. The "matches Core 1.2.0.0" README note must be refreshed to 1.2.1 when Core is pinned for 0.8.
- **No binarization is lost.** All 28 `.p3d` are ODOL and the current build binarizes nothing anyway, so `hemtt build --no-bin` is the direct equivalent. `addons/UH60/texHeaders.bin` is an Addon Builder cache (gitignored) and is not needed.
- **Bytecode is new.** HEMTT compiles every `.sqf` to `.sqfc` in build and release. That is a performance gain, but (a) HEMTT's SQF compiler refuses code it cannot parse, so the first `hemtt build` is itself a syntax audit, and (b) Arma prefers a `.sqfc` over a loose `.sqf`, so file patching silently stops working unless the dev-only exclude is active (Core's and AH-64D's documented trap).
- **Stale output is a live hazard.** `release/@H-60/addons` on this machine still holds `hct_h60_uh60_engine.pbo`, `_fd.pbo` and `_sfmplus.pbo` — addons deleted by #632. HEMTT's clean output directory removes the class of bug, but `push_dev.py`'s upload path must switch with it.

## 5. Work packages

### WP0 — Equivalence harness

Build-proof tooling, used by every later WP. Lives in `tools/`, not in the session record this time.

- `tools/pbo_compare.py`: list every PBO's entries (name, size, SHA-1) and header properties; diff two output folders; classify each difference as *expected* (rapifier bytes, `.sqfc` present/absent, rvmat text vs raP, `hemtt`/`git` header properties, prefix case) or *unexpected*. Port of the Phase 2 session comparer.
- Config-dump baseline: `tools/config_dump` run on a scons build of the pinned commit (same modset and game version as Phase 1's captures; no ACRE). Values, not bytes, are the acceptance criterion for configs.
- Acceptance: the harness run on two consecutive scons builds of the same commit reports only `timepacked`-class differences.

### WP1 — Scouting pass (scratch worktree, zero repo changes)

A `git worktree` of Main with a draft `.hemtt/project.toml` modelled on Core's and the AH-64D's. Run `hemtt check`, `hemtt build --no-bin`, inventory every failure. Deliverable: a findings list in the WP2 PR descriptions (and `docs/phase-3/proof/scouting.md` if long).

Checklist:
1. `[files] exclude` reproducing `buildExtIncludes.txt` (`*.png`, `*.tga`, `*.md`, anything else the manifest diff shows).
2. `ignore_pboprefix = true` on every addon with `prefix = "hct"`: confirm the built PBO's `prefix` header property still reads `z\vtx\addons\<x>` and that nothing else (launch, signing authority aside) derives a path from the project prefix.
3. `H60_SFX` `__EVAL` arithmetic — pass, or `[rapify] enabled = false` for that one addon.
4. `eicas_bones.hpp`: confirm the commented-out `__EXEC` blocks are inert under HEMTT (they should be) and queue them for deletion in WP2b.
5. `hemtt check --pedantic` volume by lint, so `lints.toml` can start at Core's permissive baseline and tighten per PR (ruled: baseline first, tighten as we go).
6. Bytecode compile errors: every `.sqf` HEMTT refuses is a real finding (fix in WP2).
7. Stringtable lints on the 9 `stringtable.xml` files (`<Project name="VTX">`, unused keys).
8. In-PBO content: do `hemtt`-rapified configs dump to the same values (first run of WP0 against a HEMTT build).
9. Timings: `hemtt build` wall-clock on this machine vs the ~minutes of scons (which rebuilds all 25 PBOs every run).
10. Ask Brad up front whether the H-60 should adopt Core's dev-mode `.sqfc` exclude switch and `hemtt launch` for file patching — it shapes `project.toml` and the developer instructions.

### WP2 — HEMTT project config + tree fixes (small PRs to Main)

Each PR keeps **both** builds green: scons CI stays as it is until WP4.

- **2a `.hemtt/` lands**: `project.toml` (`prefix = "hct"`, `mainprefix = "z"`, `[version] path` pointing at the main addon, `git_hash` as agreed, `[files] include` = `mod.cpp`, `meta.cpp`, the two logos, `LICENSE`, `README.md`; `[files] exclude` from WP1; `[hemtt.release] sign/archive`), `lints.toml` (Core's baseline + whatever WP1 showed must be ignored for now), `launch.toml` (`minimal` = CBA + ACE + Hatchet Framework; `profiling` extends it with Arma Script Profiler — master plan 3.2), `ignore_pboprefix = true` in all 25 `addon.toml` plus any escape WP1 proved necessary, `.gitignore` gains `.hemttout/` and `keys/` (already) and loses the stale remnants. "Release notes: Ignore".
- **2b tree fixes**, one PR per class of finding (preprocessor strictness, bytecode-compile refusals, stringtable fixes), each proven with WP0 against a scons build of its own head: config values identical, SQF validator counts unchanged. Any finding whose fix would change a value is *not* a WP2 fix — it goes to §8 for a ruling.
- **2c `include/bmkhs_helisim` README** refreshed to the pinned Core version (rides whichever PR touches it, or the 0.8 release PR).
- **2d folder renames** (one PR, the user-visible one — "Release notes: Enhancement"): the 25 `git mv`s of §6, the `"hct_h60_"` literal in `SConstruct` and `PBO_PREFIX` in `push_dev.py` become `"hct_"` so both pipelines emit identical filenames during the overlap, `[version] path` in `project.toml`, `devScripts/uh60_misc` → `devScripts/h60_misc`, the `noBinarize` names in `tools/build.json`, the paths in `include/bmkhs_helisim/README.md` and in the docs. `$PBOPREFIX$` contents, `COMPONENT` macros, CfgPatches classes and every `z\vtx\addons\...` path are untouched, so the config dump must come out identical. Lands **after** #630 → #631 → #633 merge (they touch three of the folders); case-only renames need `git mv`, not Explorer.
- Collision note: PRs #630 → #631 → #633 are open on Main and touch `uh60_hoist`, `uh60_doorguns`, `MH60M` and `uh60_mfd`. 2a adds only new files and cannot collide; 2b PRs avoid those addons until the chain merges, or stack on #633.

### WP3 — Equivalence proof

Same Main commit built by `scons all` and by `hemtt build --no-bin`:
- `tools/pbo_compare.py`: every difference classified *expected*; zero *unexpected*.
- `tools/config_dump`: identical values, every class, every variant (same method as Phase 1).
- In-game smoke on the HEMTT build only: spawn every variant, MFD page walk, HeliSim start sequence, one hoist cycle, FLIR on — looking for script errors the bytecode compiler or the stricter preprocessor might have introduced. Clean RPT required.
- Report in `docs/phase-3/proof/equivalence-<sha>.md`.

### WP4 — Cut-over (four reversible steps, each its own PR)

- **4a CI.** `build.yml` gains an `ubuntu-latest` job: `arma-actions/hemtt@v1` (with `GITHUB_TOKEN` to avoid the API rate limit that failed the framework's early runs), `hemtt check --pedantic`, `hemtt build --no-bin`, rename `.hemttout/build` → `@H-60`, upload as the artifact. The Windows scons job stays beside it. The commented-out `validate` job is replaced by a real one (see 4d). Fork PRs now get a green or red check instead of a skip. `paths-ignore` for `docs/**` and `**.md` as the framework and Core do.
- **4b devbuild on HEMTT.** The devbuild bot needs no change (it only stamps `script_version.hpp` and pushes a branch). `push_dev.py`: `build()` runs `hemtt build --no-bin`, copies `.hemttout/build` into the mod folder, writes the Dev `mod.cpp`, verifies 25 fresh PBOs by **listing** the output rather than predicting names; `wipe_mirror()` and the AddonBuilder registry lookups go; the two recorded traps are designed out (fetch before checking out `devbuild`; refuse to build when the local `devbuild` is behind `origin/devbuild`). One tester wave flies this build with a test card; its items are "nothing changed" items plus any WP3 smoke item.
- **4c Stable release path.** `hemtt release --no-bin --no-sign` produces the unsigned `.hemttout/release/@H-60` and `releases/*.zip`; Riverman signs the PBOs with DSSignFile and uploads by hand, exactly as today (ruled 2026-10-09), so the stable-release procedure changes only in where the unsigned package comes from. The `mod.cpp` swap step disappears because the repo-root `mod.cpp` *is* the Stable one and only the Dev script overwrites it. SCons stays in the tree. README build instructions and `docs/README.md` updated. "Release notes: Ignore" — the filename change was announced with 2d.
- **4d Validators.** Port the Phase 2 session scripts into `tools/` and wire them into the CI `validate` job and a documented pre-commit: include-case + orphan-header walker, `PREP` ↔ file parity, empty-file detection, `arma-actions/bom-check` on `addons/`, the existing `sqf_validator.py`, a `checkFilePaths.py`-style naming validator with `vtx` regexes (addon folders, `fnc_*.sqf`, `.hpp` naming), and `pbo_compare.py` as a manual tool. HEMTT's own stringtable lint covers 4.6's regression guard. Each validator lands with the tree already passing it, or it is not wired yet.
- **4e Retire SCons** — gated, at Riverman's discretion, after one Stable or one full tester wave has shipped from HEMTT (ruled 2026-10-09). Delete `SConstruct`, `.sconsign.dblite`, `tools/buildExtIncludes.txt`, the `build/` junction scheme, the `print.exe` hack, the `A3TOOLS_S3_URL` secret dependency and the Windows CI job. `tools/build.json` is scons-only except for `devNextVersion`, which the devbuild bot reads: that key moves to `tools/devbuild.json` and the bot's `git show` line in `devbuild.yml` follows it in the same PR (ruled 2026-10-09).

### WP5 — Hygiene tail (master plan 3.5; optional, can ride the 0.8 release PR)

One changelog (`CHANGELOG-DEV.md` folded into `CHANGELOG.md`, sectioned), release-drafter's tag template and placeholder text, the two issue-template filenames with trailing spaces, `AUTHORS.txt`/`meta.cpp`/`author=""` fields, the 8 stale branches (Riverman deletes). Nothing here gates the migration.

## 6. PBO naming — RULED 2026-10-09

HEMTT names PBOs `<prefix>_<folder>.pbo`. Riverman's ruling: project `prefix = "hct"` and the addon folders are renamed so the filenames come out right with **no rename hook**. The `$PBOPREFIX$` files keep their `z\vtx\addons\...` content (§4), so the 178 files and the p3ds that hardcode those paths, the `COMPONENT` macros, the CfgPatches classes (`vtx_uh60_mfd` …), function names, CBA settings and keybinds are all untouched. `mission.sqm` `addons[]` entries keep loading; no stubs are needed. The only consumers of the filenames are server mod whitelists and the `.bisign` files.

Every folder is lower-case. Every non-airframe folder carries `h60_` so no other Hatchet pack can ever produce the same filename (the Interaction Framework already ships `HCT_main.pbo`; a bare `hct_stretcher.pbo` is a name any pack could claim). The four airframe folders carry only their designation.

| Folder today | Folder after | PBO today | PBO after |
|---|---|---|---|
| `uh60_mfd`, `uh60_flir`, `uh60_fms`, `uh60_hoist`, `uh60_weapons`, `uh60_doorguns`, `uh60_misc`, `uh60_ui`, `uh60_jvmf`, `uh60_cas`, `uh60_aar`, `uh60_acre`, `uh60_anvishud`, `uh60_config`, `uh60_helisim`, `uh60_ground` | `h60_<x>` | `hct_h60_uh60_<x>.pbo` | `hct_h60_<x>.pbo` |
| `main`, `ace_viv`, `air_control`, `stretcher` | `h60_main`, `h60_ace_viv`, `h60_air_control`, `h60_stretcher` | `hct_h60_<x>.pbo` | `hct_h60_<x>.pbo` (unchanged) |
| `H60_SFX` | `h60_sfx` | `hct_h60_H60_SFX.pbo` | `hct_h60_sfx.pbo` |
| `UH60`, `HH60`, `MH60M`, `MH60S` | `uh60`, `hh60`, `mh60m`, `mh60s` | `hct_h60_UH60.pbo` … | `hct_uh60.pbo`, `hct_hh60.pbo`, `hct_mh60m.pbo`, `hct_mh60s.pbo` |

**Timing.** The Dev branch gets the new names on the first devbuild after WP2d — harmless, it is unsigned and no whitelist tracks it. Stable gets them at the minor bump it next ships with (0.8 if 2d lands first, else 0.9), announced in that changelog so server whitelists change once. The master plan's "folder renames deferred until a model-touching release" note was written when the folder name was tied to the junction path; the `$PBOPREFIX$` file carries that path, so it no longer applies.

## 7. Branch & PR strategy

- Everything cuts from Main, `--no-track`, one `phase3/<slug>` branch per PR, chained sequentially per the standing policy. Claude stages; Riverman commits, pushes, opens and merges.
- Order: WP0 (tools only) → WP2a (`.hemtt/` lands, no behavior) → WP2b fixes (as many as WP1 found) → WP2d folder renames (after the open chain) → WP3 proof (docs only) → WP4a → WP4b (+ tester wave) → WP4c → WP4d → WP5 → WP4e when Riverman calls it.
- Labels: "Release notes: Ignore" for everything except 2d (the filename change).
- Reviewers: Brad for `project.toml`, `lints.toml` and the rapify exceptions; BroBeans as usual for anything touching SQF.
- Signing is ruled (DSSignFile stays), so 4c has no open prerequisite.

## 8. Rulings and open items

**Ruled (Riverman, 2026-10-09):**

- **PBO naming** — §6: prefix `hct`, lower-case `h60_*` folder renames, no hook.
- **Who signs** — Riverman keeps signing with DSSignFile. HEMTT runs with `--no-sign`; CI never holds a key.
- **When SCons dies** — after one Stable or one full tester wave from HEMTT, whichever Riverman is comfortable with at the time (WP4e).
- **Lint policy** — start at Core's permissive baseline, tighten rule by rule in later PRs, each with the tree already clean. Banned-command rules belong to Phase 4.
- **Workshop upload stays local** — `push_dev.py` keeps using PublisherCmd with the logged-in Steam client; Stable uploads stay manual; CI never gets Steam credentials.
- **`devNextVersion` moves to `tools/devbuild.json`** in WP4e, with the bot's one `git show` line in `devbuild.yml` updated in the same PR; the rest of `build.json` dies with SCons.

**Open:**

1. **Dev-mode file patching.** Adopt Core's commented-out `**/*.sqfc` exclude switch + AH-64D's `pre_release` guard, or leave developers on `hemtt dev`? Ask Brad first (WP1 item 10).

## 9. Verification & acceptance

| Step | Passes when |
|---|---|
| WP0 | Two scons builds of one commit compare clean; config-dump baseline captured and spot-checked against Phase 1's |
| WP1 | Findings list exists; every HEMTT failure has a WP2 PR or a §8 ruling |
| WP2 (each PR) | scons CI green; config values identical to the PR's base; SQF validator counts unchanged; `hemtt build --no-bin` succeeds locally |
| WP3 | Zero *unexpected* manifest differences; identical config values; clean RPT on the smoke pass |
| WP4a | Both CI jobs green on Main and on a fork PR |
| WP4b | A HEMTT devbuild Workshop push with a tester wave and no build-attributable reports |
| WP2d | Both pipelines emit the §6 filenames; config dump identical; `git log --follow` works on a moved file |
| WP4c | `hemtt release --no-sign` output signs cleanly with DSSignFile and verifies in game; scons still present and green |
| WP4e | scons files gone, `devNextVersion` re-homed, bot and CI green on the next devbuild |
| WP4d | Every wired validator passes on Main the day it lands |

## 10. Do-NOT list

- Do not change any CfgPatches class name, function name, CBA setting or keybind name — `vtx` → `hct` is a Phase 4+ decision with its own deprecation plan.
- Do not touch `$PBOPREFIX$` contents; the baked `z\vtx\addons\...` paths live there, not in the folder names. Folder renames happen only in WP2d, after the open PR chain merges.
- Do not let a value change ride a Phase 3 PR. Anything the config dump shows as different gets its own ruling.
- Do not enable HEMTT binarization; there are no MLODs in the tree and the current build binarizes nothing.
- Do not ship a release while the dev-only `.sqfc` exclude is active (adopt the AH-64D guard hook if the exclude is adopted).
- Do not move Workshop credentials into CI.
- Do not delete SCons, the Windows job or `build.json` before Riverman calls WP4e, and do not delete `build.json` without moving `devNextVersion` to `tools/devbuild.json` and updating the bot in the same PR.
- Do not name private reference projects in this repo; cite AH-64D, HeliSim Core and the Hatchet Interaction Framework.

## 11. Risks & mitigations

| Risk | Mitigation |
|---|---|
| `hemtt check --pedantic` floods with lints, stalling the phase | Permissive `lints.toml` first; lints enabled one at a time, each with the tree already clean |
| Bytecode compiler refuses SQF that Arma accepts (rare syntax) | WP1 lists them; each is a small, behavior-preserving rewrite proven by the SQF validator and an in-game check |
| Developer workflow change (junctions → `hemtt dev`/`launch`) breaks Brad's or BroBeans's testing loop | Ask first (WP1 item 10); document the new loop in README before 4c; keep `scons symlinks` until 4e |
| Prefix-case or header-property differences hide a real manifest difference | `pbo_compare.py` classifies expected differences explicitly; anything unclassified fails |
| The PBO rename trips a community server's mod whitelist | Changelog announcement at the minor bump Stable ships with; Dev-branch names are not whitelisted anywhere |
| Folder renames collide with the open #630 → #631 → #633 chain | 2d waits for the chain; squash merges across a `git mv` are not attempted |
| Two queued devbuild regenerations overwrite each other's stamp (recorded trap) | Unchanged by this phase; documented in `push_dev.py` and re-verified by the version in `DEVBUILD.md` before each push |
| CI minutes: `ubuntu-latest` HEMTT builds of a 770 MB addon tree | Framework and Core builds take minutes; artifact upload of ~770 MB is the real cost — keep the existing `-nobin` artifact only on Main pushes if quota bites |

## 12. What this phase hands to later phases

- Phase 4 inherits a lint gate it can tighten rule by rule (`sqf.banned_commands`, naming validators, stringtable usage).
- Phase 5 inherits `hemtt launch` profiles for the MP repro rig and `tools/pbo_compare.py` for every refactor proof.
- Phase 6 inherits one changelog and a release path (`hemtt release` → GitHub release draft) with no hand steps except signing and the Workshop upload.
