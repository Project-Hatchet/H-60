#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

["vtx_uh60m_enabled_jvmf","CHECKBOX",["Enable JVMF", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_fms","CHECKBOX",["Enable FMS", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_mfd","CHECKBOX",["Enable MFD", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_fd","CHECKBOX",["Enable FD", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_cas","CHECKBOX",["Enable CAS", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_aar","CHECKBOX",["Enable AAR", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_flir","CHECKBOX",["Enable FLIR", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;
["vtx_uh60m_enabled_engine","CHECKBOX",["Enable ENGINE", "Uncheck to disable this component for debug reasons"],["UH-60M", "Debug"],[true],nil,{}] call CBA_Settings_fnc_init;