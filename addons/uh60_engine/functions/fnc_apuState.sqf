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

//Manage APU fuel pump State
 // - Exit so there's this function can be overwriten
if (_animName == "Switch_fuelPump") exitwith {
  [{
      params ["_vehicle"];
      _apuFuelSwitchPos = _vehicle animationPhase "Switch_fuelPump";
      _state = ["OFF","ON"] select (_apuFuelSwitchPos <= 0.1);

      //- Exit if Current value and result is the same
      if ((_vehicle getVariable ["vtx_uh60_acft_apuFuelSwitchState", "OFF"]) == _state) exitWith {};

      _vehicle setVariable ["vtx_uh60_acft_apuFuelSwitchState", _state, true];
      
      //- overwrite this function
      _this set [1,"APU_FUEL"];
      _this call vtx_uh60_engine_fnc_apuState;
    },
    _this,
    //- Random between 8~10 sec (For APU burns out the fuel)
    [random [8, 9, 10] ,0] select ((_vehicle getVariable ["vtx_uh60_acft_apuFuelSwitchState","OFF"]) == "OFF")
  ] call CBA_fnc_waitAndExecute;
};

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
  params ["_args","_Vars","_APU_Exception"];

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
}] remoteExecCall ['call', [0, -2] select isDedicated];
