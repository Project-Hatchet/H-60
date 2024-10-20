/**
 * Used to fire a weapon that is currently not selected, and then reset the selected weapon
 */

params ["_vehicle","_weapon","_fireMode"];
private _currentWeapon = currentWeapon _vehicle;
player forceWeaponFire [_weapon,_fireMode];
_vehicle selectWeapon _currentWeapon;