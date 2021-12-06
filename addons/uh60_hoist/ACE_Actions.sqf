private _displayName = localize LSTRING(RescueHoist);
private _condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist || {[_player] call vtx_uh60_hoist_fnc_canMoveHeliToHook}};
private _statement = {};
private _action = ["vtx_hoist_action","Rescue Hoist","z\vtx\addons\uh60_hoist\data\ui\iconHook.paa", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(DeployHook);
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_canDeployHook};
_statement = vtx_uh60_hoist_fnc_deployHook;
_action = ["vtx_hoist_DeployHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(SecureHook);
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_canSecureHook};
_statement = vtx_uh60_hoist_fnc_secureHook;
_action = ["vtx_hoist_SecureHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(RecoverPerson);
_condition = vtx_uh60_hoist_fnc_canRecoverPerson;
_statement = vtx_uh60_hoist_fnc_recoverPerson;
_action = ["vtx_hoist_RecoverPerson", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(MoveToHook);
_condition = {[_player] call vtx_uh60_hoist_fnc_canMoveHeliToHook};
_statement = {[_player] call vtx_uh60_hoist_fnc_moveHeliToHook};
_action = ["vtx_hoist_MoveToHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(RaiseHookToHeli);
_condition = {[player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_isHoistReady};
_statement = vtx_uh60_hoist_fnc_raiseHookToHeli;
_action = ["vtx_hoist_RaiseHookToHeli", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(LowerHookToGround);
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_isHoistReady};
_statement = vtx_uh60_hoist_fnc_lowerHookToGround;
_action = ["vtx_hoist_LowerHookToGround", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(StabilizeHook);
_condition = {[_player] call vtx_uh60_hoist_fnc_canControlHoist && [_target] call vtx_uh60_hoist_fnc_isHookDeployed}; // can stabilize while hoist is "working"
_statement = vtx_uh60_hoist_fnc_stabilizeHook;
_action = ["vtx_hoist_StabilizeHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(Working);
_condition = vtx_uh60_hoist_fnc_isHoistWorking; // not sure how to interrupt a ropeUnwind, so disable actions while unwinding
_statement = {true};
_action = ["vtx_hoist_Working", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 1, ["ACE_SelfActions", "vtx_hoist_action"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(RepairHoistHook);
_condition = vtx_uh60_hoist_fnc_isHookDamaged;
_statement = vtx_uh60_hoist_fnc_resetHook;
_action = ["vtx_hoist_RepairHoistHook", _displayName, "", _statement, _condition, {}, [], "hoist_hook_pos"] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;

_displayName = localize LSTRING(AttachHook);
_condition = vtx_uh60_hoist_fnc_canAttachHook;
_statement = vtx_uh60_hoist_fnc_attachHook;
_action = ["vtx_hoist_AttachHook", _displayName, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
["vtx_hook", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
