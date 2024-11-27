/*
 * vtx_uh60_Sound_fnc_PlayEngineGlobal
 *
 * engine power Sound
 *
 * params (array)[(object) vehicle, (array) _Vars]
 */
params ["_vehicle","_Vars"];

//-Engine Start
if ((_Vars find "STARTING" > -1) && (_rotorspeed < 0.6)) then {
  [_vehicle,"Startup",40] call vtx_uh60_Sound_fnc_EngineEH;
};

//-Engine Off
if ((_Vars find "OFF" > -1) && (_rotorspeed != 0)) then {
  [_vehicle,"Shutdown",18] call vtx_uh60_Sound_fnc_EngineEH;
};