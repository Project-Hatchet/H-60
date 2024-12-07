#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

["vtx_uh60m_enabled_jvmf","CHECKBOX","(DEBUG) Enable JVMF","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_fms","CHECKBOX","(DEBUG) Enable FMS","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_mfd","CHECKBOX","(DEBUG) Enable MFD","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_fd","CHECKBOX","(DEBUG) Enable FD","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_cas","CHECKBOX","(DEBUG) Enable CAS","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_aar","CHECKBOX","(DEBUG) Enable AAR","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_flir","CHECKBOX","(DEBUG) Enable FLIR","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_engine","CHECKBOX","(DEBUG) Enable ENGINE","UH-60M",[true],nil,{}] call CBA_Settings_fnc_init;