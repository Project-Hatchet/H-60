// Pack-wide developer switch (CBA, Hatchet H-60 > Developer). Default off.
//
// Developer Mode turns on, together:
//  - the developer panel (h60_misc fnc_devPanel): HeliSim's live state on screen whenever
//    the player is in an H-60, and the automatic start's progress while one runs
//  - the "Automatic Engine Startup (DEV)" vehicle action (h60_misc fnc_quickstart)
//  - script debug output to chat and the RPT across the pack (it replaces the old
//    Enable Debug Messages setting, and the h60_ground taxi gate-hunt log)
// Read live everywhere, so switching it off mid-run aborts a start in progress and drops
// the panel.
[
    "hct_h60_devMode",
    "CHECKBOX",
    [LSTRING(DevMode), LSTRING(DevMode_Tooltip)],
    ["STR_hct_h60_main_Category", "STR_hct_h60_main_DeveloperCategory"],
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;
