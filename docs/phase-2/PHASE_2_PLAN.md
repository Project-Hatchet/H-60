# H-60 Phase 2 — Delete First, Refactor Second: As-Built Record

**Prepared:** 2026-10-08 · **Status:** in progress — four PRs open against the HeliSim integration branch (`UH60-HeliSim-Integration`, PR #632), not Main.
**Prerequisite:** Phase 1 — **COMPLETE** (Stable 0.7.10, 2026-10-06).
**Plain-English summary:** `H60_Phase_2_Plain_English.pdf` beside this file (re-render when this record changes).

---

## 1. Objective

Remove what nothing uses and fix what only Windows tolerates, with **zero behavior change**, so that the HEMTT migration (Phase 3) starts from a tree a Linux runner can build. Every PR in this phase is proven by rebuilding the affected addons before and after and comparing the rapified `config.bin` of each PBO: identical apart from AddonBuilder's `timepacked` trailer, or the PR is not a Phase 2 PR.

## 2. Two rulings that shaped the delivery

- **Chain of small PRs, not one PR** (Riverman, 2026-10-07, per the standing sequential-PR policy). The master plan's original "one PR, reviewed as pure deletions" line is superseded.
- **Built on the HeliSim branch, not Main** (Riverman, 2026-10-07). HeliSim (PR #632) arrived before Phase 2 started, deletes three addons outright (`uh60_engine`, `uh60_fd`, `uh60_sfmplus`) and edits two dozen more, and will see many iterations before it merges. Since 0.8 Stable *is* HeliSim, nothing loses release timing by targeting its branch, and deleting against today's Main would mean deleting things HeliSim already deleted. The Phase 2 PRs are therefore siblings cut off the integration branch's head, each targeting that branch; GitHub retargets any still-open one to Main when #632 merges.

## 3. The audit, re-run against the HeliSim head (1fe131e)

The August audit numbers moved once HeliSim and Phase 1's tidy PR were in the tree:

| Item | August audit | Re-audit 2026-10-07 |
|---|---|---|
| Case-broken `#include` paths | 12 | **11** (the `uh60_sfmplus` one died with the addon) + 1 include of a file that does not exist, inside a header that is itself dead |
| Empty (2-byte) files | 7 | **6** (3 new ones found: an IVHMS draw page, a JVMF dialog init, a CCFS renderer) |
| Orphan headers | ~30 | **~25** after resolving prefix-path (`\z\vtx\...`) includes, which the plain scan had mis-flagged; the 9 `UH60/config/MFD/` orphans were already removed in Phase 1 |
| Duplicate headers | mfdDefines ×3, uiDefines ×2, flir bones ×2, gau21L ×2 | uiDefines and flir bones already fixed in Phase 1; **gau21L folded here; mfdDefines deferred** (see §5) |
| Commented-out code | 1,622 lines | 1,468 code-like lines in 168 files; the long tail of single-line remnants is left alone |

Audit tooling lives in the session record, not the repo: a Python include-graph walker (relative and prefix-path includes, orphan detection, byte-duplicate hashing) and a PBO manifest/config.bin comparer. Worth porting into `tools/` with Phase 3's validators.

## 4. The PRs

| PR | Branch | What | Proof |
|---|---|---|---|
| **#637** | `phase2/include-case-fixes` | 11 include lines re-cased to match the files on disk (no renames); `MH60S/config/gau21L_free.hpp` deleted, both MH60S include sites point at `gau21L.hpp`; this phase's header in the master plan rewritten | 6 addons, config.bin identical |
| **#638** | `phase2/dead-files` | 37 files deleted (2.6 MB): 6 empty files and their two `PREP` lines, 21 never-included headers (the dead `copilotFLIR.hpp` turret, the abandoned flat MFD pages, three `uh60_mfd` class files never wired into `config.cpp`, …), 5 per-functions `script_component.hpp` copies no function reads, a stray `.rtm` copy, the duplicate Stratis map texture, an unused normal map, `.travis.yml`, `tools/.vscode/tasks.py` | 12 addons, config.bin identical; in-game MFD page walk on Stratis passed (Riverman) |
| **#639** | `phase2/comment-cleanup` | ~440 commented-out code lines removed across 25 files; two all-comment files deleted with their include lines; the three "testing, update fncs on the fly" `#undef PREP` blocks; the three stale "model lacks the View-Gunner LOD" comments rewritten (the LOD has existed since Sept 2026; the copilot optics seat is a separate pass); two commented-out FLIR keybinds collapsed to a one-line note | 10 addons, config.bin identical; SQF validator counts unchanged |
| **#640** | `phase2/texture-dedup` | Commit 1: three byte-identical livery textures folded (10.5 MB out of `uh60_misc`), texture sources repointed. Commit 2 (a bug fix found during the livery check, by ruling): UH-60M Slick and UH-60M spawn with the "UH-60M (US Army)" skin, the stock skin and the Eden "7645" option are retired because the markings overlay they used renders white in game, and every texture source names its markings slot explicitly (an empty slot made the Garage draw the markings mesh untextured on every livery) | config string table differs by exactly the intended paths; livery check in game passed (Riverman) |

Each PR deliberately avoids files the others touch, and avoids files Brad is actively editing except where unavoidable (one comment line in `H60_base.hpp`, one dangling comment in `monospace.hpp`, the changelog). Brad's PR edits two of the dead flat PFD pages that #638 deletes; those edits were inert.

## 5. Deferred, with reasons

- **`mfdDefines.hpp` ×3 reconcile.** Brad is editing the `uh60_mfd` copy for HeliSim's cockpit slots. Reconciling under him would fight every iteration. Do it when the slot edits settle; it is the seed of the Phase 5.5 ledger.
- **`condition = "0"` MFD elements (11 in 9 files).** Live config, not comments: removing them changes the rapified output, so they need the in-game config-dump harness, and a decision on whether any is a half-built feature.
- **ARMED4 / `FLIR_PYLONS_4` MFD classes.** Dead once the MLASS is gone (#631), but #631 is on the Main track; delete after Brad merges Main into his branch.
- **Asset sweep in the model addon.** Several `.rtm` crew animations with no config reference (needs a CfgMoves audit), two cockpit texture pairs duplicated between `UH60` and `uh60_mfd` (possible references inside binarized models), the twelve per-folder `env_land_co.paa` copies (26 rvmats point at them), and `Markings_ca.paa`, unreferenced by config after #640 but still baked into the model's markings selection.
- **The 56-line commented ACRE knob block** in `uh60_acre/config/hct.hpp`. Complete and well-formed; reads as parked, not failed. Ask BroBeans before touching.
- **The door gun turret file's commented lines** document what the model still needs, and #633 edits that file on the Main track.
- **The comment long tail** (~140 files, a few single-line alternates each). Low value per file, high review noise.
- **From the master plan's addendum, still open:** `uh60_cas/fnc_registerCaution.sqf` and `fnc_shutdown.sqf`, `uh60_weapons/fnc_handleDamage.sqf`, the unwired loading screen (`fnc_loadingScreen` + `RscDisplayLoadProjectHatchet` + `construction.paa`), the abandoned NVGHUD wiring, the dead stringtable keys, the five `typicalCargo[]` sites, the `vxf_core` warning block. Candidates for a PR 5 once #637–#640 are in.

## 6. Verification method (keep for every later deletion PR)

1. Build the affected addons at the base commit; extract each PBO's manifest (entry names, sizes, MD5) and `config.bin`.
2. Apply the change. Wipe the AddonBuilder mirror for every addon that lost a file (it syncs additively) and the `build\` junction staging when the addon set changes.
3. Rebuild; compare `config.bin` with the `timepacked` trailer masked, and diff the manifests. Expected: identical configs, only the removed entries gone, only the edited sources changed.
4. For anything that is not byte-identical by design (texture repoints), diff the config string table and hand the in-game check to Riverman with a concrete test card.

## 7. Do-NOT list

- Do not touch `uh60_helisim`, `uh60_ground`, `main/script_macros.hpp` or any file in Brad's active edit set beyond the unavoidable lines above.
- Do not "fix" a dead file's content on the way out; delete or leave.
- Do not delete a commented block that documents a failed experiment; label it instead.
- Do not stack Phase 2 PRs on each other unless one edits the same files as another; siblings merge in any order.
