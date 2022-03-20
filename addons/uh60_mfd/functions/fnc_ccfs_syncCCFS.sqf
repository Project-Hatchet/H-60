params ["_vehicle"];
if (isNull vtx_uh60_ccfs_playerSelected) exitWith {};
if (!isPlayer vtx_uh60_ccfs_playerSelected) exitWith {};
if (vtx_uh60_ccfs_gameState == "MENU") exitWith {};
private _otherOpponent = vtx_uh60_ccfs_playerSelected getVariable ["vtx_uh60_opponent", objNull];
if (_otherOpponent != player) then {
	vtx_uh60_ccfs_gameState = "DISCONNECTED";
};

vtx_uh60_ccfs_paddlePositions set [1, vtx_uh60_ccfs_playerSelected getVariable ["vtx_uh60_paddlePos", 0]];
//if (vtx_uh60_ccfs_paddleMoved) then {
player setVariable ["vtx_uh60_paddlePos", vtx_uh60_ccfs_paddlePositions # 0, true];
//	vtx_uh60_ccfs_paddleMoved = false;
//};

if (vtx_uh60_ccfs_isHost) then {
	["vtx_uh60_ccfs_ballPos", [1 - (vtx_uh60_ccfs_ballPos # 0), (vtx_uh60_ccfs_ballPos # 1)]] call vtx_uh60_mfd_fnc_setRemoteVariable;
};