#include "script_component.hpp"
/*
 * vtx_uh60_mfd_fnc_storePylons
 *
 * Stores pylon values used in MFDs for recall during reload events
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

private _pylonArray = [];

{
  _x params ["_index", "", "", "_mag", "_value"];

  if (_mag == "vtx_1000rnd_dummy") then {
    _pylonArray pushBack [_index, _value];
  };
} forEach getAllPylonsInfo _vehicle;

_vehicle setVariable [QGVAR(pylonConfig), _pylonArray];
