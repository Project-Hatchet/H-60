params ["_vehicle"];
private _logic = "logic" createVehicleLocal [0,0,0];
_logic setName "MIKE";
vtx_uh60_ccfs_playerSelected = _logic;
vtx_uh60_ccfs_isHost = true;
[] call vtx_uh60_mfd_fnc_resetGameVariables;
vtx_uh60_ccfs_gameState = "PAUSED";