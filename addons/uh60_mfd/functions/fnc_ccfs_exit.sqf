params ["_vehicle"];
vtx_uh60_ccfs_gameState = "MENU";
if (!isNull vtx_uh60_ccfs_playerSelected && vtx_uh60_ccfs_gameState != "DISCONNECTED") then {
  ["vtx_uh60_ccfs_playerSelected", objNull] call vtx_uh60_mfd_fnc_setRemoteVariable;
  ["vtx_uh60_ccfs_gameState", "DISCONNECTED"] call vtx_uh60_mfd_fnc_setRemoteVariable;
};
if (vtx_uh60_ccfs_isHost) then {
  player setVariable ["vtx_uh60_openLobby", false, true];
};
vtx_uh60_ccfs_playerSelected = objNull;