/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_cockpitAllowed

Description:
    Hatchet's interactionCondition for a HeliSim control: whether it may move to the
    target position. A refused control does not move - a mechanical stop. Reads the
    control's interlocks as Core does (bmkhs_fnc_control). See docs/HATCHET.md.

Parameters:
    _args    - Hatchet's arguments: the lever array [vehicle, animation, target,
               label, ...], or the vehicle alone from buttonDown [Array, Object]
    _control - The control's variableName [String]

Returns:
    Whether it may move [Boolean]
---------------------------------------------------------------------------- */
params ["_args", "_control"];

//buttonDown checks with the vehicle alone - nothing to stop there
if !(_args isEqualType []) exitWith {true};
_args params ["_heli", "", "", "_label"];

private _cfg    = ("getText (_x >> 'variableName') == _control" configClasses (configOf _heli >> "BMKHS_HeliSim" >> "Controls")) param [0, configNull];
private _wanted = toLower ((_label splitString " ") joinString "");
private _poss   = "true" configClasses (_cfg >> "Positions");
private _index  = _poss findIf {toLower configName _x == _wanted};
if (_index < 0) exitWith {true};
private _pos = _poss # _index;

//A gate is a variable name, or {circuit, threshold} - circuits only solve where the aircraft is local
private _gate = {
    if (_this isEqualType []) then {
        !local _heli || {([_heli, _this # 0] call bmkhs_fnc_systemCircuit) >= (_this # 1)}
    } else {
        _heli getVariable [_this, false]
    };
};
private _enabled   = (getArray (_cfg >> "enabledBy") + getArray (_pos >> "enabledBy")) findIf {!(_x call _gate)} < 0;
private _inhibited = (getArray (_cfg >> "inhibitedBy") + getArray (_pos >> "inhibitedBy")) findIf {_x call _gate} >= 0;
if (!_enabled || _inhibited) exitWith {false};

//A power lever cannot go to FLY while the other engine is starting
if (_control in ["eng1PwrLvr", "eng2PwrLvr"] && {_index == 2}) exitWith {
    ((_heli getVariable "bmkhs_engState") # ([1, 0] select (_control == "eng2PwrLvr"))) != "STARTING"
};

true
