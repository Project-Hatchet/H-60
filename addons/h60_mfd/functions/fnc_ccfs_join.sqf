/*
 * hct_h60_mfd_fnc_ccfs_join
 *
 * CCFS: joins the selected player's lobby, or starts a game against the aircraft AI if that is the selection.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
if (isNull hct_h60_ccfs_playerSelected) exitWith {hint "No player selected"};
if (hct_h60_ccfs_playerSelected == player) exitWith {
	_this call hct_h60_mfd_fnc_startAIGame;
};
hct_h60_ccfs_isHost = false;
hct_h60_ccfs_playerSelected setVariable ["hct_h60_opponent", player, true];
player setVariable ["hct_h60_opponent", hct_h60_ccfs_playerSelected, true];
["hct_h60_ccfs_playerSelected", player] call hct_h60_mfd_fnc_setRemoteVariable;
[] call hct_h60_mfd_fnc_resetGameVariables;
["PAUSED"] call hct_h60_mfd_fnc_ccfs_changeGameState;
hct_h60_ccfs_playerSelected setVariable ["hct_h60_openLobby", false, true];
