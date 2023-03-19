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
    /*
    // find cargo positions close to hook
    private _fullCrew = fullCrew [_heli, "", true];
    private _typeArray = ["vtx_UH60M"];
    private _typeIndex = _typeArray find typeOf _heli;

    // preferred cargo seats near the hook
    private _seatArray = [[3,4]];
    private _openSeats = _seatArray select {(_fullCrew select _x select 0) isEqualTo objNull};
    if !(_openSeats isEqualTo []) exitWith {_unit moveInCargo [_heli, _openSeats # 0]; true};

    // try to find any open cargo seat
    _openSeats = _fullCrew select {(_x select 0) isEqualTo objNull}
        _unit moveInCargo _heli;
    } else {
        _unit moveInCargo [_heli, ;
    };
    if (_typeIndex == -1) exitWith {_unit moveInCargo _heli;};
    if (_typeIndex == -1) exitWith {_unit moveInAny _heli;};
    */
}, [_unit, _heli]] call CBA_fnc_waitUntilAndExecute;

true
