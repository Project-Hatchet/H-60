params ["_vehicle", "_frameTime"];

if (inputAction "lookCenter" > 0) then {
	_vehicle setPilotCameraRotation [0, 0];
};

(getPilotCameraRotation _vehicle) params ["_yawRad", "_pitchRad"];
private _pitch = deg _pitchRad; private _yaw = deg _yawRad;
if (vtx_uh60_flir_slewX != 0 || vtx_uh60_flir_slewY != 0) then {
	private _zoomRaw = ([0.5,0.5] distance2D  worldToScreen positionCameraToWorld [0,3,4]) 
	* (getResolution select 5) / 2;
	private _slewMod = vtx_uh60_flir_unstabilizedSlewSpeed / _zoomRaw;

	if (vtx_uh60_flir_slewX != 0) then {
		_yaw = (_yaw + (vtx_uh60_flir_slewX * _slewMod));
	};
	if (vtx_uh60_flir_slewY != 0) then {
		_pitch = _pitch + (vtx_uh60_flir_slewY * _slewMod);
	};
	_vehicle setPilotCameraRotation [rad _yaw, rad _pitch];
};

(_vehicle call BIS_fnc_getPitchBank) params ["_vehiclePitch"];
vtx_uh60_flir_camera setDir ((direction _vehicle) + _yaw);
[vtx_uh60_flir_camera, _vehiclePitch + _pitch, 0] call BIS_fnc_setPitchBank;