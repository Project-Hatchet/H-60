/*
 * Author: Ampersand
 * Switch seats with the dead/unconscious pilot
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [] call vtx_uh60_fnc_switchTurret
 */

params ["_unit", "_vehicle", "_turret"];

moveOut _unit;

[{
  params ["_unit"];
  _unit == vehicle _unit
}, {
  [{
    params ["_unit", "_vehicle", "_turret"];
    _unit moveInTurret [_vehicle, _turret];
    _vehicle == vehicle _unit
  }, {
  systemChat "moved to turret";}, _this] call CBA_fnc_waitUntilAndExecute;
}, _this] call CBA_fnc_waitUntilAndExecute;
