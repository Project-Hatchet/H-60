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
_vehicle setUserMFDvalue [27, 1 - _coverage];

private _centerMode = _vehicle getVariable ["vtx_uh60_mfd_tac_center_mode", 0];
private _center = switch (_centerMode) do {
	case 0;
	case 1: {
		vtx_uh60_mfd_tac_cursorPos = [
			((vtx_uh60_mfd_tac_cursorPos # 0) - (vtx_uh60_mfd_slewX * 0.005)) max 0 min 1,
			((vtx_uh60_mfd_tac_cursorPos # 1) + (vtx_uh60_mfd_slewY * 0.005)) max 0 min 1
		];
		private _cursorToMap = [
			(0.5 - (vtx_uh60_mfd_tac_cursorPos # 0)) * _world_size * _coverage,
			(0.5 - (vtx_uh60_mfd_tac_cursorPos # 1)) * _world_size * _coverage * -1
		];
		private _cursorToMapRotated = [_cursorToMap, -(getDir _vehicle)] call BIS_fnc_rotateVector2D;
		vtx_uh60_mfd_tac_mapPos = getPos _vehicle vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];
		getPos _vehicle
	};
	case 2: {
		vtx_uh60_mfd_tac_cursorPos = [0.5,0.5];
		vtx_uh60_mfd_tac_mapPos = vtx_uh60_mfd_tac_mapPos vectorAdd [vtx_uh60_mfd_slewX * 100, vtx_uh60_mfd_slewY * 100, 0];
		vtx_uh60_mfd_tac_mapPos
	};
	case 3: {
		vtx_uh60_mfd_tac_cursorPos = [
			((vtx_uh60_mfd_tac_cursorPos # 0) - (vtx_uh60_mfd_slewX * 0.005)) max 0 min 1,
			((vtx_uh60_mfd_tac_cursorPos # 1) + (vtx_uh60_mfd_slewY * 0.005)) max 0 min 1
		];
		vtx_uh60_mfd_tac_mapPos
	};
};

if (local _vehicle) then {

    private _gridPosX = [_center # 0,0] call BIS_fnc_parseNumber;
    private _gridPosY = [_center # 1,0] call BIS_fnc_parseNumber;

    private _map_anim_x = (_gridPosX/_world_size);
    private _map_anim_y = (_gridPosY/_world_size);
    //systemChat str [_plannedPos distance (getPos _vehicle), vectorMagnitude (velocity _vehicle)];
    _vehicle animateSource ["MAP_X", _map_anim_x, 1];
    _vehicle animateSource ["MAP_Y", _map_anim_y, 1];
    private _rotation = if (_centerMode == 0) then {getDir _vehicle} else {0};
    _vehicle animateSource ["MAP_Rotation", _rotation, true];
};

if (_coverage < 0 || _coverage > 1) exitWith {_vehicle setUserMFDvalue [27, -1];};

_vehicle setUserMFDvalue [18, _centerMode];
_vehicle setUserMFDvalue [29, vtx_uh60_mfd_tac_cursorPos # 0];
_vehicle setUserMFDvalue [30, vtx_uh60_mfd_tac_cursorPos # 1];
