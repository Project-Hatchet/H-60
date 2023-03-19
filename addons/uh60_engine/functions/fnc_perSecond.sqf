#include "defines.hpp"

/*
 * vtx_uh60_engine_fnc_perSecond
 *
 * handles occasional updates of data
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

private _fuelConsumed = vtx_uh60_engine_lastFuelLevel - fuel _vehicle;

vtx_uh60_engine_lastFuelLevel = fuel _vehicle;
if (_fuelConsumed > 0) then {
    private _fuelTimeSecondsTotal = (fuel _vehicle) / _fuelConsumed;
    private _fuelTimeStr = [_fuelTimeSecondsTotal] call CBA_fnc_formatElapsedTime;
    vtx_uh60_engine_fuelTime = _fuelTimeStr;
    vtx_uh60_engine_fuelConsumption = _fuelConsumed * 2040 * 60;
    vtx_uh60_engine_fuelRange = round ((_fuelTimeSecondsTotal * (vectorMagnitude (velocity _vehicle))) * 0.000539957);
};

private _esisCount = _vehicle getVariable ["ESIS_COUNTER", 0];
if (!local _vehicle || vtx_uh60m_simpleStartup) exitWith {
    _vehicle setUserMFDValue [49, _esisCount];
};

if (_esisCount > -1) then {
    _vehicle setVariable ["ESIS_COUNTER", _esisCount - 1, true];
    _vehicle setUserMFDValue [49, _esisCount];
};

if (difficultyEnabledRTD) then {
    [_vehicle] call vtx_uh60_engine_fnc_acftRTDController;
};

private _temp = ((getPosASL player) # 2) call ace_weather_fnc_calculateTemperatureAtHeight;
_vehicle animate ["Gauge_temp_left", 0.5 + (_temp / 100), 2];
_vehicle animate ["Gauge_temp_right", 0.5 + (_temp / 100), 2];