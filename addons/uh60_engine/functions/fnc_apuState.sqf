/*
 * vtx_uh60_engine_fnc_apuState
 *
 * manages APU state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */
#include "defines.hpp"
params ["_vehicle", "_animName", "_animEndState"];

private _apuFueled = (_vehicle animationPhase "Switch_fuelPump" == 0) && (fuel _vehicle > 0);
private _apuState = _vehicle animationPhase "Switch_apucont" < 0.1;

private _apuWasOn = _vehicle getVariable ["APU_POWER", false];
private _turnAPUOn = (_apuFueled && _apuState);
if (_turnAPUOn && _animName == "Switch_apucont" && !_apuWasOn) then {
    if (!isNil "vtx_uh60_apuSound_dummy") then {deleteVehicle vtx_uh60_apuSound_dummy};
    vtx_uh60_apuSound_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
    vtx_uh60_apuSound_dummy attachTo [_vehicle, [0,-1,1]];
    vtx_uh60_apuSound_dummy say3d    ["VTX_UH60_Start_APU", 50, 1];
    [_vehicle, "APU ON", {(_this # 0) getVariable ["APU_POWER", false]}] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    if ((!_apuFueled || !_apuState) && _apuWasOn) then {
        if (!isNil "vtx_uh60_apuSound_dummy") then {deleteVehicle vtx_uh60_apuSound_dummy};
        vtx_uh60_apuSound_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
        vtx_uh60_apuSound_dummy attachTo [_vehicle, [0,-1,1]];
        vtx_uh60_apuSound_dummy say3d    ["VTX_UH60_Stop_APU", 50, 1];
        [_vehicle, "APU ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
    };
};
[_vehicle] spawn {
    params ["_vehicle"];
    sleep 4;
    private _apuFueled = (_vehicle animationPhase "Switch_fuelPump" == 0) && (fuel _vehicle > 0);
    private _apuState = _vehicle animationPhase "Switch_apucont" < 0.5;
    private _turnAPUOn = (_apuFueled && _apuState);
    _vehicle animateSource ["APUOn", 1];
    sleep 2;
    _vehicle setVariable ["APU_POWER", _turnAPUOn, true];
    [_vehicle] call vtx_uh60_engine_fnc_batteryState;
};

if ((_vehicle animationPhase "Switch_apugen" == 0) && _apuState) then {
    [_vehicle, "APU GEN ON", {(_this # 0) getVariable ["APU_POWER", false]}] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    [_vehicle, "APU GEN ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
};
