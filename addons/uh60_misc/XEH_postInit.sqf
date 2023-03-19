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


private _doorOpenLeft = [
 "vtx_uh60_cabinDoorLeft", // * 0: Action name <STRING>
 "Open/Close cabin door",  // * 1: Name of the action shown in the menu <STRING>
 "", // * 2: Icon <STRING>
 {_target animateSource ["cabinDoor_L", (if ((_target animationPhase "cabinDoor_L") > 0) then {0} else {1})]}, // * 3: Statement <CODE>
 {true}, // * 4: Condition <CODE>
 nil, // * 5: Insert children code <CODE> (Optional)
 [], // * 6: Action parameters <ANY> (Optional)
 {_target selectionPosition "cabindoor_L_handle"}, // * 7: Position (Position array, Position code or Selection Name) <ARRAY>, <CODE> or <STRING> (Optional)
 2, // * 8: Distance <NUMBER> (Optional)
 [false,false,false,false,false], // * 9: Other parameters [showDisabled,enableInside,canCollapse,runOnHover,doNotCheckLOS] <ARRAY> (Optional)
 {} // * 10: Modifier function <CODE> (Optional)
];
private _doorOpenRight = ["vtx_uh60_cabinDoorRight", "Open/Close cabin door", "", {_target animateSource ["cabinDoor_R", (if ((_target animationPhase "cabinDoor_R") > 0) then {0} else {1})]}, {true}, nil, [], {_target selectionPosition "cabindoor_R_handle"}, 2, [false,false,false,false,false], {} ];

private _doorOpenRightCpt = ["vtx_uh60_cptDoorRight", "Open/Close cockpit door", "", {_target animateDoor ["Door_RF", (if ((_target doorPhase "Door_RF") > 0) then {0} else {1})]}, {true}, nil, [], {_target selectionPosition "cockpitdoor_right"}, 2, [false,false,false,false,false], {} ];
private _doorOpenLefttCpt = ["vtx_uh60_cptDoorRight", "Open/Close cockpit door", "", {_target animateDoor ["Door_LF", (if ((_target doorPhase "Door_LF") > 0) then {0} else {1})]}, {true}, nil, [], {_target selectionPosition "cockpitdoor_left"}, 2, [false,false,false,false,false], {} ];

{
    ["vtx_h60_base",0,[],(_x call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
} forEach [_doorOpenLeft, _doorOpenRight, _doorOpenRightCpt, _doorOpenLefttCpt];

_digitOptionsCode = {
    params ["_target", "_player", "_params"];
    _params params ["_first", "_second"];
    private _returns = [];
    for "_i" from 0 to 9 do {
        private _statement = {
            params ["_target", "_player", "_params"];
            _target setObjectTextureGlobal [_params # 1, format ["\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_%1_ca.paa", _params # 0]];
            _target setObjectTextureGlobal [_params # 2, format ["\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_%1_ca.paa", _params # 0]];
        };
        private _action = ["vtx_uh60_firstNumber", format ["Set to %1", _i], "", _statement, {true}, nil, [_i, _first, _second], {}, 2] call ace_interact_menu_fnc_createAction;
        _returns pushBack [_action, [], _target]
    };
    _returns
};
// _editNumbersOptionsCode = {
//     params ["_target", "_player", "_params"];
//     private _first = (["vtx_uh60_firstNumber", "First digit", "", {hint "yessssss"}, {true}, _digitOptionsCode, [0], {}, 2] call ace_interact_menu_fnc_createAction);
//     private _second = (["vtx_uh60_secondNumber", "Second digit", "", {hint "yessssss"}, {true}, _digitOptionsCode, [1], {}, 2] call ace_interact_menu_fnc_createAction);
//     [[_first, [], _target], [_second, [], _target]]
// };



vtx_uh60_markings_options = ("true" configClasses (configFile >> "CfgVehicles" >> "vtx_h60_base" >> "Attributes" >> "vtx_uh60_Markings" >> "values")) apply {[getText (_x >> "name"), getText (_x >> "value")]};
_markingsOptions = {
    params ["_target", "_player", "_params"];
    vtx_uh60_markings_options apply {
        _x params ["_name", "_path"];
        private _action = [_name, _name, "", {_target setObjectTextureGlobal [19, _this # 2]}, {true}, {}, _path] call ace_interact_menu_fnc_createAction;
        [_action, [], _target]
    }
};
private _editMarkingsLeft = ["vtx_uh60_editMarkingsLeft", "Change Markings", "", {}, {!(_target getVariable ["vtx_autostarted", false])}, _markingsOptions, [], {[-1,1,0.5]}, 2];
private _editMarkingsRight = ["vtx_uh60_editMarkingsRight", "Change Markings", "", {}, {!(_target getVariable ["vtx_autostarted", false])}, _markingsOptions, [], {[1,1,0.5]}, 2];
["vtx_h60_base",0,[],(_editMarkingsLeft call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
["vtx_h60_base",0,[],(_editMarkingsRight call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;


private _editNumbersLeftFirst = ["vtx_uh60_paintNumbersLeftFirst" + (str random 1), "Change number tape", "", {}, {true}, _digitOptionsCode, [21,23], {(_target selectionPosition "cabindoor_L_handle") vectorAdd [0,-1.2,0.5]}, 1.5];
private _editNumbersRightFirst = ["vtx_uh60_paintNumbersRightFirst" + (str random 1), "Change number tape", "", {}, {true}, _digitOptionsCode, [20,22], {(_target selectionPosition "cabindoor_R_handle") vectorAdd [0,-1.2,0.5]}, 1.5];
private _editNumbersLeft = ["vtx_uh60_paintNumbersLeft" + (str random 1), "Change number tape", "", {}, {true}, _digitOptionsCode, [20,22], {(_target selectionPosition "cabindoor_L_handle") vectorAdd [0,-0.9,0.5]}, 1.5];
private _editNumbersRight = ["vtx_uh60_paintNumbersRight" + (str random 1), "Change number tape", "", {}, {true}, _digitOptionsCode, [21,23], {(_target selectionPosition "cabindoor_R_handle") vectorAdd [0,-0.9,0.5]}, 1.5];
["vtx_h60_base",0,[],(_editNumbersLeftFirst call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
["vtx_h60_base",0,[],(_editNumbersRightFirst call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
["vtx_h60_base",0,[],(_editNumbersLeft call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
["vtx_h60_base",0,[],(_editNumbersRight call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;

private _customizationOptions = [
  ["vtx_fuelprobe", "Fuel Probe", ["vtx_fuelProbe", "fuelProbe_show", 1, 0, 7], {[1.3,4.1,-1.2]}],
  ["vtx_hoist", "Rescue Hoist", ["vtx_hoist", "Hoist_hide", 0, 1, 3], {[1.1,1.9,0.35]}],
  ["vtx_cockpitdoors", "Cockpit Doors", ["vtx_cockpitdoors", "Cockpitdoors_Hide", 0, 1, 3], {[1.1,5.1,-0.7]}]
];

{
  _x params ["_className", "_description", "_addParams", "_position", ["_range", 2]];
  private _addOption = [
    (_className + "_attach"),
    ("Attach " + _description),
    "",
    vtx_uh60_misc_fnc_addCustomization,
    vtx_uh60_misc_fnc_canCustomizeVariant,
    nil,
    _addParams,
    _position,
    _range,
    [false,false,false,false,false],
    {}
  ];
  private _removeOption = [
    (_className + "_remove"),
    ("Remove " + _description),
    "",
    vtx_uh60_misc_fnc_removeCustomization,
    vtx_uh60_misc_fnc_canRemoveCustomization, nil, _addParams, _position, _range, [false,false,false,false,false], {}
  ];
  ["vtx_h60_base",0,[],(_addOption call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
  ["vtx_h60_base",0,[],(_removeOption call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
} forEach _customizationOptions;
