#include "script_component.hpp"
/*
 * hct_h60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
private _worldSize = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];

//private _centered = _vehicle ammoOnPylon 4 == 0;
private _centered = getUserMFDValue _vehicle select USERMFDV_TAC_CENTER == 0;
//private _fixed = _vehicle ammoOnPylon 7 == 0;
private _fixed = getUserMFDValue _vehicle select USERMFDV_TAC_MOVE == 0;
//private _selfAligned = _vehicle ammoOnPylon 5 == 0;
private _selfAligned = getUserMFDValue _vehicle select USERMFDV_TAC_ALIGN == 0;

private _rotation = if (_selfAligned) then {getDirVisual _vehicle} else {0};

private _center = if (_centered) then {
	getPosVisual _vehicle;
} else {
	private _cursorToMapRotated = [[0,_worldSize / _zoomLevel * 0.15], -(_rotation)] call BIS_fnc_rotateVector2D;
	getPosVisual _vehicle vectorAdd [_cursorToMapRotated # 0, _cursorToMapRotated # 1, 0];
};

private _movingCursor = (hct_h60_mfd_slewX != 0) || (hct_h60_mfd_slewY != 0);
//private _staticMap = _vehicle ammoOnPylon 7 > 0;
private _staticMap = getUserMFDValue _vehicle select USERMFDV_TAC_MOVE > 0;
private _cursorLimits = [0.1,0.9];


if (_staticMap) then {
	_center = hct_h60_mfd_tac_mapPos
};

if (!isNil "hct_h60_tac_hookedObject") then {
	private _position = switch (hct_h60_tac_hookedObject # 1) do {
		case "ground": {
			if (typeName (hct_h60_tac_hookedObject # 0) == "GROUP") then [{getPosVisual leader (hct_h60_tac_hookedObject # 0)}, {getPosVisual (hct_h60_tac_hookedObject # 0)}];
		};
		case "waypoint": {waypointPosition (hct_h60_tac_hookedObject # 0)};
		default {[-10000,0,0]};
	};

	hct_h60_mfd_tac_cursorPos = [_position] call hct_h60_mfd_fnc_tac_worldToCursor;
};

if (_movingCursor) then {
	hct_h60_tac_hookedObject = nil;
	if (_staticMap) then {
		private _movingHorizontal = (hct_h60_mfd_tac_cursorPos # 0 in _cursorLimits);
		private _moveVector = [0,0,0];
		if (_movingHorizontal) then {
			_moveVector = _moveVector vectorAdd [50 * (hct_h60_mfd_slewX / _zoomLevel),0,0];
		};
		private _movingVertical = 	(hct_h60_mfd_tac_cursorPos # 1 in _cursorLimits);
		if (_movingVertical) then {
			_moveVector = _moveVector vectorAdd [0,50 * (hct_h60_mfd_slewY / _zoomLevel),0];
		};
		if (_selfAligned) then {
			_moveVector = [_moveVector, -(getDirVisual _vehicle)] call BIS_fnc_rotateVector2D;
		};
		_center = _center vectorAdd _moveVector;

		hct_h60_mfd_tac_cursorPos = [
			((hct_h60_mfd_tac_cursorPos # 0) - (hct_h60_mfd_slewX * 0.010)) max (_cursorLimits # 0) min (_cursorLimits # 1),
			((hct_h60_mfd_tac_cursorPos # 1) + (hct_h60_mfd_slewY * 0.010)) max (_cursorLimits # 0) min (_cursorLimits # 1)
		];
		hct_h60_mfd_tac_mapPos = _center;
	} else {
		//[_vehicle, 7, 1] call hct_h60_mfd_fnc_setPylonValue;
    _vehicle setUserMFDValue [USERMFDV_TAC_MOVE, 1];
		hct_h60_mfd_tac_mapPos = getPos _vehicle;
	};
	[true] call hct_h60_mfd_fnc_tac_sync;
};

if (local _vehicle) then {
	// animateSource is global where the aircraft is local: only send a change
	// (deadband ~0.3 m of map / 0.05 deg), not three updates every frame
	private _map_anim_x = (_center # 0) / _worldSize;
	private _map_anim_y = (_center # 1) / _worldSize;
	if (abs ((_vehicle animationSourcePhase "MAP_X") - _map_anim_x) > 0.00001) then {
		_vehicle animateSource ["MAP_X", _map_anim_x, true];
	};
	if (abs ((_vehicle animationSourcePhase "MAP_Y") - _map_anim_y) > 0.00001) then {
		_vehicle animateSource ["MAP_Y", _map_anim_y, true];
	};
	private _rotation = if (_selfAligned) then {getDirVisual _vehicle} else {0};
	if (abs ((_vehicle animationSourcePhase "MAP_Rotation") - _rotation) > 0.05) then {
		_vehicle animateSource ["MAP_Rotation", _rotation, true];
	};
};

_vehicle setUserMFDvalue [29, hct_h60_mfd_tac_cursorPos # 0];
_vehicle setUserMFDvalue [30, hct_h60_mfd_tac_cursorPos # 1];



private _positionToMfd = {
	params ["_pos", "_i1", "_i2"];
	// private _direction = (_center getDir _pos) - _rotation;
	// _vehicle setUserMFDvalue [_i1, if(_direction < 0) then {_direction + 360} else {_direction}];
	// _vehicle setUserMFDvalue [_i2, ((_center distance2D _pos) * _zoomLevel) / (hct_h60_fms_mapSize / 2)];

	private _diff = _pos vectordiff _center;
	private _dir = getDir _vehicle; // the aircraft's heading (was the player's)
	private _rotated = [_diff, _dir] call BIS_fnc_rotateVector2D;
	_vehicle setUserMFDvalue [_i1, -1 * ((_rotated # 0) / (_worldSize/2)) * _zoomLevel];
	_vehicle setUserMFDvalue [_i2, (_rotated # 1)/ (_worldSize/2) * _zoomLevel];

};

[getPosVisual _vehicle, 27, 28] call _positionToMfd;
