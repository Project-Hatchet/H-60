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
 * [true] call hct_h60_weapons_fnc_ehFireSelected
 */

#define FORCE_FIRE_TIMEOUT 10

params ["_isKeyDown", "_vehicle"];

hct_h60_weapons_isKeyUp = !_isKeyDown;

if (hct_h60_weapons_isKeyUp) exitWith {};

private _currentWeapon = currentWeapon _vehicle;
if !(
  _currentWeapon isKindOf ["MGunCore", configFile >> "CfgWeapons"] ||
  _currentWeapon isKindOf ["CannonCore", configFile >> "CfgWeapons"]
) exitWith {
  _vehicle fireAtTarget [objNull];
};

if (!isNil "hct_h60_weapons_fireSelectedPFH") exitWith {};

// Every frame on purpose: fireAtTarget only fires once the weapon is ready, so
// polling each frame keeps the full rate of fire. (This read a non-existent
// "_reloadTime" property, which is 0 - i.e. every frame. A real reloadTime delay
// would add up to a frame per shot, ~15% fewer rounds on the M230.) Runs only
// while the trigger is held, capped by FORCE_FIRE_TIMEOUT.
private _reloadTime = 0;
hct_h60_weapons_fireSelectedPFH = [{
    params ["_args", "_pfhID"];
    _args params ["_vehicle", "_currentWeapon", "_endTime"];

    if (hct_h60_weapons_isKeyUp || {CBA_missionTime >= _endTime}) exitWith {
        [_pfhID] call CBA_fnc_removePerFrameHandler;
        hct_h60_weapons_fireSelectedPFH = nil;
    };

    _vehicle fireAtTarget [objNull];
}, _reloadTime, [_vehicle, _currentWeapon, CBA_missionTime + FORCE_FIRE_TIMEOUT]] call CBA_fnc_addPerFrameHandler;
