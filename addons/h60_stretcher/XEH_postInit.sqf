#include "script_component.hpp"

private _displayName = localize LSTRING(Fold);
private _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\close_ca.paa";
private _condition = {params ["_stretcher"]; crew _stretcher isEqualTo []};
private _statement = {
  params ["_stretcher"];
  private _pos = getPosASL _stretcher;
  deleteVehicle _stretcher;
  private _item = createVehicle [QGVAR(item), [0, 0, 0], [], 0, "NONE"];
  _item setPosASL _pos;
};
_action = [QGVAR(fold), _displayName, _icon, _statement, _condition] call ace_interact_menu_fnc_createAction;
[QGVAR(1), 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
