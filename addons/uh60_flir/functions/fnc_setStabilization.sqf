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

private _intersectResult = if (_camPosASL isNotEqualTo []) then {
    // Scripted camera passes its true view ray. The pilot camera can trail a
    // moving target in fullscreen, so raycast what the player actually sees;
    // otherwise moving vehicles can only ever be locked from PiP (#538)
    private _hits = lineIntersectsSurfaces [_camPosASL, _tgtPosASL, hct_vehicle];
    if (_hits isEqualTo []) then {nil} else {
        (_hits # 0) params ["_pos", "", "_obj", "_parent"];
        [_pos, [_obj, _parent] select (!isNull _parent)]
    };
} else {
    private _slewOrigin = (_cameraVectorWorld) call CBA_fnc_vect2Polar;
    [_originPos, _slewOrigin # 1, _slewOrigin # 2] call vtx_uh60_flir_fnc_intersectAtPolar
};

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
// Fallback: boresight cone search on VISUAL positions. A raycast tests sim
// positions, which trail the rendered hull on movers - so aiming dead-on at a
// moving vehicle can still miss. Pick the candidate closest to the view axis
// within a small cone instead (#538 fullscreen lock)
if (isNull _trackTarget) then {
  private _rayOrigin = [_originPos, _camPosASL] select (_camPosASL isNotEqualTo []);
  private _rayDir = if (_camPosASL isNotEqualTo []) then {_camPosASL vectorFromTo _tgtPosASL} else {vectorNormalized _cameraVectorWorld};
  private _coneCos = cos 2.5; // half-cone in degrees
  private _bestDot = _coneCos;
  {
    if (_x != hct_vehicle && {vehicle _x != hct_vehicle}) then {
      private _dot = _rayDir vectorDotProduct (_rayOrigin vectorFromTo getPosASLVisual _x);
      if (_dot > _bestDot) then {_bestDot = _dot; _trackTarget = _x};
    };
  } forEach (hct_vehicle nearEntities [["LandVehicle", "Air", "Ship"], 5000]);
};
if (missionNamespace getVariable ["vtx_uh60_ui_showDebugMessages", false]) then {
  systemChat format ["FLIR lock: rayHit=%1 target=%2", typeOf _hitObject, typeOf _trackTarget];
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

