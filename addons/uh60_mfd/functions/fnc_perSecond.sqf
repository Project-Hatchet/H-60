/*
 * vtx_uh60_mfd_fnc_perSecond
 *
 * handles occasional updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

_vehicle setUserMFDText [9, str round ((vectorMagnitude wind) * 1.94384)];
private _stabAnim = _vehicle animationPhase "Stabilator_rotate";
private _stabAngle = ceil (80 - (_stabAnim * 1.1111111 + 13));
_vehicle setUserMFDText [11, str (_stabAngle min 40 max 0)];
if (local _vehicle && ((getPos _vehicle) distance vtx_uh60_map_lastPosition) > 0.5) then {
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
vtx_uh60_map_lastPosition = getPos _vehicle;

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _coverage = (4000 * _zoomLevel) / ((_world_size / 2) * 1.49);
_vehicle setUserMFDvalue [27, 1 - _coverage];
if (_coverage < 0 || _coverage > 1) exitWith {_vehicle setUserMFDvalue [27, -1];};
