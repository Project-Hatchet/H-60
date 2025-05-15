/**
 * Used to fire a weapon that is currently not selected, and then reset the selected weapon
 */

params ["_vehicle","_weapon","_fireMode"];

if !(typeOf _vehicle isKindOf "vtx_H60_base") exitWith {false};

private _currentWeapon = currentWeapon _vehicle;
if (_weapon == "MISSILE") then {
	[_vehicle] call vtx_uh60_weapons_fnc_commandFireMissile;
} else {
	driver _vehicle forceWeaponFire [_weapon,_fireMode];
};

_vehicle selectWeapon _currentWeapon;