# H-60 Phase 1 — Base-Class Consolidation: Detailed Plan

**Prepared:** 2026-08-17 · **Updated:** 2026-09-04 (Phase 0 closed out; Riverman's 2026-08-29 rulings on addon naming and MEDEVAC placement folded in) · **Basis:** master improvement plan §Phase 1 (corrected Snow plan), the verified UH60↔uh60_config structural diff (2026-08-17), and Riverman's rulings on the Slick armament, MLASS lifetime, and HH60 separation.
**Prerequisite:** Phase 0 — **COMPLETE.** Shipped as Stable 0.7.9 (2026-09-04); all Phase 0 PRs merged to Main. **Phase 1 kickoff: GO given 2026-09-05** — gating 0.7.10-cycle config PRs merged (#591/#595/#599/#601; #594/#597 are SQF-only and don't gate), PR strategy ruled (§8.3: sequential PRs).

---

## 1. Objective

Today `vtx_H60_base` is **fully declared in four addons** (UH60, uh60_config, H60_SFX, ace_viv) and three variants (`vtx_UH60M`, `vtx_UH60M_SLICK`, `vtx_HH60`) are **declared twice** (UH60 + uh60_config). Whoever loads last silently wins every property collision. This is how the Slick's minigun visibility got inverted without anyone noticing, and it is the leading suspect for issue **#510** (cockpit sound attenuation loss).

Phase 1 ends with **one full declaration per class, everywhere** — the rule both reference projects (AH-64D, MH-47G) enforce without exception:

- Every other touchpoint becomes an honest **delta**: forward-declare the parent, re-open the class, add only your own members.
- Behavior after the change is **provably identical** to before (config-dump diff), except where a divergence is resolved deliberately and on the record.

Phase 1 does **not** merge addons, rename classes, move assets, or delete dead code (that's Phase 2). It is a declaration-ownership cleanup plus one structural move: the HH60's departure into its own addon.

---

## 2. Target end-state

| Addon | Role after Phase 1 |
|---|---|
| **UH60** | Assets (unchanged) + the **only** full declarations of `vtx_H60_base` and the **Army family**: `vtx_UH60M`, `vtx_UH60M_SLICK`, `vtx_UH60M_MEDEVAC` *(moves in from uh60_config — Riverman's 2026-08-29 ruling; see WP2.4)* |
| **HH60** *(new addon — `addons/HH60`, named per Riverman 2026-08-29)* | The **Air Force bird**: sole owner of `vtx_HH60` (config-only; flies the shared p3d until the HH-60W model conversion) |
| **uh60_config** | Honest systems-delta layer: TextureSources (liveries), MASS_* weight logic, granular seat sources, hct_turret panels, FFV windows, CBA functions; sole owner of `vtx_S70M` (never duplicated) |
| **H60_SFX** | Sound-only delta on `vtx_H60_base` (its current full redeclaration demoted) |
| **ace_viv** | Unchanged (already a one-property delta; see §6 warnings) |
| **MH60M / MH60S** | Unchanged structurally; `requiredAddons` corrected |
| Other 11 re-openers (mfd, fms, anvishud, sfmplus, acre, cas, hoist, misc, weapons, ui, aar) | Unchanged — they are already well-behaved deltas |

> **End-state note (ruled 2026-09-05, Riverman + BroBeans):** the adopted long-term architecture is the AH-64D-style **asset/config split** — `uh60_config` (shipping later as `hct_h60_config`) becomes the sole owner of all vehicle config and `UH60` goes asset-only, so config changes stop repacking the model PBO. **Phase 1 is unchanged by this.** It stages single ownership in UH60 because the deduplication is direction-agnostic, and uh60_config cannot own declarations until the MFD-wiring inversion flips it from last-loader to first-loader (master plan §Phase 2.5). Relocating the one consolidated copy afterwards is mechanical, proven by this same harness.

Variant identity rulings that govern the merge:

- **`vtx_UH60M_SLICK` is the armed ViV-cargo variant.** uh60_config's values (miniguns **shown**) are the intent; UH60's hide-lines are the wrong copy and are deleted. *(Riverman, 2026-08-17)*
- **`vtx_UH60M_MEDEVAC` (HH-60M) is the only unarmed military variant. `vtx_S70M` is civilian, unarmed.**
- **`vtx_HH60` is currently a G-dressed airframe with a W-style cockpit; its long-term identity is the HH-60W.** No G-specific fidelity work; the class name does not change in Phase 1 (rename decision deferred to the model conversion — consider a scope-1 compat alias then).
- **MLASS stays flyable** until its planned removal; Phase 1 must not degrade it.

---

## 3. Work packages, in order

### WP0 — Verification harness (build first, use throughout)

1. **Config-dump script**: for each spawnable class, dump every property with **values** (the master plan's snippet — `configProperties` with `getNumber`/`getText`/`getArray`; the Snow plan's names-only version misses silent value changes).
2. **Baseline capture on Main** for the full spawn matrix: `vtx_UH60M`, `vtx_UH60M_SLICK`, `vtx_UH60M_MEDEVAC`, `vtx_HH60`, `vtx_S70M` *(the Snow plan omitted it)*, `vtx_MH60M`, `vtx_MH60M_DAP`, `vtx_MH60M_DAP_MLASS`, and the MH60S set.
3. Store dumps as files; the acceptance test for every WP below is `diff old new` = empty except the deliberate changes listed in that WP.

### WP1 — `vtx_H60_base`: one owner

1. UH60's declaration ([UH60/config/cfgVehicles.hpp:38-458]) becomes the single source.
2. **H60_SFX** (config.cpp:200-312): demote to a delta carrying *only* its sound content (`soundEngineOn*`, `class sounds`, SoundSets). Two traps from the corrected plan:
   - `playerPosition = 1` (config.cpp:197) sits on the **vanilla** `Heli_Transport_01_base_F → CargoTurret` — it must **not** move into `vtx_H60_base`.
   - H60_SFX redeclares **76** `vtx_*` classes in total; sweep `Compat.hpp` siblings into delta form in the same pass.
3. **ace_viv**: stays exactly as-is (see §6 — do not "clean up" its GVAR macro).
4. **Base-level value collisions** — resolve to the later-loading (live) value, then delete the loser:
   - `RotorHFold`: keep `animPeriod=5; initPhase=0` (uh60_config), delete UH60's `1 / -0.125`.
   - The ~60 duplicated AnimationSources between the two AnimationSources blocks: keep one copy of each; uh60_config retains only sources it genuinely adds or extends (`mass=`, `forceAnimate`, `onPhaseChanged`, blade-fold set, windows, wipers).
5. uh60_config's `vtx_H60_base` delta keeps its legitimate content: `class Armory` blank, `TextureSources` (12 liveries), `hct_turret_1/2/3`, its class EHs and CBA functions. *(The corrected plan explicitly rejects making it a bare stub — delta-extension from a later loader is the reference-blessed pattern.)*

**Deliberate changes to log:** none expected at runtime — WP1 should be config-dump **byte-identical** for every variant.

### WP2 — Army variant merges (`vtx_UH60M`, `vtx_UH60M_SLICK`)

1. **`vtx_UH60M`**: the two halves are disjoint (identity/visual in UH60; seats/MFD/medical in uh60_config). Keep the full declaration in UH60; uh60_config's block remains as the delta that wires MFD elements (it must stay in uh60_config — it references `uh60_mfd`/`fms`/`anvishud` content that loads after UH60). Net config: identical.
2. **`vtx_UH60M_SLICK`**: merge per the armament ruling — miniguns/mounts/gunner seats **shown**. Delete UH60's five `ANIM_INIT(...,1)` hide lines (UH60:564-568); keep uh60_config's `initPhase=0` set and granular `CabinSeats_1/2/3`. Remove the now-dead master `CabinSeats_Hide,1` and `Hoist_hide`/sight lines only if the config dump proves them inert; otherwise keep and log.
3. **Audit the Slick's turret-lock indexes**: uh60_config's `cabindoor_L/R onPhaseChanged` locks turrets `[[3],[4]]`/`[[1],[2]]`, which matches neither HH60 (`[[5],[6]]`) nor MEDEVAC mappings. Verify against the merged Slick's actual `Turrets` order (UH60's block contributes `cargoTurretsDoor.hpp` — 7 door cargo turrets) and correct. **This is a deliberate change if wrong today; test door-lock behavior per seat in-game.**
4. **MEDEVAC placement — RULED (Riverman, 2026-08-29): `vtx_UH60M_MEDEVAC` moves to UH60** beside its Army siblings (it is an Army airframe — the HH-60M). It is not duplicated, so this is a clean relocation, not a merge; but its block lives in uh60_config today, so audit its `#include`s and any `MASS_*`/macro usage before the move (do-NOT list item 5) and carry every dependency along or leave a delta behind in uh60_config for content that must load after uh60_mfd/fms/anvishud.

**Deliberate changes to log:** Slick turret-lock indexes (if corrected). Everything else byte-identical — including the relocated MEDEVAC, whose config dump must not change.

### WP3 — HH60 separation (new addon)

1. Create `addons/HH60` *(folder name ruled by Riverman, 2026-08-29)* with a CfgPatches class distinct from the vehicle class (`vtx_HH60_addon` or similar — avoid colliding with `vtx_HH60`), `requiredAddons[] = {"vtx_UH60", "vtx_UH60_mfd", "vtx_UH60_fms", "vtx_UH60_anvishud"}` — the same set uh60_config needs, because the HH60 is the only variant wiring the full-FLIR `VTX_MFD_1..4`.
2. Move **both halves** into it: UH60's full declaration (UH60:498-550) + uh60_config's delta (uh60_config:340-401), merged into one clean declaration deriving from `vtx_H60_base` — the MH60M/MH60S pattern.
3. Resolve its one conflict on the record: `CabinSeats_Hide` → `initPhase=0` (uh60_config's granular replacement is the live behavior; UH60's `,1` line was dead-but-misleading).
4. `units[]`: remove `vtx_HH60` from UH60's CfgPatches, add to the new addon's.
5. **Assets stay in UH60** (shared `vtx_uh60.p3d`, `pavehawk.hpp` model.cfg fragment, HH60/HH60_Fire textures) — path references need no dependency edge. The new addon is config-only until the HH-60W model work.
6. **Load-order fix for patchers of `vtx_HH60`:** `H60_SFX` (Compat.hpp adds `CargoTurret_01` to vtx_HH60) currently requires only `vtx_uh60`+`vtx_uh60_config`. Either add the new HH60 addon to H60_SFX's `requiredAddons`, or move that one compat block into the new addon. Recommendation: add the dependency — keeps sound content in the sound addon.
7. `uh60_config` keeps **nothing** HH60-specific afterward.

**Deliberate changes to log:** none at runtime — the merged HH60 config must dump identically to today's post-load-order result.

### WP4 — requiredAddons and inherit-header cleanup

1. Add `"vtx_UH60"` to `MH60M/config.cpp:9` and `MH60S/config.cpp:9` (they derive from `vtx_H60_base` but never declare the dependency — works today only by accident of load order).
2. `CfgAnimationSourcesInherit.hpp` (UH60; consumed only by MH60M/MH60S): with single ownership established this forward-declaration crutch may be simplifiable — **investigate, but defer any change to Phase 2/4 if it isn't a pure win.** It is not required for Phase 1's goal.
3. While in the area, note (do not fix) Phase 2 candidates uncovered by the diff: the disabled parallel livery system (`vehicleCustomization.hpp`, include commented at UH60:87), `units[]` case mismatch `vtx_UH60M_Slick` vs `SLICK` (harmless), dead `doorguns.hpp`.

---

## 4. Branch & PR strategy

The master plan scoped Phase 1 as one PR; with the HH60 amendment, three **sequential** PRs keep each diff reviewable and independently regression-tested, at the cost of the middle state shipping nothing user-visible:

1. `restructure/base-single-owner` — WP1 (base class + H60_SFX demotion). Config-dump proof: byte-identical.
2. `restructure/army-variant-merge` — WP2. Proof: byte-identical except logged Slick items.
3. `restructure/hh60-addon` — WP3 + WP4. Proof: byte-identical per variant; spawn matrix green; #510 retest.

Same workflow as Phase 0: branch published at creation, commits local until Riverman verifies, PR on his word. Each PR's build = full `scons all` (25 PBOs, 26 after the HH60 addon lands) plus the config-dump diff attached to the PR description.

**Coordination with the 0.7.10 dev cycle (added 2026-09-04):** several feature/fix PRs are in flight against the same config territory Phase 1 restructures — #591 (FMS interaction points), #594 (FLIR slew deadzone), #595 (ACRE comms sync), #597 (network improvements), #599 (MH60M door initPhase). Sequence at kickoff: either land/close them first, or capture the WP0 baseline *after* each merge and rebase the restructure branches — a Phase 1 branch must never carry a config-dump diff caused by someone else's merge. Re-capture the baseline whenever Main moves.

---

## 5. Verification & acceptance

- **Config-dump diff** (WP0 harness) — the primary proof, run per-variant per-PR.
- **Spawn matrix** — every class in WP0's list spawns in Eden/Zeus, textures and seats correct, no RPT errors. Include getting in pilot/copilot/door-gun/cargo seats.
- **Issue #510 as acceptance test** *(from the master plan; #510 and #439 now sit on the Phase 1 milestone)*: cockpit sound attenuation depends on turret-config merges across the four competing base declarations; if Phase 1 is done right, attenuation works (or its true cause is exposed). Test UH60M + MH60M cockpit audio before/after. Second candidate mechanism from the MH-47G reference (2026-08-23): a missing View Geometry LOD silently disables attenuation entirely — check the p3d before concluding the config diff explains everything.
- **Issue #439 retest** (hover symbology on UH/HH models) after WP3 — `vtx_HH60` was one of the duplicate-delta'd classes.
- **Slick functional test**: door guns present and usable (armament ruling), ViV cargo loading works, door-lock behavior per seat (WP2.3).
- **MLASS regression**: spawns, 4 pylons work, FLIR page carets/icons intact (Phase 0 #566 behavior preserved).
- **MP smoke test** on a dedicated server for one Army variant + HH60: crew seats, doors, sounds — the load-order-sensitive surfaces.

---

## 6. Do-NOT list (traps recorded in the corrected plan and diff)

1. **Do not move `playerPosition = 1`** (H60_SFX config.cpp:197) into `vtx_H60_base` — it belongs to the vanilla CargoTurret path.
2. **Do not copy `GVAR(lockSeats)` text between addons** — in ace_viv it expands to `vtx_ace_viv_lockSeats`; pasted elsewhere it expands differently and silently breaks ace_viv's scripts. Leave ace_viv untouched.
3. **Do not re-open a populated nested container from a second addon** (the MH-47G "shadow-not-merge law"): re-opening `class Turrets` replaces the whole tree. Deltas add top-level members or extend via forward-declared inner classes only.
4. **Do not resolve collisions toward UH60's values** — the later loader's value is today's live behavior; keeping UH60's would change the aircraft (the Slick incident is the proof).
5. **Do not relocate the MASS_* macros casually** — they live in `uh60_config/script_component.hpp:20-42` and feed its AnimationSources; if any animation-source file moves addons, the defines must move to a shared header first. `hct_minigun.hpp` additionally depends on `POS_MOVE_CABIN_COCKPIT` (main/script_macros.hpp) — verify include chains before moving it.
6. **Do not touch MLASS-specific content beyond keeping it working** — it is scheduled for removal; don't invest, don't break.
7. **Do not rename `vtx_HH60`** in this phase — mission/save compatibility; the rename rides with the HH-60W model conversion.

---

## 7. Risks & mitigations

| Risk | Mitigation |
|---|---|
| Silent value change survives the merge | Value-capturing config dump (not names-only); per-variant diffs attached to PRs |
| Load-order patcher breaks when vtx_HH60 moves (H60_SFX Compat, missions referencing the class) | Class name unchanged; explicit requiredAddons edge; spawn matrix + #439/#510 retests |
| Slick turret-lock indexes were wrong all along | Treated as deliberate, tested change (WP2.3), not silently "fixed" |
| H60_SFX demotion drops a sound property | Its 76-class redeclaration sweep is diffed class-by-class; #510 test doubles as the audio acceptance gate |
| Regression discovered post-merge | Three small sequential PRs — each independently revertable; bisection stays cheap |

---

## 8. Open items

1. ~~Name for the new addon folder~~ — **RULED (2026-08-29): `addons/HH60`**; CfgPatches class distinct from the vehicle class, exact name picked at implementation.
2. ~~MEDEVAC declaration placement~~ — **RULED (2026-08-29): moves to UH60** with the Army family (see WP2.4).
3. ~~Three-PR split vs single PR~~ — **RULED (Riverman, 2026-09-05): three sequential PRs, per §4.** Standing policy from here on: phases are planned as sequential PRs unless Riverman rules otherwise for a specific phase.
4. When WP2.3's turret-lock audit produces its answer: confirm the intended door-lock behavior per Slick seat (during-work item, Riverman's call).
