/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_controlConfig

Description:
    A HeliSim control's config class and its position names, by the control's
    variableName. Cached per aircraft class: the cockpit glue asks on every
    interaction check and keybind, and the config never changes in a mission.

Parameters:
    _heli    - The helicopter [Object]
    _control - Control variableName, e.g. "eng1PwrLvr" [String]

Returns:
    [control config (configNull if none), position names in lower case] [Array]
---------------------------------------------------------------------------- */
params [["_heli", objNull, [objNull]], ["_control", "", [""]]];

if (isNil "vtx_uh60_helisim_controlCache") then { vtx_uh60_helisim_controlCache = createHashMap; };

private _type = typeOf _heli;
private _byControl = vtx_uh60_helisim_controlCache get _type;
if (isNil "_byControl") then {
    _byControl = createHashMap;
    {
        //keys lower case: SQF's string == (the lookup this replaces) ignores case;
        //first declaration wins, as the old configClasses ... param [0] did
        private _key = toLower getText (_x >> "variableName");
        if !(_key in _byControl) then {
            _byControl set [_key, [_x, ("true" configClasses (_x >> "Positions")) apply {toLower configName _x}]];
        };
    } forEach ("true" configClasses (configOf _heli >> "BMKHS_HeliSim" >> "Controls"));
    vtx_uh60_helisim_controlCache set [_type, _byControl];
};

_byControl getOrDefault [toLower _control, [configNull, []]]
