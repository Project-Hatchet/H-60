/*
 * vtx_uh60_mfd_fnc_tac_cursorToWorld
 */

private _vehicle = vehicle player;
private _centered = _vehicle ammoOnPylon 4 == 0;
private _fixed = _vehicle ammoOnPylon 7 == 0;
private _selfAligned = _vehicle ammoOnPylon 5 == 0;
private _staticMap = _vehicle ammoOnPylon 7 > 0;
private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];

private _center = [_vehicle] call vtx_uh60_mfd_fnc_tac_getMapCenter;
private _rotation = if (_selfAligned) then {-getDir _vehicle} else {0};

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _cursorToMap = [
	(0.5 - (vtx_uh60_mfd_tac_cursorPos # 0)) * _world_size * (1/_zoomLevel),
	(0.5 - (vtx_uh60_mfd_tac_cursorPos # 1)) * _world_size * (1/_zoomLevel) * -(3/4)
];
private _cursorToMapRotated = [_cursorToMap, _rotation] call BIS_fnc_rotateVector2D;
private _cursorPos = _center vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];

_cursorPos set [2, getTerrainHeightASL _cursorPos];
_cursorPos