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
private _intersectResult = [_originPos, _slewOrigin # 1, _slewOrigin # 2] call vtx_uh60_flir_fnc_intersectAtPolar;

if (isNil "_intersectResult") exitWith {};
_intersectResult params ["_intersect", "_hitObject"];

// Prefer the object the ray actually hit — a proximity search around the impact
// point misses large vehicles (origin > 5 m from the hull) and aircraft entirely,
// because a near-miss ray lands on terrain far behind the target (#538)
private _trackTarget = objNull;
if (!isNull _hitObject) then {
  private _hitVehicle = vehicle _hitObject; // crew hit resolves to their vehicle
  if (_hitVehicle isKindOf "LandVehicle" || {_hitVehicle isKindOf "Air"} || {_hitVehicle isKindOf "Ship"} || {_hitVehicle isKindOf "Man"}) then {
    _trackTarget = _hitVehicle;
  };
};
// Fallback for near misses on movers: sim position trails the rendered hull
if (isNull _trackTarget) then {
  private _nearObjects = nearestObjects [ASLtoAGL _intersect, ["Land", "Air", "Ship"], 10];
  if (_nearObjects isNotEqualTo []) then {_trackTarget = _nearObjects # 0};
};

if (!isNull _trackTarget) then {
  hct_vehicle setPilotCameraTarget _trackTarget;
  [[], _intersect, _trackTarget] call vtx_uh60_flir_fnc_syncPilotCamera;
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

