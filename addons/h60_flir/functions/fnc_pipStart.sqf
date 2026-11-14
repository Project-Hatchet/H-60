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

if (isNil "vtx_uh60_flir_camera") then {
  vtx_uh60_flir_camera = "camera" camCreate [0,0,0];
};

vtx_uh60_flir_camera cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
vtx_uh60_flir_camera camSetFocus [-1,-1];
vtx_uh60_flir_camera camCommit 0;
"vtx_uh60_flir_feed" setPiPEffect [3, 1.0, 1.0, 1.0, 0.0, [0.5, 0.5, 0.5, 0.25], [1.0, 0.0, 1.0, 1.0],  [0.199, 0.587, 0.114, 0.0]];

call vtx_uh60_flir_fnc_setIsPipHidden;

true
