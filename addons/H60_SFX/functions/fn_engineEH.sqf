/*
 * vtx_uh60_Sound_fnc_EngineEH
 *
 * engine power eventhandler for sound
 *
 * By: Aaren
 */

params["_vehicle","_type","_delay"];

private _index = ["Startup","Shutdown","APU"] find _type;
{
  setCustomSoundController [_vehicle, "CustomSoundController1" + _x, [0,1] select (_index == _forEachIndex)];
} forEach ["0","1","2"];


[{
  params ["_vehicle","_index"];
  setCustomSoundController [_vehicle, "CustomSoundController1" + str _index, 0];
},
[_vehicle, _index],
_delay
] call CBA_fnc_waitAndExecute;
