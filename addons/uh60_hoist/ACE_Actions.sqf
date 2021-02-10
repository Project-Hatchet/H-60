private _displayName = "Rescue Hoist";
private _condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist || {[_player] call vtx_uh60_hoist_fnc_canMoveHeliToHook}};
private _statement = {};
private _action = ["vtx_hoist_action","Rescue Hoist","z\vtx\addons\uh60_hoist\data\ui\iconHook.paa", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Deploy Hook";
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_canDeployHook};
_statement = vtx_uh60_hoist_fnc_deployHook;
_action = ["vtx_hoist_DeployHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Secure Hook";
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_canSecureHook};
_statement = vtx_uh60_hoist_fnc_secureHook;
_action = ["vtx_hoist_SecureHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Recover Person";
_condition = vtx_uh60_hoist_fnc_canRecoverPerson;
_statement = vtx_uh60_hoist_fnc_recoverPerson;
_action = ["vtx_hoist_RecoverPerson", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Move To Hook";
_condition = {[_player] call vtx_uh60_hoist_fnc_canMoveHeliToHook};
_statement = {[_player] call vtx_uh60_hoist_fnc_moveHeliToHook};
_action = ["vtx_hoist_MoveToHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Raise Hook To Heli";
_condition = {[player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_isHoistReady};
_statement = vtx_uh60_hoist_fnc_raiseHookToHeli;
_action = ["vtx_hoist_RaiseHookToHeli", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Lower Hook To Ground";
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_isHoistReady};
_statement = vtx_uh60_hoist_fnc_lowerHookToGround;
_action = ["vtx_hoist_LowerHookToGround", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Stabilize hook";
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_isHookDeployed}; // can stabilize while hoist is "working"
_statement = vtx_uh60_hoist_fnc_stabilizeHook;
_action = ["vtx_hoist_StabilizeHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Working...";
_condition = vtx_uh60_hoist_fnc_isHoistWorking; // not sure how to interrupt a ropeUnwind, so disable actions while unwinding
_statement = {true};
_action = ["vtx_hoist_Working", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = "Repair Hoist Hook";
_condition = vtx_uh60_hoist_fnc_isHookDamaged;
_statement = {_target animateSource ["hoist_hook_hide", 0];};
_action = ["vtx_hoist_RepairHoistHook", _displayName, "", _statement, _condition, {}, [], [1.405, 2.03, 0.45]] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
