/*
 * Author: Ampersand
 * Switch to the next weapon on the given turret of the given vehicle
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Turret <ARRAY>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_nextWeapon
 */

params ["_vehicle", ["_turret", [0]]];

private _weapon = _vehicle currentWeaponTurret _turret;
private _weapons = _vehicle weaponsTurret _turret;
_weapons pushBack (_weapons # 0);

private _found = false;
{
  if (_found) exitWith {
    _vehicle selectWeaponTurret [_x, _turret];
  };
	if (_weapon == _x) then {
    _found = true;
	};
} count _weapons;

true
