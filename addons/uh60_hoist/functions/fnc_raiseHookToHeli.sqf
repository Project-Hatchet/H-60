/*
 * Author: Ampersand
 * Take up helicopter's hoist cable to 0.5 m
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_raiseHookToHeli
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_raiseHookToHeli", _heli]};

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

_hoistPos = [1.405, 2.03, 0.45];
ropeUnwind [_rope, 1.5, 0.5];

true;
