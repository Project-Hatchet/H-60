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
	_vehicle setPylonLoadout [_x select 0, "vtx_1000rnd_dummy", true];
	_vehicle setAmmoOnPylon [_x select 0, _x select 1];
} forEach (_vehicle getVariable[QGVAR(pylonConfig), []]);
