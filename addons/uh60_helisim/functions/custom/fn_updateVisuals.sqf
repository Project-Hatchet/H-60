/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateVisuals

Description:
    Power visuals, engine sounds and OAT gauges, on the aircraft's owner.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];

private _battBus = _heli getVariable ["bmkhs_battBusOn", false];
private _acBus   = _heli getVariable ["bmkhs_acBusOn", false];
{
    _x params ["_source", "_phase"];
    if ((_heli animationSourcePhase _source) != _phase) then {
        _heli animateSource [_source, _phase, true];
    };
} forEach [
    ["PowerOnOff",      [0, 1] select _battBus],
    ["GeneratorsOnOff", [0, 1] select _acBus],
    ["ESIS_hide",       [1, 0] select (_battBus && {_acBus || {_heli getVariable ["bmkhs_stbyInstOn", false]}})]
];

private _engState = _heli getVariable ["bmkhs_engState", ["OFF", "OFF"]];
if (_engState isNotEqualTo (_heli getVariable ["vtx_uh60_helisim_lastEngState", ["OFF", "OFF"]])) then {
    _heli setVariable ["vtx_uh60_helisim_lastEngState", +_engState];
    ["vtx_uh60_helisim_playEngineSound", [_heli, +_engState, _heli getSoundController "RotorSpeed"]] call CBA_fnc_globalEvent;
};

if (time < (_heli getVariable ["vtx_uh60_helisim_visualsSecond", -1]) + 1) exitWith {};
_heli setVariable ["vtx_uh60_helisim_visualsSecond", time];

private _fat = _heli getVariable ["bmkhs_fat", 15];
_heli animate ["Gauge_temp_left",  0.5 + (_fat / 100), 2];
_heli animate ["Gauge_temp_right", 0.5 + (_fat / 100), 2];
