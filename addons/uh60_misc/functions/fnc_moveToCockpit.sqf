/*
 * Author: Ampersand
 * Move to a pilot seat
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [htf_vehicle] call vtx_uh60_misc_fnc_moveToCockpit
 */

params ["_vehicle"];

if (isNull (_vehicle turretUnit [0])) exitWith {
  player action ["moveToTurret", htf_vehicle, [0]];
  true
};
if (isNull driver _vehicle) exitWith {
  player action ["moveToDriver", htf_vehicle];
  true
};

false
