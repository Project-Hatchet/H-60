/*
 * vtx_uh60_mfd_fnc_tac_getMapCenter;
 */
params ["_vehicle"];

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _centered = _vehicle ammoOnPylon 4 == 0;
private _selfAligned = _vehicle ammoOnPylon 5 == 0;
private _staticMap = _vehicle ammoOnPylon 7 > 0;
private _rotation = if (_selfAligned) then {getDir _vehicle} else {0};
private _center = if (_centered) then {
	getPos _vehicle;
} else {
	private _cursorToMapRotated = [[0,_world_size / _zoomLevel * 0.15], -(_rotation)] call BIS_fnc_rotateVector2D;
	getPos _vehicle vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];
};
if (_staticMap) then {
	_center = vtx_uh60_mfd_tac_mapPos
};

_center