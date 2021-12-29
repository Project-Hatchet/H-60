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
	private _index = _x;

	if(_index select 3 == "vtx_1000rnd_dummy") then {
		_pylonArray pushBack [_index select 0, _index select 4];
	};
}forEach getAllPylonsInfo _vehicle;

_vehicle setVariable ["pylonConfig", _pylonArray];
