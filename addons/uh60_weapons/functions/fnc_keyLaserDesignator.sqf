#include "..\script_component.hpp"
/*
 * Author: Perk
 * Handle the Fire Laser (designator) key, toggle or hold.
 *
 * Arguments:
 * 0: State <NUMBER> (optional, default -1)
 *    -1: toggle, 0: force off, 1: force on
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call vtx_uh60_weapons_fnc_keyLaserDesignator
 * [1] call vtx_uh60_weapons_fnc_keyLaserDesignator
 */

params [["_state", -1]];

IS_EITHER_PILOT;
IS_MASTER_ARM;

private _isOn = hct_vehicle getVariable ["vtx_uh60_weapons_laserDesignatorOn", false];
private _turnOn = if (_state == -1) then { !_isOn } else { _state == 1 };

if (_turnOn isEqualTo _isOn) exitWith {};

private _currentWeapon = currentWeapon hct_vehicle;
driver hct_vehicle forceWeaponFire ["Laserdesignator_pilotCamera", "Laserdesignator_pilotCamera"];
hct_vehicle selectWeapon _currentWeapon;

hct_vehicle setVariable ["vtx_uh60_weapons_laserDesignatorOn", _turnOn];
