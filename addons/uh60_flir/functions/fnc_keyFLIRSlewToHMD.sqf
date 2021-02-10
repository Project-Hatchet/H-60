/*
 * Author: Ampersand
 * Lock FLIR to current aim pos or obj
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [] call vtx_uh60_flir_fnc_keyFLIRSlewToHMD
 */
//vtx_uh60_flir_fnc_keyFLIRSlewToHMD={

CHK_FLIR;

private _heli = vehicle player;
(getPilotCameraTarget _heli) params ["_isTracking", "_trackPos", "_trackObj"];

private _position0 = positionCameraToWorld [0, 0, 0];
private _position1 = positionCameraToWorld [0, 0, 5000];
private _intersections = lineIntersectsSurfaces [AGLToASL _position0, AGLToASL _position1, _heli];
private _target = objNull;
if !((_intersections # 0) isEqualTo []) then {
    (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
    if (_intersectObject isEqualTo objNull) then {
        _target = [_intersectPosASL, objNull] select _isTracking; // if already tracking position, untrack
    } else {
        _target = [_intersectObject, objNull] select (_trackObj == _intersectObject); // if already tracking same object, untrack
    };
    _heli setPilotCameraTarget _target;
    if !(_target isEqualTo objNull) then { [_target] call vtx_uh60_flir_fnc_syncAnimation; };
    [[], _target, true] call vtx_uh60_flir_fnc_syncPilotCamera;
};

true
