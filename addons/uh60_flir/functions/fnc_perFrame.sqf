// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];
systemChat str _time;

private _left = ((inputAction "LookLeft") min 1) + ((inputAction "AimLeft") min 1);
private _right = ((inputAction "LookRight") min 1) + ((inputAction "AimRight") min 1);
private _up = ((inputAction "LookUp") min 1) + ((inputAction "AimUp") min 1);
private _down = ((inputAction "LookDown") min 1) + ((inputAction "AimDown") min 1);
private _wasSlewing = (vtx_uh60_flir_slewX > 0 || vtx_uh60_flir_slewY > 0);
vtx_uh60_flir_slewX = 0 - _left + _right;
vtx_uh60_flir_slewY = 0 - _down + _up;
private _isSlewing = (vtx_uh60_flir_slewX > 0 || vtx_uh60_flir_slewY > 0);
private _slewingStopped = (_wasSlewing && !_isSlewing)
private _isDriver = player == driver _vehicle;
private _isInCamera = ((_isDriver && cameraView == "GUNNER") || !isNil "vtx_uh60_flir_camera");

private _otherCrew = if (_isDriver) then [{
	private _copilotTurretIndex = [_vehicle] call ace_common_fnc_getTurretCopilot;
	(_vehicle turretUnit _copilotTurretIndex)
},{
	(driver _vehicle)
}];

vtx_uh60_flir_stabilized = (getPilotCameraTarget _vehicle) # 0;
// track laser if not slewing yourself and you're the copilot
if (isLaserOn _vehicle && !_isSlewing && !_isDriver && !_isInCamera) then {
	_vehicle setPilotCameraTarget (getPosASL (laserTarget _vehicle));
};

if (_isInCamera &&_((isSlewing && time > vtx_uh60_flir_lastSync + vtx_uh60_flir_syncInterval) || _slewingStopped)) then {
	vtx_uh60_flir_lastSync = time;
	private _target = if (vtx_uh60_flir_stabilized) then [{(getPilotCameraTarget _vehicle) # 1;}, {(getPilotCameraDirection _vehicle)}];
	if (!isNil "_otherCrew") then {
		[vtx_uh60_flir_stabilized, _target] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", _otherCrew];
	};
};
_this call vtx_uh60_flir_fnc_updateUIValues;

// copilot scripted FLIR controls
if (_isDriver) exitWith {
	if (inputAction "vehLockTurretView" > 0 && !vtx_uh60_flir_stabilizing) then {
		if (!isNil "_otherCrew") then {
			if (!vtx_uh60_flir_stabilized) then {
				[true, (AGLtoASL _target)] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", (driver _vehicle)];
			} else {
				[true, objNull] remoteExecCall ["vtx_uh60_flir_fnc_syncTurret", (driver _vehicle)];
			};
		};
	};
	vtx_uh60_flir_stabilizing = (inputAction "vehLockTurretView" > 0);
};

if (inputAction "pilotCamera" > 0 && !vtx_uh60_flir_enteringOptics) then {
	vtx_uh60_flir_enteringOptics = true;
	if (isNil "vtx_uh60_flir_camera") then {
		[vehicle player] call vtx_uh60_flir_fnc_startPilotCamera;
	} else {
		[vehicle player] call vtx_uh60_flir_fnc_stopPilotCamera;
	};
};
vtx_uh60_flir_enteringOptics = (inputAction "pilotCamera" > 0);

if (isNil "vtx_uh60_flir_camera") exitWith {};
_this call vtx_uh60_flir_fnc_handleMovement;
_this call vtx_uh60_flir_fnc_handleZoom;
_this call vtx_uh60_flir_fnc_handleVisionMode;