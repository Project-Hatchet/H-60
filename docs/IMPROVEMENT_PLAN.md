# H-60 Improvement Plan

**Prepared:** 2026-08-16 · **Basis:** deep dives of the AH-64D Official Project repo (local clone @ `6babb893`, 2026-07-01) and the PGS MH-47G tree, plus a full audit of H-60 @ `Main` (`ceef447`, v0.7.7.4).
**Companion doc:** the "Snow game plan" (base-class consolidation) is folded in as Phase 1 *with corrections* — see §Phase 1; do not implement that file as written.

---

## What the references teach

Both reference mods converge on the same architecture, arrived at independently:

1. **One hub addon owns the vehicle base class**; every other addon forward-declares it and delta-extends (`class vtx_H60_base;` … `class vtx_H60_base: Heli_Transport_01_base_F { <only my delta> }`). AH-64D: `fza_ah64_controls` → 30 leaf addons. MH-47G: `pgs_hooker_core` → `pgs_mh47g_block1` → `pgs_hatchet`.
2. **`config.cpp` is a manifest, never content** — CfgPatches + `#include`s, one `.hpp` per config root class.
3. **Data lives in config, code lives in SQF.** Flight-model geometry, performance tables, mass tables, damage thresholds are config classes read via `configOf _veh >> "..."` — so `diag_mergeConfigFile` can hot-reload tuning in a running game with zero rebuilds (MH-47G's stated reason for its entire PBO layout).
4. **All per-vehicle state is `setVariable` on the vehicle object**, prefix-namespaced (`fza_systems_*` / `PGS_sys_*`), initialized behind a `local _veh && !initialized-flag` guard, broadcast only on change (both mods have a change-only publisher helper).
5. **Systems run as one ordered pass** (electrical → APU → hydraulics → fuel → engines → consumers) with explicit locality tiers: owner-only integrators, every-client derivations, interface-only presentation.
6. **Displays are native `class MFD` + `setUserMFDValue/Text`**, with a single header owning the slot allocation and (AH-64D) a doc generator that *detects index collisions*.
7. **Conventions are machine-enforced** (AH-64D: `checkFilePaths.py` in CI + pre-commit, HEMTT lints, stringtable-usage lint) — not documented and hoped for.
8. **Version is generated, never hand-edited** (AH-64D: a HEMTT hook writes `version.hpp` with semver + git hash into every addon's CfgPatches).
9. **Comments carry rationale with dates** (MH-47G: every non-obvious line records *why*, *when*, and *what failed before* — failed experiments are kept as documented warnings, and project rules have names: "shadow-not-merge law", "locality law", "no setMass").

H-60 already has the right skeleton — Hatchet interaction framework modules, CBA/ACE macros available in `main`, mostly-correct delta-extension in the leaf addons — but violates 1, 2 (partially), 3, 4, 5, 7, 8 in places, and has accumulated significant debt. The plan below is ordered so that each phase makes the next one safer.

---

## Phase 0 — Correctness fixes (ship as its own small PR, before anything else)

Real bugs found in the audit, independent of any refactor:

| # | File | Bug | Fix |
|---|---|---|---|
| 0.1 | `addons/uh60_hoist/functions/fnc_raiseHook.sqf:4` | Raise remote-executes **`fnc_lowerHook`** on the owner | Point at `fnc_raiseHook` |
| 0.2 | `fnc_raiseHook.sqf:6`, `fnc_lowerHook.sqf:6` | `private _heli = vehicle player;` shadows the `params` argument → `objNull` when remote-exec'd on a dedicated server | Use the passed `_heli` |
| 0.3 | same files | Unthrottled `while {flag} do {}` busy loops inside `spawn` | Rewrite on CBA PFH (see Phase 5.4) — interim: add a sleep/yield |
| 0.4 | `addons/main/script_macros.hpp` | `HIDDENSELECTION_EM_GOARND…EM_VS` defines are **off by one** vs the `HIDDENSELECTIONS` array; `hs_esss` (index 28) has no define | Re-index; audit every use site for baked-in compensation before fixing |
| 0.5 | `addons/uh60_engine/functions/fnc_setup.sqf:16-17` | `ENG1_PWR` initialized twice, `ENG2_PWR` never | Initialize both |
| 0.6 | `fnc_setup.sqf:35` | `player addEventHandler ["SelectedRotorLibActionPerformed", …]` leaks a duplicate handler every module start; shutdown never removes it | Guard with a stored-EH-id check (MH-47G pattern: store id in a variable, add only if nil) |
| 0.7 | `fnc_setup.sqf:12-14` | Per-vehicle EH id / fuel / altitude stored in **mission globals** — two H-60s clobber each other and shutdown removes the wrong EH | Move to `setVariable` on the vehicle |
| 0.8 | `addons/uh60_flir/functions/fnc_autoScanPattern.sqf:16`, `addons/uh60_engine/functions/fnc_engineEH.sqf:10` | Unconditional `systemChat`/`diag_log` spam in hot paths | Delete or wrap in the debug setting |
| 0.9 | `addons/uh60_hoist/ACE_Actions.sqf:2-4` | Computes `localize LSTRING(RescueHoist)` then passes the hardcoded literal instead | Use the localized variable |
| 0.10 | `addons/uh60_hoist` | Hoist ACE actions defined **twice** (config `ACE_SelfActions` + `ACE_Actions.sqf`) | Keep one source (config) |
| 0.11 | `addons/uh60_weapons/functions/fnc_getLaserCode.sqf:10-13` | Guards only `_index == -1`, then indexes `vtx_uh60_weapons_laserCodes # _index` unchecked → **zero-divisor script error** when the MFD value is out of range (reported: issue **#436**, with RPT) | Clamp/validate `_index` against the array bounds; handle unmatched `_type` (currently leaves `_pylon` nil) |
| 0.12 | `addons/uh60_fd/Armakeybinds.hpp:49,74` | ALT-hold increase/decrease keybinds format **`KnobFD%1_BALT`** but the cockpit interaction classes are `KnobFD*_ALT` (`cfgHctCockpit.hpp:379-389`) — the interaction can never resolve (part of issue **#547**) | Fix the name; test *all* FD inc/dec binds — a second, framework-side fault exists (below) |

Framework-side note for 0.12: `Interaction-Framework/addons/interaction/fnc_knobAnimate.sqf` evaluates `hct_interaction_knobHolding # 0` via a **non-lazy `&&`** while the global may still be undefined (first keybind use before any mouse-knob interaction → script error, knob never moves), and carries an unconditional `diag_log` in the knob hot path. That fix belongs in the framework repo (`D:\Documents\GitHub Repos\Interaction-Framework` locally) — file it upstream alongside the `//Delete if framework ever gets updated` workaround already noted in `main/XEH_postInit.sqf`.

**Verify:** hoist raise/lower on a dedicated server with a non-owner operator; two H-60s spawned simultaneously running engine module; RPT clean of the spam lines.

---

## Phase 1 — Base-class consolidation (the corrected Snow plan)

The Snow game plan's direction is right (make `addons/UH60` the sole owner of `vtx_H60_base`; convert the other three declaration sites to deltas/stubs; fix duplicate variant deltas; fix `requiredAddons`). Apply it **with these corrections**, all verified against the tree:

1. **`vtx_HH60` has the same duplicate-delta bug** the plan fixes for `vtx_UH60M`/`vtx_UH60M_SLICK` — declared in `UH60/config/cfgVehicles.hpp:498` *and* `uh60_config/config/cfgVehicles.hpp:340`. Merge it the same way. (The plan wrongly says UH60 doesn't declare it.)
2. **The H60_SFX bullet is half-fictional.** Its `vtx_H60_base` block (config.cpp:200-312) contains *only* sound properties (`soundEngineOn*`, `class sounds`, `class soundsext`). The "turret attenuation deltas" mostly don't exist; the one real property (`playerPosition = 1`, line 197) sits on the **vanilla** `Heli_Transport_01_base_F → CargoTurret` and must not be moved into `vtx_H60_base`. Note: H60_SFX also redeclares **76** `vtx_*` classes total (audit) — the sound-delta cleanup should sweep Compat.hpp's siblings too.
3. **uh60_config cannot become a bare forward-declare stub.** Its `vtx_H60_base` body also carries `#include "CfgTextureSources.hpp"` (a per-vehicle `class TextureSources`), `#include "hct_minigun.hpp"` (full `hct_turret_1` interaction tree), and `class hct_turret_3` — none of which the Snow plan inventories. Either move all of it to UH60, or (simpler, and the reference-blessed pattern) **leave uh60_config as a genuine delta-extension** containing exactly this content. Delta-extension from a later-loading addon is the normal pattern in both reference mods — the goal is *one full declaration + N deltas*, not *one declaration + zero deltas*.
4. **`GVAR(lockSeats)` must not be copied verbatim.** `PREFIX vtx` + `COMPONENT ace_viv` → it expands to `vtx_ace_viv_lockSeats`; pasted into a UH60-owned file it would expand differently and silently break ace_viv's scripts. Keep `ace_viv` as the one-property delta it already is.
5. **Collision precedence: prefer the later-loading addon's value, not UH60's.** `uh60_config` and `H60_SFX` declare `requiredAddons` on `vtx_UH60`, so today's load order is deterministic and *their* values win. Keeping UH60's value on a collision would change live behavior.
6. Add **`vtx_S70M`** (declared only in uh60_config:235) to the spawn-test matrix; the plan omits it entirely.
7. Line numbers in the plan have drifted (`vtx_UH60M` is at UH60:460, SLICK at :552; uh60_config deltas at :63/:277) — navigate by class name.
8. The `requiredAddons` fixes stand: add `"vtx_UH60"` to `MH60M/config.cpp:9` and `MH60S/config.cpp:9`.
9. `MASS_*` macros live in `uh60_config/script_component.hpp:20-42`; `ANIM_INIT` is already shared in `main/script_macros.hpp:10`. If the animation-source file moves, move the MASS defines to a shared header; `hct_minigun.hpp` additionally depends on `POS_MOVE_CABIN_COCKPIT` — find its home before relocating.

**Verify:** the Snow plan's §6 procedure, with the value-capturing config diff below instead of its broken snippet (its `fullText (_x select 0)` grabs child entries, and names-only diffing misses silent value changes):

```sqf
private _cfg = configFile >> "CfgVehicles" >> "vtx_UH60M";
diag_log str (configProperties [_cfg, "true", true] apply {
    [configName _x,
     if (isNumber _x) then {getNumber _x}
     else {if (isText _x) then {getText _x} else {getArray _x}}]
});
```

---

## Phase 2 — Delete first, refactor second

Cheap, zero-behavior-change, and a prerequisite for HEMTT (Phase 3). One PR, reviewed as pure deletions/renames.

**2.1 Fix the 12 case-broken `#include` paths** (audit §3.5: `main/config.cpp`, `MH60S`, `stretcher`, `UH60` ×3, `uh60_anvishud`, `uh60_config`, `uh60_fms` ×2, `uh60_sfmplus`). Windows tolerates them; HEMTT/Linux CI will not.

**2.2 Delete dead files:**
- 7 empty (2-byte) files — 3 are PREP'd: `uh60_doorguns/fnc_setKeybindText.sqf`, `uh60_fd/fnc_movePitchBank.sqf`, `uh60_weapons/fnc_toggleLaser.sqf` (remove the PREPs too)
- 7 orphan never-PREP'd SQF incl. `uh60_fms/fnc_calculatePerformance.sqf` (which defines misspelled `vtx_uh60_fmplus_fnc_*` globals — its logic returns in Phase 5.3 as config tables), 3 stale `ccfs` duplicates in `uh60_mfd`
- ~30 orphan `.hpp`: 16 in `uh60_mfd/config` (the abandoned flat→nested MFD refactor — finish it: keep nested, delete flat), all 9 of `UH60/config/MFD/` except `MFDConfig.hpp`, `MH60M/config/cfgFunctions.hpp`, `MH60S/config/gau21L.hpp` (byte-dup of `gau21L_free.hpp`), missing-file includers `UH60/config/turrets/doorguns.hpp`, `uh60_mfd/.../tac_draw.hpp`
- `.travis.yml` (dead, references scripts that don't exist), `tools/.vscode/tasks.py` (JSON misnamed `.py`)
- `uh60_sfmplus`: dead `fn_antiLift.sqf`, `fn_eventGetIn.sqf`, the commented-out half of `cfgFunctions.hpp`

**2.3 Deduplicate:**
- `mfdDefines.hpp` ×3 (`UH60/config/defines/`, `uh60_mfd/config/`, `uh60_weapons/config/` — 108 diverging lines between the latter two). Reconcile into **one** header; this becomes the seed of the MFD slot ledger in Phase 5.5.
- `uiDefines.hpp` byte-dup across `uh60_ui`/`uh60_doorguns` (ui currently includes the *doorguns* copy) → one copy, one owner.
- `flir/bones.hpp` == `flir_bones.hpp` in uh60_mfd.
- Optional space win, defer if noisy: 11 identical `env_land_co.paa` under `UH60/Data/*`, `NM_nohq.paa` == `NM_smdi.paa` in uh60_weapons (a normal map shipped as specular — check which is *intended*).

**2.4 Trim the comment graveyard where it's noise** (1,622 commented-out lines; 11 `condition = "0"` blocks; the four copy-pasted `#undef PREP` comment blocks). Exception per the MH-47G convention: keep commented code that documents a *failed experiment*, and label it as such.

**Verify:** full build + the Phase 1 config-dump diff (should be byte-identical), plus in-game MFD page walk (the flat→nested completion is the only risky deletion).

---

## Phase 3 — Build system: HEMTT migration + real CI

Model directly on AH-64D (the only reference with visible build infra). An abandoned attempt already exists (`origin/hemtt-gh-action`, `.gitignore` entries) — restart it now that 2.1 unblocks it.

**3.1 HEMTT project** — `.hemtt/project.toml` with `prefix = "vtx"`, `mainprefix = "z"`, `[version]` as the **single source of truth** (currently version lives in 4 places disagreeing: `script_version.hpp` 0.7.7.4, README badge 0.7.6.0, changelogs, git tags v0.7.8). Port AH-64D's `pre_build/version_files.rhai` hook: generate `version.hpp` (semver + git hash + addon manifest) into every addon, gitignore it, `#include` it in every CfgPatches — retiring the hand-maintained `BUILDHASH`/`RELEASENAME` lines nothing consumes.

**3.2 `hemtt launch` profiles** (`.hemtt/launch.toml`): `minimal` = CBA + ACE + Hatchet Framework workshop IDs; `profiling` extends it with Arma Script Profiler. This replaces tribal knowledge about test setups.

**3.3 Expect `addon.toml` escapes**: MFD-heavy addons using `__EVAL` (uh60_mfd, uh60_anvishud, uh60_fms) will likely need `[rapify] enabled = false` exactly as AH-64D's mpd addon does. If any addon needs binarization HEMTT can't do, wrap with a thin SCons/script orchestrator as AH-64D does — but note the current build *binarizes nothing anyway* (the `print.exe` hack), so plain `hemtt build` loses nothing.

**3.4 CI (`ubuntu-latest`, finally possible):**
- `hemtt check --pedantic` on every push
- Port AH-64D's `tools/checkFilePaths.py` with vtx-appropriate regexes (addon names, `fnc_*.sqf`, config `.hpp` naming) + add: include-path case validation, PREP↔file parity, empty-file detection, BOM check. Wire as pre-commit too.
- Un-kill the `validate` job in `build.yml` (currently fully commented out, referencing 3 validator scripts that don't exist — `tools/` has only `sqf_validator.py`).
- Keep the Windows job only if binarization returns; release via `hemtt release` (signed, archived).

**3.5 Repo hygiene:** one changelog (merge `CHANGELOG-DEV.md` into `CHANGELOG.md`, keep the sectioned format), fix release-drafter's 3-part tag template and placeholder text, rename the two issue templates with trailing spaces in their filenames, fill `AUTHORS.txt`/`meta.cpp`/`author=""` fields, delete stale branches (8 branches >12 months).

**PBO naming (direction set 2026-08-18, final call at Phase 3 execution):** released PBO filenames are `hct_h60_*` (SCons-era), classes are `vtx_*`, folders are a third scheme. **Riverman's ruling: the `hct` brand stays in filenames** — `hct` (Hatchet) is the team's *current* prefix; `vtx` is the legacy "Vortex" project name (pre-Hatchet, before Yannik chose the name) and should not be promoted into new naming. Direction: **`hct_h60_<component>` with the redundant `uh60_` stripped at build time** (`hct_h60_engine.pbo`, `hct_h60_mfd.pbo`), implemented in the HEMTT migration (folder-name→output mapping or pbo name overrides), announced in the changelog at the next minor bump so server mod-whitelists change once. Accepted cost: filename ≠ CfgPatches class (`vtx_uh60_engine`) — tolerable, and the class-side `vtx`→`hct` migration is a **known long-term aspiration but a breaking change** (missions' `addons[]`, function names, CBA settings, keybinds) that must not ride along casually; if ever attempted it needs a deprecation-alias strategy (Phase 4+ at the earliest, own decision). Layer rules regardless: `$PBOPREFIX$` (`z\vtx\addons\...`) is frozen — paths are baked into configs and p3ds; folder-case renames (`UH60` → `uh60`) deferred until a model-touching release.

---

## Phase 4 — Convention unification

The audit found 3 function-registration styles, 4 CBA-settings idioms, 2,188 hardcoded `vtx_*` names vs 102 macro uses, and load-bearing-but-undeclared dependencies everywhere. Unify on the conventions `ace_viv` (the in-repo exemplar) already follows. CI from Phase 3 enforces each rule as it lands.

**4.1 One function style.** CBA `PREP` + `PREP_RECOMPILE_START/END` everywhere. Convert `H60_SFX` (legacy CfgFunctions, tag `vtx_uh60_Sound`, no script_component.hpp at all) and `uh60_sfmplus` (manual `compile preprocessFileLineNumbers` of 3 hardcoded paths, no XEH_preInit, donor-mod class name `vtx_uh60_sfmplus_ah64_PreInits`). Fix the PREP↔file mismatches (`PREP(acftAPU)` vs `fnc_acftApu.sqf`, etc.).

**4.2 One settings idiom.** `initSettings.sqf`, modern `CBA_fnc_addSetting`, `QGVAR(...)` names, `LSTRING` label + tooltip — included at a consistent point in XEH_preInit. Migrate the two wrong-prefix settings (`vtx_uh60m_simpleStartup` in uh60_engine, `vtx_uh60m_simpleCollective` in uh60_fd): register under the correct name and, for one release, read the old key as the default so server configs don't silently reset. Move uh60_jvmf's inline setting into an initSettings.sqf.

**4.3 Macro discipline, incrementally.** Do **not** mass-rewrite 2,188 identifiers in one PR. Rule: any file touched by Phases 5–6 converts to `GVAR/QGVAR/FUNC/LSTRING` as it's touched; CI flags hardcoded prefixes only in changed files. Names referenced from config strings (`animEnd = "…vtx_uh60_engine_fnc_…"`) are public API — convert the config and SQF sides in the same commit.

**4.4 Truthful `requiredAddons` + break the inversion.** Declare the real dependencies measured in the audit (uh60_mfd → cas/flir/fms/jvmf/misc/weapons, uh60_fms → 8 addons, etc.). The deeper fix for the worst case — **UH60 (the base!) depends on five leaf addons** because `cfgHctCockpit.hpp` hardcodes their functions into `animEnd` strings — is the reference pattern: each module addon *delta-extends* `vtx_H60_base`'s `hct` class to contribute its own switches/interactions. UH60 keeps only geometry-owned interactions; `uh60_engine` brings the engine switches, `uh60_misc` its own, etc. This also fixes the `vtx_uh60m_enabled_*` vs `projectPrefix = "vtx_uh60"` mismatch and the `mfd`/`fms` modules missing from `class modules`.
Also: `uh60_aar`'s CfgPatches class is **`USAF_Hatchet_AAR`** — off-prefix, so nothing can depend on it, and its real dependency (the USAF mod) is undeclared while `skipWhenMissingDependencies=1` sits there doing nothing. Rename to `vtx_uh60_aar` and declare the USAF addon so the skip flag actually works.

**4.5 sfmplus boundary.** It's a third-party import (BradMick/MattySmith22) — treat it as vendored, not rewritten: normalize registration (4.1), purge donor residue (`fza_sfmplus_emptyMass` dual-write in `fn_massSet.sqf:58`, `fza_fnc_linearInterp` doc references), and put an accessor layer in front of the ~15 raw `getVariable "vtx_uh60_sfmplus_*"` reads that uh60_engine does, so the FM's internals can change without breaking consumers.

**4.6 Localization program.** 248 hardcoded `displayName`s vs 5 localized; 14 of 25 addons have no stringtable. Start where users see text: vehicle/editor display names, CBA settings, keybinds, ACE actions, the 30 `ToDo: Localize` markers in uh60_jvmf/uh60_weapons, hardcoded strings in `uh60_misc/XEH_postInit.sqf`. Per-addon `stringtable.xml` now; an AH-64D-style dedicated language addon is optional later — coverage matters more than location. HEMTT's stringtable lint (Phase 3) keeps it from regressing.

---

## Phase 5 — Systems architecture upgrades

The payoff phase — where the reference patterns change what the mod *is*. Each item is independently landable.

**5.1 One engine/electrical generation, one ordered pass.** `uh60_engine` currently ships two coexisting generations (old `fnc_apuState/batteryState/starterState` + new `fnc_acft*`). Finish the new one, delete the old, and restructure `fnc_acft*` on the MH-47G `fn_acftState` model:
- **Single switch-scrape tier** — all `animationSourcePhase` reads in one block; everything downstream consumes derived `GVAR(sys_*)` states. (The "AH-64 rule": a click can never wedge the machine; killing a prerequisite mid-start aborts the start with zero extra code, because interlocks are re-checked every pass.)
- **Per-engine state machine** (`OFF → MOTOR → START → RUN_GND ⇄ RUN_FLT`, abort paths hint the cause once, locally).
- **Locality tiers** declared per function: owner-only integrators (gated `CBA setting && player-in-crew && local`), every-client derivations, `hasInterface`-only presentation. Untagged state (`ENG1_PWR`, `BATT1_ENABLED`, `ESIS_COUNTER`, `MAP_Zoom`…) becomes `GVAR(...)`-tagged vehicle variables in the same sweep (Phase 4.3 rule).
- **Publisher closures**: adopt MH-47G's `_pub` (write-on-change broadcast) and `_pubDb` (deadband broadcast for continuous values) plus the `animateSource` deadband for gauge needles. Add a `vtx` equivalent of AH-64D's `fn_updateNetworkGlobal` in a common addon.

**5.2 Upgrade uh60_cas into a WCA registry.** Replace bespoke caution plumbing with the data-table pattern: one flat `[severity, text, condition]` array evaluated in the systems pass, feeding MFD text slots; master-caution edge detection with re-light on new entries; a power-up suppression window. Every entry anchored to a real hitpoint or derived system state — no faked sensors.
- **FLIR/PiP-disabled advisory (added 2026-08-20).** A Dev Branch tester reported the FLIR page "showing the TAC map" after deploy; root cause was PiP disabled in his Video options — the r2t feed was blank and the TAC map texture left on `MAP_SELECTION` by `fnc_switchPage`'s FLIR branch showed through. The mod never checks `isPiPEnabled`. Rather than a one-off `setUserMFDText` banner, register it in the WCA table as a proper advisory with TM 1-1520-280-10 caution/advisory vocabulary (e.g. the FLIR-failure / sensor-inoperative wording the -10 uses — confirm text against the TM digest before adopting), conditioned on `!isPiPEnabled` while a FLIR page is open, and suppress the PiP camera start in that state. Cheap prerequisite that can land any time before this: clear the `MAP_SELECTION` texture/material in the FLIR branch of `fnc_switchPage` so a blank feed reads as a dead screen, not a stale map.

**5.3 Performance/mass data → config.** Rebuild the deleted `fnc_calculatePerformance` as a `class vtx_Performance` config table (hover-torque + cruise tables, limits) + a `linearInterp` reader — the exact MH-47G pattern (which itself ported the interpolator *from this mod's sfmplus*, so the code exists in-tree). Same treatment for a parts-mass table if cabin-config mass simulation is wanted. Design rule to adopt verbatim: **weight affects systems only — nothing may touch setMass/addForce** outside the flight model.

**5.4 Hoist rewrite.** Replace the CfgUserActions-global-flag busy loops with CBA-scheduled motion (PFH or the MH-47G self-rechaining `waitAndExecute` pattern, which they chose specifically because PFH timing stuttered against `animPeriod`), CBA keybinds instead of raw user actions, correct locality (Phase 0 fixed the acute bugs; this is the structural fix). Put `vtx_hook*` classes in `units[]`.

**5.5 MFD infrastructure.**
- **One slot ledger**: the reconciled `mfdDefines.hpp` (Phase 2.3) becomes the single header owning every `setUserMFDValue/Text` index, AH-64D-style (`MFD_OFFSET` blocks per screen). Convert the 31 raw-integer call sites to macros.
- **Port AH-64D's collision-detecting MFD doc generator** (`tools/mfd_documentation/document.py`) — it turns the ledger into docs *and* fails CI on index collisions.
- Page pattern: adopt the `fn_page<X>Draw` + `fn_page<X>HandleControl` pairing with a per-page persistent state hashmap (AH-64D `fza_mpd_mpdState`) where pages currently improvise.
- Gate displays on the electrical sim (`GVAR(sys_acBus)`) so avionics are consumers of 5.1, not independent.
- Decide the CCFS Pong clone's fate (it's 19 functions inside uh60_mfd): keep as an easter egg behind its flag or extract/delete — either way stop shipping its 3 stale duplicate files (done in Phase 2).

**5.6 MH-60S (Knighthawk) rehabilitation.** The MH-60S variants are currently hidden from players — they broke after the 0.6.0 Army-model rework and are awaiting a dedicated pass. Their configs (including legitimate FLIR fits) are still in the tree and load-bearing for the class hierarchy, so the restructure phases must carry them along; schedule the actual rehabilitation after Phase 1 (deterministic base class) and 5.1 (systems consolidation), since both change the ground the Knighthawks stand on.

**5.7 Debug/dev tooling.** Global kill-switch variables settable from the debug console (AH-64D: `fza_ah64_nopfsched`-style) for the HCT module hot paths; the ACE `TRACE_n/LOG` macros (already included via `main`) replace the `vtx_uh60_ui_showDebugMessages` ad-hoc global that five addons read without depending on uh60_ui; formalize `uh60_misc/dev/fnc_instantStart.sqf` (currently shipped un-PREP'd) as a proper dev action that *fast-forwards the state machine rather than bypassing it* (MH-47G's `INSTANT START [TEST]` design).

---

## Phase 6 — Process & documentation

- **README**: architecture map (addon table with one-line purposes + the dependency graph), build quickstart (`hemtt dev`), link to conventions. The current README is badges + SCons install steps.
- **CONTRIBUTING.md**: the named project laws — *shadow-not-merge* (always `class X: X` when re-opening; forward-declare foreign trees on the parent), *locality law* (every function header declares its tier), *single-declaration law* (one full base-class declaration, N deltas), *no setMass/addForce outside the FM*, macro/settings/stringtable conventions from Phase 4. Laws with names get cited in review; prose doesn't.
- **Function headers**: standardize on the ACE block (Author/Arguments/Return Value/Example) and require via PR template for touched files. Current coverage: 104/305 (34%), six addons at zero.
- **Comment culture**: adopt MH-47G's dated-rationale style for every non-obvious decision (`// CRASH FIX (2026-08-10): was 0.05 = 5× less protection than any vanilla helo`), and keep failed experiments as labeled warnings instead of deleting them.
- **PR template** with a real checklist (stringtable updated / changelog entry / tested SP + MP multi-crew); issue templates already good once filenames are fixed.
- **Docs target**: the SConstruct `docs` target references a NaturalDocs config that doesn't exist. Either port AH-64D's `naturaldocs/` project config + gh-pages workflow, or drop the target and keep docs as markdown in `docs/`. Recommendation: markdown first; NaturalDocs only if the header-coverage push (above) succeeds.

---

## Cross-check: the public issue tracker

All 17 open issues on `github.com/Project-Hatchet/H-60` (checked 2026-08-16) map onto the plan — none contradict it, several independently confirm its diagnoses:

| Issue | What it reports | Where it lands in this plan |
|---|---|---|
| **#510** (confirmed) | No sound attenuation in UH60M/MH60M cockpit; suspected same cause as MH60M FLIR fullscreen breakage | Almost certainly the **Phase 1** base-class problem itself: H60_SFX's attenuation depends on turret-config merges across the four competing `vtx_H60_base` declarations, so it silently loses depending on load order. Treat as Phase 1's acceptance test. |
| **#442** | Server crashes from network overload; load ramps when a pilot boards; 10 H-60s killed a 50-player server | **Phase 0.6** (event handlers leak on every boarding) + **Phase 5.1** (deadband publishers, change-only broadcast, locality tiers) + the `spawn`-per-frame in `uh60_misc/fnc_perFrame.sqf`. The "ramps when pilot enters" signature matches the leaked-handler accumulation. |
| **#436** | `Error Nullteiler` in `fnc_getLaserCode` + frame drops | Now **Phase 0.11** (confirmed in code). |
| **#547** | FD mode increase/decrease keybinds do nothing | Now **Phase 0.12** (confirmed: `_BALT` name mismatch + framework knob bug). |
| **#498** (confirmed, "unable to fix") | AFM helicopter desyncs/dances on the ground for non-owner players | Flight-model locality — belongs with **Phase 4.5** (sfmplus boundary). The MP repro rig (Phase 6 verification) is the prerequisite for ever cracking it; MH-47G's RTD/PhysX suspension notes (`physx.hpp`) are the best available reference material. |
| **#410** | Selecting an H-60 in editor/Zeus freezes the game momentarily | Known pattern with a documented fix in MH-47G: first load of a large uncached model is synchronous — `preloadObject` warming (their `fn_acftSetup` does exactly this). Add to **Phase 5.6** as a small task; also check `editorPreview` size. |
| **#557** | Cabin crew can trigger countermeasures/autohover keybinds | **Phase 4** keybind consolidation — seat-gating conditions on CBA keybinds. |
| **#382** | "To cabin" button sends pilot to gunner seats even when disabled | **Phase 4.4** interaction cleanup (`fnc_moveToCabin` seat filtering); related to #75. |
| **#75** | Config-driven system for seats blocking doors/ViV instead of hardcoding | The issue's own sketch is already the right shape (per-vehicle `GVAR(...)` arrays — the `ace_viv` pattern). MH-47G's two-compartment seat graph + debounced AI seat dispatch is the reference implementation. Fold into **Phase 5** as its own item. |
| **#556** (high prio) | Copilot cockpit geometry vanishes; FLIR/MFD unusable from that seat | **FIXED — validated in-game on all variants (2026-08-16).** True root cause: the 0.7.6.9 FLIR update converted the copilot seat into an **optics turret**, and an optics turret makes the engine render the View-Gunner LOD — which `vtx_uh60.p3d` does not have — so the copilot fell back to a gutted resolution LOD (see-through console, ceiling artifact). Even an empty `class OpticsIn {};` triggers it, and partial strips are not enough (residual turret machinery — `forceHideGunner`, body/gun axes — still broke the seat and hid the get-in animation). Shipped fix: both `copilotFLIR.hpp` include sites now use the proven `copilot.hpp` turret for every variant, with `soundAttenuationTurret` carried over. To restore the copilot's turret-optics FLIR view: modeler adds a **View - Gunner (1000) LOD** (copy of View - Pilot) to `vtx_uh60.p3d`, then the include swap reverts. (Superseded earlier hypothesis, kept for the record:) Mechanism: `fnc_acftBattery.sqf` drives the `PowerOnOff` **hide animation** (`model.cfg`: `selection="PowerOn"`, `hideValue=0`, `unHideValue=0.5` — phase 0 hides) with the **local-effect** `animate` command from the per-client hct engine module: battery off → phase 0 → the `PowerOn` selection vanishes *on that client only*. Explains every report: per-viewer (local `animate`), engine-state-dependent, unaffected by AI pilots, invisible to texture repainting (Test A), absent from `getObjectTextures` (Test B). Regression source: the `67fc6a2` model edit grew the `PowerOn` selection from **392 faces (0.6.0 sources) to 707 faces** spanning 1.46×0.92×1.02 m of the cockpit (verified by parsing the MLOD sources in the private model-source repo — parser `mlod_selections.py` in session scratchpad), so hiding it now removes real console geometry instead of just lit-overlay quads. Confirm in-game with `vehicle player animate ["PowerOnOff", 1]` (console should appear instantly). Hotfix (config-only): stop driving `PowerOnOff` to 0 in `fnc_acftBattery` (panels keep their lit texture when unpowered — cosmetic cost). Proper fix: modeler prunes the ~315 wrongly-assigned faces from `PowerOn` in the MLOD source and re-exports. Secondary finding: `MFD1-4_hide` (`Screen_MFD1-4`, hidden at phase 0, `initPhase=0`) have **no SQF driver at all** — the MFD glass meshes are permanently hidden. Earlier LODTurnedIn theory was wrong (vanilla already supplies 1100; p3d LOD table unchanged). Latent related bug: `hs_esss` inserted mid-`HIDDENSELECTIONS` (index 28) vs appended in model.cfg, desyncing the stale `HIDDENSELECTION_EM_*` defines (Phase 0.4). |
| **#538** | FLIR won't lock/track vehicles ("worked 50% of the time before") | **Root-caused (2026-08-16):** two layers. (a) *Why it died completely:* the 0.7.6 hotfix (`b181d94`, Apr 17 — issue filed Apr 18) moved the lock trigger to `initKeybinds.sqf:2`, whose handler **exits when `cameraView == "GUNNER"`** — the exact view the copilot uses the FLIR from; the old polling path in `fnc_handleKeyInputs.sqf:28-45` was commented out. (b) *Why it was only ever 50%:* `fnc_intersectAtPolar` returns only the surface **position**, discarding the hit object, and `fnc_setStabilization:36` then requires a vehicle within **5 m** of that point (`nearestObjects`) — fails for large vehicles (origin >5 m from hull), movers (sim-vs-visual offset), and aircraft (near-miss ray hits terrain km behind). Fix: narrow the GUNNER-view guard, return the hit object from the raycast (`_intersect # 0 # 2`) and lock it directly, keep the radius test only as a widened fallback. **Phase 0-class fix.** |
| **#439** | Hover symbology broken on UH/HH models specifically | Per-variant MFD divergence — note `vtx_HH60` is one of the duplicate-delta'd classes Phase 1 fixes. Re-test after **Phase 1**; standardizing the HUD across variants (the reporter's suggestion) matches the reference mods' one-template-many-screens pattern. |
| **#419** | First waypoint in list produces no TAC map marker | Classic index bug in the uh60_mfd TAC page — small **Phase 0-class** fix, verify while in there. |
| **#523** | Mission-maker options for HMD availability + HMD damage modeling | **Phase 5.1/5.2 payoff**: once displays consume the electrical/damage sim, this is a CBA setting + a gate condition — the MH-47G "displays are consumers of the systems chain" pattern. |
| **#548** | Add/remove ERFS fuel tanks via ACE interact | Exactly AH-64D's `fza_ah64_customise` component-swap pattern (ACE interact toggling FCR/IAFS) — a direct port, **Phase 5** backlog. |
| **#522** | Fixed-forward IZLID laser on a keybind | MH-47G ships a complete IZLID implementation (`izlid.hpp`, `fn_izlidPFH` with `drawLaser`, CBA global event registration) — a direct port, **Phase 5** backlog. |
| **#371** | Better waypoint system / pod slewing / MTI | AH-64D's `fza_ah64_dms` (waypoint/route store, 3DEN attributes) is the reference architecture — **Phase 5** backlog, after the MFD slot ledger exists. |

Two takeaways: the long-standing confirmed issues either point at the root causes this plan already prioritizes (#510 → base-class determinism; #498, #442 → locality/networking) or, once actually traced, turned out to be small config/guard regressions (#556, #538 — both root-caused above). And the top community feature asks (#548, #522, #371) each have a working reference implementation in one of the two bible repos — they get dramatically cheaper after Phases 1–5 land.

## Sequencing, risk, and effort

```
Phase 0 (bugs)          — small PR, immediate. No dependencies.
Phase 1 (base class)    — one PR + full regression pass. Highest config risk; the
                          verification snippet + per-variant spawn matrix is mandatory.
Phase 2 (deletions)     — one PR, pure removals. Prereq for 3 (case fixes).
Phase 3 (HEMTT/CI)      — parallel-safe with 1–2 on a branch; land after 2.
                          From here, every later phase is lint-guarded.
Phase 4 (conventions)   — rolling, per-addon PRs. 4.4's interaction-tree inversion
                          is the one structural piece; do it as its own PR.
Phase 5 (systems)       — each item independent; 5.1 before 5.2 (WCA consumes sys
                          states) and before 5.5's power gating. Biggest single
                          effort: 5.1 (engine consolidation).
Phase 6 (process)       — start anytime; CONTRIBUTING should land with Phase 4 so
                          the laws exist before they're enforced.
```

Riskiest steps and their mitigation: Phase 1 (config-dump diff + spawn matrix), 5.1 (two-generation cutover — keep the old path deletable in one commit so bisection works), 4.4 (interaction inversion — test every cockpit switch per seat, per variant).

Verification infrastructure worth building once, used everywhere: the config-dump diff script (Phase 1), a **MP repro rig** mission (dedicated server + 2 clients, one non-owner operator — MH-47G's practice, which is how their hardest locality bugs were found), and the CI validators (Phase 3).

## Decisions for Riverman

1. **PBO naming** — adopt `vtx_*` filenames at next minor (recommended) or keep `hct_h60_*` for launcher-preset stability.
2. **Mass macro rewrite vs incremental** — incremental recommended (4.3); a big-bang rewrite of 2,188 identifiers is high-risk, low-reward.
3. **uh60_config's future** — genuine delta addon (recommended, matches references) vs full merge into UH60.
4. **CCFS Pong** — easter egg or delete.
5. **Localization ambition** — English-complete stringtables first (recommended), translations later via the AH-64D language-addon model if contributors appear.

---

## Addendum — legacy audit (2026-08-23)

A dedicated sweep for outdated/deprecated material left by the mod's successive authorship eras (the prefix lineage is `vxf` → `vtx` → `hct`; git shows ~24 contributor identities across four eras). Findings below are slotted into the phase where they belong. Items already catalogued in Phases 2/4 are not repeated.

### Fix immediately (Phase 0 tail — live defects)

- **Phantom handlers.** `vtx_uh60_flir_fnc_syncTurret` does not exist but is remote-executed from `uh60_fms/fnc_interaction_waypoint.sqf:104,110` — FMS "slave FLIR to waypoint" errors silently. `vtx_uh60_hoist_fnc_getInHeli` (called from `fnc_getInHeliHook.sqf:23`) and `vtx_uh60_misc_fnc_switchTurret` (CBA event registered in `uh60_misc/XEH_postInit.sqf:12-13`, nothing raises it) are dead on one or both ends.
- **Dev tooling ships to players.** `uh60_misc/dev/` (including a ~6 KB captured session-state dump in `fnc_instantStart.sqf`) is packed into the released PBO — the build has no exclude list. Also ~48 MB of source `.tga` files pack alongside their `.paa` equivalents because `tools/buildExtIncludes.txt` includes `*.tga`; this is most of `uh60_misc`'s PBO weight.
- **Unguarded debug output**: `uh60_misc/fnc_fold.sqf:74` systemChats the fold time to players on every fold.
- **`H60_SFX` remote-exec gap.** Its `CfgFunctions`-registered sound functions are `remoteExecCall`'d by name from `uh60_engine` with no `CfgRemoteExec` whitelist entry — works on default servers, fails on locked-down ones.
- **Config typos with runtime effect**: unquoted classnames in arrays (`magazines[]={60Rnd_CMFlareMagazine}` at `UH60/config/cfgVehicles.hpp:296`); `UH60/cfgSetting.hpp:5` declares `main_addon = "UH60"` but the CfgPatches class is `vtx_uh60`, so the CBA version-dependency check never fires.

### Fold into Phase 2 (delete first)

- Orphan function files beyond the existing list: `uh60_cas/fnc_registerCaution.sqf`, `uh60_cas/fnc_shutdown.sqf` (references nonexistent `fnc_hitEH`), `uh60_engine/fnc_acftSoundController.sqf` (PREP commented out), `uh60_jvmf/fnc_initDialog.sqf`, `uh60_weapons/fnc_handleDamage.sqf` (dead, contains `hint` debug and a top-level pylon-arming dev harness — delete with prejudice), `uh60_misc/dev/*` (or exclude at build), `UH60/config/MFD/Components/horizon.hpp` (`MFD_PFD_TEST`, included nowhere).
- Dead stringtable keys: all 5 in `uh60_mfd` (whole file removable), 2 in `uh60_fd`, 3 in `uh60_hoist`, 1 each in `ace_viv`/`UH60`, plus the 4 fold-complexity keys whose feature is disabled at every layer (`uh60_misc/XEH_preInit.sqf:6` comments out its own initSettings include; the only consumer is commented out in XEH_postInit).
- The custom loading screen: `RscDisplayLoadProjectHatchet` is registered in config but its `fnc_loadingScreen` is never PREP'd — and the engine never instantiates a renamed load display anyway. Wire it properly or delete class + function + `data/splash/construction.paa`.
- Abandoned NVGHUD/HDTS wiring: the include is commented out in `uh60_anvishud/config/cfgVehicles.hpp:42-58` while the whole `config/NVGHUD/` tree ships and `uh60_config` still delta-inherits `class NVGHUD` in 6 places from classes that no longer exist.
- Commented damage-rvmat swap lists in `UH60/config/cfgVehicles.hpp:302-324` reference ~10 nonexistent rvmats; the two that do exist are referenced only from those comments (orphan assets).
- `.travis.yml` (already listed) — note it also pins Python 3.4 and invokes `tools/config_style_checker.py`, which doesn't exist; the GitHub Actions `validate` job is commented out and references three validators (`config_style_checker`, `stringtable_validator`, `return_checker`) that don't exist either. Delete or restore as a pair with Phase 3's real CI.
- Dead A2-era config properties: `typicalCargo[]` (5 sites, ignored by Arma 3), `soundEngineOn*[]` dummy-sound arrays in `H60_SFX` with two older commented generations beside them, empty `FalconDED` font family in `UH60/config.cpp:35-40`.
- The `vxf_core` runtime migration warning in `main/XEH_postInit.sqf:10-13` (two framework generations old) and its sibling "delete if framework ever gets updated" workaround block.

### Fold into Phase 3 (build)

- Build excludes: strip `dev/` folders and `*.tga` from packing (HEMTT does this naturally; if SCons lives on, fix `buildExtIncludes.txt`).
- `script_version.hpp` ships a hardcoded stale `BUILDHASH ea0e3438` and `RELEASENAME HATCHET-ARMA-2.20` — generate at build time or drop.
- `SConstruct` computes `cfgConvertArg` (deliberate garbage value) and never uses it; `.gitignore`/`.vscode` still carry `.hemtt` remnants from the abandoned first HEMTT attempt.

### Fold into Phase 4 (conventions)

- The `vtx`→`hct` rename is half-done in *presentation*, not just filenames: `script_mod.hpp` `PREFIX vtx` renders every launcher entry as "vtx - …", the launcher logo is `logo_vtx_ca.paa`, and every stringtable declares `<Project name="VTX">` with `STR_VTX_*` keys. Decide how much of the visible branding moves to Hatchet within the frozen-classname constraint.
- Version-gate fossils: `uh60_flir/fnc_setup.sqf:73-90` branches on `productVersion >= 2.07` (mod requires 2.12 — the else branch is unreachable); `uh60_sfmplus` `requiredVersion = 1.0`; `uh60_aar` `requiredVersion = 1.62` + OFP-era `version=1`; `H60_SFX` `requiredVersion = 0.1`.
- CBA settings API drift: `CBA_fnc_addSetting` (13 calls) vs internal `CBA_Settings_fnc_init` (7 calls, three casings), mixed within single files (`uh60_anvishud/initSettings.sqf`).
- `spawn`+`sleep` scheduling leftovers where CBA helpers exist: hoist winch loops (no sleep at all — being fixed on `fix/hoist-raise-lower`), `uh60_doorguns/fnc_fired.sqf`, `uh60_misc/fnc_perFrame.sqf:12` (spawns a script per keypress-frame to defer one frame), `uh60_mfd`/`uh60_weapons` `fnc_handleDamage` sleep chains, `fnc_quickstart.sqf`'s 34-line sleep script.
- ACE integration reaches into internals: `uh60_weapons/fnc_hellfireGuidanceInit.sqf:140-166` hand-inlines `ace_missileguidance` PFH state (unversioned internals — breaks whenever ACE restructures `_args`); `uh60_flir/fnc_mfdWaypoint.sqf:41` reads raw MicroDAGR variables unguarded while `uh60_fms` uses the public API correctly; `ace_viv/XEH_postInit.sqf:35,48` registers unload actions on class `All`; `:43` has an `if (count _cargoList < 0)` branch that can never run.
- Hardcoded English where stringtable keys already exist (hoist ACE actions/config/keybinds, `"UH-60M Blackhawk"` CBA category in two addons, all 3DEN attributes, JVMF's ~30 `ToDo: Localize` markers).

### Fold into Phase 5 (systems)

- **5.1 addendum:** `uh60_sfmplus` defines functions as wrappers around `call compile preProcessFileLineNumbers`, so `fnc_engineController` re-reads and recompiles its file from the PBO on every call — per frame, per helicopter. Converting sfmplus to normal PREP compilation is a free flight-model perf win and should ride with the engine consolidation. Its `XEH_PREP.hpp` is also included twice (preStart and preInit).
- Six copies of a hardcoded hoist position `[1.405, 2.03, 0.45]` (one drifted to `…2.031, 0.49`) stand in for a missing model memory point — goes with the 5.4 hoist rewrite plus a modeler request.

### Fold into Phase 6 (process/docs)

- Attribution is effectively absent: `AUTHORS.txt` is a lone UTF-8 BOM (empty since 2021); 22 of 24 CfgPatches have `author = ""`; the only real credits are a frozen text page inside the MFD config (`uh60_mfd/config/MFD/pages/ccfs_menu_draw.hpp:95-104`) that disagrees with git history. Regenerate AUTHORS from git (mind the duplicate identities), populate CfgPatches via a macro, and make the MFD page include it or drop it.
- Public metadata drift: README badge says 0.7.6.0 vs actual 0.7.7.4; `CHANGELOG.md` is 8 dev releases behind `CHANGELOG-DEV.md`; `meta.cpp` is empty (no Workshop publishedid); two different Discord invites (README vs issue templates) and two different repo URLs (`H-60` vs `public_h-60`) in circulation; issue-template filenames contain stray spaces and `config.yml` points at a misnamed file.
- Third-party-era corners to document (not necessarily change): `uh60_aar`'s `USAF_Hatchet_AAR` CfgPatches class predates every project convention; `uh60_jvmf`'s cTab hook hardcodes a specific community fork's icon table behind `__has_include` logic whose branch order looks inverted (`fnc_ctabToJvmf.sqf:13-17`) — verify intent before touching.
