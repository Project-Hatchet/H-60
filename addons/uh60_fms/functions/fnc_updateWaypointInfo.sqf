/*
 * vtx_uh60_fms_fnc_updateWaypointInfo
 *
 * processes waypoint info
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

private _wayPoint = [group player, currentWaypoint group player];
private _position = waypointPosition _wayPoint;
if ((count customWaypointPosition) > 0) then {
    _position = customWaypointPosition;
    _vehicle setUserMFDText [7, "MAP MARK"];
} else {
    _vehicle setUserMFDText [7, waypointDescription _wayPoint];
};

private _centerMode = _vehicle getVariable ["vtx_uh60_mfd_tac_center_mode", 0];
private _center = switch (_centerMode) do {
    case 0: {getPos _vehicle};
    case 1: {getPos _vehicle};
    case 2: {vtx_uh60_mfd_tac_mapPos};
    case 3: {vtx_uh60_mfd_tac_mapPos};
};
private _startDir = if (_centerMode == 0) then {getDir _vehicle} else {0};

private _waypointDirection = (_center getDir _position) - _startDir;
_vehicle setUserMFDvalue [0, _waypointDirection];
_vehicle setUserMFDvalue [1, _center distance2D _position];

private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private ["_waypointPosition"];
{
    _waypointPosition = waypointPosition [group player, (currentWaypoint group player) + _forEachIndex - 1];
    if (!(_waypointPosition isEqualTo [0,0,0])) then {
        private _direction = (_center getDir _waypointPosition) - _startDir;
        _vehicle setUserMFDvalue [_x # 0, if(_direction < 0) then {_direction + 360} else {_direction}];
        _vehicle setUserMFDvalue [_x # 1, ((_center distance2D _waypointPosition) * _zoomLevel) / (vtx_uh60_fms_mapSize / 2)];
    } else {
        _vehicle setUserMFDvalue [_x # 0, -1];
        _vehicle setUserMFDvalue [_x # 1, -1];
    };
} forEach [[2,3],[4,5],[6,7],[8,9],[33,34],[35,36]];

if ((getPilotCameraTarget _vehicle) # 0) then {
    private _target = (getPilotCameraTarget _vehicle) # 1;
    private _direction = (_center getDir _target) - _startDir;
    _vehicle setUserMFDvalue [10, if(_direction < 0) then {_direction + 360} else {_direction}];
    _vehicle setUserMFDvalue [11, ((_center distance2D _target) * _zoomLevel) / (vtx_uh60_fms_mapSize / 2)];
} else {
    _vehicle setUserMFDvalue [10,-1];
    _vehicle setUserMFDvalue [11,-1];
};

if (!isNil "vtx_uh60_fms_nearestLocation") then {
    private _direction = (_center getDir (getPos vtx_uh60_fms_nearestLocation)) - _startDir;
    _vehicle setUserMFDvalue [41, if(_direction < 0) then {_direction + 360} else {_direction}];
    _vehicle setUserMFDvalue [42, ((_center distance2D (getPos vtx_uh60_fms_nearestLocation)) * _zoomLevel) / (vtx_uh60_fms_mapSize / 2)];
} else {
    _vehicle setUserMFDvalue [41,-1];
    _vehicle setUserMFDvalue [42,-1];
};

if (speed _vehicle > 2) then {
    private _speedMS = vectorMagnitude (velocity _vehicle);
    private _tofSecondsTotal = (_position distance _vehicle) / _speedMS;
    private _tofHours = floor (_tofSecondsTotal / 60 / 60);
    private _tofMinutes = floor (_tofSecondsTotal / 60 % 60);
    private _tofSeconds = round (_tofSecondsTotal % 60);
    private _tofStr = format["%1:%2:%3",_tofHours, _tofMinutes, _tofSeconds];
    _vehicle setUserMFDText [8, _tofStr];
};