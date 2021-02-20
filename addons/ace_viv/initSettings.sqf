[
    QGVAR(loadDistance),
    "SLIDER",
    ["Loading Distance", "Cargo must be within this distance to be loaded"],
    "VXF Interaction",
    [5, 50, 15, 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(timeFactor),
    "SLIDER",
    ["Loading Time Factor", "Multiplier for the time it takes to load cargo. Default is 2 + mass / 100 seconds."],
    "VXF Interaction",
    [0.1, 10, 1, 1],
    true
] call CBA_Settings_fnc_init;
