[
    "hct_h60_anvishud_defaultMode", "LIST",
    [localize LSTRING(HMDDefaultMode), LSTRING(HMDDefaultMode_Description)],
    ["STR_hct_h60_main_Category", "STR_hct_h60_anvishud_SettingsCategory"],
    [[-1, 1, 2, 3, 4], [
        "STR_3DEN_Attributes_Radar_RadarOff_text",
        LSTRING(ImperialFull),
        LSTRING(ImperialDecluttered),
        LSTRING(MetricFull),
        LSTRING(MetricDecluttered)
    ], 0],
    false // isGlobal
] call CBA_settings_fnc_init;

[
    "hct_h60_anvishud_settingColor",
    "COLOR",
    [localize LSTRING(Color), LSTRING(Color_Description)],
    ["STR_hct_h60_main_Category", "STR_hct_h60_anvishud_SettingsCategory"],
    [0.082, 0.608, 0.039],
    false, // isGlobal
    {
      private _vehicle = vehicle player;
      if !(_vehicle isKindOf QBASE_CLASS) exitWith {};
      [_vehicle] call hct_h60_anvishud_fnc_configureHMD;
    },
    false
] call CBA_settings_fnc_init;

[
    "hct_h60_anvishud_settingBrightness",
    "SLIDER",
    [localize LSTRING(Brightness), LSTRING(Brightness_Description)],
    ["STR_hct_h60_main_Category", "STR_hct_h60_anvishud_SettingsCategory"],
    [0, 1, 0.6, 2, true], //4th parameter (boolean) expresses slider value as % in settings
    false, // "_isGlobal"
    {
        private _vehicle = vehicle player;
        if !(_vehicle isKindOf QBASE_CLASS) exitWith {};
        [_vehicle] call hct_h60_anvishud_fnc_configureHMD;
    }
] call CBA_fnc_addSetting;
