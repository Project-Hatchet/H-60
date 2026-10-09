# HeliSim controls through Hatchet

How a cockpit control on the H-60 gets from a click (or keybind) to HeliSim and back
on screen. Every HeliSim control follows this; don't add another path.

## The rule

- **Hatchet is the only thing that moves a cockpit control.** Clicks, keybinds, linked
  controls and the quickstart all go through a Hatchet interaction.
- **HeliSim is the only state.** The pack tells HeliSim the moment Hatchet starts a move,
  and everything else reads HeliSim's published variables.
- **The pack never animates a HeliSim control.** The `controlMoved` handler in
  `uh60_helisim/XEH_preInit.sqf` reacts to moves (APU sound) but
  moves nothing.

## The pieces

| Piece | File | Job |
|---|---|---|
| Hatchet interaction | `uh60_config/.../cfgHctCockpit.hpp` | Animates the control; calls the pack |
| Control | `uh60_helisim/.../helisim_controls.hpp` | HeliSim's positions; `hctInteraction[]` names the interaction |
| `cockpitAllowed` | `uh60_helisim/functions/custom` | `interactionCondition`: may it move there? |
| `cockpitInteract` | `uh60_helisim/functions/custom` | `animStart` / `buttonUp`: tell HeliSim, on the owner |
| `cockpitBind` | `uh60_helisim/functions/custom` | Keybinds and linked controls: drive the interaction |

## A click

1. Hatchet checks `interactionCondition` → `cockpitAllowed`, which asks Core
   (`bmkhs_fnc_controlAllowed`) - HeliSim's interlocks are Core's to answer. **Refused means the control does not
   move** - the guide's mechanical stop. Nothing has to snap back.
2. Hatchet calls `animStart` → `cockpitInteract` with the target label, then starts the
   animation. Telling HeliSim here, not in `animEnd`, keeps the engine and the lever in
   step - `animEnd` fires on arrival (or after 3 s).
3. `cockpitInteract` maps the label to a position and calls `bmkhs_fnc_controlSet` where
   the aircraft is local. From the other seat it raises `vtx_uh60_helisim_controlSet` on
   the owner (a CBA event, so CfgRemoteExec whitelists don't block it).

## A keybind

The bind row (`headers/bmkhs_controls.hpp`, via `config/CfgUserActions.hpp`) calls
`cockpitBind` with the control and position index. `cockpitBind` finds the interaction
from `hctInteraction[]` and runs `hct_interaction_fnc_scriptedInteract` with that
position's label. From there it is a click: steps 1-3 above.

- A button interaction (the starters) has no labels; a bind to a non-rest position presses
  it.
- `scriptedInteract` leaves its interaction as Hatchet's current button. `cockpitBind`
  restores the cursor's, or Hatchet's interact key could fire the scripted one again.

## Linked controls - the power levers

Moving a power lever to FLY while the other engine runs at IDLE takes both to FLY, as on
the AH-64. `cockpitInteract` moves the other lever **through `cockpitBind`**, so Hatchet
animates both at the same rate. The other lever's own `animStart` sees
`vtx_uh60_helisim_linking` and does not link back.

Other engine OFF or already at FLY: only the clicked lever moves. Other engine STARTING:
`cockpitAllowed` refuses FLY.

## The flight director panel

The FD buttons and knobs are not HeliSim controls - they are Core's FMC inputs, the same
actions a keybind sends. Each calls `vtx_uh60_helisim_fnc_fmcInput`, which hands it to Core's
`inputControlHandle` / `inputAnalogHandler` on the owner:

- **Buttons** send the mode's action (`bmkhs_fdAlt`, ...). Core engages it and cancels the others
  on its axis; the light follows Core's `fdModeChanged` event.
- **Knobs** - a drag (`fnc_fdKnob`) sends the knob's position as a fraction of the target's range
  (`bmkhs_fdAltTarget`, ...); the push sends sync (`bmkhs_fdAltSync`). The knob table in
  `XEH_preInit.sqf` maps each knob's animation to target units.
- **The knobs follow Core.** `fnc_updateCockpit` turns a knob to Core's target whenever the two
  differ by more than half a step - a sync, a keybind step, ALTP capture - except for a second
  after a drag.

## Rates

Hatchet animates with `animateSource` at the interaction's `animSpeed`, in phase per second
(the sources' `animPeriod` is 1). A control whose HeliSim move takes time must travel in
that time:

- Power levers: Hatchet's `animSpeedCode` calls `fnc_leverSpeed` as each move starts.
  IDLE to FLY takes the engine's `leverTravelTime`, read from Core (`bmkhs_engines`), as
  HeliSim's governor does; every other move HeliSim makes at once, and the lever takes
  0.5 s (`HAND_SECONDS`) - a snap looks wrong. Changing `leverTravelTime` changes the lever
  with it. `animSpeed = 0.0775` (`(0.85 - 0.23) / 8`) is only for a Hatchet without
  `animSpeedCode`.
- Everything else snaps (`animSpeed = 0`) or uses its existing speed.

## Adding a HeliSim control

1. Declare it in `helisim_controls.hpp` with `hctInteraction[]` - the class path under
   `interaction`, e.g. `{"startUp", "b_gen1"}`.
2. In `cfgHctCockpit.hpp`, give the interaction:
   - `animLabels[]` whose labels are the position class names (case and spaces aside:
     `"APU BOOST"` ↔ `ApuBoost`)
   - `animStart="[(_this # 0), '<variableName>', (_this # 2)] call vtx_uh60_helisim_fnc_cockpitInteract";`
   - `interactionCondition="[_this, '<variableName>'] call vtx_uh60_helisim_fnc_cockpitAllowed";`
   - no `animEnd` that calls the pack
3. Add its bind rows to `headers/bmkhs_controls.hpp`.
4. **Check inheritance.** A Hatchet class inheriting from a HeliSim switch inherits its
   `animStart` and `interactionCondition`. A child that is not a HeliSim control blanks
   both (see the boost pumps and the parking brake).

## Don'ts

- Don't `animateSource` a HeliSim control from the pack.
- Don't call `bmkhs_fnc_controlSet` from a keybind or script - go through `cockpitBind`.
- Don't put an interaction's HeliSim call in `animEnd`.
- Don't restate position phases in the controls config. Hatchet's `animStates[]` is the
  only place a position's phase lives.

## Versus the AH-64

The AH-64 gives each power-lever detent its own `buttonDown` hotspot, and its pack
animates the lever in `controlMoved`. The H-60 model has one memory point per lever, so it
uses Hatchet's lever interaction instead and lets Hatchet animate. Hatchet also supports
`positionType = "coordinates"`, which would allow per-detent hotspots without new memory
points if that is ever wanted.
