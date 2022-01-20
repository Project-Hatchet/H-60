[
    "vtx_uh60_hoist_setting_useAttachScript", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Use Attach Script", "When in the hoist hook, automatically switch between walking with hook attached and sitting in the hook seat based on height and cable stretch."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    ["UH-60M", "Hoist"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;
