# HeliSim Core headers - vendored copy

A copy of the HeliSim Core header `uh60_helisim` includes, committed so the H-60 builds
with nothing but `scons` - no submodule, no junction, no setup step. SConstruct copies
`include\` into `build\` beside `x\cba` and `z\ace`, which is how `\bmkhs_helisim\...` resolves.

**Matches HeliSim Core 1.1.1.0.**

**Do not edit these files here.** Change them in HeliSim Core, then copy them back over.
The procedure is in HeliSim Core's `docs/AIRCRAFT_GUIDE.md` under
"Building your mod against Core's headers".

| Header | Included by |
|---|---|
| `fmOverride.hpp` | `addons/uh60_helisim/config/cfgVehicles.hpp` - the flight model override block |

A no-systems aircraft needs only this one. Add the others (`hitPoints.hpp`,
`controlMacros.hpp`, `functions/.../*.hpp`) when the pack starts including them.
