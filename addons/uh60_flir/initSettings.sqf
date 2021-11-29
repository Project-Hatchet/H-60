[
    "vtx_uh60_flir_setting_AimSlewBlockMouse", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["FLIR Aim Slew Block Mouse", "Block mouse from moving the cyclic while slewing FLIR. Not needed if Aim Slew key is same as ACE Interaction key."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_syncDelay", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    ["Sync Delay", "Delay in seconds between each sync of pilot camera state between two player pilots. Higher is less network load."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.001, 0.1, 0.015, 3], // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimSlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    ["FLIR Aim Slew Speed", "Sensitivity when slewing the FLIR using mouse or 'Aim <Up|Down|Left|Right>' inputs."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    ["FLIR Aim Slew Pan Speed", "Sensitivity multiplier for pan vs tilt. Use this to adjust diagonal movement."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_KeySlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    ["FLIR Key Slew Speed", "Sensitivity when slewing the FLIR using the mod's keybinds."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_KeyXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    ["FLIR Key Slew Pan Speed", "Sensitivity multiplier for pan vs tilt. Use this to adjust diagonal movement."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_animateTurret", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Animate Turret", "Animate the FLIR pod model. Small performance savings if unchecked."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;
