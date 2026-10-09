/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_fmcInput

Description:
    A cockpit FMC button or knob, handed to Core's input on the aircraft's owner - the
    same action a keybind sends.

Parameters:
    _heli  - The helicopter [Object]
    _name  - Core's action, e.g. "bmkhs_fdAlt" [String]
    _value - Pressed, for a button; 0..1 of the target's range, for a knob [Bool, Number]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli", "_name", "_value"];

if (!local _heli) exitWith {
    ["vtx_uh60_helisim_fmcInput", _this, _heli] call CBA_fnc_targetEvent;
};

if (_value isEqualType true) then {
    [_name, _value, _heli] call bmkhs_fnc_inputControlHandle;
} else {
    [_name, _value, _heli] call bmkhs_fnc_inputAnalogHandler;
};
