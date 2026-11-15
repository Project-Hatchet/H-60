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
 * call hct_h60_flir_fnc_setup
 */

params ["_vehicle"];
if (!hasPilotCamera _vehicle) exitWith {false};
private _isNotInCockpit = [_vehicle] call hct_h60_flir_fnc_syncPilots;
if (_isNotInCockpit) exitWith {false};

[{hct_player action ["TurnIn", hct_vehicle];}] call CBA_fnc_execNextFrame;
// Created once per client and reused: they were re-created on every seat entry
// and never destroyed.
if (isNil "hct_h60_flir_blackColor") then {
  hct_h60_flir_blackColor = ppEffectCreate ["colorCorrections",2001];
};
hct_h60_flir_blackColor ppEffectAdjust [0, 1.0, 0.0, [0, 0, 0, 0.75], [1, 1.0, 1.0, 1.0], [0, 0, 0, 0.0]];
hct_h60_flir_blackColor ppEffectCommit 0;

if (isNil "hct_h60_flir_grainEffect") then {
  hct_h60_flir_grainEffect = ppEffectCreate ["FilmGrain",2000];
};
hct_h60_flir_grainEffect ppEffectAdjust [1,0,1,1,1,false];
hct_h60_flir_grainEffect ppEffectCommit 0;

hct_h60_flir_aspectRatio = getResolution # 4;
hct_h60_flir_featureCamera = "";
hct_h60_flir_pilotCameraTarget = getPilotCameraTarget _vehicle;

private _vehicleConfig = configOf _vehicle;
private _pilotCameraConfig = _vehicleConfig >> "pilotCamera";
if (!isClass _pilotCameraConfig) exitWith {false};

hct_h60_flir_controllable = getNumber (_pilotCameraConfig >> "controllable") == 1;
hct_h60_flir_minTurn = getNumber (_pilotCameraConfig >> "minTurn") / 180 * pi;
hct_h60_flir_maxTurn = getNumber (_pilotCameraConfig >> "maxTurn") / 180 * pi;
hct_h60_flir_minElev = getNumber (_pilotCameraConfig >> "minElev") / 180 * pi;
hct_h60_flir_maxElev = getNumber (_pilotCameraConfig >> "maxElev") / 180 * pi;

_vehicle setVariable ["hct_h60_flir_targets", _vehicle getVariable ["hct_h60_flir_targets", 0]];
_vehicle setVariable ["hct_h60_flir_stowed", _vehicle getVariable ["hct_h60_flir_stowed", true], true];

private _OpticsIn = _pilotCameraConfig >> "OpticsIn";
private _fovClasses = "true" configClasses _OpticsIn;
hct_h60_flir_OpticsInfo = createHashMapFromArray (_fovClasses apply {
	[
    getNumber (_x >> "initFov"),
		[
      getArray (_x >> "visionMode"),
  		getArray (_x >> "thermalMode"),
  		getText (_x >> "opticsDisplayName")
    ]
	]
});
hct_h60_flir_camFOVLevels = keys hct_h60_flir_OpticsInfo;
hct_h60_flir_camFOVLevels sort false; // Descending
hct_h60_flir_FOV = hct_h60_flir_camFOVLevels # 0;

hct_h60_flir_camPos = getPilotCameraPosition _vehicle;
private _dir = getPilotCameraDirection _vehicle;
hct_h60_flir_camDirAndUp = [
  _dir,
  _dir vectorCrossProduct (_dir vectorCrossProduct [0, 0, -1])
];

hct_h60_flir_isVisibleMap = visibleMap;
call hct_h60_flir_fnc_setIsPipHidden;

if (hct_h60_flir_playerIsPilot) then {
  if (productVersion # 2 >= 207) then {
    // https://community.bistudio.com/wiki/Arma_3:_Event_Handlers#VisionModeChanged
    _id = player addEventHandler ["VisionModeChanged", {
    	params ["", "_visionMode", "_TIindex"];
      if (cameraView == "GUNNER") then {
        [hct_h60_flir_visionModesHashMap get [_visionMode, _TIindex]] call hct_h60_flir_fnc_setVisionMode;
      };
    }];
    hct_h60_flir_playerEHs pushBack ["VisionModeChanged", _id];
  } else {
    _id = ["visionMode", {
      params ["_unit", "_newvVsionMode", "_oldVisionMode"];
      if (cameraView == "GUNNER") then {
        // Sync Vision Mode
        [hct_h60_flir_visionModesHashMap get [_newvVsionMode, [-1, 0] select (_newvVsionMode > 1)]] call hct_h60_flir_fnc_setVisionMode;
      };
    }] call CBA_fnc_addPlayerEventHandler;
    hct_h60_flir_playerCBAEHs pushBack ["visionMode", _id];
  };
};

//params ["_unit", "_newView", "_oldView"]; // "GUNNER", "INTERNAL", "EXTERNAL"
_id = ["vehicle", {
  params ["_unit", "_newVehicle", "_oldVehicle"];
  if (_unit == _newVehicle) then {
    //"filmGrain" ppEffectEnable false;
    15 cutText ["", "PLAIN"];
  };
}] call CBA_fnc_addPlayerEventHandler;
hct_h60_flir_playerCBAEHs pushBack ["vehicle", _id];

//params ["_unit", "_newView", "_oldView"]; // "GUNNER", "INTERNAL", "EXTERNAL"
_id = ["cameraView", {
  params ["_unit", "_newView", "_oldView"];
  call hct_h60_flir_fnc_setIsPipHidden;

  if !(hct_h60_flir_playerIsPilot && {hct_h60_flir_controllable}) exitWith {};
  if (_newView == "GUNNER") then {
    //15 cutRsc ["hct_h60_flir_crossHair", "PLAIN"];
    //"filmGrain" ppEffectAdjust [0.5, 2, 1, 1, 1];
    //"filmGrain" ppEffectCommit 0;
    //"filmGrain" ppEffectEnable true;
  } else {
    //"filmGrain" ppEffectEnable false;
    15 cutText ["", "PLAIN"];
  };
}] call CBA_fnc_addPlayerEventHandler;
hct_h60_flir_playerCBAEHs pushBack ["cameraView", _id];

//params ["_unit", "_featureCamera"]; // "", "curator", "splendid", "nexus"
_id = ["featureCamera", {
  params ["", "_featureCamera"];
  hct_h60_flir_featureCamera = _featureCamera;
  call hct_h60_flir_fnc_setIsPipHidden;
  // Fix pip black screen
  if (_featureCamera == "" && {call hct_h60_mfd_fnc_isAnyFlirOpened}) then {
    if (!isNil "hct_h60_flir_camera" || {isNull hct_h60_flir_camera}) then {
      call hct_h60_flir_fnc_pipStart;
    };
    if (!isNil "hct_h60_mfd_slingCam" || {isNull hct_h60_mfd_slingCam}) then {
      [hct_vehicle, true] call hct_h60_mfd_fnc_slingCam;
    };
  };
  if (hct_h60_flir_isInScriptedCamera) then {
    [_featureCamera == ""] call hct_h60_flir_fnc_scriptedCamera;
  };
}] call CBA_fnc_addPlayerEventHandler;
hct_h60_flir_playerCBAEHs pushBack ["featureCamera", _id];

_id = ["unit", {
  [false] call hct_h60_flir_fnc_scriptedCamera;
}] call CBA_fnc_addPlayerEventHandler;
hct_h60_flir_playerCBAEHs pushBack ["unit", _id];

//params ["_unit", "_isVisibleMap"]; // true, false
_id = ["visibleMap", {
  params ["", "_isVisibleMap"];
  hct_h60_flir_isVisibleMap = _isVisibleMap;
  if (hct_h60_flir_playerIsPilot && {cameraView == "GUNNER"}) then {
    // When pilot is in gunner view, remove/add the crosshair when going in and out of map
    if (_isVisibleMap) then {
      15 cutText ["", "PLAIN"];
    } else {
      //15 cutRsc ["hct_h60_flir_crossHair", "PLAIN"];
    };
  };
  call hct_h60_flir_fnc_setIsPipHidden;
}] call CBA_fnc_addPlayerEventHandler;
hct_h60_flir_playerCBAEHs pushBack ["visibleMap", _id];

//remove ace LST
[_vehicle,1,["ACE_SelfActions","LSTOn"]] call ace_interact_menu_fnc_removeActionFromObject;
[_vehicle,1,["ACE_SelfActions","LSTOff"]] call ace_interact_menu_fnc_removeActionFromObject;

true
