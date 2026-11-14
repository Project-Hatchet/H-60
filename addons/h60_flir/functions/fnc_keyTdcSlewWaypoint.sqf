#include "script_component.hpp"
/*
 * Author: Perk
 * Slew FLIR to the current group waypoint same as the FLIR page's
 * "Slew To Waypoint" button.
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * None
 *
 * Example:
 * call vtx_uh60_flir_fnc_keyTdcSlewWaypoint
 */

IS_EITHER_PILOT;

if (!vtx_uh60_flir_controllable) exitWith {};

private _currentWaypointIndex = currentWaypoint group player;
private _waypoints = waypoints group player;

if (_currentWaypointIndex >= count _waypoints) exitWith {}; // no valid waypoint

private _target = AGLToASL waypointPosition [group player, _currentWaypointIndex];
hct_vehicle setPilotCameraTarget _target;
[[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;
