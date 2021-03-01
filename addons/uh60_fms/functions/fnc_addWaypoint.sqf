/*
 * vtx_uh60_fms_fnc_addWaypoint
 *
 * Insert a waypoint both in to the player's waypoint list and the MicroDAGR
 *
 * params (array)[(string) label, (vec3) location, (optional:string) description]
 */

params ["_label", "_location", "_description"];
 
private _microDagrWaypoints = [] call ace_microdagr_fnc_deviceGetWaypoints;
private _newWP = [_label, _location];
_microDagrWaypoints pushBack _newWP;
ACE_player setVariable ["ace_microdagr_waypoints", _microDagrWaypoints];

private _wp = group player addWaypoint [_newWP # 1, -1, (count waypoints group player), _newWP # 0];
_wp setWaypointDescription (_newWP # 0);
_wp setWaypointStatements ["false", ""];