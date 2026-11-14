/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateLimits

Description:
    Swaps Core's dual engine torque limits by airspeed and its Nr limits by engine state,
    on the aircraft's owner, before Core's frame. Shared on change.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];
#include "\bmkhs_helisim\functions\core\core.hpp"

private _cfg = configOf _heli >> "BMKHS_HeliSim";

//Dual engine torque, below / above 80 kt
private _ias     = ((_heli getVariable ["bmkhs_vel2D", 0]) * MPS_TO_KNOTS) > 80;
private _engines = _heli getVariable ["bmkhs_engines", []];
private _changed = false;
{
    private _tq = getArray ((("true" configClasses (_cfg >> "Engines")) # _forEachIndex) >> (["tqLimitsSlow", "tqLimitsFast"] select _ias));
    if ((_x get "tqLimits") isNotEqualTo _tq) then {
        _x set ["tqLimits", _tq];
        _changed = true;
    };
} forEach _engines;
if (_changed) then { _heli setVariable ["bmkhs_engines", _engines, true] };

//Nr, power on with an engine running
private _powerOn = "ON" in (_heli getVariable ["bmkhs_engState", ["OFF", "OFF"]]);
private _nr = getArray (_cfg >> (["nrLimitsPowerOff", "nrLimitsPowerOn"] select _powerOn));
if ((_heli getVariable ["bmkhs_nrLimits", []]) isNotEqualTo _nr) then {
    _heli setVariable ["bmkhs_nrLimits", _nr, true];
};

//For the gauges - the continuous torque limit in force, and power on / off
if (_engines isNotEqualTo []) then {
    private _tqSet = (_engines # 0) get (["tqLimits", "tqLimitsSe"] select (_heli getVariable ["bmkhs_isSingleEng", false]));
    _heli setUserMFDValue [107, ((_tqSet # 0) # 0) * 100];
};
_heli setUserMFDValue [108, parseNumber _powerOn];
