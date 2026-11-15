/*
 * hct_h60_mfd_fnc_ccfs_syncCCFS
 *
 * CCFS: keeps the game in step with a human opponent; drops to DISCONNECTED if they leave.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
if (isNull hct_h60_ccfs_playerSelected) exitWith {};
if (!isPlayer hct_h60_ccfs_playerSelected) exitWith {};
if (hct_h60_ccfs_gameState == "MENU") exitWith {};
private _otherOpponent = hct_h60_ccfs_playerSelected getVariable ["hct_h60_opponent", objNull];
if (_otherOpponent != player) then {
	hct_h60_ccfs_gameState = "DISCONNECTED";
};

hct_h60_ccfs_paddlePositions set [1, hct_h60_ccfs_playerSelected getVariable ["hct_h60_paddlePos", 0]];
//if (hct_h60_ccfs_paddleMoved) then {
player setVariable ["hct_h60_paddlePos", hct_h60_ccfs_paddlePositions # 0, true];
//	hct_h60_ccfs_paddleMoved = false;
//};

if (hct_h60_ccfs_isHost) then {
	["hct_h60_ccfs_ballPos", [1 - (hct_h60_ccfs_ballPos # 0), (hct_h60_ccfs_ballPos # 1)]] call hct_h60_mfd_fnc_setRemoteVariable;
};
