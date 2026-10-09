/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_fdKnob

Description:
    A dragged FD panel knob: its position as a fraction of the target's range, to Core.

Parameters:
    _heli   - The helicopter [Object]
    _target - "ralt", "alt", "altp", "ias" or "hdg" [String]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli", "_target"];

(vtx_uh60_helisim_fdKnobs get _target) params ["_source", "_perPhase", "_range", "_action"];
private _phase = _heli animationSourcePhase _source;
//The heading knob turns endlessly - past either end of the circle, put it back inside it
if (_target == "hdg") then {
    private _turn = _range / _perPhase;
    if (_phase < 0 || {_phase >= _turn}) then {
        _phase = ((_phase mod _turn) + _turn) mod _turn;
        _heli animateSource [_source, _phase, true];
    };
};
private _units = _phase * _perPhase;

//The knob follows Core's target again once the drag is over - see fn_updateCockpit
_heli setVariable ["vtx_uh60_helisim_fdKnobAt_" + _target, time];

[_heli, _action, _units / _range] call vtx_uh60_helisim_fnc_fmcInput;
