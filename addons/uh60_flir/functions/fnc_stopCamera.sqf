/*
 * Author: Yax
 * Disable the pip camera
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_stopCamera
 */
//vtx_uh60_flir_fnc_stopCamera = {
params ["_vehicle"];

camDestroy vtx_uh60_flir_camera;
vtx_uh60_flir_camera cameraEffect ["terminate", "back", "vtx_uh60_flir_feed"];
vtx_uh60_flir_camera = nil;

[_vehicle] call vtx_uh60_flir_fnc_updatePilots;

true
