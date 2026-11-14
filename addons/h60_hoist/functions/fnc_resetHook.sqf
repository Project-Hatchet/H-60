/*
 * Author: Ampersand
 * Reset hoist hook
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_resetHook
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_resetHook", _heli]};

_heli animateSource ["hoist_hook_hide", 0];
(_heli getVariable ["vtx_uh60_hoist_vars", []]) params [
  ["_rope", objNull], ["_dummy", objNull], ["_hook", objNull]
];

if (!isNull _rope) then {ropeDestroy _rope};
if (!isNull _dummy) then {deleteVehicle _dummy};
if (!isNull _hook) then {
  {moveOut _x} count crew _hook;
  deleteVehicle _hook;
};
_heli setVariable ["vtx_uh60_hoist_vars", [], true];

true
