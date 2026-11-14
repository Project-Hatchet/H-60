/*
 * vtx_uh60_mfd_fnc_setRemoteVariable
 *
 * CCFS: sets a mission variable on the selected opponent's machine.
 *
 * params [(string) name, (any) value]
 */

params ["_key", "_value"];
[missionNamespace, [_key, _value]] remoteExec ["setVariable", vtx_uh60_ccfs_playerSelected];
