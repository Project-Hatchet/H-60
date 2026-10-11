/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_cockpitAllowed

Description:
    Hatchet's interactionCondition for a HeliSim control: whether it may move to the
    target position. HeliSim's interlocks are Core's to answer (bmkhs_fnc_controlAllowed);
    a refused control does not move. See docs/HATCHET.md.

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
private _index  = ("true" configClasses (_cfg >> "Positions")) findIf {toLower configName _x == _wanted};
if (_index < 0) exitWith {true};

if !([_heli, _control, _index] call bmkhs_fnc_controlAllowed) exitWith {false};

//A power lever cannot go to FLY while the other engine is starting
if (_control in ["eng1PwrLvr", "eng2PwrLvr"] && {_index == 2}) exitWith {
    ((_heli getVariable "bmkhs_engState") # ([1, 0] select (_control == "eng2PwrLvr"))) != "STARTING"
};

true
