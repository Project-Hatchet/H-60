/*
 * hct_h60_mfd_fnc_startAIGame
 *
 * CCFS: starts a game against the aircraft AI (a local logic as the opponent).
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
private _logic = "logic" createVehicleLocal [0,0,0];
_logic setName "MIKE";
hct_h60_ccfs_playerSelected = _logic;
hct_h60_ccfs_isHost = true;
[] call hct_h60_mfd_fnc_resetGameVariables;
hct_h60_ccfs_gameState = "PAUSED";
