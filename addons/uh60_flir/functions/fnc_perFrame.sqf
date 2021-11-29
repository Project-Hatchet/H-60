// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];

if (vtx_uh60_flir_setting_animateTurret && {local _vehicle}) then {
  [_vehicle] call vtx_uh60_flir_fnc_syncAnimation;
};
[] call vtx_uh60_flir_fnc_handleKeyInputs; // Zoom and Vision Mode
[_vehicle] call vtx_uh60_flir_fnc_handleSlew;
[_vehicle] call vtx_uh60_flir_fnc_updateCamera;

_this call vtx_uh60_flir_fnc_updateUIValues;
