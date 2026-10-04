vtx_uh60_helisim_baseClass = getText (configFile >> "CfgPatches" >> "vtx_uh60_helisim" >> "bmkhsBaseClass");

//Control moves from a machine that doesn't own the aircraft
["vtx_uh60_helisim_controlSet", {_this call bmkhs_fnc_controlSet}] call CBA_fnc_addEventHandler;

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
