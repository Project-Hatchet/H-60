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
h60_config          the common base: hct_H60_base, crew, shared turrets/parts/animation
   │                and texture sources, shared weapons, MASS_* (script_mass.hpp),
   │                variant scaffolds (config/variantExterns.hpp, variantBaseInherit.hpp)
   │
systems             h60_helisim, h60_mfd, h60_fms, h60_flir, h60_weapons, h60_cas, h60_misc,
   │                h60_ground, h60_hoist, h60_doorguns, h60_anvishud, h60_jvmf, h60_ui,
   │                h60_sounds, h60_ace_viv, h60_stretcher
   │                → extend hct_H60_base only
   │
variants (leaves)   uh60m   hct_UH60M, hct_UH60M_SLICK, hct_UH60M_MEDEVAC
   │                s70i    hct_S70i
   │                hh60    hct_HH60              (+ HH-60G liveries)
   │                mh60m   hct_MH60M, _DAP (+ textures the p3d bakes in; hct_MH60M_DAP_MLASS is a hidden compat stub of the DAP)
   │                mh60s   4 hidden hct_MH60S classes
   │
optional compat     h60_acre, h60_aar, h60_air_control (skipWhenMissingDependencies)
                    → may re-open variants; they load after them
legacy names        h60_compat_vtx: old vtx_* CfgPatches, classnames and functions
```

PBOs come out as `hct_h60_<x>.pbo` for the core and systems, and as `hct_<airframe>.pbo`
for the airframes.

## Naming

- **Identifiers** use `PREFIX hct` and `COMPONENT` = the folder name: CfgPatches
  `hct_h60_mfd`, functions `hct_h60_mfd_fnc_x`, globals `hct_h60_mfd_x`, stringtable
  keys `STR_hct_h60_mfd_x`; airframes `hct_uh60m`, `hct_mh60m`, ...; classes `hct_*`
  (`hct_H60_base`, `hct_UH60M`). Every component starts with `h60_` (or is an airframe):
  the Hatchet framework already owns `hct_core`, `hct_interaction`, `hct_main`, `hct_util`.
- **File paths** keep the frozen `$PBOPREFIX$` `z\vtx\addons\<COMPONENT_PATH>`: the
  binarised models bake those paths in. Each `script_component.hpp` defines
  `COMPONENT_PATH` (its prefix leaf, e.g. `uh60_mfd`), and `h60_main/script_macros.hpp`
  points CBA's path macros (PREP, COMPILE_FILE, QPATHTOF) at it. Write absolute
  includes through the prefix: `\z\vtx\addons\uh60_config\...` is the `h60_config`
  folder. `PATHTOEF` is disabled (own-component paths only).
- `vtx` survives only in those paths, in `model.cfg` (keyed to `vtx_uh60.p3d`), in asset
  file names, and in the four Eden attribute `property` keys (`vtx_attribute_doorNumbers`,
  `vtx_attribute_markings`, `vtx_uh60_FoldRotorBlades`, `vtx_uh60_RemoveFuelProbe`):
  those are stored in mission.sqm, so renaming them would drop saved settings.
- **h60_compat_vtx** keeps pre-rename content loading: every old CfgPatches name, hidden
  `vtx_*` aliases of the placeable vehicles/units, weapons and magazines, and the old
  function names pointing at the new functions. Generated once; add nothing to it.

## Rules

1. **One declaration per class.** A variant is declared and configured only inside its
   own PBO. That covers everything specific to it: HeliSim seats
   (`class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_<x> };` as its last member), turrets,
   MFD templates, liveries and its editor preview.
2. **Systems extend the base, not variants.** Re-open `hct_H60_base` with
   `class X: X` and forward-declare inner classes. Never re-open a populated container
   without them.
3. **No variant names in SQF.** Ask a trait instead:
   `HAS_TRAIT(_vehicle,"irLaser")` or `[_vehicle, "irLaser"] call hct_h60_main_fnc_getTrait`.
   For class-wide ACE actions or CBA class event handlers, register on
   `[trait] call hct_h60_main_fnc_getTraitClasses`. Use `QBASE_CLASS` for the base. The
   `variant-layering` check fails on any variant classname literal in SQF.
4. **Stable names.** CfgPatches classes, classnames, function names, CBA setting and
   keybind names and Eden attribute properties are what missions and players' saved
   settings refer to. Renaming one is a breaking change: give it a compatibility alias
   (as h60_compat_vtx does) and a changelog line. `$PBOPREFIX$` contents never change.
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

These are declared on `hct_H60_base` (all default to 0) and set by variants:

| Trait | Meaning | Set by |
|---|---|---|
| `hct_trait_flirTurretAnimated` | FLIR ball follows the pilot camera | MH-60M family |
| `hct_trait_irLaser` | fixed-forward IZLID keybind | MH-60M family |
| `hct_trait_erfsService` | ERFS attach/remove ACE actions | MH-60M family |

To add a trait, give it a default on the base, set it in the variants that have it,
and read it with `GET_TRAIT`/`HAS_TRAIT`.

## Adding a variant

1. Create `addons/<name>/` containing `$PBOPREFIX$` (`z\vtx\addons\<name>`) and
   `addon.toml` (`ignore_pboprefix = true`). Add a `script_component.hpp` that includes
   main's macros, `\z\vtx\addons\uh60_config\script_mass.hpp` and
   `\z\vtx\addons\uh60_helisim\config\bmkhs_config\helisim_seats.hpp`.
2. Make `config.cpp` a manifest: CfgPatches with `units[]` and
   `requiredAddons[] = {"hct_UH60", "hct_h60_config", "hct_h60_helisim"}` plus any
   system whose templates it mounts, followed by `#include "config\cfgVehicles.hpp"`.
3. In `config/cfgVehicles.hpp`, include
   `\z\vtx\addons\uh60_config\config\variantExterns.hpp` at file scope and
   `...\variantBaseInherit.hpp` inside `class CfgVehicles`, then declare
   `class hct_<X>: hct_H60_base { ... }` with its traits and seats.
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
