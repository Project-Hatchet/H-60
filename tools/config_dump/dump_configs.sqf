comment "VTX H-60 Phase 1 config-dump harness (WP0). Docs: tools/config_dump/README.md. This file must stay comment-free: the debug console compiles pasted text WITHOUT the preprocessor, so // and /* */ are parse errors here (the comment command is safe).";

VTXDUMP_lines = 0;

VTXDUMP_fnc_emit = {
    private _line = _this;
    private _marker = "VTXDUMP|";
    while { true } do {
        diag_log text (_marker + (_line select [0, 900]));
        VTXDUMP_lines = VTXDUMP_lines + 1;
        if (count _line <= 900) exitWith {};
        _line = _line select [900];
        _marker = "VTXDUMP+|";
    };
};

VTXDUMP_fnc_walk = {
    params ["_cfg", "_file", "_path", "_depth"];
    if (_depth > 24) exitWith {
        (_file + "|" + _path + "|ERROR|depthLimit|") call VTXDUMP_fnc_emit;
    };

    (_file + "|" + _path + "|inherits||" + configName inheritsFrom _cfg) call VTXDUMP_fnc_emit;

    private _propNames = (configProperties [_cfg, "!isClass _x", true]) apply { configName _x };
    _propNames sort true;
    {
        private _p = _cfg >> _x;
        private _out = _file + "|" + _path + "|?|" + configName _p + "|";
        if (isNumber _p) then { _out = _file + "|" + _path + "|N|" + configName _p + "|" + str getNumber _p; };
        if (isText _p)   then { _out = _file + "|" + _path + "|T|" + configName _p + "|" + str getText _p; };
        if (isArray _p)  then { _out = _file + "|" + _path + "|A|" + configName _p + "|" + str getArray _p; };
        _out call VTXDUMP_fnc_emit;
    } forEach _propNames;

    private _subNames = (configProperties [_cfg, "isClass _x", true]) apply { configName _x };
    (_file + "|" + _path + "|classOrder||" + (_subNames joinString ",")) call VTXDUMP_fnc_emit;
    _subNames sort true;
    {
        [_cfg >> _x, _file, _path + " >> " + _x, _depth + 1] call VTXDUMP_fnc_walk;
    } forEach _subNames;
};

private _t0 = diag_tickTime;

("META|BEGIN|game=" + str productVersion) call VTXDUMP_fnc_emit;
("META|modVersion|" + getText (configFile >> "CfgPatches" >> "vtx_main" >> "versionStr")) call VTXDUMP_fnc_emit;

private _vehicles = [
    "vtx_H60_base",
    "vtx_UH60M", "vtx_UH60M_SLICK", "vtx_UH60M_MEDEVAC",
    "vtx_HH60", "vtx_S70M",
    "vtx_MH60M", "vtx_MH60M_DAP", "vtx_MH60M_DAP_MLASS",
    "vtx_MH60S", "vtx_MH60S_Pylons", "vtx_MH60S_GAU21L", "vtx_MH60S_Pylons_GAU21L"
];
{
    private _cfg = configFile >> "CfgVehicles" >> _x;
    if (isClass _cfg) then {
        [_cfg, configName _cfg, configName _cfg, 0] call VTXDUMP_fnc_walk;
    } else {
        (_x + "||ERROR|missingClass|") call VTXDUMP_fnc_emit;
    };
} forEach _vehicles;

{
    private _rootName = _x;
    private _root = configFile >> _rootName;
    if (isClass _root) then {
        private _kidNames = (configProperties [_root, "isClass _x", false]) apply { configName _x };
        _kidNames sort true;
        {
            private _kid = _root >> _x;
            private _srcs = (configSourceAddonList _kid) apply { toLower _x };
            if (_srcs findIf { (_x select [0, 4]) == "vtx_" } > -1) then {
                [_kid, _rootName, _rootName + " >> " + configName _kid, 0] call VTXDUMP_fnc_walk;
            };
        } forEach _kidNames;
    };
} forEach [
    "CfgSoundShapes", "CfgSoundCurves", "CfgSound3DProcessors",
    "cfgDistanceFilters", "CfgSoundSets", "CfgSoundShaders",
    "CfgSounds", "CfgSFX", "CfgMusic", "CfgFunctions"
];

("META|DONE|lines=" + str VTXDUMP_lines + "|seconds=" + str (diag_tickTime - _t0)) call VTXDUMP_fnc_emit;
systemChat "VTX config dump complete - run tools/config_dump/extract_dump.ps1";
hint ("VTX config dump complete" + toString [10] + str VTXDUMP_lines + " lines in " + str (diag_tickTime - _t0) + "s" + toString [10] + "Now run tools/config_dump/extract_dump.ps1");

VTXDUMP_fnc_emit = nil;
VTXDUMP_fnc_walk = nil;
VTXDUMP_lines = nil;
