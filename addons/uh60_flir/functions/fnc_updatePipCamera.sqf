
params ["_vehicle", "_frameTime"];
if (vtx_uh60_flir_stabilized) then {
	private _target = (getPilotCameraTarget _vehicle) # 1;
	private _vector = (getPosASL vtx_uh60_flir_pip_camera) vectorFromTo _target;

	_vehicle setPilotCameraDirection (_vehicle vectorWorldToModel ((getPosASL _vehicle) vectorFromTo _target));

	private _polar = _vector call CBA_fnc_vect2Polar;
	vtx_uh60_flir_pip_camera setDir (_polar # 1);
	[vtx_uh60_flir_pip_camera, _polar # 2, 0] call BIS_fnc_setPitchBank;
} else {
	(getPilotCameraRotation _vehicle) params ["_yawRad", "_pitchRad"];
	private _pitch = -(deg _pitchRad); private _yaw = -(deg _yawRad);
	(_vehicle call BIS_fnc_getPitchBank) params ["_vehiclePitch"];
	vtx_uh60_flir_pip_camera setDir ((direction _vehicle) + _yaw);
	[vtx_uh60_flir_pip_camera, _vehiclePitch + _pitch, 0] call BIS_fnc_setPitchBank;
};

vtx_uh60_flir_pip_camera camCommit 0;