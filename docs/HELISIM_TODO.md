# UH-60 HeliSim integration - to-do

Open items for the UH-60 pack (`addons/uh60_helisim`) and the HeliSim Core work it depends on.

## HeliSim Core

- [ ] **Add AIR SOURCE (ENG / APU) bleed selection to Core.** The selection of which bleed
  source feeds the pneumatic system is a flight model item, not pack logic. The UH-60's AIR
  SOURCE switch is one three-position control (ENG / OFF / APU), and Core's component gates
  only read booleans or circuits, so it cannot gate the APU bleed and the engine bleed
  separately from config. **Interim:** the pack's `controlMoved` handler
  (`XEH_preInit.sqf`) publishes `vtx_uh60_helisim_airSrcEng` / `vtx_uh60_helisim_airSrcApu`
  from the switch position, and the `ApuBleed` / `EngineBleed` producers gate on them.
  Remove both once Core owns the selection.
- [ ] **Make `BMKHS_CONTROL` (controlMacros.hpp) build-tool portable.** It builds `onActivate`
  with `__EVAL(format[...])`. HEMTT evaluates that; Arma's Addon Builder (the H-60's scons
  build) compiles it to `<null>`, so every keybind shows in the menu and does nothing. Plain
  preprocessor quoting works under both. The guide's group-view pattern has the same problem:
  `QUOTE(bmkhs_ctrl_##cname##_##ptok)` keeps the `##` literally under Addon Builder, so the
  group names match no action and the menu section is empty; pasting in a helper macro first
  and quoting that works under both. **Interim:** the pack redefines both views in
  `config/CfgUserActions.hpp`.

- [ ] **Expose the control interlock check.** `bmkhs_fnc_control` checks `enabledBy[]` /
  `inhibitedBy[]` internally; there is no query for "may this control move there". The
  H-60's `cockpitAllowed` mirrors that loop so Hatchet can refuse before moving (see
  `docs/HATCHET.md`). A Core query would remove the copy.
- [ ] **Merge and publish Core 1.2.0.** Committed on Core branch `release/1.2.0` (not merged to
  master, not pushed): the mass `Equipment` block, control mixing from config, the simple rotor
  `controlMap[]`, casual upright tail rotors, per-engine fuel selectors and "off", drive
  failures latching on every engine a summing component carries, the rig's force path and the
  guide's outputs Reference. The H-60 depends on all of it.
- [ ] **Fire model.** Core has none (`SYS_ENG_OIL_FIRE_CHANCE` is defined but unused), so the
  H-60's FIRE lamp is never lit.
- [ ] **Battery low-charge threshold.** Core only exposes the 0.25 dropout, so the H-60's BATT
  LOW lamp is never lit.

## Possible future Core features

Not planned - candidates, recorded so the reasoning isn't lost.

- [ ] **Rotor downwash on the stabilator.** `wing/fn_wing.sqf` gives the stabilator freestream
  air and rotation only - no rotor wake. Adding the main rotor's induced velocity (momentum
  theory, from thrust, density and disc area) to the stab's relative wind, scaled by a tuned
  wake-impingement curve (wake skew against the stab's position), would give the UH-60's
  low-speed pitch-up as the wake sweeps the tail (~15-40 kt), make the stabilator schedule and
  stab failures matter at low speed, and let the rig derive collective to pitch mixing. Needs
  the wing force path ported to the rig to tune.

## Hatchet framework

Do after the H-60 HeliSim integration is complete.

- [ ] **Per-detent animation speeds (PR to `Project-Hatchet/hatchet-framework`).** Hatchet has
  one `animSpeed` per interaction, so the power levers travel OFF↔IDLE at the IDLE→FLY rate
  (~3 s) while HeliSim switches instantly - the cockpit is not congruent with the engine. Add
  e.g. `animSpeeds[]` alongside `animStates[]` in `fnc_loadItem` / `fnc_leverAnimate`, then set
  the levers to `{0, 0, 0.0775}` (snap, snap, travel to FLY). See `docs/HATCHET.md` → Rates.

## After the H-60 release

- [ ] **Update the EC665 and AH-64D to HeliSim Core 1.2.0.** 1.2.0 adds the mass `Equipment`
  block, control mixing, the rotor `controlMap[]`, casual upright tail rotors and the guide's
  outputs Reference - all optional or no-ops for an aircraft that declares none. Re-vendor Core's
  headers in each, raise their stated minimum Core version, and check each still builds and
  flies (the AH-64D's tail is already upright, so casual is unchanged for it).
- [ ] **Rework the AH-64D and EC665 pedals the H-60's way.** Give each tail rotor a
  `controlMap[]` and a three-row (left / mid / right) lift and drag table, fitted with the rig
  (`python/dev/forces.py`, pointed at the pack with `BMKHS_CONFIG`): hover trim where the pilot
  should hold it, full pedal holding full collective, equal spare yaw both ways. Then
  flight-test the yaw rate. Both still use the old multi-row pedal tables.

## H-60

- [ ] **Flight director drives HeliSim's controls, not the airframe.** `uh60_fd` holds vertical
  speed, heading and pitch with `addForce` / `addTorque` on the aircraft
  (`fnc_verticalVelocity`, `fnc_hdg`, `fnc_achievePitch`), bypassing HeliSim's rotor and
  controls. Rework it to command HeliSim's control inputs, as a real autopilot moves the controls.
- [ ] **Ground handling outside HeliSim.** `uh60_ground` taxi and parking-brake hold
  (`fnc_taxiTick`, `fnc_pbHoldTick`) set the aircraft's velocity directly. Decide whether
  HeliSim owns ground handling (a Core item if so) and move it there.
- [ ] **MH-60S seats.** Its classes were not in the seat measurement, so they count pilots
  only.
- [ ] **Finish tuning the control mixing.** All mixes come from the rig
  (`python/dev/forces.py`) at 80% of full compensation, against the REALISTIC centre of mass
  {0, 1.605, 0.3} at 7671 kg: collective to yaw / roll / pitch, yaw to pitch, yaw to roll.
  Still open: CollectiveAirspeedToYaw (No.2 FCC) is 0 - not derived. Re-run the rig whenever the
  rotor tables or the centre of mass change.
- [ ] **Something opposes yaw in game.** A 100 kN.m yaw torque test (pedals centred, FMC on)
  reached 41 deg/s in 0.22 s, then collapsed to ~4 deg/s within a second with the torque still
  on, and swung back the other way when it was removed - a building, stateful counter-moment
  well over 100 kN.m that no logged Core output accounts for. It is why the tail rotor needs
  several times a real 60's thrust (and the roll and right-pedal sink that come with it).
  Next step: the same `[YAWDAMP]` test in the AH-64D, to tell a common cause from an H-60 one.