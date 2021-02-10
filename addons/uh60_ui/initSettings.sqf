#include "script_component.hpp"

[
    "vtx_uh60m_trackIR_interaction_cursor",
    "CHECKBOX",
    "Detached interaction cursor(trackIR users)",
    "UH-60M",
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "vtx_uh60m_trackIR_interaction_cursorSensitivity",
    "SLIDER",
    "Detached cursor Sensitivity",
    "UH-60M",
    [1,10,2.5,1],
    nil,
    {}
] call CBA_Settings_fnc_init;
