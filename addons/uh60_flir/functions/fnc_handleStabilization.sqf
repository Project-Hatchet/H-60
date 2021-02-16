/*
 * vtx_uh60_flir_fnc_handleStabilization
 */
params ["_vehicle", "_frameTime"];
if (inputAction "vehLockTurretView" > 0 && !vtx_uh60_flir_stabilizing) then {
	_this call vtx_uh60_flir_fnc_toggleStabilization;
};
if (vtx_uh60_flir_stabilized) then {
	private _target = (getPilotCameraTarget _vehicle) # 1;
	private _vector = (getPosASL vtx_uh60_flir_camera) vectorFromTo _target;

	_vehicle setPilotCameraDirection (_vehicle vectorWorldToModel ((getPosASL _vehicle) vectorFromTo _target));

	private _polar = _vector call CBA_fnc_vect2Polar;
	vtx_uh60_flir_camera setDir (_polar # 1);
	[vtx_uh60_flir_camera, _polar # 2, 0] call BIS_fnc_setPitchBank;
};
vtx_uh60_flir_stabilizing = (inputAction "vehLockTurretView" > 0);
vtx_uh60_flir_camera camCommit 0;