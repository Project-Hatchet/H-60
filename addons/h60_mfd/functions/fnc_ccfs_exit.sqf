/*
 * hct_h60_mfd_fnc_ccfs_exit
 *
 * CCFS: leaves the game, telling the opponent and closing a hosted lobby.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
hct_h60_ccfs_gameState = "MENU";
if (!isNull hct_h60_ccfs_playerSelected && hct_h60_ccfs_gameState != "DISCONNECTED") then {
	["hct_h60_ccfs_playerSelected", objNull] call hct_h60_mfd_fnc_setRemoteVariable;
	["hct_h60_ccfs_gameState", "DISCONNECTED"] call hct_h60_mfd_fnc_setRemoteVariable;
};
if (hct_h60_ccfs_isHost) then {
	player setVariable ["hct_h60_openLobby", false, true];
};
hct_h60_ccfs_playerSelected = objNull;
