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

params [["_unit", objNull, [objNull]]];
if (isNull _unit) exitWith {false};
if !(local _unit) exitWith {[_unit] remoteExecCall ["vtx_uh60_hoist_fnc_moveHeliToHook", _unit]};

// The unit's own helicopter: this runs where _unit is local, which is not
// necessarily the machine whose player started it (was `vehicle player`).
private _heli = objectParent _unit;
if (isNull _heli) exitWith {false};
private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

moveOut _unit;
[{
	params ["_unit"];
	isNull objectParent _unit
}, {
	params ["_unit", "_hook"];
	_unit moveInCargo _hook;
    // attachHook takes [hook, unit] (the arguments were swapped here)
    [_hook, _unit] call vtx_uh60_hoist_fnc_attachHook;
}, [_unit, _hook]] call CBA_fnc_waitUntilAndExecute;

true
