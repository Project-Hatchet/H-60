/*
 * vtx_uh60_engine_fnc_pbToggle
 *
 * Toggles the parking brake lever - the one entry point every input
 * converges on: the Armakeybinds "Parking Brake" bind, the SFM
 * HeliWheelsBrake watcher (fnc_pbKeyTick), and (under AFM) the RotorLib
 * action EH in fnc_setup all end up flipping the same lever, and the
 * lever's state is what the slope hold and taxi drive read.
 *
 * Direct animateSource (the fnc_setup RotorLib-EH pattern), NOT the
 * framework's scriptedInteract with a computed label - that path
 * double-actuated (suspected click-retry while the lever animation is
 * still traveling; flagged for the framework conversation).
 *
 * animateSource where the vehicle is local = global effect; a pilot who
 * doesn't own the airframe (rare MP case) is a no-op for now.
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];
if (isNull _vehicle || {!alive _vehicle} || {!local _vehicle}) exitWith {};
private _new = [1, 0] select ((_vehicle animationPhase "handle_wheelbrake") > 0.5);
_vehicle animateSource ["Handle_wheelbrake", _new, true];
[_vehicle, true, ["OFF", "ON"] select (_new > 0.5)] call vtx_uh60_engine_fnc_wheelBrakes;
