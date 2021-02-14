// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
params ["_vehicle", "_frameTime"];


if (inputAction "pilotCamera" > 0 && !vtx_uh60_flir_enteringOptics) then {
	vtx_uh60_flir_enteringOptics = true;
	if (isNil "vtx_uh60_flir_camera") then {
		[vehicle player] call vtx_uh60_flir_fnc_startPilotCamera;
	} else {
		[vehicle player] call vtx_uh60_flir_fnc_stopPilotCamera;
	};
};

vtx_uh60_flir_enteringOptics = (inputAction "pilotCamera" > 0);


private _left = ((inputAction "LookLeft") min 1) + ((inputAction "AimLeft") min 1);
private _right = ((inputAction "LookRight") min 1) + ((inputAction "AimRight") min 1);
private _up = ((inputAction "LookUp") min 1) + ((inputAction "AimUp") min 1);
private _down = ((inputAction "LookDown") min 1) + ((inputAction "AimDown") min 1);
vtx_uh60_flir_slewX = 0 - _left + _right;
vtx_uh60_flir_slewY = 0 - _down + _up;


if (isNil "vtx_uh60_flir_camera") exitWith {};
_this call vtx_uh60_flir_fnc_handleMovement;
_this call vtx_uh60_flir_fnc_handleZoom;
_this call vtx_uh60_flir_fnc_handleVisionMode;
_this call vtx_uh60_flir_fnc_updateUIValues;