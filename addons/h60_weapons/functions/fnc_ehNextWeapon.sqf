#include "script_component.hpp"
/*
 * Author: Ampersand
 * Handle the Next Weapon event.
 * S
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle] call vtx_uh60_weapons_fnc_ehNextWeapon
 */

params ["_vehicle"];

vtx_uh60_weapons_isKeyUp = !_isKeyDown;

private _currentWeapon = currentWeapon _vehicle;

private _weapons = weapons _vehicle - ["CMFlareLauncher", "Laserdesignator_pilotCamera"];
private _currentWeaponIndex = _weapons find _currentWeapon;
private _nextWeaponIndex = _currentWeaponIndex + 1;
if (_nextWeaponIndex == count _weapons) then {
    _nextWeaponIndex = 0;
};

_vehicle selectWeapon (_weapons select _nextWeaponIndex);
