/*
 * vtx_uh60_fms_fnc_hasWaypoint
 *
 * Check if a waypoint exists by its name
 *
 * params (array)[(string) label, (vec3) location, (optional:string) description]
 */

params ["_name"];
 
private _group = group player;
private _hasWaypoint = false;
private _waypoints = waypoints _group;
{
	if (waypointName _x == _name) exitWith {
		_hasWaypoint = true;
	};
} forEach _waypoints;
_hasWaypoint