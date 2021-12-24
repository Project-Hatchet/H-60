// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];

if (!vtx_uh60_flir_isPipHidden || {vtx_uh60_flir_isInScriptedCamera} || {vtx_uh60_flir_playerIsPilot && cameraView == "GUNNER"}) then {
  [_vehicle] call vtx_uh60_flir_fnc_handleKeyInputs;
  [_vehicle] call vtx_uh60_flir_fnc_handleSlew;
};

if (vtx_uh60_flir_isPipHidden && {!vtx_uh60_flir_isInScriptedCamera}) exitWith {};

[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
_this call vtx_uh60_flir_fnc_updateUIValues;
