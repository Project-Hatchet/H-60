params ["_vehicle"];
if (!vtx_uh60_flir_stabilized) then {
	systemChat "STAB ON";
	private _target = screenToWorld [0.5, 0.5];
	vtx_uh60_flir_stabTarget = _target;
	vtx_uh60_flir_stabilized = true;
} else {
	systemChat "STAB OFF";
	vtx_uh60_flir_stabilized = false;
};
vtx_uh60_flir_camera camCommit 0;