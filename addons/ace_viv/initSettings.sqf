[
    QGVAR(loadDistance),
    "SLIDER",
    ["Maximum Loading Distance", "Cargo must be within this distance to be loaded"],
    ["UH-60M", "ViV"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [5, 50, 15, 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(timeFactor),
    "SLIDER",
    ["Loading Time Factor", "Multiplier for the time it takes to load cargo. Default is 2 + mass / 100 seconds."],
    ["UH-60M", "ViV"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 1],
    true
] call CBA_Settings_fnc_init;
