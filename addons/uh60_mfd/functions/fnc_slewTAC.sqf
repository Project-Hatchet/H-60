/*
 * vtx_uh60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _coverage = (4000 * _zoomLevel) / ((_world_size / 2) * 1.49);

private _centerMode = 0;
private _cursorToMapRotated = [[0,_world_size / _zoomLevel * 0.15], -(getDir _vehicle)] call BIS_fnc_rotateVector2D;
private _center = getPos _vehicle vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];


if (local _vehicle) then {
	private _gridPosX = [_center # 0,0] call BIS_fnc_parseNumber;
	private _gridPosY = [_center # 1,0] call BIS_fnc_parseNumber;

	private _map_anim_x = (_gridPosX/_world_size);
	private _map_anim_y = (_gridPosY/_world_size);

	_vehicle animateSource ["MAP_X", _map_anim_x, 1];
	_vehicle animateSource ["MAP_Y", _map_anim_y, 1];
	private _rotation = if (_centerMode == 0) then {getDir _vehicle} else {0};
	_vehicle animateSource ["MAP_Rotation", _rotation, true];
};

_vehicle setUserMFDvalue [18, _centerMode];
_vehicle setUserMFDvalue [29, vtx_uh60_mfd_tac_cursorPos # 0];
_vehicle setUserMFDvalue [30, vtx_uh60_mfd_tac_cursorPos # 1];
