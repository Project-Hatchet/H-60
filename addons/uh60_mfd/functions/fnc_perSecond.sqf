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

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _coverage = (4000 * _zoomLevel) / ((_world_size / 2) * 1.49);
_vehicle setUserMFDvalue [27, 1 - _coverage];
if (_coverage < 0 || _coverage > 1) exitWith {_vehicle setUserMFDvalue [27, -1];};
