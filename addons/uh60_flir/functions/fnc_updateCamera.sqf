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

private _camPosASL = vxf_vehicle modelToWorldVisualWorld vtx_uh60_flir_camPos;
vtx_uh60_flir_camera setPosASL _camPosASL;
getPilotCameraTarget _vehicle params ["_isTracking", "_tgtPosASL", ""];
if (_isTracking) then {
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

//drawLine3D [ASLToAGL _camPosASL, ASLToAGL _tgtPosASL, [0,1,0,1]];
//drawLine3D [ASLToAGL _camPosASL, _camPosASL vectorAdd (vxf_vehicle vectorModelToWorldVisual _dir), [1,0,0,1]];
//drawLine3D [ASLToAGL _camPosASL, _camPosASL vectorAdd ((vxf_vehicle vectorModelToWorldVisual getPilotCameraDirection vxf_vehicle) vectorMultiply 1000), [0,0,1,1]];

true
