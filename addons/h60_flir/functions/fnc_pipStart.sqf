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
 * [_vehicle] call hct_h60_flir_fnc_pipStart
 */

if (isNil "hct_h60_flir_camera") then {
  hct_h60_flir_camera = "camera" camCreate [0,0,0];
};

hct_h60_flir_camera cameraEffect ["internal", "BACK", "hct_h60_flir_feed"];
hct_h60_flir_camera camSetFocus [-1,-1];
hct_h60_flir_camera camCommit 0;
"hct_h60_flir_feed" setPiPEffect [3, 1.0, 1.0, 1.0, 0.0, [0.5, 0.5, 0.5, 0.25], [1.0, 0.0, 1.0, 1.0],  [0.199, 0.587, 0.114, 0.0]];

call hct_h60_flir_fnc_setIsPipHidden;

true
