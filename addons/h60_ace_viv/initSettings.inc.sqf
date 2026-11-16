[
    QGVAR(loadDistance),
    "SLIDER",
    ["STR_hct_h60_ace_viv_MaximumLoadingDistance", "STR_hct_h60_ace_viv_MaxLoadingDistance_Tooltip"],
    ["STR_hct_h60_main_Category", "STR_hct_h60_ace_viv_SettingsCategory"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [5, 50, 15, 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(timeFactor),
    "SLIDER",
    ["STR_hct_h60_ace_viv_LoadingTimeFactor", "STR_hct_h60_ace_viv_LoadingTimeFactor_Tooltip"],
    ["STR_hct_h60_main_Category", "STR_hct_h60_ace_viv_SettingsCategory"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 1],
    true
] call CBA_Settings_fnc_init;
