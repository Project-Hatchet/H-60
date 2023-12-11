/*
 * vtx_uh60_engine_fnc_apuState
 *
 * manages APU state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */
#include "defines.hpp"
params ["_vehicle", "_animName", "_animEndState"];

_vehicle call vtx_uh60_engine_fnc_UpdateAPU_State;

private _Vars = ["battBusState","apuPwrSwitchState","apuFuelSwitchState"] apply {
  _vehicle getVariable ("vtx_uh60_acft_" + _x)
};

//- Play Sound Globally
[
  [
    [
      _vehicle ,_Vars,({_x == "ON"} count _Vars) == 3
    ],
  {["battBusState","apuPwrSwitchState","apuFuelSwitchState"] apply {_vehicle getVariable ("vtx_uh60_acft_" + _x)}}
], {
  params ["_args","_Vars"];

  [{
    params["_vehicle","_old_status","_state"];

    //Simulate the APU spooling up
    _apuRPM_pct = [_vehicle,_state] call vtx_uh60_engine_fnc_acft_SetAPU;
    setCustomSoundController [_vehicle, "CustomSoundController1", _apuRPM_pct * 2];
    setCustomSoundController [_vehicle, "CustomSoundController2", _apuRPM_pct * 2];

    _status = ["vtx_uh60_acft_battBusState","vtx_uh60_acft_apuPwrSwitchState","vtx_uh60_acft_apuFuelSwitchState"] apply {_vehicle getVariable _x};
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
  if (({_x == "ON"} count (call _Vars)) == 3) then {
    [_vehicle, ["vtx_soundAPUInt","vtx_soundAPUExt"],"ON", _Vars, 3, true] call vtx_uh60_Sound_fnc_EngineEH;
  };
}] remoteExecCall ['call', [0, -2] select isDedicated];
