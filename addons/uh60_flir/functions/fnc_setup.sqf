/*
 * Author: Ampersand
 * Set variables for current seat
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * call vtx_uh60_flir_fnc_setup
 */

params ["_vehicle"];
if (!hasPilotCamera _vehicle) exitWith {false};
private _isNotInCockpit = [_vehicle] call vtx_uh60_flir_fnc_syncPilots;
if (_isNotInCockpit) exitWith {false};

vtx_uh60_flir_aspectRatio = getResolution # 4;
vtx_uh60_flir_featureCamera = "";
vtx_uh60_flir_pilotCameraTarget = getPilotCameraTarget _vehicle;

private _vehicleConfig = configOf _vehicle;
private _pilotCameraConfig = _vehicleConfig >> "pilotCamera";
if (!isClass _pilotCameraConfig) exitWith {false};

vtx_uh60_flir_controllable = getNumber (_pilotCameraConfig >> "controllable") == 1;
vtx_uh60_flir_minTurn = getNumber (_pilotCameraConfig >> "minTurn") / 180 * pi;
vtx_uh60_flir_maxTurn = getNumber (_pilotCameraConfig >> "maxTurn") / 180 * pi;
vtx_uh60_flir_minElev = getNumber (_pilotCameraConfig >> "minElev") / 180 * pi;
vtx_uh60_flir_maxElev = getNumber (_pilotCameraConfig >> "maxElev") / 180 * pi;

private _OpticsIn = _pilotCameraConfig >> "OpticsIn";
private _fovClasses = "true" configClasses _OpticsIn;
vtx_uh60_flir_OpticsInfo = createHashMapFromArray (_fovClasses apply {
	[
    getNumber (_x >> "initFov"),
		[
      getArray (_x >> "visionMode"),
  		getArray (_x >> "thermalMode"),
  		getText (_x >> "opticsDisplayName")
    ]
	]
});
vtx_uh60_flir_camFOVLevels = keys vtx_uh60_flir_OpticsInfo;
vtx_uh60_flir_camFOVLevels sort false; // Descending
vtx_uh60_flir_FOV = vtx_uh60_flir_camFOVLevels # 0;

vtx_uh60_flir_camPos = getPilotCameraPosition _vehicle;
private _dir = getPilotCameraDirection _vehicle;
vtx_uh60_flir_camDirAndUp = [
  _dir,
  _dir vectorCrossProduct (_dir vectorCrossProduct [0, 0, -1])
];

vtx_uh60_flir_isVisibleMap = visibleMap;
call vtx_uh60_flir_fnc_setIsPipHidden;

if (vtx_uh60_flir_playerIsPilot) then {
  if (productVersion # 2 >= 207) then {
    // https://community.bistudio.com/wiki/Arma_3:_Event_Handlers#VisionModeChanged
    _id = player addEventHandler ["VisionModeChanged", {
    	params ["", "_visionMode", "_TIindex"];
      if (cameraView == "GUNNER") then {
        [vtx_uh60_flir_visionModesHashMap get [_visionMode, _TIindex]] call vtx_uh60_flir_fnc_setVisionMode;
      };
    }];
    vtx_uh60_flir_playerEHs pushBack ["VisionModeChanged", _id];
  } else {
    _id = ["visionMode", {
      params ["_unit", "_newvVsionMode", "_oldVisionMode"];
      if (cameraView == "GUNNER") then {
        // Sync Vision Mode
        [vtx_uh60_flir_visionModesHashMap get [_newvVsionMode, [-1, 0] select (_newvVsionMode > 1)]] call vtx_uh60_flir_fnc_setVisionMode;
      };
    }] call CBA_fnc_addPlayerEventHandler;
    vtx_uh60_flir_playerCBAEHs pushBack ["visionMode", _id];
  };
};

// track SACLOS
_id = _vehicle addEventHandler ["Fired", {
	//params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
	params ["", "", "", "", "_ammo", "", "_projectile"];
	if (cameraView != "GUNNER" && {getNumber (configFile >> "CfgAmmo" >> _ammo >> "manualControl") == 1}) then {
		[{
			params ["_projectile", "_pfhID"];
			private _pos = screenToWorld [0.5, 0.5];
			if (_pos distance positionCameraToWorld [0, 0, 0] > 5000) then {
				_pos = positionCameraToWorld [0, 0, 5000];
			};
			_projectile setMissileTargetPos _pos;
			if (!alive _projectile) then {
				[_pfhID] call CBA_fnc_removePerFrameHandler;
			};
		}, 0, _projectile] call CBA_fnc_addPerFrameHandler;
	};
}];
vtx_uh60_flir_vehicleEHs pushBack ["Fired", _id];

//params ["_unit", "_newView", "_oldView"]; // "GUNNER", "INTERNAL", "EXTERNAL"
_id = ["cameraView", {
  params ["_unit", "_newView", "_oldView"];
  call vtx_uh60_flir_fnc_setIsPipHidden;
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerCBAEHs pushBack ["cameraView", _id];

//params ["_unit", "_featureCamera"]; // "", "curator", "splendid", "nexus"
_id = ["featureCamera", {
  params ["", "_featureCamera"];
  vtx_uh60_flir_featureCamera = _featureCamera;
  call vtx_uh60_flir_fnc_setIsPipHidden;
  // Fix pip black screen
  if (_featureCamera == "" && {call vtx_uh60_mfd_fnc_isAnyFlirOpened}) then {
    call vtx_uh60_flir_fnc_pipStart;
  };
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerCBAEHs pushBack ["featureCamera", _id];

//params ["_unit", "_isVisibleMap"]; // true, false
_id = ["visibleMap", {
  params ["", "_isVisibleMap"];
  vtx_uh60_flir_isVisibleMap = _isVisibleMap;
  call vtx_uh60_flir_fnc_setIsPipHidden;
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerCBAEHs pushBack ["visibleMap", _id];

true
