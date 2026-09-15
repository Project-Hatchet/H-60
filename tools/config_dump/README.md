# Config-dump harness (Phase 1 · WP0)

Proves that a restructure branch is **behavior-identical** to Main: the effective,
inheritance-resolved config values the engine sees for every spawnable H-60 class
are captured before and after, and the diff must be empty except for the deliberate
changes each work package logs (see `docs/phase-1/PHASE_1_PLAN.md` §3/§5).

## What it captures

- **CfgVehicles spawn matrix + `vtx_H60_base`**: `vtx_UH60M`, `vtx_UH60M_SLICK`,
  `vtx_UH60M_MEDEVAC`, `vtx_HH60`, `vtx_S70M`, `vtx_MH60M`, `vtx_MH60M_DAP`,
  `vtx_MH60M_DAP_MLASS`, `vtx_MH60S`, `vtx_MH60S_Pylons`, `vtx_MH60S_GAU21L`,
  `vtx_MH60S_Pylons_GAU21L` — full recursive tree, inherited members included
  (so a shadowed merge that silently drops inherited content shows up, the #510
  failure mode).
- **Sound/function roots**: every class under `CfgSoundShapes`, `CfgSoundCurves`,
  `CfgSound3DProcessors`, `cfgDistanceFilters`, `CfgSoundSets`, `CfgSoundShaders`,
  `CfgSounds`, `CfgSFX`, `CfgMusic`, `CfgFunctions` that any `vtx_*` addon
  contributes (via `configSourceAddonList`) — this is the coverage for the
  H60_SFX demotion in WP1.

Properties are emitted **name-sorted** and subclasses recursed name-sorted, so a
declaration merely moving between addons produces **no diff** as long as values
survive. Subclass order is behavior for indexed access (turret indexes), so each
class also emits one `classOrder` line in **engine order** — if that line diffs,
a real ordering change happened and must be assessed, not ignored.

## Capture procedure

1. Build the tree into the local mod as usual and launch Arma 3 with the mod's
   **actual dependencies** (CBA, ACE, Hatchet Framework, the H-60 build).
   ACRE is NOT required: `uh60_acre` is `skipWhenMissingDependencies` and its
   layer is simply absent without it — fine, Phase 1 never touches it.
   Use the **same game version and same modset for every capture** — the dump
   includes inherited vanilla/ACE values and optional layers like uh60_acre,
   so a mismatched modset diffs everywhere.
2. Open Eden (VR map is fine) → Tools → **Debug Console** (or Esc console in a
   mission preview). Paste the entire contents of `dump_configs.sqf` and
   **LOCAL EXEC**. The game may freeze for a minute or two; wait for the
   *"VTX config dump complete"* hint.
   > **Why the script has no comments:** the debug console compiles pasted text
   > *without* running the preprocessor, so `//` and `/* */` are parse errors
   > there. Keep `dump_configs.sqf` comment-free; document changes here instead.

3. From the repo root:

   ```
   powershell -ExecutionPolicy Bypass -File tools\config_dump\extract_dump.ps1 -Label baseline-<short-sha>
   ```

   It parses the newest RPT in `%LOCALAPPDATA%\Arma 3` (override with `-RptPath`)
   and writes one file per class/root to `tools\config_dump\dumps\<Label>\`.
   If you dumped more than once in a session, the last complete run wins.
4. Label convention: `baseline-<Main short-sha>` for Main captures,
   `<branch>-<short-sha>` for restructure-branch captures.

## Comparing

```
git diff --no-index tools/config_dump/dumps/baseline-f3edead tools/config_dump/dumps/base-single-owner-abc1234
```

Acceptance per PHASE_1_PLAN.md: empty diff, except the deliberate changes the
work package logs (e.g. WP2's Slick turret-lock correction). Attach the diff (or
its emptiness) to the restructure PR. **Re-capture the baseline whenever Main
moves** — a restructure branch must never carry a config diff caused by someone
else's merge.

`dumps/` is git-ignored; dumps are working evidence, not repo content.
