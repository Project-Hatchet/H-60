/*
 * vtx_uh60_mfd_fnc_ccfs_host
 *
 * CCFS: opens a lobby on this machine and shows the waiting page.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
vtx_uh60_ccfs_playerSelected = objNull;
[] call vtx_uh60_mfd_fnc_resetGameVariables;
vtx_uh60_ccfs_gameState = "WAITING";
vtx_uh60_ccfs_isHost = true;
player setVariable ["vtx_uh60_openLobby", true, true];
[_vehicle, _value, 8, true] call vtx_uh60_mfd_fnc_switchPage;
