#include "script_component.hpp"
/*
 * Author: Ampersand
 * Creates a stretcher vehicle and removes the inventory item
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Variant <NUMBER> 1 to 3
 *
 * Return Value:
 * 0: Stretcher <OBJECT>
 *
 * Example:
 * [_unit] call vtx_stretcher_fnc_unfold
 */

params ["_unit", ["_variant", 0, 0]];

_player removeItem "vtx_stretcher_item";

if !(_variant in [1, 2, 3]) then {
  _variant = selectRandom [1, 2, 3];
};
private _class = "vtx_stretcher_" + str _variant;

[_unit, "PutDown"] call ace_common_fnc_doGesture;
private _vehicle = _class createVehicle getPos _unit;

if (_unit == ACE_player) then {
  [_unit, _vehicle] call ace_dragging_fnc_startCarry;
};
