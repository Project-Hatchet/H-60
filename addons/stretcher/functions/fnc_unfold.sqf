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

_unit removeItem "vtx_stretcher_item";
[_unit, "PutDown"] call ace_common_fnc_doGesture;

private _pos = _unit modelToWorld [0,0,0];
private _offset = if ((_unit call CBA_fnc_getUnitAnim select 0) == "prone") then { 1 } else {0.8};

_pos set [0, (_pos select 0) + (sin getDir _unit) * _offset];
_pos set [1, (_pos select 1) + (cos getDir _unit) * _offset];
_pos set [2, [_unit] call CBA_fnc_realHeight];

if !(_variant in [1, 2, 3]) then {
  _variant = selectRandom [1, 2, 3];
};
private _class = "vtx_stretcher_" + str _variant;
private _vehicle = _class createVehicle _pos;
_vehicle setPos _pos;
_vehicle setDir getDir _unit;
