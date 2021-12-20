params ["_vehicle"];

if (!(isEngineOn _vehicle)) then {
    _vehicle setPilotCameraTarget objNull;
    _vehicle setPilotCameraDirection [0, 1, 0];
    [_vehicle] call vtx_uh60_flir_fnc_syncAnimation;
};

if (!isNil "vtx_uh60_flir_camera") then {
  [_vehicle] call vtx_uh60_flir_fnc_pipStop;
};

{
  _x call CBA_fnc_removePlayerEventHandler;
} count vtx_uh60_flir_playerCBAEHs;

{
  _vehicle removeEventHandler _x;
} count vtx_uh60_flir_vehicleEHs;

{
  player removeEventHandler _x;
} count vtx_uh60_flir_playerEHs;

call vtx_uh60_flir_fnc_initVars;
