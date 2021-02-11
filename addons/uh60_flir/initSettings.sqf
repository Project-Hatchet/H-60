[
    "vtx_uh60_flir_AnalogSlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    "FLIR Analog Slew Speed", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "UH-60M", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        vtx_uh60_flir_AnalogSlewSpeed = _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_KeySlewSpeed", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    "FLIR Key Slew Speed", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "UH-60M", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        vtx_uh60_flir_KeySlewSpeed = _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_AnalogXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    "FLIR Analog Pan Speed", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "UH-60M", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        vtx_uh60_flir_AnalogSlewSpeed = _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_KeyXFactor", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "SLIDER", // setting type
    "FLIR Key Pan Speed", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "UH-60M", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [0.1, 10, 1, 2], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        vtx_uh60_flir_KeySlewSpeed = _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[
    "vtx_uh60_flir_useCopilotAI", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Use Copilot AI", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "UH-60M", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    false, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        vtx_uh60_flir_useCopilotAI = _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;
