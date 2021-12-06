/*
 * Author: Ampersand
 * Start or stop the the scripted camera
 *
 * Arguments:
 * 0: Start <BOOLEAN>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [true] call vtx_uh60_flir_fnc_scriptedCamera
 */

params ["_show"];

if (_show) then {
  if (isNil "vtx_uh60_flir_camera") then {
    vtx_uh60_flir_camera = "camera" camCreate [0,0,0];
  };
  //private _initFovStep = ((_vehicle getVariable "vtx_flir_fovObjects") # (_vehicle getVariable ["vtx_flir_initFovMode",0]));
  //vtx_uh60_flir_camera camSetFov (_initFovStep # 0);
  //vtx_uh60_flir_FOV = _initFovStep;
  vtx_uh60_flir_camera cameraEffect ["Internal", "BACK"];
  vtx_uh60_flir_camera camSetFocus [-1,-1];
  vtx_uh60_flir_camera camCommit 0;
  15 cutRsc ["vtx_uh60_flir_cameraOverlay", "PLAIN"];
  showCinemaBorder false;

  "filmGrain" ppEffectAdjust [0.5, 2, 1, 1, 1];
  "filmGrain" ppEffectCommit 0;
  "filmGrain" ppEffectEnable true;

  [vtx_uh60_flir_pipEffect, false] call vtx_uh60_flir_fnc_setVisionMode;
  vtx_uh60_flir_isInScriptedCamera = true;

} else {

  vtx_uh60_flir_camera cameraEffect ["terminate", "back"];
  "filmGrain" ppEffectEnable false;
  15 cutText ["", "PLAIN"];

  if (!(call vtx_uh60_mfd_fnc_isAnyFlirOpened)) then {
    camDestroy vtx_uh60_flir_camera;
    vtx_uh60_flir_camera = nil;
  } else {
    // Fix pip black screen
    vtx_uh60_flir_camera cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
    "vtx_uh60_flir_feed" setPiPEffect vtx_uh60_flir_pipEffect;
  };

  vtx_uh60_flir_isInScriptedCamera = false;
};
call vtx_uh60_flir_fnc_setIsPipHidden;

true
