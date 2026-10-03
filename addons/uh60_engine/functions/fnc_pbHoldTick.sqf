/*
 * vtx_uh60_engine_fnc_pbHoldTick
 *
 * SFM parking-brake hold (MH-47G-proven template): owner-side tick; brake
 * lever SET + weight on wheels + slow -> horizontal velocity damped each
 * tick, so a parked ship stops creeping downhill on slopes. Deliberately
 * soft - stands down above 8 km/h so it never fights a takeoff or a
 * landing rollout. AFM/RTD untouched: there setBrakesRTD provides real
 * wheel brakes (fnc_wheelBrakes) and this chain refuses to run, so
 * HeliSim later needs no changes here.
 *
 * The lever animation is the single source of truth - hand click, brake
 * key and the AFM RotorLib event all converge on Handle_wheelbrake, and
 * this chain only ever reads its phase.
 *
 * Armed by fnc_pbArm from the engine perSecond loop, which is also what
 * re-arms it after an ownership transfer; setVelocity has local effect,
 * hence the owner gating.
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

// tuning knobs (one-time init; console-tunable live like the taxi set)
if (isNil "vtx_uh60_pbHoldMaxSlope") then {
    vtx_uh60_pbHoldDamp     = 0.15; // horizontal velocity multiplier per tick
    vtx_uh60_pbHoldMaxKmh   = 8;    // above this the hold stands down (takeoff/rollout)
    // TM 1-1520-280-10 5-28: slope landing limits are 15 deg upslope /
    // lateral, 6 deg nose-down. Undamped the hold gripped a 20 deg slope
    // (2026-09-08 test - stronger than the real gear); beyond this ground
    // angle the brakes lose and the ship slides, matching the book's
    // envelope edge with a small margin.
    vtx_uh60_pbHoldMaxSlope = 17;   // deg terrain slope: past this, no hold
};

if (isNull _vehicle || {!alive _vehicle} || {!local _vehicle}
    || {difficultyEnabledRTD && {isObjectRTD _vehicle}}) exitWith {
    _vehicle setVariable ["vtx_uh60_engine_pbHoldOn", false];
};
// per-tick gates just skip the damp (no chain churn on brake taps)
if ((_vehicle animationPhase "handle_wheelbrake") > 0.5
    && {isTouchingGround _vehicle} && {(speed _vehicle) < vtx_uh60_pbHoldMaxKmh}
    && {acos ((surfaceNormal (getPosASL _vehicle)) # 2) < vtx_uh60_pbHoldMaxSlope}) then {
    private _vel = velocity _vehicle;
    // horizontal exponential damp; vertical untouched so the suspension
    // settles instead of being pinned mid-droop
    _vehicle setVelocity [(_vel # 0) * vtx_uh60_pbHoldDamp, (_vel # 1) * vtx_uh60_pbHoldDamp, _vel # 2];
};
[vtx_uh60_engine_fnc_pbHoldTick, [_vehicle], 0.1] call CBA_fnc_waitAndExecute;
