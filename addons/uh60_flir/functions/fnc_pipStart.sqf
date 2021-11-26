/*
 * Author: Yax
 * Start the pip camera
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_pipStart
 */

if (!isNil "vtx_uh60_flir_camera") then { call vtx_uh60_flir_fnc_pipStop };

vtx_uh60_flir_camera = "camera" camCreate [0,0,0];
vtx_uh60_flir_camera cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
"vtx_uh60_flir_feed" setPiPEffect [3,0.6,0.7,0.2,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]];

call vtx_uh60_flir_fnc_setIsPipHidden;

[
  !vtx_uh60_flir_controllable,
  vtx_uh60_flir_camPos,
  vtx_uh60_flir_camDirAndUp,
  vtx_uh60_flir_FOV,
  [0]
] call vtx_uh60_flir_fnc_setFixedPIP;

true
