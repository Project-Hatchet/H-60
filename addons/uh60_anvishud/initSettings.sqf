[
    "vtx_uh60_anvishud_defaultMode", "LIST",
    [localize LSTRING(HMDDefaultMode), LSTRING(HMDDefaultMode_Description)],
    ["UH-60M", "HMD"],
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
    "vtx_uh60_anvishud_setting_color", "COLOR",
    ["Color", "HMD Color"],
    ["UH-60M", "HMD"],
    [0.082, 0.608, 0.039, 1],
    false, // isGlobal
    {
      private _vehicle = vehicle player;
      if (_vehicle isKindOf "vtx_h60_base") then {
        vtx_uh60_anvishud_setting_color params ["_r", "_g", "_b", "_a"];
        _vehicle setPylonLoadout ["dummy10", "vtx_1000rnd_dummy", true];
        _vehicle setPylonLoadout ["dummy11", "vtx_1000rnd_dummy", true];
        _vehicle setPylonLoadout ["dummy12", "vtx_1000rnd_dummy", true];
        _vehicle setPylonLoadout ["dummy13", "vtx_1000rnd_dummy", true];
        _vehicle setAmmoOnPylon ["dummy10", _r * 1000];
        _vehicle setAmmoOnPylon ["dummy11", _g * 1000];
        _vehicle setAmmoOnPylon ["dummy12", _b * 1000];
        _vehicle setAmmoOnPylon ["dummy13", _a * 1000];
      };
    },
    false
] call CBA_settings_fnc_init;
