params ["_vehicle", "_frameTime"];

if (vtx_uh60_flir_slewX == 0 && vtx_uh60_flir_slewY == 0) exitWith {};

private _target = (getPilotCameraTarget _vehicle) # 1;
private _vector = (getPosASL vtx_uh60_flir_camera) vectorFromTo _target;
private _polar = _vector call CBA_fnc_vect2Polar;
private _zoomRaw = ([0.5,0.5] distance2D  worldToScreen positionCameraToWorld [0,3,4]) 
* (getResolution select 5) / 2;
private _slewMod = vtx_uh60_flir_stabilizedSlewSpeed / _zoomRaw;
private _newDir = [
	(_polar # 1) + (vtx_uh60_flir_slewX * _slewMod),
	(_polar # 2) + (vtx_uh60_flir_slewY * _slewMod)
];


private _intersect = [(getPosASL vtx_uh60_flir_camera), _newDir # 0, _newDir # 1] call vtx_uh60_flir_fnc_intersectAtPolar;

if(vtx_uh60m_trackIR_interaction_systemChat) then {systemChat str _intersect;};
if (!isNil "_intersect") then {
	_vehicle setPilotCameraTarget _intersect;
};