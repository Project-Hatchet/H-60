params ["_vehicle", "_frameTime"];
private _memPoint = _vehicle getVariable "vtx_flir_mempoint";
private _vehicleCamPos = _vehicle modelToWorldVisual (_vehicle selectionPosition _memPoint);
vtx_uh60_flir_camera camSetPos _vehicleCamPos;
_this call vtx_uh60_flir_fnc_handleStabilization;
if (vtx_uh60_flir_stabilized) then {
	_this call vtx_uh60_flir_fnc_stabilizedMovement;
} else {
	_this call vtx_uh60_flir_fnc_unstabilizedMovement;
};
vtx_uh60_flir_camera camCommit 0;