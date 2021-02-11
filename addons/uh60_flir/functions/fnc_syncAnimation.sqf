/*
 * Author: Ampersand
 * Align the local or remote copilot turret to tracking target position
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 0: Position ASL <ARRAY>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_syncAnimation
 */
//vtx_uh60_flir_fnc_syncAnimation={
params ["_heli", "_target"];

private _heli = vehicle player;

// exit conditions
if (
    vtx_uh60_flir_isCopilotInGunnerView || {
    isNull (_heli turretUnit [0]) || {
    CBA_missionTime - vtx_uh60_flir_lastSyncTimeAnimation < 0.015}}
) exitWith { false };

// locality check
if (!(_heli turretLocal [0])) exitWith {_this remoteExecCall ["vtx_uh60_flir_fnc_syncAnimation", vtx_uh60_flir_otherPilot]; false };

["vtx_uh60_flir_syncPilotCamera", [_rot_dir, _target], [vtx_uh60_flir_otherPilot]] call CBA_fnc_targetEvent;
vtx_uh60_flir_lastSyncTimeAnimation = CBA_missionTime;

_heli lockCameraTo [_target, [0]];

true
