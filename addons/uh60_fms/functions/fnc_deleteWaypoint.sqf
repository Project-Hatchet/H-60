/*
 * vtx_uh60_fms_fnc_deleteWaypoint
 *
 * Delete a waypoint both in to the player's waypoint list and the MicroDAGR
 * params (array)[(object) player]
 */

params ["_player"];
private _microDagrWaypoints = [] call ace_microdagr_fnc_deviceGetWaypoints; 

_grp = group _player; 
_idx = currentWaypoint _grp; 
_desc = waypointDescription [_grp, _idx];

_pos = waypointPosition [_grp, _idx]; 
_pos resize 2; 

_currentwp = [_desc, _pos]; 
 
{ 
	if (_x # 0 == _desc) then {
		_dagrPos = _x # 1; 
		_dagrPos resize 2;
		if (_dagrPos isEqualTo _pos) exitWith {
			deleteWaypoint [_grp, _idx]; //Delete WP 
			_microDagrWaypoints deleteAt _forEachIndex; //Delete microDagr WP 
			[_player, "", _idx - 1] call vtx_uh60_fms_fnc_selectWaypoint; //Select new WP 
		};
	};
} forEach _microdagrWaypoints; 
 
ACE_player setVariable ["ace_microdagr_waypoints", _microDagrWaypoints];