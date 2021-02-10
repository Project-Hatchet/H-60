/*
 * Author: Ampersand
 * Secure helicopter's hoist hook
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_secureHook
 */
 
params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_secureHook", _heli]};

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{};
_hoist_vars params ["_rope", "_dummy", "_hook"];

detach _hook;
_hook setVariable ["vtx_uh60_hoist_heli", nil, true];
deleteVehicle _hook;
deleteVehicle _dummy;
ropeDestroy    _rope;
_heli animateSource ["hoist_hook_hide", 0];
_heli setVariable ["vtx_uh60_hoist_vars", [], true];

true
