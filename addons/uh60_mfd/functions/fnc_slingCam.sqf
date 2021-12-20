#include "script_component.hpp"
/*
 * Author: Ampersand
 * Toggle sling camera on the pip MFD
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Show <BOOLEAN>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle, true] call vtx_uh60_mfd_fnc_slingCam
 */

params ["_vehicle", ["_show", true]];

if (_show) then {
  if (!isNil "vtx_uh60_flir_camera") then {
    vtx_uh60_flir_camera cameraEffect ["terminate", "back", "vtx_uh60_flir_feed"];
  };
  if (isNil "vtx_uh60_mfd_slingCam") then {
    vtx_uh60_mfd_slingCam = "camera" camCreate [0,0,0];
  };
  vtx_uh60_mfd_slingCam attachTo [_vehicle, _vehicle selectionPosition "slingcam"];
  vtx_uh60_mfd_slingCam setVectorDirAndUp [[0, 0, -1], [0, 1, 0]];
  vtx_uh60_mfd_slingCam cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
  vtx_uh60_mfd_slingCam camSetFocus [-1,-1];
  vtx_uh60_mfd_slingCam camCommit 0;
} else {
  if (!isNil "vtx_uh60_mfd_slingCam") then {
    camDestroy vtx_uh60_mfd_slingCam;
    vtx_uh60_mfd_slingCam cameraEffect ["terminate", "back", "vtx_uh60_flir_feed"];
    vtx_uh60_mfd_slingCam = nil;
  };
  if (!isNil "vtx_uh60_flir_camera") then {
    vtx_uh60_flir_camera cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
  };
};
vtx_uh60_flir_pipIsFixed = _show;

true
