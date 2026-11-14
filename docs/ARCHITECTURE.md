# H-60 pack architecture (Snow fork)

This fork is laid out as a **common base plus one PBO per airframe family**. Every
variant is a leaf. The pack's systems talk to aircraft only through the base class
and through config traits, never by variant name. `tools/validate_tree.py` enforces
the rules below in CI.

## Layers

```
h60_main            macros (script_macros.hpp), version, trait lookup (getTrait)
   │
uh60                shared assets: vtx_uh60.p3d, model.cfg, anims, fonts, every texture the p3d bakes in
h60_config          the common base: vtx_H60_base, crew, shared turrets/parts/animation
   │                and texture sources, shared weapons, MASS_* (script_mass.hpp),
   │                variant scaffolds (config/variantExterns.hpp, variantBaseInherit.hpp)
   │
systems             h60_helisim, h60_mfd, h60_fms, h60_flir, h60_weapons, h60_cas, h60_misc,
   │                h60_ground, h60_hoist, h60_doorguns, h60_anvishud, h60_jvmf, h60_ui,
   │                h60_sfx, h60_ace_viv, h60_stretcher
   │                → extend vtx_H60_base only
   │
variants (leaves)   uh60m   vtx_UH60M, vtx_UH60M_SLICK, vtx_UH60M_MEDEVAC
   │                s70i    vtx_S70i
   │                hh60    vtx_HH60              (+ HH-60G liveries)
   │                mh60m   vtx_MH60M, _DAP (+ textures the p3d bakes in; vtx_MH60M_DAP_MLASS is a hidden compat stub of the DAP)
   │                mh60s   4 hidden vtx_MH60S classes
   │
optional compat     h60_acre, h60_aar, h60_air_control (skipWhenMissingDependencies)
                    → may re-open variants; they load after them
```

PBOs come out as `hct_h60_<x>.pbo` for the core and systems, and as `hct_<airframe>.pbo`
for the airframes. Folder names are independent of the shipped paths. Each addon's
`$PBOPREFIX$` (`z\vtx\addons\<old name>`) is frozen, because models and configs bake
those paths in. Always include through the prefix: `\z\vtx\addons\uh60_config\...`
lives in the `h60_config` folder.

## Rules

1. **One declaration per class.** A variant is declared and configured only inside its
   own PBO. That covers everything specific to it: HeliSim seats
   (`class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_<x> };` as its last member), turrets,
   MFD templates, liveries and its editor preview.
2. **Systems extend the base, not variants.** Re-open `vtx_H60_base` with
   `class X: X` and forward-declare inner classes. Never re-open a populated container
   without them.
3. **No variant names in SQF.** Ask a trait instead:
   `HAS_TRAIT(_vehicle,"irLaser")` or `[_vehicle, "irLaser"] call vtx_main_fnc_getTrait`.
   For class-wide ACE actions or CBA class event handlers, register on
   `[trait] call vtx_main_fnc_getTraitClasses`. Use `QBASE_CLASS` for the base. The
   `variant-layering` check fails on any variant classname literal in SQF.
4. **Frozen names.** Don't rename CfgPatches classes, `$PBOPREFIX$` contents,
   function names, CBA setting names or keybind names, because missions and saved
   settings depend on them. `vtx_uh60_config` stays as a CfgPatches name, so missions
   that list it keep loading.
5. **Runtime calls need no load edge.** Every function is compiled at preInit.
   Add a `requiredAddons` edge only when config merge order matters. Check the effect
   first: load order also orders the Hatchet `modules` and `interaction` lists, and the
   first matching interaction point wins.
6. **Locality.** Broadcast (`setVariable [.., .., true]`, `animateSource` where local)
   only on change, and only from the aircraft's owner. Read HeliSim Core's `bmkhs_*`
   variables with a default.
7. Inherited rules from upstream: `playerPosition = 1` stays on the vanilla
   `CargoTurret`, `GVAR(lockSeats)` stays in ace_viv, and `MASS_*` lives in
   `h60_config/script_mass.hpp`.

## Variant traits

These are declared on `vtx_H60_base` (all default to 0) and set by variants:

| Trait | Meaning | Set by |
|---|---|---|
| `vtx_trait_flirTurretAnimated` | FLIR ball follows the pilot camera | MH-60M family |
| `vtx_trait_irLaser` | fixed-forward IZLID keybind | MH-60M family |
| `vtx_trait_erfsService` | ERFS attach/remove ACE actions | MH-60M family |
| `vtx_trait_crewChiefTurnOut` | crew-chief turn-in/out seat swap | DAP |

To add a trait, give it a default on the base, set it in the variants that have it,
and read it with `GET_TRAIT`/`HAS_TRAIT`.

## Adding a variant

1. Create `addons/<name>/` containing `$PBOPREFIX$` (`z\vtx\addons\<name>`) and
   `addon.toml` (`ignore_pboprefix = true`). Add a `script_component.hpp` that includes
   main's macros, `\z\vtx\addons\uh60_config\script_mass.hpp` and
   `\z\vtx\addons\uh60_helisim\config\bmkhs_config\helisim_seats.hpp`.
2. Make `config.cpp` a manifest: CfgPatches with `units[]` and
   `requiredAddons[] = {"vtx_UH60", "vtx_UH60_config", "vtx_uh60_helisim"}` plus any
   system whose templates it mounts, followed by `#include "config\cfgVehicles.hpp"`.
3. In `config/cfgVehicles.hpp`, include
   `\z\vtx\addons\uh60_config\config\variantExterns.hpp` at file scope and
   `...\variantBaseInherit.hpp` inside `class CfgVehicles`, then declare
   `class vtx_<X>: vtx_H60_base { ... }` with its traits and seats.
4. Put variant-only textures and the preview in `<name>/data/`. Anything the shared
   p3d bakes in stays where it is.
5. Add the folder to `VARIANT_ADDONS` in `tools/validate_tree.py`.

## Verifying a change

- `hemtt check`: compare the warning list against the previous build. Don't add
  warnings.
- `python tools/validate_tree.py` (CI `validate` job).
- `python tools/config_flatten.py dump <build> <out>` runs before and after, then
  `compare` checks inheritance-resolved config values offline. A restructure must
  show no value changes.
- In game: `tools/config_dump` (the authority) and `tools/class_matrix.sqf` in the
  debug console, which spawns every variant and logs seats, turrets, pylons and mass.
- `hemtt launch minimal`, or `hemtt launch profiling` for performance work.
