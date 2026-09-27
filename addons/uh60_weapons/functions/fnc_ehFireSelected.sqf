#include "script_component.hpp"
/*
 * Author: Ampersand
 * Handle the Fire Selected Weapon event.
 * Run PFH to fire the weapon until the key is released.
 *
 * Arguments:
 * 0: Is Key Down <BOOLEAN>
 * 1: Vehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [true] call vtx_uh60_weapons_fnc_ehFireSelected
 */

#define FORCE_FIRE_TIMEOUT 10

params ["_isKeyDown", "_vehicle"];

vtx_uh60_weapons_isKeyUp = !_isKeyDown;

if (vtx_uh60_weapons_isKeyUp) exitWith {};

private _currentWeapon = currentWeapon _vehicle;
if !(
  _currentWeapon isKindOf ["MGunCore", configFile >> "CfgWeapons"] ||
  _currentWeapon isKindOf ["CannonCore", configFile >> "CfgWeapons"]
) exitWith {
  _vehicle fireAtTarget [objNull];
};

if (!isNil "vtx_uh60_weapons_fireSelectedPFH") exitWith {};

private _reloadTime = getNumber (configFile >> "CfgWeapons" >> _currentWeapon >> "_reloadTime");
vtx_uh60_weapons_fireSelectedPFH = [{
    params ["_args", "_pfhID"];
    _args params ["_vehicle", "_currentWeapon", "_endTime"];

    if (vtx_uh60_weapons_isKeyUp || {CBA_missionTime >= _endTime}) exitWith {
        [_pfhID] call CBA_fnc_removePerFrameHandler;
        vtx_uh60_weapons_fireSelectedPFH = nil;
    };

    _vehicle fireAtTarget [objNull];
}, _reloadTime, [_vehicle, _currentWeapon, CBA_missionTime + FORCE_FIRE_TIMEOUT]] call CBA_fnc_addPerFrameHandler;
