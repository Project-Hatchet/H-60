/*
 * Author: Ampersand
 * Fire the current weapon on the given turret of the given vehicle
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Turret Path <ARRAY>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_fireWeapon
 */

params ["_vehicle", ["_turretPath", [0]]];

weaponState [_vehicle, _turretPath] params ["_weapon", "", "", "_magazine", "_ammo"];

{
	_x params ["_xMagazine", "_xTurret", "_xAmmo", "_id", "_owner"];
	if (_xTurret isEqualTo _turretPath && {_xMagazine == _magazine}) exitWith {
		_vehicle action ["UseMagazine", _vehicle, player, _owner, _id];
	};
} count magazinesAllTurrets _vehicle;

true
