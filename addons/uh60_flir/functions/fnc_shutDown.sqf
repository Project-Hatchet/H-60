
params ["_vehicle"];

if (!(isEngineOn _vehicle)) then {
    _vehicle setPilotCameraTarget objNull;
    _vehicle setPilotCameraDirection [0,1,0];
    _vehicle lockCameraTo [objNull, [0]];
};

_this call vtx_uh60_flir_fnc_stopMFD;

{
  _x call CBA_fnc_removePlayerEventHandler;
} count vtx_uh60_flir_playerEHs;
