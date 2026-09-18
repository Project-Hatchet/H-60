#include "script_component.hpp"
/*
 * Author: Perk
 * Mark a waypoint at wherever FLIR is currently designating (TDC). Numbers
 * count down from 99 so they don't collide with mission planned waypoints,
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * None
 *
 * Example:
 * call vtx_uh60_flir_fnc_keyTdcWaypointSet
 */

IS_EITHER_PILOT;

if (!vtx_uh60_flir_controllable) exitWith {};

getPilotCameraTarget hct_vehicle params ["_isTracking", "_tgtPosASL", ""];

private _trackedObj = vtx_uh60_flir_pilotCameraTarget param [2, objNull];
if (!isNull _trackedObj) then {
  _isTracking = true;
  _tgtPosASL = getPosASLVisual _trackedObj;
};

if (!_isTracking) exitWith {}; // nothing designated to mark

[str vtx_uh60_flir_tdcWaypointNum, ASLToAGL _tgtPosASL, ""] call vtx_uh60_fms_fnc_addWaypoint;

if (vtx_uh60_flir_tdcWaypointNum > 2) then {
  vtx_uh60_flir_tdcWaypointNum = vtx_uh60_flir_tdcWaypointNum - 1;
};
