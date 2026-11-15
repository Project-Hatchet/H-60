#include "..\script_component.hpp"
/*
 * hct_h60_acre_fnc_notifyOtherSeat
 *
 * Tells the other pilot's machine that this seat changed its ACRE radio setup, so the FMS radio pages stay in sync.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

private _otherUnit = if (player == driver _vehicle) then {
  _vehicle turretUnit [0]
} else {
  driver _vehicle
};

if (isNull _otherUnit) exitWith {};

[QGVAR(radioUpdated), [_vehicle], _otherUnit] call CBA_fnc_targetEvent;
