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

private _battBus   = _heli getVariable ["bmkhs_battBusOn", false];
private _acBus     = _heli getVariable ["bmkhs_acBusOn", false];
private _stbyInst  = (_heli getVariable ["bmkhs_stbyInstIdx", 0]) == 1;
private _esisOn    = _battBus && {_acBus || _stbyInst};
if (_esisOn isNotEqualTo (_heli getVariable ["vtx_uh60_helisim_esisOn", false])) then {
    _heli setVariable ["vtx_uh60_helisim_esisOn", _esisOn, true];
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
if (_engState isNotEqualTo (_heli getVariable ["vtx_uh60_helisim_lastEngState", ["OFF", "OFF"]])) then {
    _heli setVariable ["vtx_uh60_helisim_lastEngState", +_engState];
    ["vtx_uh60_helisim_playEngineSound", [_heli, +_engState, _heli getSoundController "RotorSpeed"]] call CBA_fnc_globalEvent;
};

if (time < (_heli getVariable ["vtx_uh60_helisim_visualsSecond", -1]) + 1) exitWith {};
_heli setVariable ["vtx_uh60_helisim_visualsSecond", time];

private _fat = _heli getVariable ["bmkhs_fat", 15];
_heli animate ["Gauge_temp_left",  0.5 + (_fat / 100), 2];
_heli animate ["Gauge_temp_right", 0.5 + (_fat / 100), 2];
