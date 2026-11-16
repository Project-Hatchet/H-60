#include "script_component.hpp"
/*
 * Author: Ampersand
 * Lock FLIR to current aim pos or obj
 *
 * The lock key is a toggle. With a track active it releases it. Otherwise it casts the
 * view ray (out to 16 km) and locks, in order of preference:
 *  1. the vehicle or soldier the ray hits;
 *  2. the vehicle nearest the aim line that the ray narrowly missed (the "near-miss
 *     assist" - see _fnc_nearMiss);
 *  3. the point the ray hit (a geo lock);
 *  and with nothing hit and nothing near the line (open sky), releases a geo lock.
 *
 * Call through hct_h60_flir_fnc_lockPress from a key: several input paths can report
 * one press, and only that function debounces them.
 *
 * Arguments:
 * 0: Camera Position ASL <ARRAY> (default: the pilot camera)
 * 1: Target Position ASL <ARRAY> - a point along the view ray
 * 2: Sync <BOOLEAN> (unused)
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call hct_h60_flir_fnc_setStabilization
 */
#define MAX_RAY_RANGE 16000      // fnc_intersectAtPolar's reach
#define AIR_SEARCH_RANGE 5000    // aircraft considered when the ray finds only sky
#define BEHIND_HIT_MARGIN 25     // m a target may sit beyond the surface the ray hit
#define LATERAL_MAX_GROUND 25    // m off the aim line a missed ground target may be
#define LATERAL_MAX_AIR 40       // m for aircraft, whose sim/visual lag is larger

params [
  ["_camPosASL", []],
  ["_tgtPosASL", []],
  ["_sync", true]
];

private _trackObj = hct_h60_flir_pilotCameraTarget param [2, objNull];

private _originPos = hct_vehicle modelToWorldVisualWorld (getPilotCameraPosition hct_vehicle);
private _cameraVectorWorld = hct_vehicle vectorModelToWorld (getPilotCameraDirection hct_vehicle);

// Break any lock, leaving the camera looking where the player was looking
private _fnc_release = {
  private _dir = hct_vehicle vectorWorldToModelVisual (
    [
      _cameraVectorWorld,
      ATLToASL positionCameraToWorld [0,0,0]
      vectorFromTo
      ATLToASL positionCameraToWorld [0,0,1000]
    ] select hct_h60_flir_isInScriptedCamera
  );
  hct_vehicle setPilotCameraTarget objNull;
  hct_vehicle setPilotCameraDirection _dir;
  // remember the released direction: if the VANILLA lock action re-locks after
  // us on the same press (its toggle state is desynced; HOTAS bindings bypass
  // the display-level consume hooks), the per-frame authority in fnc_handleSlew
  // stomps the rogue lock and restores this direction
  hct_h60_flir_lastReleaseDir = _dir;
  hct_h60_flir_lastReleaseTime = diag_tickTime;
  [[], objNull] call hct_h60_flir_fnc_syncPilotCamera;
};

// The lock key is a toggle: with an object track active the camera is being
// steered onto the target, so a fresh boresight ray always re-hits the same
// vehicle and silently re-locked it. Break the lock instead - in fullscreen
// there is no other way out, since mouselook deliberately does not stomp
// tracks (#538 follow-up)
if (!isNull _trackObj) exitWith {
  call _fnc_release;
  if (missionNamespace getVariable ["hct_h60_devMode", false]) then {
    systemChat format ["FLIR lock: released %1", typeOf _trackObj];
  };
  true
};

// The view ray. The scripted camera passes its true ray: the pilot camera can trail a
// moving target in fullscreen, so cast what the player actually sees (#538). Every view
// casts the same 16 km - the scripted camera's used to stop at 5 km.
private _rayOrigin = [_originPos, _camPosASL] select (_camPosASL isNotEqualTo []);
private _rayDir = if (_camPosASL isNotEqualTo []) then {_camPosASL vectorFromTo _tgtPosASL} else {vectorNormalized _cameraVectorWorld};
private _polar = _rayDir call CBA_fnc_vect2Polar;
private _intersectResult = [_rayOrigin, _polar # 1, _polar # 2, hct_vehicle] call hct_h60_flir_fnc_intersectAtPolar;

private _intersect = [];
private _hitObject = objNull;
if (!isNil "_intersectResult") then {
  _intersectResult params ["_pos", "_obj"];
  _intersect = _pos;
  _hitObject = _obj;
};

// 1. The object the ray actually hit
private _trackTarget = objNull;
if (!isNull _hitObject) then {
  private _hitVehicle = vehicle _hitObject; // crew hit resolves to their vehicle
  if (_hitVehicle isKindOf "LandVehicle" || {_hitVehicle isKindOf "Air"} || {_hitVehicle isKindOf "Ship"} || {_hitVehicle isKindOf "Man"}) then {
    _trackTarget = _hitVehicle;
  };
};

// 2. Near-miss assist. A raycast tests sim positions, which trail the rendered hull on
// movers, so aiming dead on at a moving vehicle can miss and hit the ground behind it
// (#538). Accept the vehicle closest to the aim line, but only one the player could be
// aiming at:
//  - not beyond the surface the ray hit (a far vehicle behind a hill, a building or
//    the aim point used to win - "it locked something far off");
//  - within a few metres of the line, and inside a cone that narrows with zoom (the
//    old fixed 2.5 deg was 130 m wide at 3 km);
//  - in line of sight.
// With only sky ahead, aircraft along the line are still found.
if (isNull _trackTarget) then {
  private _hitDist = if (_intersect isEqualTo []) then {MAX_RAY_RANGE} else {_rayOrigin distance _intersect};
  private _fov = missionNamespace getVariable ["hct_h60_flir_FOV", 0.5];
  private _coneDeg = ((2 * (atan _fov)) * 0.03) max 0.1 min 2.5; // ~3% of the field of view
  private _bestDot = cos _coneDeg;
  private _candidates = if (_intersect isEqualTo []) then {
    hct_vehicle nearEntities [["Air"], AIR_SEARCH_RANGE]
  } else {
    hct_vehicle nearEntities [["LandVehicle", "Air", "Ship"], (_hitDist + BEHIND_HIT_MARGIN) min AIR_SEARCH_RANGE]
  };
  {
    if (_x != hct_vehicle && {alive _x}) then {
      private _aim = aimPos _x;
      private _toAim = _aim vectorDiff _rayOrigin;
      private _along = _toAim vectorDotProduct _rayDir;
      if (_along > 0 && {_along <= _hitDist + BEHIND_HIT_MARGIN}) then {
        private _lateral = vectorMagnitude (_toAim vectorDiff (_rayDir vectorMultiply _along));
        private _dot = _along / (vectorMagnitude _toAim);
        if (
          _dot > _bestDot
          && {_lateral <= ([LATERAL_MAX_GROUND, LATERAL_MAX_AIR] select (_x isKindOf "Air"))}
          && {(lineIntersectsSurfaces [_rayOrigin, _aim, hct_vehicle, _x, true, 1, "VIEW", "FIRE"]) isEqualTo []}
        ) then {
          _bestDot = _dot;
          _trackTarget = _x;
        };
      };
    };
  } forEach _candidates;
};

if (missionNamespace getVariable ["hct_h60_devMode", false]) then {
  systemChat format ["FLIR lock: rayHit=%1 target=%2", typeOf _hitObject, typeOf _trackTarget];
};

if (!isNull _trackTarget) exitWith {
  hct_vehicle setPilotCameraTarget _trackTarget;
  [[], aimPos _trackTarget, _trackTarget] call hct_h60_flir_fnc_syncPilotCamera;
  true
};

// 3. A geo lock on the hit point - or, pressed on an existing geo lock or at open sky,
// a release
if ((getPilotCameraTarget hct_vehicle) # 0 || {_intersect isEqualTo []}) then {
  if ((getPilotCameraTarget hct_vehicle) # 0) then {call _fnc_release};
} else {
  hct_vehicle setPilotCameraTarget _intersect;
  [[], _intersect] call hct_h60_flir_fnc_syncPilotCamera;
};
true
