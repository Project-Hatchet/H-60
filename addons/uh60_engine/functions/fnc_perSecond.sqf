/*
 * vtx_uh60_engine_fnc_perSecond
 *
 * handles occasional updates of data
 *
 * params (array)[(object) vehicle]
 */
#include "defines.hpp"
params ["_vehicle"];

private _esisCount = _vehicle getVariable ["ESIS_COUNTER", 0];
if (!local _vehicle || vtx_uh60m_simpleStartup) exitWith {
    _vehicle setUserMFDValue [49, _esisCount];
};



private _eng1Powered = _vehicle getVariable ["ENG1_PWR",0] > 0;
private _eng2Powered = _vehicle getVariable ["ENG2_PWR",0] > 0;
private _apuPower = GET("APU_POWER",false);

_engine1Generator = ANIMATED("Switch_gen1",0) && _eng1Powered;
_engine2Generator = ANIMATED("Switch_gen2",0) && _eng2Powered;
_apuGenerator =     ANIMATED("Switch_apugen",0) && _apuPower;

private _batteriesOn = BATT_ON;
private _drainRate = GET("POWER_DRAIN_RATE",0);

if (_esisCount > -1) then {
    _vehicle setVariable ["ESIS_COUNTER", _esisCount - 1, true];
    _vehicle setUserMFDValue [49, _esisCount];
};

#define CONSUMPTION(POWER) (0.00158675799 * POWER + 0.092)
private _temp = ((getPosASL player) # 2) call ace_weather_fnc_calculateTemperatureAtHeight;
private _tempMultiplier = 1 + (_temp * 0.001);
private _torqueMultiplier = 1 + ((collectiveRTD _vehicle) * 0.1);
// Update fuel consumption
{ // forEach [GET("ENG1_PWR",0),GET("ENG2_PWR",0)]
    if(_x > 0) then {
        private _consumption = CONSUMPTION(_x) * _tempMultiplier * _torqueMultiplier;
        _vehicle setFuel ((fuel _vehicle) - (_consumption / 60 / 60));
    };
} forEach [GET("ENG1_PWR",0),GET("ENG2_PWR",0)];

private _fuelConsumed = vtx_uh60_engine_lastFuelLevel - fuel _vehicle;
vtx_uh60_engine_lastFuelLevel = fuel _vehicle;
if (_fuelConsumed > 0) then {
    private _fuelTimeSecondsTotal = (fuel _vehicle) / _fuelConsumed;
    private _fuelTimeHours = floor (_fuelTimeSecondsTotal / 60 / 60);
    private _fuelTimeMinutes = floor (_fuelTimeSecondsTotal / 60 % 60);
    private _fuelTimeSeconds = round (_fuelTimeSecondsTotal % 60);
    private _fuelTimeStr = format["%1:%2:%3",_fuelTimeHours, _fuelTimeMinutes, _fuelTimeSeconds];
    vtx_uh60_engine_fuelTime = _fuelTimeStr;
    vtx_uh60_engine_fuelConsumption = _fuelConsumed * 2040 * 60;
    vtx_uh60_engine_fuelRange = round ((_fuelTimeSecondsTotal * (vectorMagnitude (velocity _vehicle))) * 0.000539957);
};

private _fuelFlow1 = [_vehicle, "Lever_fuelsys1", "Switch_fuelboostpump1"] call vtx_uh60_engine_fnc_hasFuelFlow;
private _fuelFlow2 = [_vehicle, "Lever_fuelsys2", "Switch_fuelboostpump2"] call vtx_uh60_engine_fnc_hasFuelFlow;
if (isEngineOn _vehicle) then {
    private _enginePower1 = (_vehicle getVariable ["ENG1_PWR", 0]);
    private _enginePower2 = (_vehicle getVariable ["ENG2_PWR", 0]);
    private _wantedRPM1 = _enginePower1 * 250 * _fuelFlow1 * (1-(_vehicle getHitPointDamage "HitEngine1"));
    private _wantedRPM2 = _enginePower2 * 250 * _fuelFlow2 * (1-(_vehicle getHitPointDamage "HitEngine2"));
    _vehicle setWantedRPMRTD [_wantedRPM1, 30, 0];
    _vehicle setWantedRPMRTD [_wantedRPM2, 30, 1];
    vtx_uh60_engine_stateChanged = false;
    if (_vehicle getVariable "ENG_START1") then {
        if (enginesRpmRTD _vehicle # 0 > 5000) then {
             _vehicle setVariable ["ENG_START1", false, true];
             [_vehicle] call vtx_uh60_cas_fnc_updateCautions;
        };
    };
    if (_vehicle getVariable "ENG_START2") then {
        if (enginesRpmRTD _vehicle # 1 > 5000) then {
             _vehicle setVariable ["ENG_START2", false, true];
             [_vehicle] call vtx_uh60_cas_fnc_updateCautions;
        };
    };
} else {
    _vehicle setWantedRPMRTD [0, 10, 0];
    _vehicle setWantedRPMRTD [0, 10, 1];
};

_vehicle animate ["Gauge_temp_left", 0.5 + (_temp / 100), 2];
_vehicle animate ["Gauge_temp_right", 0.5 + (_temp / 100), 2];
