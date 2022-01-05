/*
 * vtx_uh60_mfd_fnc_setPylonValue
 *
 * Writes an individual pylon value and stores the value so that it's not disrupted during reload events (i.e. MFD fluid issues)
 *
 * params (array)[(object) vehicle, (integer or string) pylon index or name, (integer or string pylon value]
 */

params ["_vehicle", "_index", "_value"];

_vehicle setPylonLoadout [_index, "vtx_1000rnd_dummy", true];
_vehicle setAmmoOnPylon [_index, _value];

[_vehicle] call vtx_uh60_mfd_fnc_storePylons;
