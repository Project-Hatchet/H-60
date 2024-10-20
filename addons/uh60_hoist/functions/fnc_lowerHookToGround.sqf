/*
 * Author: Ampersand
 * release hoist cable to ground level or max of 88 m
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_lowerHookToGround
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_lowerHookToGround", _heli]};

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

ropeUnwind [_rope, 1.7, 88 min (getPos _hook # 2)];

true
