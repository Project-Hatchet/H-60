params ["_vehicle"];
if (!vtx_uh60_flir_stabilized) then {
	private _target = screenToWorld [0.5, 0.5];
	_vehicle setPilotCameraTarget (AGLtoASL _target);
	[true, (AGLtoASL _target)] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", (driver _vehicle)];
} else {
	vtx_uh60_flir_stabilized = false;
	_vehicle setPilotCameraTarget objNull;
	[true, objNull] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", (driver _vehicle)];
};
vtx_uh60_flir_camera camCommit 0;