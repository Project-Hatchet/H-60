# Phase 3 · WP1 scouting pass — findings

**Date:** 2026-10-09 · **Tree:** Main `c10917c` in a detached worktree · **HEMTT:** 1.22.0 · **Game:** Arma 3 2.22
**Result:** after the tree fixes listed below, `hemtt check` reports 0 errors and `hemtt build --no-bin` packs all 25 PBOs in 48 s. A scons build of the *same* worktree compares against the HEMTT build with **0 unexpected differences** (`tools/pbo_compare.py`, report classes below). Config *values* still need the in-game dump proof (WP3); this pass proves the manifests.

## 1. HEMTT project config that worked

- `project.toml`: `prefix = "hct"`, `mainprefix = "z"`, version from `addons/main/script_version.hpp` (HEMTT's default location; it accepts `PATCHLVL`), `git_hash = 0`, `[files] include` = `mod.cpp`, `meta.cpp`, both logos, `LICENSE`, `README.md`; `[files] exclude` = `*.png`, `*.tga`, `*.md`, `texHeaders.bin` (reproduces `tools/buildExtIncludes.txt`); `[hemtt.release] sign = false` (ruled: DSSignFile stays).
- `lints.toml`: HeliSim Core's permissive baseline, unchanged.
- Every addon: `addon.toml` with `ignore_pboprefix = true`. The `$PBOPREFIX$` files are untouched and are what ships: the built PBOs' `prefix` property reads `z\vtx\addons\<x>` exactly as the scons PBOs do (the compare found no prefix differences). HEMTT requires a `$PBOPREFIX$` file per addon; the flag only silences the "does not match `z\hct\addons\<folder>`" warning.
- No addon needed `[rapify] enabled = false`.

## 2. What HEMTT rejected, and the value-neutral fixes

Every fix was checked against the **derapified scons `config.bin`** (`hemtt utils config derapify`) so the shipped value is unchanged. CfgConvert stores every unquoted non-numeric token as a *string*; HEMTT's parser refuses them. Quoting them reproduces the shipped value exactly.

| Finding (code) | Count | Where | Fix |
|---|---|---|---|
| `enum {...}` statement (CCHU) | 1 | `main/basicDefines_A3.hpp` | line deleted; nothing in the tree uses the names |
| bare macro args `CCFS_POLYGON(BALL_X,BALL_Y)` (CCHU) | 1 | `uh60_mfd/.../ccfs_draw.hpp` | `"BALL_X"`,`"BALL_Y"` — CfgConvert shipped the bare names as strings (the CCFS ball is dead either way; MFD-pass item) |
| `VERSION_CONFIG` → `version = 0.7.10.0` (L-C01M) | 25 | every `config.cpp` | own `VERSION_CONFIG` in `script_mod.hpp` writing `version = QUOTE(VERSION)` — the shipped value *is* the string `"0.7.10.0"` |
| bare identifiers as values (L-C01): `Compartment2`, `translation`, `UH60_Pilot`, `db5`, `true/false`, `B_Parachute_02_F`, p3d paths, `wheels` | ~60 | 20 files | quoted |
| dialog coordinates `x = 0.38 * safezoneW + safezoneX;` (L-C01) | 198 | jvmf, ui, weapons dialogs | quoted (CfgConvert shipped them as strings) |
| SQF code as values `buttonUp = [...] call fnc;` (L-C01) | 60 | fms interaction/keypads, acre | `QUOTE([ARR_n(...)] call fnc)`; embedded `"word"` → `QUOTE(QUOTE(word))`, which both preprocessors stringize to `""word""` |
| MFD condition macros emitting bare expressions (L-C01M) | ~2,900 | `COND_ISNUMBER`, `COND_SUBPAGE`, `COND_NOT_SUBPAGE`, `COND_SUBPAGE_OR_SUBPAGE`, `HVR_CONDITION_PAGES`, `COND_METRIC/IMPERIAL/FULL_ONLY`, `BOXEDTEXT_CONDITION` callers | macros now emit `QUOTE(...)`; bare `_EXPR` variants added for the composed ones |
| bone / class names as bare tokens in macros (L-C01M) | ~1,400 | `POINTS_LEVEL_{N,M,W}`, `LEVEL_TEXT`, `LEVEL_NARROW/WIDE`, `MFD_BTN`, `KNEELING_SEAT`, `HMD_COLOR`, `USERNNN`, `mag_xx`, `TEXT_LEFT_MID_USERTEXT`, `GVAR(item)` | `QUOTE()` inside the macro body |
| parent class case `: level0`, `: TAC_WP1_Dist`, `vtx_ApuSoundLoop_Ext_…` (L-C05) | 290 | ESIS/pfd macros, tac/bones.hpp, SFX | case matched to the definition |
| `TEXT_MID_SCALED(...);` extra `;` (L-C17) | 3 | `ESIS_BOOT.hpp` | removed |
| `#include "initSettings.sqf";` trailing `;` (PE14) | 3 | three `XEH_preInit.sqf` | removed |
| include-only SQF files lint as standalone (SPE2) | 7 | `initSettings.sqf` ×6, hoist `ACE_Actions.sqf` | renamed `*.inc.sqf` (ACE's convention; HEMTT skips them), include lines updated |
| `#if __has_include` (PE23) | 1 | `uh60_jvmf/fnc_ctabToJvmf.sqf` | `#pragma hemtt flag pe23_ignore_has_include` — file ships as source, no bytecode |

Scale: 64 files, 404 lines changed, 7 renames. Addons touched: uh60_config 15 files, uh60_mfd 10, jvmf 5, weapons/hoist/fms/anvishud 4 each, ui 3, ground/flir/main/ace_viv/MH60S 2 each, misc/acre/stretcher/MH60M/H60_SFX 1 each. None of the files the open #630 → #631 → #633 chain edits are touched (`uh60_hoist/*.sqf`, `uh60_misc/XEH_*`, `MH60M/config/cfgVehicles.hpp`, `uh60_mfd/config/cfgVehicles.hpp`, `uh60_config/.../doorgunsTurnOut.hpp`, …); the 25 `VERSION_CONFIG` sites are fixed through `script_mod.hpp` alone, so no per-addon `config.cpp` changes.

## 3. The one real bug found (needs a ruling — value change)

Sixteen `limitsArrayTop[]`/`limitsArrayBottom[]` lines in **five files** write the FFV seat arcs with square brackets:

```
limitsArrayBottom[] = {[-45,-94.9656],[-45,80.9904],[-31.9033,82.8465],[-31.7935,95]};
```

CfgConvert shipped them as **strings**: `{"[-45", "-94.9656]", "[-45", "80.9904]", …}`. The engine cannot read those as angle pairs, so the passenger/kneeling FFV seat limits in `uh60_config/config/turrets/cargoTurrets.hpp`, `cargoTurretsDoor.hpp`, `dapPaxSeats.hpp`, `vehicles/S70i.hpp` and `MH60S/config/cargoTurretsGAU21L.hpp` have never applied in a shipped build. HEMTT refuses the syntax outright. The scouting worktree carries the brace fix (`{{-45,-94.9656},…}`) because nothing else parses; **this is a behavior change** (seats gain the intended arcs) and belongs in its own small fix PR with a changelog line, before or alongside WP2b — Riverman's call. Not in the #633 door-gun files.

Two smaller oddities kept value-identical on purpose (candidates for a later ruling, not Phase 3): `movingEnable = true;` / `hasDriver = false;` ship as the strings `"true"`/`"false"` (quoted as-is), and the CCFS ball polygon references bones `BALL_X`/`BALL_Y` that do not exist.

## 4. Packer differences the compare tool classifies as expected

`tools/pbo_compare.py compare <scons addons> <hemtt addons>` on the same tree → 25 pairs, classes:

| Class | Count | Meaning |
|---|---|---|
| bytecode-added | 317 | HEMTT adds `.sqfc` beside every `.sqf` (ACE ships the same) |
| rapified-bytes | 25 | `config.bin` bytes differ between rapifiers — values proven by the dump (WP3) |
| rapified-vs-text | 52 | all `.rvmat`: scons shipped text, HEMTT rapifies them |
| source-config-shipped | 25 | Addon Builder packs `config.cpp` beside `config.bin`; HEMTT does not |
| stringtable-binarized | 18 | HEMTT writes `stringtable.bin` for all 10 stringtables; Addon Builder wrote one for only 4 of them (and kept the `.xml`). ACE ships `stringtable.bin`, so the engine side is fine |
| texheaders-cache | 10 | each packer generates its own `texHeaders.bin` |
| header-prop-added | 75 | HEMTT adds `hemtt`, `git`, `author` header properties |
| timestamp | 25 | never compared |

## 5. What the dump comparison must tolerate (WP0 → `tools/config_dump/compare_dumps.py`)

- CfgConvert stores unquoted arithmetic as strings (`"160/256"`); HEMTT stores the number. The engine resolves both.
- Arma's preprocessor parenthesises substituted macro arguments — `(user25>((3+0.2)-0.1))` vs HEMTT's `(user25>(3+0.2-0.1))`; expanded `ARR_n` macros are spaced differently inside code strings.
- `compare_dumps.py` normalises all three (numbers as floats, arithmetic evaluated, `userN` expressions evaluated at sample points, whitespace-insensitive strings) and lists what still differs. Self-test on the Phase 1 captures: 575,884 values identical.

## 6. Noise worth knowing (warnings only, build unaffected)

- **PW1 ×1,804** macro redefinitions: the MFD page headers redefine layout macros per page. Not suppressible in HEMTT 1.22; cosmetic in CI logs.
- **PW3 ×442** padded macro arguments (`SEAT_DRIVER(Seat01, 0.53, 4.44,-0.33)` style): 142 in Brad's `helisim_mass.hpp`, 104 in `uh60_mfd/config/interaction.hpp`. Suppressible per file with `#pragma hemtt flag pw3_ignore_format`; fixing the spacing could change whitespace inside generated strings, so leave for Phase 4.
- **L-C11ME ×54** sound paths without extension (H60_SFX), **L-C19 ×23** `cfgVehicles`-style casing, **L-C14 ×18** unused external class declarations, a dozen SQF lints (all-caps variables in jvmf, `select` idioms, three undefined framework functions HEMTT cannot see). Phase 4 material; the lint baseline leaves them as warnings.

## 7. Facts for the plan

- `hemtt build --no-bin`: 48 s for 25 PBOs / 719 MB on this machine; scons takes several minutes and rebuilds everything every run.
- The stale AddonBuilder mirror lives at `%TEMP%\z\vtx` and is **exactly** what `push_dev.py wipe_mirror()` deletes; a `cmd /c rmdir` with `%TEMP%` from Git Bash does not reach it. The contaminated first compare shipped ~290 Phase-2-deleted files (fonts, textures, functions) inside the scons PBOs — a live reminder of why the mirror wipe matters until WP4e.
- HEMTT requires a `$PBOPREFIX$` file in every addon (an addon without one fails with "Addon prefix not found").
- `QUOTE(QUOTE(x))` is the portable way to embed a quoted string inside a `QUOTE()`d code value; a single inner `"x"` is not escaped by either preprocessor.
