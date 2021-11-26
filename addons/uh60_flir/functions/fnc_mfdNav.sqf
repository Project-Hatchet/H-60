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
 * [_vehicle] call vtx_uh60_flir_fnc_mfdNav
 */

//if (vtx_uh60_flir_isPipHidden) exitWith {};

params ["_vehicle"];

if (!vtx_uh60_flir_controllable) exitWith {};

_vehicle setPilotCameraTarget objNull;
_vehicle setPilotCameraDirection [0, 1, 0];
[
  false,
  vtx_uh60_flir_camPos,
  [[0, 1, 0], [0, 0, 1]],
  0.3,
  vtx_uh60_flir_pipEffect
] call vtx_uh60_flir_fnc_setFixedPIP;

// sync to other pilot
[[0, 1, 0], objNull] call vtx_uh60_flir_fnc_syncPilotCamera;
/*
vtx_uh60_flir_FOV = 0.3;
[0.3] call vtx_uh60_flir_fnc_setFOV;
[objNull] call vtx_uh60_flir_fnc_syncAnimation;
*/

true
