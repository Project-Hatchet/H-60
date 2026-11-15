/*
 * Author: Ampersand
 * Lock FLIR to current aim pos or obj
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [] call hct_h60_flir_fnc_keyFLIRSlewToHMD
 */

if (
  !hct_h60_flir_controllable
) exitWith {};

[
  AGLToASL positionCameraToWorld [0, 0, 0],
  AGLToASL positionCameraToWorld [0, 0, 5000]
] call hct_h60_flir_fnc_setStabilization;

true
