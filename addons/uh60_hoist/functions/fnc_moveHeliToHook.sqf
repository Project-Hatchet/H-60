/*
 * Author: Ampersand
 * move unit from heli to hook
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_unit] call vtx_uh60_hoist_fnc_moveHeliToHook
 */

params ["_unit"];
if !(local _unit) exitWith {[_unit] remoteExecCall ["vtx_uh60_hoist_fnc_moveHeliToHook", _unit]};

private _hoist_vars = vehicle player getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

moveOut _unit;
[{
  params ["_unit"];
  vehicle _unit == _unit
}, {
  params ["_unit", "_hook"];
  _unit moveInCargo _hook;
    [_unit, _hook] spawn vtx_uh60_hoist_fnc_attachHook;
}, [_unit, _hook]] call CBA_fnc_waitUntilAndExecute;

true
