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
if (("STARTING" in _Vars) && (_rotorspeed < 0.6)) then {
  [_vehicle,"Startup",40] call hct_h60_sounds_fnc_EngineEH;
};

//-Engine Off
if (("OFF" in _Vars) && (_rotorspeed != 0)) then {
  [_vehicle,"Shutdown",18] call hct_h60_sounds_fnc_EngineEH;
};
