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

// Pavehawk and Seahawk FLIR turrets don't animate properly yet
if (!(_vehicle isKindOf "vtx_MH60M")) exitWith {};

private _rotation = getPilotCameraRotation _vehicle;
if (_rotation isNotEqualTo [
  _vehicle animationSourcePhase "FLIR_DIRECTION",
  _vehicle animationSourcePhase "FLIR_ELEVATION"
]) then {
  _rotation params ["_azimuth", "_elevation"];
  _vehicle animateSource ["FLIR_DIRECTION", _azimuth, true];
  _vehicle animateSource ["FLIR_ELEVATION", _elevation, true];
};

true
