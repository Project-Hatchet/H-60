#include "script_component.hpp"
/*
 * Author: Ampersand
 * Lock FLIR to current aim pos or obj
 *
 * Arguments:
 * 0: Camera Position ASL <ARRAY>
 * 1: Target Position ASL <ARRAY>
 * 2: Sync <BOOLEAN>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call vtx_uh60_flir_fnc_setStabilization
 */

params [
  ["_camPosASL", []],
  ["_tgtPosASL", []],
  ["_sync", true]
];

//if (vtx_uh60_flir_playerIsPilot && {vtx_uh60_flir_isCopilotInGunnerView}) exitWith {false};

vtx_uh60_flir_pilotCameraTarget params ["_isTracking", "", "_trackObj"];


private _originPos = hct_vehicle modelToWorldVisualWorld (getPilotCameraPosition hct_vehicle);
private _cameraVectorWorld = hct_vehicle vectorModelToWorld (getPilotCameraDirection hct_vehicle);
private _slewOrigin = (_cameraVectorWorld) call CBA_fnc_vect2Polar;
private _intersect = [_originPos, _slewOrigin # 1, _slewOrigin # 2] call vtx_uh60_flir_fnc_intersectAtPolar;

if (isNil "_intersect") exitWith {};

private _nearObjects = nearestObjects [ASLtoAGL _intersect, ["Land", "Air", "Ship"], 5];
if (_nearObjects isNotEqualTo []) then {
  hct_vehicle setPilotCameraTarget (_nearObjects # 0);
  [[], _intersect, (_nearObjects # 0)] call vtx_uh60_flir_fnc_syncPilotCamera;
} else {
  if ((getPilotCameraTarget hct_vehicle) # 0) then {

    private _dir = hct_vehicle vectorWorldToModelVisual (
      [
        _cameraVectorWorld,
        ATLtoASL positionCameraToWorld [0,0,0]
        vectorFromTo
        ATLtoASL positionCameraToWorld [0,0,1000]
      ] select vtx_uh60_flir_isInScriptedCamera
    );


    hct_vehicle setPilotCameraTarget objNull;
    hct_vehicle setPilotCameraDirection _dir;
    [[], objNull] call vtx_uh60_flir_fnc_syncPilotCamera;

  } else {
    hct_vehicle setPilotCameraTarget _intersect;
    [[], _intersect] call vtx_uh60_flir_fnc_syncPilotCamera;
  };
};

