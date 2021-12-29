/*
 * vtx_uh60_mfd_fnc_restorePylons
 *
 * Restores pylon values used in MFDs for recall during reload events
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

{
	private _index = _x;

	_vehicle setPylonLoadout [_index select 0, "vtx_1000rnd_dummy", true];
	_vehicle setAmmoOnPylon [_index select 0, _index select 1];

} forEach (_vehicle getVariable["pylonConfig", []]);
