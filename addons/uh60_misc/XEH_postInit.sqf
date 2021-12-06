#include "script_component.hpp"

private _action = [
    "vtx_UH60_attach",
    "Attach to Blackhawk",
    "",
    {[_target] call vtx_uh60_misc_fnc_attachCRRC;},
    {(count (nearestObjects [_target, ["vtx_H60_base"], 10])) > 0}
] call ace_interact_menu_fnc_createAction;
["Rubber_duck_base_F",0,["ACE_MainActions"],_action, true] call ace_interact_menu_fnc_addActionToClass;

params ["_heli"];
private _displayName = "Skis";
private _condition = {true};
private _statement = {};
private _action = ["vtx_skis",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Install Skis";
_condition = {((_this select 0) animationPhase "skis") == 0};
_statement = {(_this select 0) animate ["skis", 1];};
_action = ["vtx_skis",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_skis"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Uninstall Skis";
_condition = {((_this select 0) animationPhase "skis") == 1};
_statement = {(_this select 0) animate ["skis", 0];};
_action = ["vtx_skis",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_skis"], _action, true] call ace_interact_menu_fnc_addActionToClass;