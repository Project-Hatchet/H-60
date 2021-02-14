params ["_vehicle", "_frameTime"];
(vtx_uh60_flir_camera call BIS_fnc_getPitchBank) params ["_pitch"];
private _currentFovIndex = ((_vehicle getVariable "vtx_flir_initFovMode") * 1.5 + 1);
private _slewMod = 0.25 / _currentFovIndex;
if (inputAction "AimLeft" > 0 || inputAction "AimRight" > 0) then {
	private _newDir = 0 - (inputAction "AimLeft") + (inputAction "AimRight");
	vtx_uh60_flir_camera setDir ((getDir vtx_uh60_flir_camera) + (_newDir * _slewMod));
};
if (inputAction "AimDown" > 0 || inputAction "AimUp" > 0) then {
	private _pitchChange = 0 - (inputAction "AimDown") + (inputAction "AimUp");
	_pitch = _pitch + (_pitchChange * _slewMod);
};
[vtx_uh60_flir_camera, _pitch, 0] call BIS_fnc_setPitchBank;