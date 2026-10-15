//Pack-wide developer switch (CBA, UH-60M > Developer). Default off.
//
//Developer Mode turns on, together:
//  - the developer panel (uh60_misc fnc_devPanel): HeliSim's live state on screen whenever
//    the player is in an H-60, and the automatic start's progress while one runs
//  - the "Automatic Engine Startup (DEV)" vehicle action (uh60_misc fnc_quickstart)
//  - script debug output to chat and the RPT across the pack (every former
//    vtx_uh60_ui_showDebugMessages read, and the uh60_ground taxi gate-hunt log)
//Read live everywhere, so switching it off mid-run aborts a start in progress and drops
//the panel.
[
    "vtx_uh60_devMode",
    "CHECKBOX",
    [LSTRING(DevMode), LSTRING(DevMode_Tooltip)],
    ["UH-60M", "Developer"],
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;
