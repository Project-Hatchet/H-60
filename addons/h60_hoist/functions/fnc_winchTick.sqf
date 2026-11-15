#include "script_component.hpp"
/*
 * Author: Snow
 * One 10 Hz step of the rescue-hoist winch, on the helicopter's owner. Pays the
 * cable out (lower) or reels it in (raise) for as long as the hoist key is held,
 * then re-arms itself. Started by fnc_lowerHook / fnc_raiseHook; ends when the key
 * is released or the hook is reset.
 *
 * (Was a spawned while/sleep loop per direction - same cadence and order: check
 * the key, wind one step, wake the rope body, wait 0.1 s.)
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Direction: 1 lowers, -1 raises <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_heli, 1] call hct_h60_hoist_fnc_winchTick
 *
 * Public: No
 */

params ["_heli", "_direction"];

private _lowering = _direction > 0;
private _keyHeld = ["hct_h60_hoist_retracting", "hct_h60_hoist_extending"] select _lowering;
private _running = ["hct_h60_hoist_raiseLoopRunning", "hct_h60_hoist_lowerLoopRunning"] select _lowering;

if (isNull _heli) exitWith {};
private _hoist_vars = _heli getVariable ["hct_h60_hoist_vars", []];
if (!(_heli getVariable [_keyHeld, false]) || {_hoist_vars isEqualTo []}) exitWith {
    _heli setVariable [_running, false];
};
_hoist_vars params ["_rope", "_dummy"];

private _ropeLength = ropeLength _rope;
if (_lowering) then {
    private _speed = [MAX_HOIST_SPEED, NEAR_END_SPEED] select (MAX_ROPE_LENGTH - _ropeLength < NEAR_END_THRESHOLD); // slow near the cable end
    ropeUnwind [_rope, _speed, (_ropeLength + _speed * 0.3) min MAX_ROPE_LENGTH]; // target kept ahead of the winch so _speed governs
} else {
    private _speed = [MAX_HOIST_SPEED, NEAR_END_SPEED] select (_ropeLength < NEAR_END_THRESHOLD); // slow near the hook stop
    ropeUnwind [_rope, _speed, (_ropeLength - _speed * 0.3) max 0];
};
_dummy awake true; // the 10 Hz winch cadence lets the rope-end body fall asleep in PhysX

[FUNC(winchTick), [_heli, _direction], 0.1] call CBA_fnc_waitAndExecute;
