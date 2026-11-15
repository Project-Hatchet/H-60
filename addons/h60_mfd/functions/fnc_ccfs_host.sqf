/*
 * hct_h60_mfd_fnc_ccfs_host
 *
 * CCFS: opens a lobby on this machine and shows the waiting page.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
hct_h60_ccfs_playerSelected = objNull;
[] call hct_h60_mfd_fnc_resetGameVariables;
hct_h60_ccfs_gameState = "WAITING";
hct_h60_ccfs_isHost = true;
player setVariable ["hct_h60_openLobby", true, true];
[_vehicle, _value, 8, true] call hct_h60_mfd_fnc_switchPage;
