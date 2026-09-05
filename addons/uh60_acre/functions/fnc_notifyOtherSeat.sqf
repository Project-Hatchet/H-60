#include "..\script_component.hpp"

params ["_vehicle"];

private _otherUnit = if (player == driver _vehicle) then {
  _vehicle turretUnit [0]
} else {
  driver _vehicle
};

if (isNull _otherUnit) exitWith {};

[QGVAR(radioUpdated), [_vehicle], _otherUnit] call CBA_fnc_targetEvent;
