/*
 * Author: Ampersand
 * Align the the pip camera to the pilotCamera and set fov
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_updateCamera
 */

params ["_heli"];
if (
    isNil "vtx_uh60_flir_camera" || {
    !(cameraView isEqualTo "INTERNAL") || {
    visibleMap || {
    !isNull curatorCamera}}}
) exitWith { false };

private _dir = getPilotCameraDirection _heli;
(getPilotCameraTarget _heli) params ["_stabilized", "_position", "_object"];
private _cameraPosition = getPilotCameraPosition _heli;
private _cameraPositionWorld = _heli modelToWorldVisualWorld _cameraPosition;
vtx_uh60_flir_camera setPosASL _cameraPositionWorld;
private _cameraDirection = _cameraPositionWorld vectorFromTo _position;
_dir = if (_stabilized) then [{_cameraDirection}, {_dir}];
if (!_stabilized && attachedTo vtx_uh60_flir_camera != _heli) then {
    vtx_uh60_flir_camera attachTo [_vehicle, (getpilotCameraPosition _vehicle)];
};
if (_stabilized && attachedTo vtx_uh60_flir_camera == _heli) then {
    detach vtx_uh60_flir_camera;
};
if (_stabilized && attachedTo vtx_uh60_flir_camera == _heli) then {
    detach vtx_uh60_flir_camera;
};

vtx_uh60_flir_camera setVectorDirAndUp [
    _dir,
    _dir vectorCrossProduct [-(_dir select 1), _dir select 0, 0]
];
vtx_uh60_flir_camera camSetFov vtx_uh60_flir_fov;
//vtx_uh60_flir_camera camCommit 0;

vtx_uh60_flir_camera setVectorDirAndUp [
    _dir,
    _dir vectorCrossProduct [-(_dir select 1), _dir select 0, 0]
];
vtx_uh60_flir_camera camSetFov vtx_uh60_flir_fov;
//vtx_uh60_flir_camera camCommit 0;

true
