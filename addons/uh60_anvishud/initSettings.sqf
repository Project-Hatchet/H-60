[
    "vtx_uh60_anvishud_defaultMode", "LIST",
    [localize LSTRING(HMDDefaultMode), LSTRING(HMDDefaultMode_Description)],
    "UH-60M",
    [[-1, 1, 2, 3, 4], [
        "STR_3DEN_Attributes_Radar_RadarOff_text",
        LSTRING(ImperialFull),
        LSTRING(ImperialDecluttered),
        LSTRING(MetricFull),
        LSTRING(MetricDecluttered)
    ], 0],
    false // isGlobal
] call CBA_settings_fnc_init;
