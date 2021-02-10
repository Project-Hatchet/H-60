/*
 * Author: Ampersand
 * Align the local copilot turret to the local pilotCamera
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_syncCameraMode
 */
/*
 * vtx_uh60_flir_fnc_syncCameraMode
 */
params ["_cameraMode"];
if vtx_uh60_flir_otherPilotIsPlayer then {
    ["vtx_uh60_flir_syncCameraMode", [_cameraMode], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
};

true
