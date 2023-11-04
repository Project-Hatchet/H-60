#include "script_component.hpp"

[
    "UH-60M Blackhawk",
    "vtx_uh60m_c_help",
    LSTRING(HelpMode),
    {},{
        private _vehicle = vehicle player;
        if ([_vehicle, "ui", "vtx_H60_base"] call hatchet_core_fnc_hasModule) then {
            vtx_uh60_ui_helpEnabled = !vtx_uh60_ui_helpEnabled;
            [_vehicle, vtx_uh60_ui_helpEnabled] call vtx_uh60_ui_fnc_showHelp;
        };
    },
    [35, [false, true, false]],
    false
] call CBA_fnc_addKeybind;
