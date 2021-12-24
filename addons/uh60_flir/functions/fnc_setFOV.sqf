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
 * [_fov] call vtx_uh60_flir_fnc_setFOV
 */

params ["_fov", ["_sync", true]];

vtx_uh60_flir_FOV = _fov;
vtx_uh60_flir_camera camSetFov _fov;

if (_sync && {vtx_uh60_flir_otherPilotIsPlayer}) then {
  ["vtx_uh60_flir_syncFOV", [_fov], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
};


true
