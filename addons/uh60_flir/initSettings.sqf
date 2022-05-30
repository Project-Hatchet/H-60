[
    "vtx_uh60_flir_setting_AimSlewBlockMouse", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    [localize LSTRING(SettingFLIRAimSlewBlockMouse), LSTRING(SettingFLIRAimSlewBlockMouse_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_syncDelay", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [localize LSTRING(SyncDelay), LSTRING(SyncDelay_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.001, 0.1, 0.015, 3], // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimSlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [localize LSTRING(AimSlewSpeed), LSTRING(AimSlewSpeed_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [localize LSTRING(AimXFactor), LSTRING(AimXFactor_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_KeySlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [localize LSTRING(KeySlewSpeed), LSTRING(KeySlewSpeed_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_KeyXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [localize LSTRING(KeySlewPanSpeed), LSTRING(KeySlewPanSpeed_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_animateTurret", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    [localize LSTRING(AnimateTurret), LSTRING(AnimateTurret_Description)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;
