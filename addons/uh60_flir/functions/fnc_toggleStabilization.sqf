params ["_vehicle"];
if (!vtx_uh60_flir_stabilized) then {
	systemChat "STAB ON";
	private _target = screenToWorld [0.5, 0.5];
	_vehicle setPilotCameraTarget (AGLtoASL _target);
} else {
	systemChat "STAB OFF";
	vtx_uh60_flir_stabilized = false;
	_vehicle setPilotCameraTarget objNull;
};
vtx_uh60_flir_camera camCommit 0;