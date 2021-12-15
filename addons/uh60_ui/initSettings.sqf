#include "script_component.hpp"

[
    "vtx_uh60m_trackIR_interaction_cursor",
    "CHECKBOX",
    [LSTRING(Cursor), LSTRING(Cursor_Description)],
    "UH-60M",
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "vtx_uh60m_trackIR_interaction_cursorSensitivity",
    "SLIDER",
    [LSTRING(DetachedCursorSensitivity), LSTRING(Cursor_Description)],
    "UH-60M",
    [1,10,2.5,1],
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "vtx_uh60_ui_showDebugMessages",
    "CHECKBOX",
    [LSTRING(Enable_systemChat), LSTRING(Enable_systemChat)],
    "UH-60M",
    [true],
    nil,
    {}
] call CBA_Settings_fnc_init;
