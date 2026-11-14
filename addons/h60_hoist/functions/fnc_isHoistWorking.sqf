/*
 * Author: Ampersand
 * check if heli's hoist is [un]winding rope
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_isHoistWorking
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

!(ropeUnwound _rope)

