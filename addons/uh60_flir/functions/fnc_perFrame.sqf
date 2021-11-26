// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];

[] call vtx_uh60_flir_fnc_handleKeyInputs; // Zoom and Vision Mode
[_vehicle] call vtx_uh60_flir_fnc_handleSlew;
[_vehicle] call vtx_uh60_flir_fnc_updateCamera;

_this call vtx_uh60_flir_fnc_updateUIValues;
