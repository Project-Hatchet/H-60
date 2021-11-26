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
 * [_vehicle] call vtx_uh60_flir_mfdSling
 */

//if (vtx_uh60_flir_isPipHidden) exitWith {};

params ["_vehicle"];

_vehicle setPilotCameraTarget objNull;
_vehicle setPilotCameraDirection [0, 0.000001, 1];
[
  true,
  _vehicle selectionPosition "slingload0",
  [[0, 0, -1], [0, 1, 0]],
  0.5,
  [0]
] call vtx_uh60_flir_fnc_setFixedPIP;

true
