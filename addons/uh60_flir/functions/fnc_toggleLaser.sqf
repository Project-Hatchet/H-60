/*
 * Author: Ampersand
 * Toggle the laser designator
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_toggleLaser
 */

params ["_vehicle"];
private _pilot = driver _vehicle;
if (isNull _pilot) exitWith {
  systemChat "Cannot toggle laser if pilot seat is empty.";
  false
};

private _turretPath = [-1];
private _magazine = "Laserbatteries";

{
	_x params ["_xMagazine", "_xTurret", "_xAmmo", "_id", "_owner"];
	if (_xTurret isEqualTo _turretPath && {_xMagazine == _magazine}) exitWith {
		_vehicle action ["UseMagazine", _vehicle, _pilot, _owner, _id];
	};
} count magazinesAllTurrets _vehicle;

true
