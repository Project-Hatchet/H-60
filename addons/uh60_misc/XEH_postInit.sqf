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

// private _doorOpenRightCpt = ["vtx_uh60_cptDoorRight", "Open/Close cockpit door", "", {_target animateDoor ["Door_RF", (if ((_target doorPhase "Door_RF") > 0) then {0} else {1})]}, {true}, nil, [], {_target selectionPosition "cabindoor_R_handle"}, 2, [false,false,false,false,false], {} ];

private _digitOptionsCode = {
    params ["_target", "_player", "_params"];
    systemChat str _params;
    private _returns = [];
    for "_i" from 0 to 9 do {
        private _action = ["vtx_uh60_firstNumber", format ["Set to %1", _i], "", {}, {true}, nil, [], {}, 2, [false,false,false,false,false], {} ] call ace_interact_menu_fnc_createAction;
        _returns pushBack [_action, [], _target]
    };
    _returns
};
private _editNumbersOptionsCode = {
    params ["_target", "_player", "_params"];
    private _first = (["vtx_uh60_firstNumber", "First digit", "", {}, {true}, nil, [0], {}, 2, [false,false,false,false,false], {} ] call ace_interact_menu_fnc_createAction);
    private _second = (["vtx_uh60_secondNumber", "Second digit", "", {}, {true}, nil, [1], {}, 2, [false,false,false,false,false], {} ] call ace_interact_menu_fnc_createAction);
    [[_first, [], _target], [_second, [], _target]]
};
private _editNumbersLeft = ["vtx_uh60_paintNumbersLeft2", "Change number tape", "", {}, {true}, nil, [], {(_target selectionPosition "cabindoor_L_handle") vectorAdd [0,-1,0.5]}, 10, [false,false,false,false,false], {} ];
private _editNumbersRight = ["vtx_uh60_paintNumbersRight2", "Change number tape", "", {}, {true}, nil, [], {(_target selectionPosition "cabindoor_R_handle") vectorAdd [0,-1,0.5]}, 10, [false,false,false,false,false], {} ];

{
    ["vtx_h60_base",0,[],(_x call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
} forEach [_doorOpenLeft, _doorOpenRight, _editNumbersLeft, _editNumbersRight];