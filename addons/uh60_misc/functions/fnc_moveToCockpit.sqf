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
 * [vxf_vehicle] call vtx_uh60_misc_fnc_moveToCockpit
 */

params ["_vehicle"];

if (isNull (_vehicle turretUnit [0])) exitWith {
  player action ["moveToTurret", vxf_vehicle, [0]];
  true
};
if (isNull driver _vehicle) exitWith {
  player action ["moveToDriver", vxf_vehicle];
  true
};

false
