_getHookableObjects = {
	private _hookableObjects = getSensorTargets vehicle player;
};

_getObjectPosition = {
	switch (_this # 1) do {
		case "ground": {
			if (typeName (_this # 0) == "GROUP") then [{getPos leader (_this # 0)}, {getPos (_this # 0)}];
		};
		case "waypoint": {waypointPosition (_this # 0)};
		default {[-10000,0,0]};
	};
};

params ["_vehicle"];

if (_vehicle ammoOnPylon 7 == 0) exitWith {};

private _group = group player;
private _waypointIdx = currentWaypoint _group;
private _waypoints = (waypoints _group) select [_waypointIdx, 6];
private _fixedWaypoints = _waypoints apply {[_x, "waypoint"]};
private _hookableObjects = (getSensorTargets _vehicle) + _fixedWaypoints;
if (!isNil "cTabBFTmembers") then {
	_hookableObjects = _hookableObjects + (cTabBFTgroups apply {[group (_x # 0), "ground", "friendly"]});
};

// _hookableObjects
private _cursorPos = [] call vtx_uh60_mfd_fnc_tac_cursorToWorld;
private _nearestObject = nil;
{
	if (isNil "_nearestObject") then {
		_nearestObject = _x;
		continue;
	};
	private _nearestPosition = _nearestObject call _getObjectPosition;
	private _position = _x call _getObjectPosition;
	if (_cursorPos distance2D _nearestPosition > _cursorPos distance2D _position) then {
		_nearestObject = _x;
	};
} forEach _hookableObjects;

if (isNil "_nearestObject") exitWith {
	[_vehicle, 7, 1] call vtx_uh60_mfd_fnc_setPylonValue;
};
if (_cursorPos distance2D (_nearestObject call _getObjectPosition) > 500) exitWith {
	[_vehicle, 7, 1] call vtx_uh60_mfd_fnc_setPylonValue;
};
private _hookInfo = _nearestObject call vtx_uh60_mfd_fnc_tac_getHookInfo;
_vehicle setUserMFDText [45, _hookInfo # 0];
_vehicle setUserMFDText [46, _hookInfo # 1];
_vehicle setUserMFDText [47, _hookInfo # 2];
_vehicle setUserMFDText [48, _hookInfo # 3];
[_vehicle, 7, 2] call vtx_uh60_mfd_fnc_setPylonValue;
