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

if (_camPosASL isEqualTo []) then {
  _camPosASL = AGLToASL (vxf_vehicle modelToWorldVisual (vtx_uh60_flir_camPos));
};
if (_tgtPosASL in [[0, 0, 0], []]) then {
  private _flirDir = vxf_vehicle vectorModelToWorldVisual (getPilotCameraDirection vxf_vehicle);
  _tgtPosASL = _camPosASL vectorAdd (_flirDir vectorMultiply 5000);
};

private _intersections = lineIntersectsSurfaces [_camPosASL, _tgtPosASL, vxf_vehicle];
private _target = objNull;
if (_intersections isEqualTo []) then {
  if (_tgtPosASL # 2 > _camPosASL # 2) then {
    _target = [_tgtPosASL, objNull] select _isTracking; // Looking up
  } else {
    _target = [AGLToASL screenToWorld [0.5, 0.5], objNull] select _isTracking; // Looking down
  };
} else {
  (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
  if (isNull _intersectObject) then {
    // Terrain
    _target = [_intersectPosASL, objNull] select _isTracking; // if already tracking position, untrack
  } else {
    // Object
    if (speed _intersectObject > 0) then {
      // Moving vehicle
      _target = [objNull, _intersectObject] select (_trackObj != _intersectObject); // if already tracking same object, untrack
    } else {
      // Stationary target
      _target = [objNull, _intersectPosASL] select (_trackObj != _intersectObject); // if already tracking same object, untrack
    };
  };
};

vxf_vehicle setPilotCameraTarget _target;

[[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;

true
