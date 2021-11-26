/*
 * Author: Ampersand
 * Lock pilot camera to custom waypoint (shift-click) or next waypoint
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_mfdWaypoint
 */

//if (vtx_uh60_flir_isPipHidden) exitWith {};

params ["_vehicle"];

if (!vtx_uh60_flir_controllable) exitWith {};

[
  false,
  vtx_uh60_flir_camPos,
  [[0, 1, 0], [0, 0, 1]],
  0.3,
  vtx_uh60_flir_pipEffect
] call vtx_uh60_flir_fnc_setFixedPIP;

if (customWaypointPosition isNotEqualTo []) exitWith {
  _vehicle setPilotCameraTarget AGLToASL customWaypointPosition;
  vtx_uh60_flir_isStabilized = true;
  true
};

private _index = currentWaypoint group player;
private _waypoints = waypoints group player;
if (ace_microdagr_currentwaypoint > -1) then {
  _vehicle setPilotCameraTarget ((player getVariable "ace_microdagr_waypoints") # ace_microdagr_currentwaypoint # 1);
  vtx_uh60_flir_isStabilized = true;
};

false
