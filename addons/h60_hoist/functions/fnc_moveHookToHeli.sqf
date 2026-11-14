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

params ["_unit"];
if !(local _unit) exitWith {[_unit] remoteExecCall ["vtx_uh60_hoist_fnc_moveHookToHeli", _unit]};

private _hook = vehicle _unit;
if (_hook == _unit) exitWith {false};

private _heli = _hook getVariable ["vtx_uh60_hoist_heli", objNull];
if (_heli == objNull) exitWith {false};

_unit leaveVehicle _hook;
moveOut _unit;

[{
	params ["_unit"];
	vehicle _unit == _unit
}, {
	params ["_unit", "_heli"];
    _unit assignAsCargo _heli;
    _unit moveInCargo _heli;
}, [_unit, _heli]] call CBA_fnc_waitUntilAndExecute;

true
