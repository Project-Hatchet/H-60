params ["_vehicle"];
if (vtx_uh60_ccfs_gameState =="PAUSED") exitWith {
  ["PLAYING"] call vtx_uh60_mfd_fnc_ccfs_changeGameState;
};
if (vtx_uh60_ccfs_gameState =="PLAYING") exitWith {
  ["PAUSED"] call vtx_uh60_mfd_fnc_ccfs_changeGameState;
};