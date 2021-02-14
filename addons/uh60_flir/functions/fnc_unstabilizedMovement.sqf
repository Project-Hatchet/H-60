params ["_vehicle", "_frameTime"];

if (vtx_uh60_flir_slewX == 0 && vtx_uh60_flir_slewY == 0) exitWith {};

(vtx_uh60_flir_camera call BIS_fnc_getPitchBank) params ["_pitch"];
private _zoomRaw = ([0.5,0.5] distance2D  worldToScreen positionCameraToWorld [0,3,4]) 
* (getResolution select 5) / 2;
private _slewMod = vtx_uh60_flir_unstabilizedSlewSpeed / _zoomRaw;
if (vtx_uh60_flir_slewX != 0) then {
	vtx_uh60_flir_camera setDir ((getDir vtx_uh60_flir_camera) + (vtx_uh60_flir_slewX * _slewMod));
};
if (vtx_uh60_flir_slewY != 0) then {
	_pitch = _pitch + (vtx_uh60_flir_slewY * _slewMod);
};
[vtx_uh60_flir_camera, _pitch, 0] call BIS_fnc_setPitchBank;