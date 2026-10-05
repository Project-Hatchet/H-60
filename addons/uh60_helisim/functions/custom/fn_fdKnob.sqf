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
private _units = (_heli animationSourcePhase _source) * _perPhase;
if (_target == "hdg") then { _units = ((_units mod _range) + _range) mod _range };

//The knob follows Core's target again once the drag is over - see fn_updateCockpit
_heli setVariable ["vtx_uh60_helisim_fdKnobAt_" + _target, time];

[_heli, _action, _units / _range] call vtx_uh60_helisim_fnc_fmcInput;
