/*
 * vtx_uh60_engine_fnc_starterState
 *
 * manages starter state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */

params ["_vehicle", "_animName", "_animEndState"];

private _batteriesOn = (_vehicle getVariable ["BATT1_POWER", 100]) + (_vehicle getVariable ["BATT2_POWER", 100]) > 0;
private _ignitionState = (_vehicle animationPhase "Switch_ignition" == 1) && _batteriesOn;
if (!_ignitionState) exitWith {
    _vehicle setVariable ["ENG_START1", false, true];
    _vehicle setVariable ["ENG_START2", false, true];
};
private _airFlow =
    (_vehicle animationPhase "Switch_airsce" < 0.2 && _vehicle getVariable ["APU_POWER", false]) ||
    (_vehicle animationPhase "Switch_airsce" > 0.7 && isEngineOn _vehicle);

// this code should only run when ignition is on
private _altASLKFt = ((getPosASL player) # 2) * 3.28 / 1000;
private _temp = ((getPosASL player) # 2) call ace_weather_fnc_calculateTemperatureAtHeight;

private _canStartTwin = false;
private _canStartSingle = false;

if (_temp > -55 && _temp < 52) then {
    private _underSingleStartSlope = _altASLKFt < (-(6/19) * _temp + 7.9);
    private _underSingleStartLimit = _altASLKFt < 18;
    private _underTwinStartSlope = _altASLKFt < (-(17/28) * _temp + 31.57);
    private _underTwinStartLimit = _altASLKFt < 6;
    _canStartSingle = _underSingleStartSlope && _underSingleStartLimit && _airFlow;
    _canStartTwin = _underTwinStartSlope && _underTwinStartLimit && _airFlow;
};

if(vtx_uh60_ui_showDebugMessages) then {systemChat str [_canStartSingle, _canStartTwin];};

if (_animName == "STARTER1") then {
    if((_vehicle getVariable ["ENG_START2", false] && _canStartSingle) || _canStartTwin) then {
        _vehicle setVariable ["ENG_START1", true, true];
        vtx_uh60_start1_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
        vtx_uh60_start1_dummy attachTo [_vehicle, [-1,-1,1]];
        vtx_uh60_start1_dummy say3d    ["VTX_UH60_Start_APU", 50, 2];
    } else {
    if (!isNil "vtx_uh60_start1_dummy") then {deleteVehicle vtx_uh60_start1_dummy};
        _vehicle setVariable ["ENG_START2", false, true];
    };
};
if (_animName == "STARTER2") then {
    if((_vehicle getVariable ["ENG_START1", false] && _canStartSingle) || _canStartTwin) then {
        _vehicle setVariable ["ENG_START2", true, true];
        vtx_uh60_start2_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
        vtx_uh60_start2_dummy attachTo [_vehicle, [1,-1,1]];
        vtx_uh60_start2_dummy say3d    ["VTX_UH60_Start_APU", 50, 2];
    } else {
        _vehicle setVariable ["ENG_START1", false, true];
        if (!isNil "vtx_uh60_start2_dummy") then {deleteVehicle vtx_uh60_start2_dummy};
    };
};

[_vehicle] call vtx_uh60_cas_fnc_updateCautions;