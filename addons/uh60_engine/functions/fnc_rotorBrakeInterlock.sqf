#include "defines.hpp"

/*
 * vtx_uh60_engine_fnc_rotorBrakeInterlock
 *
 * blocks the throttles from going over idle
 *
 * params (array)[(object) vehicle, (string) animation, (string) animationTarget]
 */
params ["_vehicle", "_animation", "_animationTarget", "_animationTargetLabel", "_animationSpeed", "_animStart", "_animEnd"];

// just stop if rotorbrake is up
if (ANIM("Lever_RotorBrake") < 0.5) exitWith {true};

private _locked = (_animationTarget > 0.5);
if (_locked) then {
    hint "throttle blocked by rotorbrake interlock";
};
// return true if not locked to allow lever to move
!_locked
