/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_cockpitBind

Description:
    Moves a HeliSim control from script - keybinds and linked controls. Goes through the
    control's Hatchet interaction, so Hatchet animates it and its animStart tells
    HeliSim, the same as a click. See docs/HATCHET.md.

Parameters:
    _heli    - The helicopter [Object]
    _control - The control's variableName [String]
    _index   - Position index [Number]

Returns:
    Nothing
---------------------------------------------------------------------------- */
params ["_heli", "_control", "_index"];

private _hct = _heli getVariable ["hct_config", configNull];
if (isNull _hct) exitWith {};

private _cfg  = ("getText (_x >> 'variableName') == _control" configClasses (configOf _heli >> "BMKHS_HeliSim" >> "Controls")) param [0, configNull];
private _path = getArray (_cfg >> "hctInteraction");
private _item = _hct >> "interaction";
{_item = _item >> _x} forEach _path;

//scriptedInteract leaves its interaction as Hatchet's current button; put the cursor's back.
private _prev = missionNamespace getVariable "hct_interaction_currentButton";

private _labels = getArray (_item >> "animLabels");
if (_labels isEqualTo []) then {
    //A button (the starters) - pressing it is all a bind can do
    if (_index != getNumber (_cfg >> "rest")) then {
        [_heli, _path] call hct_interaction_fnc_scriptedInteract;
    };
} else {
    private _posName = toLower configName (("true" configClasses (_cfg >> "Positions")) # _index);
    private _label   = _labels param [_labels findIf {toLower ((_x splitString " ") joinString "") == _posName}, ""];
    if (_label != "") then {
        [_heli, _path, _label] call hct_interaction_fnc_scriptedInteract;
    };
};

missionNamespace setVariable ["hct_interaction_currentButton", _prev];
