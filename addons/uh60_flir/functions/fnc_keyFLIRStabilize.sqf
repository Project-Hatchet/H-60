/*
 * Author: Ampersand
 * Lock FLIR to current aim pos or obj
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call vtx_uh60_flir_fnc_keyFLIRStabilize
 */
//vtx_uh60_flir_fnc_keyFLIRStabilize={

CHK_FLIR;
if (vtx_uh60_flir_playerIsPilot && {vtx_uh60_flir_isCopilotInGunnerView}) exitWith {false};

private _heli = vehicle player;
(getPilotCameraTarget _heli) params ["_isTracking", "_trackPos", "_trackObj"];

private _flirPos = AGLToASL (_heli modelToWorldVisual (getPilotCameraPosition _heli));
private _flirDir = _heli vectorModelToWorldVisual (getPilotCameraDirection _heli);
private _position1 = _flirPos vectorAdd (_flirDir vectorMultiply 5000);

private _intersections = lineIntersectsSurfaces [_flirPos, _position1, _heli];
private _target = objNull;
if !((_intersections # 0) isEqualTo []) then {
    (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
    if (_intersectObject isEqualTo objNull) then {
        _target = [_intersectPosASL, objNull] select _isTracking; // if already tracking position, untrack
    } else {
        _target = [_intersectObject, objNull] select (_trackObj == _intersectObject); // if already tracking same object, untrack
    };
};
_heli setPilotCameraTarget _target;
if (vtx_uh60_flir_playerIsCopilot && {vtx_uh60_flir_isCopilotInGunnerView}) then {
    _heli lockCameraTo [_target, [0]];
};
if !(_target isEqualTo objNull) then { [_target] call vtx_uh60_flir_fnc_syncAnimation; };
[[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;

true
