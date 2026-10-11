#include "script_component.hpp"

[
    "vtx_uh60_ui_showDebugMessages",
    "CHECKBOX",
    [LSTRING(Enable_debugMessages), LSTRING(Enable_debugMessages)],
    ["UH-60M","Debug"],
    [false],
    nil,
    {}
] call CBA_Settings_fnc_init;
