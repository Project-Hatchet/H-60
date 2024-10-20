/*
 * vtx_uh60_mfd_fnc_tac_worldToCursor
 */
params ["_position"];
private _vehicle = vehicle player;
private _centered = _vehicle ammoOnPylon 4 == 0;
private _fixed = _vehicle ammoOnPylon 7 == 0;
private _selfAligned = _vehicle ammoOnPylon 5 == 0;
private _staticMap = _vehicle ammoOnPylon 7 > 0;

private _center = [_vehicle] call vtx_uh60_mfd_fnc_tac_getMapCenter;
private _rotation = if (_selfAligned) then {getDir _vehicle} else {0};

private _worldSize = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _mapScale = _worldSize / _zoomLevel;
private _vect = _center vectorDiff _position;
private _cursorToMapRotated = [_vect, _rotation] call BIS_fnc_rotateVector2D;
private _cursorPos = [
	((_cursorToMapRotated # 0) * 1) / _mapScale,
	-((_cursorToMapRotated # 1) * 4/3) / _mapScale
];
_cursorPos = _cursorPos vectorAdd [0.5, 0.5];
_cursorPos