/*
 * Author: Ampersand
 * Align flir turret and both pilotCameras straight forward at widest FOV
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_nav
 */

CHK_FLIR;

params ["_vehicle"];

_vehicle setPilotCameraTarget objNull;
_vehicle setPilotCameraDirection [0,1,0];
vtx_uh60_flir_fov = 0.3;
[0.3] call vtx_uh60_flir_fnc_syncFOV;

// sync to other pilot
[[0, 1, 0], objNull] call vtx_uh60_flir_fnc_syncPilotCamera;
[objNull] call vtx_uh60_flir_fnc_syncAnimation;

true
