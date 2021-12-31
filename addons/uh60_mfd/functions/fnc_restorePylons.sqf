#include "script_component.hpp"
/*
 * vtx_uh60_mfd_fnc_restorePylons
 *
 * Restores pylon values used in MFDs for recall during reload events
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

{
  _x params["_index", "_value"];

  [_vehicle, _index, _value] call vtx_uh60_mfd_fnc_setPylonValue;

} forEach (_vehicle getVariable[QGVAR(pylonConfig), []]);
