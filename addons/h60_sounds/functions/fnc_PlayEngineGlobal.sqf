#include "..\script_component.hpp"
/*
 * hct_h60_sounds_fnc_PlayEngineGlobal
 *
 * engine power Sound
 *
 * params (array)[(object) vehicle, (array) _Vars, (number) _rotorspeed]
 */
params ["_vehicle","_Vars","_rotorspeed"];

//-Engine Start
if ((_Vars find "STARTING" > -1) && (_rotorspeed < 0.6)) then {
  [_vehicle,"Startup",40] call hct_h60_sounds_fnc_EngineEH;
};

//-Engine Off
if ((_Vars find "OFF" > -1) && (_rotorspeed != 0)) then {
  [_vehicle,"Shutdown",18] call hct_h60_sounds_fnc_EngineEH;
};
