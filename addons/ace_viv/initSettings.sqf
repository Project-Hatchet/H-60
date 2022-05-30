[
    QGVAR(loadDistance),
    "SLIDER",
    [localize LSTRING(MaxLoadingDistance), LSTRING(MaxLoadingDistance_Description)],
    ["UH-60M", "ViV"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [5, 50, 15, 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(timeFactor),
    "SLIDER",
    [localize LSTRING(LoadingTimeFactor), LSTRING(LoadingTimeFactor_Description)],
    ["UH-60M", "ViV"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 1],
    true
] call CBA_Settings_fnc_init;
