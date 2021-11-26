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

if (vtx_uh60_flir_isPipHidden) exitWith {};
if (vtx_uh60_flir_playerIsPilot && {vtx_uh60_flir_isCopilotInGunnerView}) exitWith {false};

(getPilotCameraTarget vxf_vehicle) params ["_isTracking", "_trackPos", "_trackObj"];

if (_camPosASL isEqualTo []) then {
  _camPosASL = AGLToASL (vxf_vehicle modelToWorldVisual (vtx_uh60_flir_camPos));
};
if (_tgtPosASL isEqualTo []) then {
  private _flirDir = vxf_vehicle vectorModelToWorldVisual (getPilotCameraDirection vxf_vehicle);
  _tgtPosASL = _camPosASL vectorAdd (_flirDir vectorMultiply 5000);
};

private _intersections = lineIntersectsSurfaces [_camPosASL, _tgtPosASL, vxf_vehicle];
private _target = objNull;
if !((_intersections # 0) isEqualTo []) then {
  (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
  if (isNull _intersectObject) then {
    // Terrain
    vtx_uh60_flir_isStabilized = !vtx_uh60_flir_isStabilized;
    _target = [objNull, _intersectPosASL] select vtx_uh60_flir_isStabilized; // if already tracking position, untrack
  } else {
    // Object
    vtx_uh60_flir_isStabilized = _trackObj != _intersectObject;
    _target = [objNull, _intersectObject] select vtx_uh60_flir_isStabilized; // if already tracking same object, untrack
  };
};
vxf_vehicle setPilotCameraTarget _target;

if (vtx_uh60_flir_playerIsCopilot && {vtx_uh60_flir_isCopilotInGunnerView}) then {
  vxf_vehicle lockCameraTo [_target, [0]];
};
if !(_target isEqualTo objNull) then { [_target] call vtx_uh60_flir_fnc_syncAnimation; };
[[], _target] call vtx_uh60_flir_fnc_syncPilotCamera;

true
