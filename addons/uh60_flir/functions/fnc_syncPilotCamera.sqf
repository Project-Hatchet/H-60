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
 * [_heli] call vtx_uh60_flir_fnc_syncPilotCamera
 */
//vtx_uh60_flir_fnc_syncPilotCamera={

params ["_rot_dir", "_target", ["_immediate", false]];
//systemChat format ["sending %1", _this];
if (
    vtx_uh60_flir_otherPilotIsPlayer
    && {_immediate || {CBA_missionTime - vtx_uh60_flir_lastSyncTimePilotCamera > 0.015}}
) exitWith {
    ["vtx_uh60_flir_syncPilotCamera", [_rot_dir, _target], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
    vtx_uh60_flir_lastSyncTimePilotCamera = CBA_missionTime;
    
    true
};

false
