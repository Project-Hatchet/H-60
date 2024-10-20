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


private _originPos = vxf_vehicle modelToWorldVisualWorld (getPilotCameraPosition vxf_vehicle);
private _cameraVectorWorld = vxf_vehicle vectorModelToWorld (getPilotCameraDirection vxf_vehicle);
private _slewOrigin = (_cameraVectorWorld) call CBA_fnc_vect2Polar;
private _intersect = [_originPos, _slewOrigin # 1, _slewOrigin # 2] call vtx_uh60_flir_fnc_intersectAtPolar;
if (!isNil "_intersect") then {
  private _nearObjects = nearestobjects [ASLtoAGL _intersect, ["Land", "Air", "Ship"], 5];
  if (count _nearObjects > 0) then {
    vxf_vehicle setPilotCameraTarget (_nearObjects # 0);
    [[], _intersect, (_nearObjects # 0)] call vtx_uh60_flir_fnc_syncPilotCamera;
  } else {
    if ((getPilotCameraTarget vxf_vehicle) # 0) then {
      vxf_vehicle setPilotCameraTarget objNull;
      [[], objNull] call vtx_uh60_flir_fnc_syncPilotCamera;
    } else {
      vxf_vehicle setPilotCameraTarget _intersect;
      [[], _intersect] call vtx_uh60_flir_fnc_syncPilotCamera;
    };
  };
};

