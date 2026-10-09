/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_cockpitInteract

Description:
    Hatchet's animStart (or buttonUp) for a HeliSim control. Hatchet is already moving
    the control; this tells HeliSim, on the aircraft's owner. See docs/HATCHET.md.

Parameters:
    _heli     - The helicopter [Object]
    _control  - The control's variableName, e.g. "batt1Switch" [String]
    _position - Hatchet's label ("APU BOOST" -> ApuBoost), or an index [String, Number]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli", "_control", "_position"];

private _index = _position;
if (_position isEqualType "") then {
    private _wanted = toLower ((_position splitString " ") joinString "");
    private _cfg = ("getText (_x >> 'variableName') == _control" configClasses (configOf _heli >> "BMKHS_HeliSim" >> "Controls")) param [0, configNull];
    _index = ("true" configClasses (_cfg >> "Positions")) findIf {toLower configName _x == _wanted};
};
if (_index < 0) exitWith {};

//Power lever to FLY takes the other one with it when that engine runs at IDLE. Hatchet
//moves it, so both travel at one rate. The other lever's own call skips this.
if (_control in ["eng1PwrLvr", "eng2PwrLvr"] && {_index == 2} && {isNil "vtx_uh60_helisim_linking"}) then {
    private _otherIdx = [1, 0] select (_control == "eng2PwrLvr");
    private _other    = ["eng1PwrLvr", "eng2PwrLvr"] select _otherIdx;
    if (((_heli getVariable "bmkhs_engState") # _otherIdx) == "ON" && {(_heli getVariable format ["bmkhs_%1Idx", _other]) == 1}) then {
        vtx_uh60_helisim_linking = true;
        [_heli, _other, 2] call vtx_uh60_helisim_fnc_cockpitBind;
        vtx_uh60_helisim_linking = nil;
    };
};

//Core's controlSet has no locality handling - it runs where the aircraft is local.
if (local _heli) then {
    [_control, _index, _heli] call bmkhs_fnc_controlSet;
} else {
    ["vtx_uh60_helisim_controlSet", [_control, _index, _heli], _heli] call CBA_fnc_targetEvent;
};
