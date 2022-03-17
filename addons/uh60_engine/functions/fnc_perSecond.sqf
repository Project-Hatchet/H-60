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

if (_esisCount > -1) then {
    _vehicle setVariable ["ESIS_COUNTER", _esisCount - 1, true];
    _vehicle setUserMFDValue [49, _esisCount];
};

if (difficultyEnabledRTD) then {
    [_vehicle] call vtx_uh60_engine_fnc_acftRTDController;
};