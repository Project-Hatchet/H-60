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
 * [_vehicle] call hct_h60_flir_fnc_mfdNav
 */

//if (hct_h60_flir_isPipHidden) exitWith {};

params ["_vehicle"];

if (!hct_h60_flir_controllable) exitWith {};

[_vehicle, false] call hct_h60_mfd_fnc_slingCam;
hct_h60_flir_pipIsFixed = false;

_vehicle setPilotCameraTarget objNull;
_vehicle setPilotCameraDirection [0, 1, 0];

// sync to other pilot
[[0, 1, 0], objNull] call hct_h60_flir_fnc_syncPilotCamera;
/*
hct_h60_flir_FOV = 0.3;
[0.3] call hct_h60_flir_fnc_setFOV;
[objNull] call hct_h60_flir_fnc_syncAnimation;
*/

true
