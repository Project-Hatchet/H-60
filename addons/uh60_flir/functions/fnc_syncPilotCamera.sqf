/*
 * Author: Ampersand
 * Sync the rotation/direction and tracking target of the pilotCamera to the other player pilot
 *
 * Arguments:
 * 0: Rotation <ARRAY> || Direction <ARRAY>
 * 1: Target <OBJECT> || Position ASL <ARRAY>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_syncPilotCamera
 */

params ["_rot_dir", "_target", ["_targetObject", objNull], ["_immediate", false]];

vtx_uh60_flir_pilotCameraTarget = getPilotCameraTarget vxf_vehicle;
if (vtx_uh60_flir_pilotCameraTarget # 0) then {
  vtx_uh60_flir_pilotCameraTarget set [2, _targetObject];
};

if (
    vtx_uh60_flir_otherPilotIsPlayer
    && {_immediate || {CBA_missionTime - vtx_uh60_flir_lastSyncTimePilotCamera > vtx_uh60_flir_setting_syncDelay}}
) exitWith {
    ["vtx_uh60_flir_syncPilotCamera", [_rot_dir, _target, _targetObject], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
    vtx_uh60_flir_lastSyncTimePilotCamera = CBA_missionTime;

    true
};

false
