/*
 * Author: Ampersand
 * Move to a cabin seat
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [htf_vehicle] call vtx_uh60_misc_fnc_moveToCabin
 */

params ["_vehicle"];

private _allTurrets = allturrets [_vehicle, true];
_allTurrets deleteAt 0; // Remove copilot seat

scopeName "main";

{
  if (isNull (_vehicle turretUnit _x)) then {
    player action ["moveToTurret", htf_vehicle, _x];
    true breakOut "main";
  };
} count _allTurrets;

false
