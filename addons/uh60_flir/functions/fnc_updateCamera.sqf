/*
 * Author: Ampersand
 * Align the the pip camera to the pilotCamera and set fov
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_updateCamera
 */

params ["_vehicle"];

if (
  isNil "vtx_uh60_flir_camera" ||
  {vtx_uh60_flir_pipIsFixed && {!vtx_uh60_flir_isInScriptedCamera}} || // Sling cam
  {cameraView isNotEqualTo "INTERNAL"} ||
  {visibleMap} ||
  {!isNull curatorCamera}
) exitWith { false };

private _camPosASL = vxf_vehicle modelToWorldVisualWorld vtx_uh60_flir_camPos;
vtx_uh60_flir_camera setPosASL _camPosASL;
if (vtx_uh60_flir_isStabilized) then {
  (getPilotCameraTarget _vehicle) params ["", "_tgtPosASL", ""];
  if (vtx_uh60_flir_isInScriptedCamera) then { // Fix laser target wandering off
    private _laserTarget = laserTarget vxf_vehicle;
    if (!isNull _laserTarget) then {
      _laserTarget setPosASL _tgtPosASL;
    };
  };
  private _dir = _camPosASL vectorFromTo _tgtPosASL;
  vtx_uh60_flir_camera setVectorDirAndUp [
    _dir,
    _dir vectorCrossProduct (_dir vectorCrossProduct (_vehicle vectorModelToWorldVisual [0, 0, -1]))
  ];
} else {
  private _dir = getPilotCameraDirection _vehicle;
  vtx_uh60_flir_camera setVectorDirAndUp [
    _vehicle vectorModelToWorldVisual _dir,
    _vehicle vectorModelToWorldVisual (_dir vectorCrossProduct (_dir vectorCrossProduct [0, 0, -1]))
  ];
};

//(getPilotCameraTarget _vehicle) params ["_isStabilized", "_position"];
//drawLine3D [ASLToAGL _camPosASL, ASLToAGL _position, [0,1,0,1]];
//drawLine3D [ASLToAGL _camPosASL, _camPosASL vectorAdd (vxf_vehicle vectorModelToWorldVisual _dir), [1,0,0,1]];
//drawLine3D [ASLToAGL _camPosASL, _camPosASL vectorAdd ((vxf_vehicle vectorModelToWorldVisual getPilotCameraDirection vxf_vehicle) vectorMultiply 1000), [0,0,1,1]];

true
