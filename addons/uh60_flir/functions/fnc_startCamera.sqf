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
 * [_heli] call vtx_uh60_flir_fnc_startCamera
 */
//vtx_uh60_flir_fnc_startCamera = {
params ["_vehicle"];

if (!isNil "vtx_uh60_flir_camera") exitWith { vtx_uh60_flir_camera };

vtx_uh60_flir_camera = "camera" camCreate [0,0,0];
vtx_uh60_flir_camera camSetFov 0.25;
vtx_uh60_flir_camera cameraEffect ["internal", "BACK", "vtx_uh60_flir_feed"];
vtx_uh60_flir_camera camCommit 0;

"vtx_uh60_flir_feed" setPiPEffect [3,0.6,0.7,0.2,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]];

[_vehicle] call vtx_uh60_flir_fnc_updatePilots;

true
