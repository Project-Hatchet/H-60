/* ----------------------------------------------------------------------------
Function: hct_h60_helisim_fnc_updateVisuals

Description:
    Power visuals, engine sounds and OAT gauges, on the aircraft's owner.

Parameters:
    _heli - The helicopter [Object]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli"];

private _battBus   = _heli getVariable ["bmkhs_battBusOn", false];
private _acBus     = _heli getVariable ["bmkhs_acBusOn", false];
private _stbyInst  = (_heli getVariable ["bmkhs_stbyInstIdx", 0]) == 1;
private _esisOn    = _battBus && {_acBus || _stbyInst};
if (_esisOn isNotEqualTo (_heli getVariable ["hct_h60_helisim_esisOn", false])) then {
    _heli setVariable ["hct_h60_helisim_esisOn", _esisOn, true];
    if (_esisOn) then { _heli setVariable ["ESIS_START_TIME", CBA_missionTime, true] };
};
{
    _x params ["_anim", "_phase"];
    if ((_heli animationPhase _anim) != _phase) then {
        _heli animate [_anim, _phase, true];
    };
} forEach [
    ["PowerOnOff",      [0, 1] select _battBus],
    ["GeneratorsOnOff", [0, 1] select _acBus],
    ["ESIS_hide",       [1, 0] select _esisOn]
];

private _engState = _heli getVariable ["bmkhs_engState", ["OFF", "OFF"]];
if (_engState isNotEqualTo (_heli getVariable ["hct_h60_helisim_lastEngState", ["OFF", "OFF"]])) then {
    _heli setVariable ["hct_h60_helisim_lastEngState", +_engState];
    ["hct_h60_helisim_playEngineSound", [_heli, +_engState, _heli getSoundController "RotorSpeed"]] call CBA_fnc_globalEvent;
};

if (time < (_heli getVariable ["hct_h60_helisim_visualsSecond", -1]) + 1) exitWith {};
_heli setVariable ["hct_h60_helisim_visualsSecond", time];

// animate is a network message: send the gauges only when the reading moved
private _gauge = 0.5 + ((round (_heli getVariable ["bmkhs_fat", 15])) / 100);
if (_gauge != (_heli getVariable ["hct_h60_helisim_fatGauge", -1])) then {
    _heli setVariable ["hct_h60_helisim_fatGauge", _gauge];
    _heli animate ["Gauge_temp_left",  _gauge, 2];
    _heli animate ["Gauge_temp_right", _gauge, 2];
};
