params ["_vehicle"];
if (isNull vtx_uh60_ccfs_playerSelected) exitWith {hint "No player selected"};
if (vtx_uh60_ccfs_playerSelected == player) exitWith {
  _this call vtx_uh60_mfd_fnc_startAIGame;
};
vtx_uh60_ccfs_isHost = false;
vtx_uh60_ccfs_playerSelected setVariable ["vtx_uh60_opponent", player, true];
player setVariable ["vtx_uh60_opponent", vtx_uh60_ccfs_playerSelected, true];
["vtx_uh60_ccfs_playerSelected", player] call vtx_uh60_mfd_fnc_setRemoteVariable;
[] call vtx_uh60_mfd_fnc_resetGameVariables;
["PAUSED"] call vtx_uh60_mfd_fnc_ccfs_changeGameState;
vtx_uh60_ccfs_playerSelected setVariable ["vtx_uh60_openLobby", false, true];