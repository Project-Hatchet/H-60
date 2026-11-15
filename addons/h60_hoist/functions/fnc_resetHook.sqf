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
 * [_heli] call hct_h60_hoist_fnc_resetHook
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["hct_h60_hoist_fnc_resetHook", _heli]};

_heli animateSource ["hoist_hook_hide", 0];
(_heli getVariable ["hct_h60_hoist_vars", []]) params [
  ["_rope", objNull], ["_dummy", objNull], ["_hook", objNull]
];

if (!isNull _rope) then {ropeDestroy _rope};
if (!isNull _dummy) then {deleteVehicle _dummy};
if (!isNull _hook) then {
  {moveOut _x} count crew _hook;
  deleteVehicle _hook;
};
_heli setVariable ["hct_h60_hoist_vars", [], true];

// the deploy's RopeBreak handler (deployHook) goes with the rope
private _ropeBreakEH = _heli getVariable ["hct_h60_hoist_ropeBreakEH", -1];
if (_ropeBreakEH != -1) then {
  _heli removeEventHandler ["RopeBreak", _ropeBreakEH];
  _heli setVariable ["hct_h60_hoist_ropeBreakEH", -1];
};

true
