/*
 * Author: Ampersand
 * move unit from hook to heli
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_unit] call vtx_uh60_hoist_fnc_moveHookToHeli
 */

params [["_unit", objNull, [objNull]]];
if (isNull _unit) exitWith {false};
if !(local _unit) exitWith {[_unit] remoteExecCall ["vtx_uh60_hoist_fnc_moveHookToHeli", _unit]};

private _hook = objectParent _unit;
if (isNull _hook) exitWith {false};

private _heli = _hook getVariable ["vtx_uh60_hoist_heli", objNull];
if (isNull _heli) exitWith {false}; // `== objNull` is never true

_unit leaveVehicle _hook;
moveOut _unit;

[{
	params ["_unit"];
	isNull objectParent _unit
}, {
	params ["_unit", "_heli"];
    _unit assignAsCargo _heli;
    _unit moveInCargo _heli;
}, [_unit, _heli]] call CBA_fnc_waitUntilAndExecute;

true
