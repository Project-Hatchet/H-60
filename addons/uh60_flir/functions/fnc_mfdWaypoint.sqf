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

if (!vtx_uh60_flir_controllable) exitWith {false};

[_vehicle, false] call vtx_uh60_mfd_fnc_slingCam;
vtx_uh60_flir_pipIsFixed = false;

if (customWaypointPosition isNotEqualTo []) exitWith {
  _vehicle setPilotCameraTarget AGLToASL customWaypointPosition;
  [[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;
  true
};

private _currentWaypointIndex = currentWaypoint group player;
private _waypoints = waypoints group player;

if (_currentWaypointIndex < count _waypoints) exitWith { // valid base game waypoint
  private _target = AGLToASL waypointPosition [group player, _currentWaypointIndex];
  _vehicle setPilotCameraTarget _target;
  [[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;
  true
};

if (ace_microdagr_currentwaypoint > -1) exitWith {
  _vehicle setPilotCameraTarget ((player getVariable "ace_microdagr_waypoints") # ace_microdagr_currentwaypoint # 1);
  [[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;
  true
};

false
