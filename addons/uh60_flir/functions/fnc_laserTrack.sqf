#include "script_component.hpp"
params ["_vehicle"];
if (getUserMFDValue _vehicle select USERMFDV_LST_MODE == 2) then {
	_this call vtx_uh60_flir_fnc_autoScanPattern;
};

if (!local _vehicle) exitWith {};

private _laserCode = [_vehicle, "LST"] call vtx_uh60_weapons_fnc_getLaserCode;
private _origin = _vehicle selectionPosition "pilotcamera_flir_pos";
private _direction = getPilotCameraDirection _vehicle;
private _fov = 8;
private _laserResult = [
	_vehicle modelToWorldVisualWorld _origin,
	_vehicle vectorModelToWorldVisual _direction,
	20,
	10000,
	[1550,1550],
	_laserCode
] call ace_laser_fnc_seekerFindLaserSpot;
if (isNil "_laserResult" || {isNull (_laserResult # 1)}) exitWith {};
_vehicle setPilotCameraTarget (_laserResult # 0);
[[], (_laserResult # 0)] call vtx_uh60_flir_fnc_syncPilotCamera;

_vehicle setUserMFDValue [USERMFDV_LST_MODE, 0];
