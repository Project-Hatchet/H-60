/*
 * vtx_uh60_engine_fnc_apuState
 *
 * manages APU state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */
#include "defines.hpp"
params ["_vehicle", "_animName", "_animEndState"];

_battBusState = _vehicle getVariable "vtx_uh60_acft_battBusState";
_apuPwrSwitchState = _vehicle getVariable "vtx_uh60_acft_apuPwrSwitchState";
_apuFuelSwitchState = _vehicle getVariable "vtx_uh60_acft_apuFuelSwitchState";

if (_apuPwrSwitchState == "ON" && _apuFuelSwitchState == "ON" && _battBusState == "ON") then {
  [_vehicle,["vtx_soundAPUInt","vtx_soundAPUExt"],"ON", {
    ["vtx_uh60_acft_battBusState","vtx_uh60_acft_apuPwrSwitchState","vtx_uh60_acft_apuFuelSwitchState"] apply {_vehicle getVariable _x}
  },3] call vtx_uh60_Sound_fnc_EngineEH;
};
