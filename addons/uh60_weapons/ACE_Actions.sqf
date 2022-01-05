private _displayName = "Adjust Pylon Position";
private _condition = {_this call vtx_uh60_weapons_fnc_canAdjustPylonPosition};
private _statement = {_this call vtx_uh60_weapons_fnc_adjustPylonPosition};
// Left Pylon
private _action = [
  "vtx_pylonPositionL",
  _displayName,
  "\a3\3den\Data\CfgWrapperUI\Cursors\3denMoveZ_ca.paa",
  _statement,
  _condition,
  {},
  0,
  "pylonLeft"
] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
// Right Pylon
_action = [
  "vtx_pylonPositionR",
  _displayName,
  "\a3\3den\Data\CfgWrapperUI\Cursors\3denMoveZ_ca.paa",
  _statement,
  _condition,
  {},
  1,
  "pylonRight"
  //[2.16147,0.33224,-0.557818]
] call ace_interact_menu_fnc_createAction;
["vtx_H60_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
