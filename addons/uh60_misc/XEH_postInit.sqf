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
private _displayName = "Door Numbers";
private _condition = {true};
private _statement = {};
private _action = ["vtx_door_numbers",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "First Number";
private _condition = {true};
private _statement = {};
private _action = ["vtx_door_number_first",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Second Number";
private _condition = {true};
private _statement = {};
private _action = ["vtx_door_number_second",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Zero";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_0_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_0_ca.paa"];};
private _action = ["vtx_door_number_first_zero",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "One";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_1_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_1_ca.paa"];};
private _action = ["vtx_door_number_first_one",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Two";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_2_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_2_ca.paa"];};
private _action = ["vtx_door_number_first_two",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Three";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_3_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_3_ca.paa"];};
private _action = ["vtx_door_number_first_three",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Four";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "E:\Arma Dev Bench\Work Bench\VTX_Templates\Num_4_ca.paa"];(_this select 0) setObjectTexture [22, "E:\Arma Dev Bench\Work Bench\VTX_Templates\Num_4_ca.paa"];};
private _action = ["vtx_door_number_first_four",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Five";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_5_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_5_ca.paa"];};
private _action = ["vtx_door_number_first_five",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Six";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_6_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_6_ca.paa"];};
private _action = ["vtx_door_number_first_six",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Seven";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_7_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_7_ca.paa"];};
private _action = ["vtx_door_number_first_seven",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Eight";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_8_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_8_ca.paa"];};
private _action = ["vtx_door_number_first_eight",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Nine";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_9_ca.paa"];(_this select 0) setObjectTexture [22, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_9_ca.paa"];};
private _action = ["vtx_door_number_first_nine",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "CLEAR";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [20, ""];(_this select 0) setObjectTexture [22, ""];};
private _action = ["vtx_door_number_first_clear",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_first"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Zero";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_0_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_0_ca.paa"];};
private _action = ["vtx_door_number_second_zero",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "One";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_1_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_1_ca.paa"];};
private _action = ["vtx_door_number_second_one",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Two";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_2_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_2_ca.paa"];};
private _action = ["vtx_door_number_second_two",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Three";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_3_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_3_ca.paa"];};
private _action = ["vtx_door_number_second_three",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Four";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "E:\Arma Dev Bench\Work Bench\VTX_Templates\Num_4_ca.paa"];(_this select 0) setObjectTexture [23, "E:\Arma Dev Bench\Work Bench\VTX_Templates\Num_4_ca.paa"];};
private _action = ["vtx_door_number_second_four",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Five";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_5_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_5_ca.paa"];};
private _action = ["vtx_door_number_second_five",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Six";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_6_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_6_ca.paa"];};
private _action = ["vtx_door_number_second_six",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Seven";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_7_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_7_ca.paa"];};
private _action = ["vtx_door_number_second_seven",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Eight";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_8_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_8_ca.paa"];};
private _action = ["vtx_door_number_second_eight",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "Nine";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_9_ca.paa"];(_this select 0) setObjectTexture [23, "\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_9_ca.paa"];};
private _action = ["vtx_door_number_second_nine",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _displayName = "CLEAR";
private _condition = {true};
private _statement = {(_this select 0) setObjectTexture [21, ""];(_this select 0) setObjectTexture [23, ""];};
private _action = ["vtx_door_number_second_clear",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_door_numbers","vtx_door_number_second"], _action, true] call ace_interact_menu_fnc_addActionToClass;

params ["_heli"];
private _displayName = "Cabin Doors";
private _door = "";
private _desired = "";
private _condition = {true};
private _statement = {};
private _action = ["vtx_cabin_doors",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Close Left Door";
_condition = {((_this select 0) animationPhase "cabindoor_l") == 0};
_statement = {(_this select 0) animate ["cabindoor_l", 1];};
_action = ["vtx_cabin_doors",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_cabin_doors"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Close Right Door";
_condition = {((_this select 0) animationPhase "cabindoor_r") == 0};
_statement = {(_this select 0) animate ["cabindoor_r", 1];};
_action = ["vtx_cabin_doors",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_cabin_doors"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Open Left Door";
_condition = {((_this select 0) animationPhase "cabindoor_l") == 1};
_statement = {(_this select 0) animate ["cabindoor_l", 0];};
_action = ["vtx_cabin_doors",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_cabin_doors"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Open Right Door";
_condition = {((_this select 0) animationPhase "cabindoor_r") == 1};
_statement = {(_this select 0) animate ["cabindoor_r", 0];};
_action = ["vtx_cabin_doors",_displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, ["ACE_MainActions","vtx_cabin_doors"], _action, true] call ace_interact_menu_fnc_addActionToClass;