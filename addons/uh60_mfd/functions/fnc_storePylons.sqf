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
	if (_x select 3 == "vtx_1000rnd_dummy") then {
		_pylonArray pushBack [_x select 0, _x select 4];
	};
} forEach getAllPylonsInfo _vehicle;

_vehicle setVariable [QGVAR(pylonConfig), _pylonArray];
