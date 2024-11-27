/*
 * vtx_uh60_Sound_fnc_PlayAPUGlobal
 *
 * APU power Sound
 *
 * params (array)[(ARRAY) _args, (CODE) _Vars]
 * - _args : ["_vehicle","_old_status","_state"]
 */
params ["_args","_Vars"];

[{
  params["_vehicle","_old_status","_state"];

  //Simulate the APU spooling up
  _apuRPM_pct = [_vehicle,_state] call vtx_uh60_engine_fnc_acft_SetAPU;
  setCustomSoundController [_vehicle, "CustomSoundController1", _apuRPM_pct * 2];
  setCustomSoundController [_vehicle, "CustomSoundController2", _apuRPM_pct * 2];

  _status = ["battBusState","apuPwrSwitchState","apuFuelSwitchState"] apply {_vehicle getVariable ("vtx_uh60_acft_" + _x)};
  _condition = [_apuRPM_pct <= 0.001, _apuRPM_pct >= 0.9] select _state;

  !(alive _vehicle) || (_condition) || (_old_status isNotEqualTo _status)
},{
  params["_vehicle"];
  if ((_vehicle getVariable "vtx_uh60_acft_apuRPM_pct") <= 0.001) then {
    setCustomSoundController [_vehicle, "CustomSoundController1", 0];
    setCustomSoundController [_vehicle, "CustomSoundController2", 0];
    _vehicle setVariable ["vtx_uh60_acft_apuRPM_pct",0];
  };
}, _args] call CBA_fnc_waitUntilAndExecute;

//-Play APU startup sound
private _vehicle = _args # 0;
private _var = call _Vars;

if (({_x == "ON"} count _var) == 3) then {
  [_vehicle,"APU",8] call vtx_uh60_Sound_fnc_EngineEH;
};