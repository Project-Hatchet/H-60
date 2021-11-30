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
 * [vxf_vehicle] call vtx_uh60_misc_fnc_switchPilot
 */

params ["_vehicle"];

private _pilot = driver _vehicle;
if (!isNull _pilot) then {
  private _turret = _vehicle unitTurret player;
  ["vtx_uh60_misc_switchTurret", [_pilot, _vehicle, _turret], _pilot] call CBA_fnc_targetEvent;
};

moveOut player;

[{
  params ["_unit"];
  _unit == vehicle _unit
}, {
  [{
    params ["_unit", "_vehicle"];
    _unit moveInDriver _vehicle;
    _vehicle == vehicle _unit
  }, {
  systemChat "moved to driver";}, _this] call CBA_fnc_waitUntilAndExecute;
}, [player, _vehicle]] call CBA_fnc_waitUntilAndExecute;
