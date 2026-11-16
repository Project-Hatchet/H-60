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
 * [_vehicle] call hct_h60_flir_fnc_mfdWaypoint
 */

//if (hct_h60_flir_isPipHidden) exitWith {};

params ["_vehicle"];

if (!hct_h60_flir_controllable) exitWith {false};

[_vehicle, false] call hct_h60_mfd_fnc_slingCam;
hct_h60_flir_pipIsFixed = false;

if (customWaypointPosition isNotEqualTo []) exitWith {
  private _target = AGLToASL customWaypointPosition; // the sync below used an undefined _target
  _vehicle setPilotCameraTarget _target;
  [[], _target] call hct_h60_flir_fnc_syncPilotCamera;
  true
};

private _currentWaypointIndex = currentWaypoint group player;
private _waypoints = waypoints group player;

if (_currentWaypointIndex < count _waypoints) exitWith { // valid base game waypoint
  private _target = AGLToASL waypointPosition [group player, _currentWaypointIndex];
  _vehicle setPilotCameraTarget _target;
  [[], _target] call hct_h60_flir_fnc_syncPilotCamera;
  true
};

if (ace_microdagr_currentwaypoint > -1) exitWith {
  private _target = ((player getVariable ["ace_microdagr_waypoints", []]) param [ace_microdagr_currentwaypoint, []]) param [1, []];
  if (_target isEqualTo []) exitWith {false}; // the selected microDAGR waypoint is gone
  _vehicle setPilotCameraTarget _target;
  [[], _target] call hct_h60_flir_fnc_syncPilotCamera;
  true
};

false
