/*
 * vtx_uh60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

if (local _vehicle) then {
    private _plannedPos = (getPos _vehicle) vectorAdd (velocity _vehicle);

    private _world_size = [] call BIS_fnc_mapSize;
    private _gridPosX = [_plannedPos select 0,0] call BIS_fnc_parseNumber;
    private _gridPosY = [_plannedPos select 1,0] call BIS_fnc_parseNumber;

    private _map_anim_x = (_gridPosX/_world_size);
    private _map_anim_y = (_gridPosY/_world_size);
    //systemChat str [_plannedPos distance (getPos _vehicle), vectorMagnitude (velocity _vehicle)];
    _vehicle animateSource ["MAP_X", _map_anim_x, 1];
    _vehicle animateSource ["MAP_Y", _map_anim_y, 1];
    private _rotation = getDir _vehicle;
    _vehicle animateSource ["MAP_Rotation", _rotation, true];
};

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _coverage = (4000 * _zoomLevel) / ((_world_size / 2) * 1.49);
_vehicle setUserMFDvalue [27, 1 - _coverage];
if (_coverage < 0 || _coverage > 1) exitWith {_vehicle setUserMFDvalue [27, -1];};
