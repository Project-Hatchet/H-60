# HeliSim Core headers - vendored copy

A copy of the HeliSim Core header `uh60_helisim` includes, committed so the H-60 builds
with nothing but `scons` - no submodule, no junction, no setup step. SConstruct copies
`include\` into `build\` beside `x\cba` and `z\ace`, which is how `\bmkhs_helisim\...` resolves.

**Matches HeliSim Core 1.3.0.0.**

**Do not edit these files here.** Change them in HeliSim Core, then copy them back over.
The procedure is in HeliSim Core's `docs/AIRCRAFT_GUIDE.md` under
"Building your mod against Core's headers".

| Header | Included by |
|---|---|
| `fmOverride.hpp` | `addons/uh60_helisim/config/cfgVehicles.hpp` - the flight model override block |
| `hitPoints.hpp` | `addons/uh60_helisim/config/cfgVehicles.hpp` - `BMKHS_HITPOINT` for the hitpoint declarations |
| `functions/core/core.hpp` | `addons/uh60_helisim/functions/custom/fn_updateCockpit.sqf`, `addons/uh60_flir/functions/fnc_updateUIValues.sqf` - Core's unit conversions, for the readouts |
| `controlMacros.hpp` | `addons/uh60_helisim/config/CfgUserActions.hpp` - keybind row macros (`BMKHS_CONTROL` is redefined there for Addon Builder, see `docs/HELISIM_TODO.md`) |
