#include "script_component.hpp"

private _action = [
    "vtx_UH60_attach",
    "Attach to Blackhawk",
    "",
    {[_target] call vtx_uh60_misc_fnc_attachCRRC;},
    {(count (nearestObjects [_target, ["vtx_H60_base"], 10])) > 0}
] call ace_interact_menu_fnc_createAction;
["Rubber_duck_base_F",0,["ACE_MainActions"],_action, true] call ace_interact_menu_fnc_addActionToClass;

["vtx_uh60_misc_switchTurret", {
    call vtx_uh60_misc_fnc_switchTurret;
}] call CBA_fnc_addEventHandler;
