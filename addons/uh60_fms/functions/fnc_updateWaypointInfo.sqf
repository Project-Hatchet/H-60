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

private _waypointDirection = _vehicle getDir _position;
_vehicle setUserMFDvalue [0, _waypointDirection];
_vehicle setUserMFDvalue [1, _vehicle distance2D _position];

private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private ["_waypointPosition"];
{
    _waypointPosition = waypointPosition [group player, (currentWaypoint group player) + _forEachIndex - 1];
    if (!(_waypointPosition isEqualTo [0,0,0])) then {
        _vehicle setUserMFDvalue [_x # 0, _vehicle getRelDir _waypointPosition];
        _vehicle setUserMFDvalue [_x # 1, ((_vehicle distance2D _waypointPosition) * _zoomLevel) / (vtx_uh60_fms_mapSize / 2)];
    } else {
        _vehicle setUserMFDvalue [_x # 0, -1];
        _vehicle setUserMFDvalue [_x # 1, -1];
    };
} forEach [[2,3],[4,5],[6,7],[8,9],[33,34],[35,36]];

if (!isNil "fms_markpoint") then {
    _vehicle setUserMFDvalue [10, _vehicle getRelDir (fms_markpoint # 1)];
    _vehicle setUserMFDvalue [11, ((_vehicle distance2D (fms_markpoint # 1)) * _zoomLevel) / (vtx_uh60_fms_mapSize / 2)];
    _vehicle setUserMFDText [10, (fms_markpoint # 0)];
} else {
    _vehicle setUserMFDvalue [10,-1];
    _vehicle setUserMFDvalue [11,-1];
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
