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

// Move to framework
vxf_vehicle = vehicle player;
if (!hasPilotCamera vxf_vehicle) exitWith {false};

//(getPilotCameraTarget vxf_vehicle) params ["_isTracking", "_trackPos", "_trackObj"];
(getPilotCameraTarget vxf_vehicle) params ["_isTracking"];
vtx_uh60_flir_isStabilized = _isTracking;

private _vehicleConfig = configOf vxf_vehicle;
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

vtx_uh60_flir_camPos = getPilotCameraPosition vxf_vehicle;
private _dir = getPilotCameraDirection vxf_vehicle;
vtx_uh60_flir_camDirAndUp = [
  _dir,
  _dir vectorCrossProduct (_dir vectorCrossProduct [0, 0, -1])
];

vtx_uh60_flir_isVisibleMap = visibleMap;
call vtx_uh60_flir_fnc_setIsPipHidden;

//params ["_unit", "_newView", "_oldView"]; // "GUNNER", "INTERNAL", "EXTERNAL"
_id = ["cameraView", {
  params ["_unit", "_newView", "_oldView"];
  if (vtx_uh60_flir_playerIsPilot && {_newView == "GUNNER"}) then {
    // Sync FOV and Vision Mode
  };
  call vtx_uh60_flir_fnc_setIsPipHidden;
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerEHs pushBack ["cameraView", _id];

//params ["_unit", "_newView", "_oldView"]; // "GUNNER", "INTERNAL", "EXTERNAL"
_id = ["visionMode", {
  params ["_unit", "_newView", "_oldView"];
  if (vtx_uh60_flir_playerIsPilot && {_newView == "GUNNER"}) then {
    // Sync FOV and Vision Mode
  };
  call vtx_uh60_flir_fnc_setIsPipHidden;
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerEHs pushBack ["cameraView", _id];

//params ["_unit", "_featureCamera"]; // "", "curator", "splendid", "nexus"
_id = ["featureCamera", {
  params ["", "_featureCamera"];
  call vtx_uh60_flir_fnc_setIsPipHidden;
  // Fix pip black screen
  if (_featureCamera == "" && {call vtx_uh60_mfd_fnc_isAnyFlirOpened}) then {
    call vtx_uh60_flir_fnc_pipStart;
  };
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerEHs pushBack ["featureCamera", _id];

//params ["_unit", "_isVisibleMap"]; // true, false
_id = ["visibleMap", {
  params ["", "_isVisibleMap"];
  vtx_uh60_flir_isVisibleMap = _isVisibleMap;
  call vtx_uh60_flir_fnc_setIsPipHidden;
}] call CBA_fnc_addPlayerEventHandler;
vtx_uh60_flir_playerEHs pushBack ["visibleMap", _id];

true
