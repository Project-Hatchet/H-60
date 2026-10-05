vtx_uh60_helisim_baseClass = getText (configFile >> "CfgPatches" >> "vtx_uh60_helisim" >> "bmkhsBaseClass");

//Control moves and FMC input from a machine that doesn't own the aircraft
["vtx_uh60_helisim_controlSet", {_this call bmkhs_fnc_controlSet}] call CBA_fnc_addEventHandler;
["vtx_uh60_helisim_fmcInput", {_this call vtx_uh60_helisim_fnc_fmcInput}] call CBA_fnc_addEventHandler;

//FD panel knobs - {animation source, target units per phase, range, Core's value action, step}
vtx_uh60_helisim_fdKnobs = createHashMapFromArray [
    ["ralt", ["FD_1_ROT", 100,  1000,  "bmkhs_fdRaltTarget", 10]],
    ["altp", ["FD_2_ROT", 1000, 20000, "bmkhs_fdAltpTarget", 100]],
    ["alt",  ["FD_3_ROT", 1000, 20000, "bmkhs_fdAltTarget", 100]],
    ["ias",  ["FD_4_ROT", 100,  200,   "bmkhs_fdIasTarget", 10]],
    ["hdg",  ["FD_5_ROT", 36,   360,   "bmkhs_fdHdgTarget", 1]]
];
//FD mode lights - the panel's texture selection for each mode
vtx_uh60_helisim_fdLights = createHashMapFromArray [
    ["ralt", 3], ["altp", 4], ["alt", 5], ["ias", 6], ["hdg", 7], ["nav", "emmisive_fms"], ["hvr", "emmisive_hvr"]
];

//Engine and APU sound
["vtx_uh60_helisim_playEngineSound", {
    if (isDedicated) exitWith {};
    _this call vtx_uh60_Sound_fnc_PlayEngineGlobal;
}] call CBA_fnc_addEventHandler;
["vtx_uh60_helisim_playAPUSound", {
    if (isDedicated) exitWith {};
    _this call vtx_uh60_Sound_fnc_PlayAPUGlobal;
}] call CBA_fnc_addEventHandler;

[vtx_uh60_helisim_baseClass, {
    params ["_heli", "_event", ["_data", []]];

    switch (_event) do {
        case "fdModeChanged": {
            _data params ["_mode", "_on"];
            _heli setObjectTextureGlobal [vtx_uh60_helisim_fdLights get _mode, ["", "#(rgb,8,8,3)color(0,1,0,1)"] select _on];
        };

        case "apuStateChanged": {
            _heli animateSource ["APUOn", [0, 1] select (_heli getVariable ["bmkhs_apuOn", false]), true];
        };

        case "controlMoved": {
            //Hatchet animates the cockpit - nothing here moves a switch. See docs/HATCHET.md.
            _data params ["_name", "_idx", "_prevIdx", "_value", "_posName"];

            switch (_name) do {
                case "apuBtn": {
                    ["vtx_uh60_helisim_playAPUSound", [_heli, _value > 0]] call CBA_fnc_globalEvent;
                };
            };
        };
    };
}] call bmkhs_fnc_utilNotifyRegister;

//Core runs every local H-60, crewed or not.
vtx_uh60_helisim_frameHandler = addMissionEventHandler ["EachFrame", {
    {
        if (alive _x && {_x getVariable ["bmkhs_initialised", false]}) then {
            [_x] call vtx_uh60_helisim_fnc_perFrame;
        };
    } forEach (vehicles select {local _x && {_x isKindOf vtx_uh60_helisim_baseClass}});

    //Cockpit displays for the player's own H-60, local or not
    private _heli = vehicle player;
    if (_heli isKindOf vtx_uh60_helisim_baseClass && {_heli getVariable ["bmkhs_initialised", false]}) then {
        [_heli] call vtx_uh60_helisim_fnc_updateCockpit;
    };
}];
