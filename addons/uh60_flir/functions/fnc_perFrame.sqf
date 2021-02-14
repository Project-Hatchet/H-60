if (!isNil "test_fnc_perFrame") exitWith {_this call test_fnc_perFrame};

// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
params ["_vehicle", "_frameTime"];
if (isNil "vtx_uh60_flir_camera") exitWith {};
_this call vtx_uh60_flir_fnc_handleMovement;
_this call vtx_uh60_flir_fnc_handleZoom;
_this call vtx_uh60_flir_fnc_handleVisionMode;
_this call vtx_uh60_flir_fnc_updateUIValues;