/*
 * Author: Ampersand
 * Sync the turret/camera fov value to the player [co]pilot
 *
 * Arguments:
 * 0: FOV <NUMBER>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_fov] call hct_h60_flir_fnc_setFOV
 */

params ["_fov", ["_sync", true]];
// systemChat str ["SYNCING", _this];
hct_h60_flir_FOV = _fov;
if (!isNil "hct_h60_flir_camera") then { hct_h60_flir_camera camSetFov _fov; }; // no PiP camera in native gunner view, or on a remote crew's machine

if (_sync) then {
  // ["hct_h60_flir_syncFOV", [_fov], [hct_h60_flir_otherPilot]] call CBA_fnc_targetEvent;
  private _targets = (crew vehicle player) - [player];
  if (_targets isNotEqualTo []) then {
    [_fov, false] remoteExecCall ["hct_h60_flir_fnc_setFOV", _targets, false];
  };
};


true
