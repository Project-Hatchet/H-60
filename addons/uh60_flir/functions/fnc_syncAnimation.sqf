/*
 * Author: Ampersand
 * Animate the FLIR turret model
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_syncAnimation
 */

params ["_vehicle"];

(getPilotCameraRotation _vehicle) params ["_azimuth", "_elevation"];
_vehicle animateSource ["FLIR_DIRECTION", _azimuth, true];
_vehicle animateSource ["FLIR_ELEVATION", _elevation, true];

true
