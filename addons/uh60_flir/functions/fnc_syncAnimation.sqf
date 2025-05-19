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
if !(
  _vehicle isKindOf "vtx_MH60M" ||
  {_vehicle isKindOf "vtx_MH60M_DAP"} ||
  {_vehicle isKindOf "vtx_MH60M_DAP_MLASS"}
) exitWith {};

private _rotation = getPilotCameraRotation _vehicle;
if (_rotation isNotEqualTo [
  _vehicle animationSourcePhase "FLIR_DIRECTION",
  _vehicle animationSourcePhase "FLIR_ELEVATION"
]) then {
  _rotation params ["_azimuth", "_elevation"];
  private _rotationDiff = abs (((deg (_vehicle animationSourcePhase "FLIR_DIRECTION")) + 180) - ((deg _azimuth) + 180));
  private _speed = (_rotationDiff / 360) max 1;
  // systemChat str [deg _azimuth, (deg (_vehicle animationSourcePhase "FLIR_DIRECTION")),  _speed];
  _vehicle animateSource ["FLIR_DIRECTION", _azimuth, _speed];
  _vehicle animateSource ["FLIR_ELEVATION", -_elevation, _speed];
};

true
