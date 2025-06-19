#include "script_component.hpp"
/*
 * vtx_uh60_mfd_fnc_tac_getMapCenter;
 */
params ["_vehicle"];

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _centered = getUserMFDValue _vehicle select USERMFDV_TAC_CENTER == 0;
private _selfAligned = getUserMFDValue _vehicle select USERMFDV_TAC_ALIGN == 0;
private _staticMap = getUserMFDValue _vehicle select USERMFDV_TAC_MOVE > 0;

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
