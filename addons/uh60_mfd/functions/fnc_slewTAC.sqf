/*
 * vtx_uh60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"]; 
private _worldSize = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];

private _centered = _vehicle ammoOnPylon 4 == 0;
private _fixed = _vehicle ammoOnPylon 7 == 0;
private _selfAligned = _vehicle ammoOnPylon 5 == 0;
private _rotation = if (_selfAligned) then {getDir _vehicle} else {0};

private _center = if (_centered) then {
	getPos _vehicle;
} else {
	private _cursorToMapRotated = [[0,_worldSize / _zoomLevel * 0.15], -(_rotation)] call BIS_fnc_rotateVector2D;
	getPos _vehicle vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];
};

private _movingCursor = (vtx_uh60_mfd_slewX != 0) || (vtx_uh60_mfd_slewY != 0);
private _staticMap = _vehicle ammoOnPylon 7 > 0;
private _cursorLimits = [0.1,0.9];


if (_staticMap) then {
	_center = vtx_uh60_mfd_tac_mapPos
};

if (!isNil "vtx_uh60_tac_hookedObject") then {
	private _position = switch (vtx_uh60_tac_hookedObject # 1) do {
		case "ground": {
			if (typeName (vtx_uh60_tac_hookedObject # 0) == "GROUP") then [{getPos leader (vtx_uh60_tac_hookedObject # 0)}, {getPos (vtx_uh60_tac_hookedObject # 0)}];
		};
		case "waypoint": {waypointPosition (vtx_uh60_tac_hookedObject # 0)};
		default {[-10000,0,0]};
	};

	vtx_uh60_mfd_tac_cursorPos = [_position] call vtx_uh60_mfd_fnc_tac_worldToCursor;
};

if (_movingCursor) then {
	vtx_uh60_tac_hookedObject = nil;
	if (_staticMap) then {
		private _movingHorizontal = (vtx_uh60_mfd_tac_cursorPos # 0 in _cursorLimits);
		private _moveVector = [0,0,0];
		if (_movingHorizontal) then {
			_moveVector = _moveVector vectorAdd [50 * (vtx_uh60_mfd_slewX / _zoomLevel),0,0];
		};
		private _movingVertical = 	(vtx_uh60_mfd_tac_cursorPos # 1 in _cursorLimits);
		if (_movingVertical) then {
			_moveVector = _moveVector vectorAdd [0,50 * (vtx_uh60_mfd_slewY / _zoomLevel),0];
		};
		if (_selfAligned) then {
			_moveVector = [_moveVector, -(getDir _vehicle)] call BIS_fnc_rotateVector2D;
		};
		_center = _center vectorAdd _moveVector;

		vtx_uh60_mfd_tac_cursorPos = [
			((vtx_uh60_mfd_tac_cursorPos # 0) - (vtx_uh60_mfd_slewX * 0.010)) max (_cursorLimits # 0) min (_cursorLimits # 1),
			((vtx_uh60_mfd_tac_cursorPos # 1) + (vtx_uh60_mfd_slewY * 0.010)) max (_cursorLimits # 0) min (_cursorLimits # 1)
		];
		vtx_uh60_mfd_tac_mapPos = _center;
	} else {
		[_vehicle, 7, 1] call vtx_uh60_mfd_fnc_setPylonValue;
		vtx_uh60_mfd_tac_mapPos = getPos _vehicle;
	};
};

if (local _vehicle) then {
	private _gridPosX = [_center # 0,0] call BIS_fnc_parseNumber;
	private _gridPosY = [_center # 1,0] call BIS_fnc_parseNumber;

	private _map_anim_x = (_gridPosX/_worldSize);
	private _map_anim_y = (_gridPosY/_worldSize);

	_vehicle animateSource ["MAP_X", _map_anim_x, true];
	_vehicle animateSource ["MAP_Y", _map_anim_y, true];
	private _rotation = if (_selfAligned) then {getDir _vehicle} else {0};
	_vehicle animateSource ["MAP_Rotation", _rotation, true];
};

_vehicle setUserMFDvalue [29, vtx_uh60_mfd_tac_cursorPos # 0];
_vehicle setUserMFDvalue [30, vtx_uh60_mfd_tac_cursorPos # 1];



private _positionToMfd = {
	params ["_pos", "_i1", "_i2"];
	// private _direction = (_center getDir _pos) - _rotation;
	// _vehicle setUserMFDvalue [_i1, if(_direction < 0) then {_direction + 360} else {_direction}];
	// _vehicle setUserMFDvalue [_i2, ((_center distance2D _pos) * _zoomLevel) / (vtx_uh60_fms_mapSize / 2)];

	private _diff = _pos vectordiff _center;
	private _dir = direction player;
	private _rotated = [_diff, _dir] call BIS_fnc_rotateVector2D;
	_vehicle setUserMFDvalue [_i1, -1 * ((_rotated # 0) / (_worldSize/2)) * _zoomLevel];
	_vehicle setUserMFDvalue [_i2, (_rotated # 1)/ (_worldSize/2) * _zoomLevel];

};

[getPos _vehicle, 27, 28] call _positionToMfd;
