/*
 * Author: Ampersand
 * Stabilize helicopter's hoist hook
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_stabilizeHook
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_secureHook", _heli]};

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{};
_hoist_vars params ["_rope", "_dummy", "_hook"];

_dummy setDir (getDir _heli);

true
