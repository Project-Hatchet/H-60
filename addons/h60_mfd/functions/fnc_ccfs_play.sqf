/*
 * hct_h60_mfd_fnc_ccfs_play
 *
 * CCFS: toggles PLAYING / PAUSED.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
if (hct_h60_ccfs_gameState =="PAUSED") exitWith {
	["PLAYING"] call hct_h60_mfd_fnc_ccfs_changeGameState;
};
if (hct_h60_ccfs_gameState =="PLAYING") exitWith {
	["PAUSED"] call hct_h60_mfd_fnc_ccfs_changeGameState;
};
