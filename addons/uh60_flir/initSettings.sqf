// "Use Scripted Camera" setting removed: its off-mode selected the copilot
// turret optics, disabled until the model gains a View - Gunner LOD (#560).
// Restore the setting together with the optics if the mode returns.

[
    "vtx_uh60_flir_setting_animateTurret", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    [LSTRING(AnimateTurret), LSTRING(AnimateTurret_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimSlewBlockMouse", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    [LSTRING(AimSlewBlockMouse), LSTRING(AimSlewBlockMouse_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_syncDelay", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [LSTRING(SyncDelay), LSTRING(SyncDelay_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.001, 0.1, 0.015, 3], // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimSlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [LSTRING(AimSlewSpeed), LSTRING(AimSlewSpeed_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_AimXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [LSTRING(AimXFactor), LSTRING(AimXFactor_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_KeySlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [LSTRING(KeySlewSpeed), LSTRING(KeySlewSpeed_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_setting_KeyXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    [LSTRING(KeyXFactor), LSTRING(KeyXFactor_Tooltip)], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "FLIR"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.01, 100, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;
