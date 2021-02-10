/*
 * Author: Ampersand
 * Sync the turret/camera fov value to the other player pilot
 *
 * Arguments:
 * 0: FOV <NUMBER>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_syncFOV
 */

params ["_fov"];
if vtx_uh60_flir_otherPilotIsPlayer exitWith {
    ["vtx_uh60_flir_syncFOV", [_fov], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
    true
};

false
