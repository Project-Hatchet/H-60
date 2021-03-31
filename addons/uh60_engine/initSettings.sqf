[
    "vtx_uh60m_simpleStartup",
    "CHECKBOX",
    localize LSTRING(SimpleStartup),
    "UH-60M",
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "vtx_uh60m_disabled_engine",
    "CHECKBOX",
    "(DEBUG) Disable ENGINE",
    ["UH-60M","Debug"],
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;
