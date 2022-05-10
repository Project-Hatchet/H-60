/*
 * vtx_uh60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */

//if (!isNil "test_fnc_slewTAC") exitWith {_this call test_fnc_slewTAC};

params ["_vehicle"]; 
private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _coverage = (4000 * _zoomLevel) / ((_world_size / 2) * 1.49);

private _centered = _vehicle ammoOnPylon 4 == 0;
private _fixed = _vehicle ammoOnPylon 7 == 0;
private _cursorToMapRotated = [[0,_world_size / _zoomLevel * 0.15], -(getDir _vehicle)] call BIS_fnc_rotateVector2D;
private _center = if (_centered) then {
	getPos _vehicle;
} else {
	getPos _vehicle vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];
};

private _movingCursor = (vtx_uh60_mfd_slewX != 0) || (vtx_uh60_mfd_slewY != 0);
private _staticMap = _vehicle ammoOnPylon 7 > 0;
private _cursorLimits = [0.1,0.9];

if (_staticMap) then {
	_center = _vehicle getVariable ["vtx_uh60_mfd_mapCenter", _center];
};
if (_movingCursor) then {
	if (_staticMap) then {
		private _movingHorizontal = (vtx_uh60_mfd_tac_cursorPos # 0 in _cursorLimits);
		if (_movingHorizontal) then {
			_center = _center vectorAdd [50 * (vtx_uh60_mfd_slewX / _zoomLevel),0,0];
		};
		private _movingVertical = 	(vtx_uh60_mfd_tac_cursorPos # 1 in _cursorLimits);
		if (_movingVertical) then {
			_center = _center vectorAdd [0,50 * (vtx_uh60_mfd_slewY / _zoomLevel),0];
		};

		vtx_uh60_mfd_tac_cursorPos = [
			((vtx_uh60_mfd_tac_cursorPos # 0) - (vtx_uh60_mfd_slewX * 0.010)) max (_cursorLimits # 0) min (_cursorLimits # 1),
			((vtx_uh60_mfd_tac_cursorPos # 1) + (vtx_uh60_mfd_slewY * 0.010)) max (_cursorLimits # 0) min (_cursorLimits # 1)
		];
		_vehicle setVariable ["vtx_uh60_mfd_mapCenter", _center];
	} else {
		[_vehicle, 7, 1] call vtx_uh60_mfd_fnc_setPylonValue;
		_vehicle setVariable ["vtx_uh60_mfd_mapCenter", getPos _vehicle];
	};
};

if (local _vehicle) then {
	private _gridPosX = [_center # 0,0] call BIS_fnc_parseNumber;
	private _gridPosY = [_center # 1,0] call BIS_fnc_parseNumber;

	private _map_anim_x = (_gridPosX/_world_size);
	private _map_anim_y = (_gridPosY/_world_size);

	_vehicle animateSource ["MAP_X", _map_anim_x, true];
	_vehicle animateSource ["MAP_Y", _map_anim_y, true];
	private _rotation = if (_fixed) then {getDir _vehicle} else {0};
	_vehicle animateSource ["MAP_Rotation", _rotation, true];
};

_vehicle setUserMFDvalue [29, vtx_uh60_mfd_tac_cursorPos # 0];
_vehicle setUserMFDvalue [30, vtx_uh60_mfd_tac_cursorPos # 1];
