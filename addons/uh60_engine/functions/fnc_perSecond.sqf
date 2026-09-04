/*
 * vtx_uh60_engine_fnc_perSecond
 *
 * handles occasional updates of data
 *
 * params (array)[(object) vehicle]
 */
#include "defines.hpp"
#include "\z\vtx\addons\uh60_fms\config\fmsDefines.hpp"
params ["_vehicle"];

private _fuel = fuel _vehicle;
private _fuelConsumed = (_vehicle getVariable ["vtx_uh60_engine_lastFuelLevel", _fuel]) - _fuel;

_vehicle setVariable ["vtx_uh60_engine_lastFuelLevel", _fuel];

private _isPilotSeat = (player == driver _vehicle) || {(_vehicle unitTurret player) isEqualTo [0]};
if (_isPilotSeat) then {
    private _fmsPageIndex = if (player == driver _vehicle) then {FMS_R_PAGE_INDEX} else {FMS_L_PAGE_INDEX};
    if (((getUserMFDValue _vehicle) # _fmsPageIndex) == FMS_PAGE_PERFORMANCE && {_fuelConsumed > 0}) then {
        private _fuelTimeSecondsTotal = (fuel _vehicle) / _fuelConsumed;
        SET("vtx_uh60_engine_fuelTime", [_fuelTimeSecondsTotal] call CBA_fnc_formatElapsedTime);
        SET("vtx_uh60_engine_fuelConsumption", _fuelConsumed * 2040 * 60);
        SET("vtx_uh60_engine_fuelRange", round ((_fuelTimeSecondsTotal * (vectorMagnitude (velocity _vehicle))) * 0.000539957));
    };
};

private _esisCount = _vehicle getVariable ["ESIS_COUNTER", 0];
if (!local _vehicle) exitWith {
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
