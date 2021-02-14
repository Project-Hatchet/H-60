params ["_vehicle", "_frameTime"];
if (inputAction "vehLockTurretView" > 0 && !vtx_uh60_flir_stabilizing) then {
	systemChat str time;
	_this call vtx_uh60_flir_fnc_toggleStabilization;
};
if (vtx_uh60_flir_stabilized) then {
	private _vector = (getPosASL vtx_uh60_flir_camera) vectorFromTo (AGLtoASL vtx_uh60_flir_stabTarget);
	private _polar = _vector call CBA_fnc_vect2Polar;
	vtx_uh60_flir_camera setDir (_polar # 1);
	[vtx_uh60_flir_camera, _polar # 2, 0] call BIS_fnc_setPitchBank;
	drop ["\a3\data_f\Cl_basic","","Billboard",1,20,vtx_uh60_flir_stabTarget,[0,0,0],1,1.275,1.0,0.0,[1],[[1,0,0,1]],[0],0.0,2.0,"","",""];
};
vtx_uh60_flir_stabilizing = (inputAction "vehLockTurretView" > 0);
vtx_uh60_flir_camera camCommit 0;