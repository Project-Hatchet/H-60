[
    "STR_hct_h60_main_Category",
    "hct_h60_c_help",
    LSTRING(HelpMode),
    {},{
        private _vehicle = vehicle player;
        if ([_vehicle, "ui", QBASE_CLASS] call hct_core_fnc_hasModule) then {
            hct_h60_ui_helpEnabled = !hct_h60_ui_helpEnabled;
            [_vehicle, hct_h60_ui_helpEnabled] call hct_h60_ui_fnc_showHelp;
        };
    },
    [35, [false, true, false]],
    false
] call CBA_fnc_addKeybind;
