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

	_vehicle setPylonLoadout [_index, "vtx_1000rnd_dummy", true];
	_vehicle setAmmoOnPylon [_index, _value];
} forEach (_vehicle getVariable[QGVAR(pylonConfig), []]);
