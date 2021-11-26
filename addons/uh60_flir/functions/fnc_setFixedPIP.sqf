/*
 * Author: Ampersand
 * Align the pip camera and sync to other pilot
 *
 * Arguments:
 * 0: Is Fixed <BOOLEAN>
 * 1: Position <OBJECT>
 * 2: Dir and Up <ARRAY> [ARRAY, ARRAY]
 * 3: FOV <NUMBER>
 * 4: Effect <NUMBER>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [true, vtx_uh60_flir_camPos, getPilotCameraDirection _vehicle, 0.3, [0]] call vtx_uh60_flir_fnc_setFixedPIP
 */

params [["_isFixed", false], ["_pos", vtx_uh60_flir_camPos], ["_dirAndUp", vtx_uh60_flir_camDirAndUp], "_fov", "_effect", ["_sync", true]];

vtx_uh60_flir_isStabilized = false;
vtx_uh60_flir_pipIsFixed = _isFixed;
if (_isFixed) then {
  vtx_uh60_flir_camera attachTo [vxf_vehicle, _pos];
  vtx_uh60_flir_camera setVectorDirAndUp _dirAndUp;
} else {
  detach vtx_uh60_flir_camera;
};
if (!isNil "_fov") then {
  vtx_uh60_flir_FOV = _fov;
  vtx_uh60_flir_camera camSetFov _fov;
};
if (!isNil "_effect") then {
  vtx_uh60_flir_pipEffect = _effect;
  "vtx_uh60_flir_feed" setPiPEffect [_effect];
};

if (_sync && {vtx_uh60_flir_otherPilotIsPlayer}) then {
  ["vtx_uh60_flir_syncFixedPIP", _this, [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
};

true
