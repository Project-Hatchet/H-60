#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_perFrame

Description:
    Per-frame tick for one local H-60. Core runs the whole frame; this pack then
    decides whether the engines should be running from the stock cockpit.

    The stock cockpit reads Core's published variables (bmkhs_engState,
    bmkhs_engPctNg, ...) directly, so nothing is copied back.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing

Author:
    BradMick
---------------------------------------------------------------------------- */
params ["_heli"];

[_heli] call bmkhs_fnc_coreUpdate;

/////////////////////////////////////////////////////////////////////////////////////////////
// Engine start / stop - stock cockpit -> Core  /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//With useSystems = 0, Core starts its engines when Arma's engine is on and stops them when it
//is off. The stock cockpit decides that: its start switch latches an engine's starter ON
//(fnc_starterState) and its power levers say IDLE / FLY. An engine is wanted when it is
//starting or running and its lever is out of OFF; pulling every lever to OFF shuts down.
private _coreState = _heli getVariable "bmkhs_engState";
private _wantOn    = false;
{
    _x params ["_engNum", "_starterVar", "_leverVar"];
    private _core    = _coreState param [_engNum, "OFF"];
    private _starter = _heli getVariable [_starterVar, "OFF"];

    //The starter cuts out once Core has the engine lit.
    if (_starter == "ON" && {_core == "ON"}) then {
        _heli setVariable [_starterVar, "OFF", true];
        _starter = "OFF";
    };

    if ((_starter == "ON" || {_core != "OFF"}) && {(_heli getVariable [_leverVar, "OFF"]) != "OFF"}) then {
        _wantOn = true;
    };
} forEach [
    [0, "vtx_uh60_acft_eng1StarterState", "vtx_uh60_acft_eng1PwrCtrlLeverState"],
    [1, "vtx_uh60_acft_eng2StarterState", "vtx_uh60_acft_eng2PwrCtrlLeverState"]
];

if (isEngineOn _heli isNotEqualTo _wantOn) then {
    _heli engineOn _wantOn;
};
