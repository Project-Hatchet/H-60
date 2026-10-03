#include "script_component.hpp"

ADDON = false;

#include "initSettings.sqf";
#include "XEH_PREP.hpp"

// The H60_SFX sound functions used to be remoteExecCall'd by name, which a
// mission-defined CfgRemoteExec whitelist blocks. CBA events need no
// whitelist; the isDedicated guard preserves the old [0,-2] targeting
["vtx_uh60_engine_playEngineSound", {
    if (isDedicated) exitWith {};
    _this call vtx_uh60_Sound_fnc_PlayEngineGlobal;
}] call CBA_fnc_addEventHandler;
["vtx_uh60_engine_playAPUSound", {
    if (isDedicated) exitWith {};
    _this call vtx_uh60_Sound_fnc_PlayAPUGlobal;
}] call CBA_fnc_addEventHandler;

ADDON = true;
