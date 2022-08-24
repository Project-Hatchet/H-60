params ["_vehicle"];

private _origin = _vehicle selectionPosition "pilotcamera_flir_pos";
private _direction = getPilotCameraDirection _vehicle;
private _laserCode = [_vehicle, "PRI CHAN"] call vtx_uh60_weapons_fnc_getLaserCode;
private _fov = vtx_uh60_flir_FOV;
private _laserResult = [
	_vehicle modelToWorldVisualWorld _origin,
	_vehicle vectorModelToWorldVisual _direction,
	20,
	10000,
	[1550,1550],
	_laserCode
] call ace_laser_fnc_seekerFindLaserSpot;

if (isNil "_laserResult") exitWith {[false, ((getPilotCameraTarget _vehicle) # 1)]};
if (isNull (_laserResult # 1)) exitWith {[false, ((getPilotCameraTarget _vehicle) # 1)]};
[true, _laserResult # 0]
