/*
 * vtx_uh60_fms_fnc_selectWaypoint
 *
 * Selects a waypoint
 * if a name is provided, it searches by name, alternatively it searches by index
 *
 * params (array)[(object) player, (STRING) name, (NUMBER) index]
 */

params ["_player", ["_name", ""], ["_index", -1]];

private _group = group _player;
if (_name != "") exitWith {
	private _waypoints = waypoints _group;
	{
		if (waypointName _x == _name) exitWith {
			_group setCurrentWaypoint [_group, _forEachIndex];
		};
	} forEach _waypoints;
};

if ("_index" > -1) exitWith {
	_group setCurrentWaypoint [_group, _index];
};	