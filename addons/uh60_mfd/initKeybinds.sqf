[
    "UH-60M Blackhawk",
    "vtx_uh60m_c_slewup",
    LSTRING(SlewUp),
    {["slewY", 1] call vtx_uh60_mfd_fnc_interaction_slew},
    {["slewY", 0] call vtx_uh60_mfd_fnc_interaction_slew},
    [200, [false, false, false]],
    false
] call CBA_fnc_addKeybind;
[
    "UH-60M Blackhawk",
    "vtx_uh60m_c_slewdown",
    LSTRING(SlewDown),
    {["slewY", -1] call vtx_uh60_mfd_fnc_interaction_slew},
    {["slewY", 0] call vtx_uh60_mfd_fnc_interaction_slew},
    [208, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    "UH-60M Blackhawk",
    "vtx_uh60m_c_slewLeft",
    LSTRING(SlewLeft),
    {["slewX", -1] call vtx_uh60_mfd_fnc_interaction_slew},
    {["slewX", 0] call vtx_uh60_mfd_fnc_interaction_slew},
    [203, [false, false, false]],
    false
] call CBA_fnc_addKeybind;
[
    "UH-60M Blackhawk",
    "vtx_uh60m_c_slewright",
    LSTRING(SlewRight),
    {["slewX", 1] call vtx_uh60_mfd_fnc_interaction_slew},
    {["slewX", 0] call vtx_uh60_mfd_fnc_interaction_slew},
    [205, [false, false, false]],
    false
] call CBA_fnc_addKeybind;
[
    "UH-60M Blackhawk",
    "vtx_uh60m_c_slewAction",
    LSTRING(SlewAction),
    {},
    {["slewAction", 1] call vtx_uh60_mfd_fnc_interaction_slew},
    [28, [false, false, false]],
    false
] call CBA_fnc_addKeybind;