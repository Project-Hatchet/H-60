/*
 * Author: Perk
 * Check if there is any cabin seat to move to following a fallback order presented - (door gun with a weapon
 * mounted, troop commander, or a cargo bench seat)
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [hct_vehicle] call vtx_uh60_misc_fnc_canMoveToCabin
 */

params ["_vehicle"];

private _allTurrets = allturrets [_vehicle, true];
_allTurrets deleteAt 0; // Remove copilot seat

0 < ({
  private _isDoorGunTurret = _x in [[1], [2]];
  !(_isDoorGunTurret && {(_vehicle weaponsTurret _x) isEqualTo []}) && {isNull (_vehicle turretUnit _x)}
} count _allTurrets)
