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

//Config tables are fixed for the mission: read once per class, not every frame
private _type = typeOf _heli;
private _limits = vtx_uh60_helisim_limitCache get _type;
if (isNil "_limits") then {
    private _cfg = configOf _heli >> "BMKHS_HeliSim";
    _limits = [
        ("true" configClasses (_cfg >> "Engines")) apply {[getArray (_x >> "tqLimitsSlow"), getArray (_x >> "tqLimitsFast")]},
        getArray (_cfg >> "nrLimitsPowerOff"),
        getArray (_cfg >> "nrLimitsPowerOn")
    ];
    vtx_uh60_helisim_limitCache set [_type, _limits];
};
_limits params ["_engLimits", "_nrOff", "_nrOn"];

//Dual engine torque, below / above 80 kt
private _ias     = ((_heli getVariable ["bmkhs_vel2D", 0]) * MPS_TO_KNOTS) > 80;
private _engines = _heli getVariable ["bmkhs_engines", []];
private _changed = false;
{
    //an engine the config does not list keeps whatever limits it has
    private _tq = (_engLimits param [_forEachIndex, [_x get "tqLimits", _x get "tqLimits"]]) select _ias;
    if ((_x get "tqLimits") isNotEqualTo _tq) then {
        _x set ["tqLimits", +_tq]; //copy: never hand Core the cached array
        _changed = true;
    };
} forEach _engines;
if (_changed) then { _heli setVariable ["bmkhs_engines", _engines, true] };

//Nr, power on with an engine running
private _powerOn = "ON" in (_heli getVariable ["bmkhs_engState", ["OFF", "OFF"]]);
private _nr = [_nrOff, _nrOn] select _powerOn;
if ((_heli getVariable ["bmkhs_nrLimits", []]) isNotEqualTo _nr) then {
    _heli setVariable ["bmkhs_nrLimits", +_nr, true];
};

//For the gauges - the continuous torque limit in force, and power on / off
if (_engines isNotEqualTo []) then {
    private _tqSet = (_engines # 0) get (["tqLimits", "tqLimitsSe"] select (_heli getVariable ["bmkhs_isSingleEng", false]));
    _heli setUserMFDValue [107, ((_tqSet # 0) # 0) * 100];
};
_heli setUserMFDValue [108, parseNumber _powerOn];
