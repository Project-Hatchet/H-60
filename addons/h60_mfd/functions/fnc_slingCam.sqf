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
 * [_vehicle, true] call hct_h60_mfd_fnc_slingCam
 */

params ["_vehicle", ["_show", true]];

if (_show) then {
  if (!isNil "hct_h60_flir_camera") then {
    hct_h60_flir_camera cameraEffect ["terminate", "back", "hct_h60_flir_feed"];
  };
  if (isNil "hct_h60_mfd_slingCam") then {
    hct_h60_mfd_slingCam = "camera" camCreate [0,0,0];
  };
  hct_h60_mfd_slingCam attachTo [_vehicle, _vehicle selectionPosition "slingcam"];
  hct_h60_mfd_slingCam setVectorDirAndUp [[0, 0, -1], [0, 1, 0]];
  hct_h60_mfd_slingCam cameraEffect ["internal", "BACK", "hct_h60_flir_feed"];
  hct_h60_mfd_slingCam camSetFocus [-1,-1];
  hct_h60_mfd_slingCam camCommit 0;
} else {
  if (!isNil "hct_h60_mfd_slingCam") then {
    // end the effect before the camera: terminate on a destroyed camera does nothing
    hct_h60_mfd_slingCam cameraEffect ["terminate", "back", "hct_h60_flir_feed"];
    camDestroy hct_h60_mfd_slingCam;
    hct_h60_mfd_slingCam = nil;
  };
  if (!isNil "hct_h60_flir_camera") then {
    hct_h60_flir_camera cameraEffect ["internal", "BACK", "hct_h60_flir_feed"];
  };
};
hct_h60_flir_pipIsFixed = _show;

true
