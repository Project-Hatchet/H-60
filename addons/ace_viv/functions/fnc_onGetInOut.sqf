#include "script_component.hpp"
/*
 * Author: Ampersand
 * Enables or disables ViV cargo on GetIn/Out
 *
 * Arguments:
 * 0: Carrier <OBJECT>
 * 1: Role <STRING>
 * 2: Unit <OBJECT>
 * 3: Turret <ARRAT>
 *
 * Return Value:
 * Unit can configure the aircraft's pylons <BOOL>
 *
 * Example:
 * [_heli] call vtx_ace_viv_fnc_onGetInOut
 *
 * Public: No
 */

params ["_vehicle", "_role", "_unit", "_turret"];

private _enableViV = true;
private _seats = getArray (configOf _vehicle >> QGVAR(lockSeats));
{
    _x params ["_unit", "", "_cargoIndex", "_turretPath", "_isPersonTurret"];
    if (_turretPath isEqualTo [] && {_cargoIndex in _seats # 1}) then {_enableViV = false};
    if (_turretPath in _seats # 0) then {_enableViV = false};
} forEach fullCrew [_vehicle, ""];

private _cargoList = getVehicleCargo _vehicle;
if (!_enableViV && {!(_cargoList isEqualTo [])}) then {
    _vehicle enableVehicleCargo true;
    {
        objNull setVehicleCargo _x;
    } forEach _cargoList;
    _vehicle setVehicleCargo objNull;
};
if (_enableViV != vehicleCargoEnabled _vehicle) then {
    _vehicle enableVehicleCargo _enableViV;
};

setCustomSoundController [_vehicle, 'CustomSoundController9', ((1 - (_vehicle animationPhase 'cabindoor_L')) / 2 + (1 - (_vehicle animationPhase 'cabindoor_R'))) / 2];
setCustomSoundController [_vehicle, 'CustomSoundController8', _vehicle animationSourcePhase 'Cockpitdoors_Hide'];
