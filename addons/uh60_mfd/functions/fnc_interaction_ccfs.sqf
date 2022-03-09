/*
 * vtx_uh60_mfd_fnc_interaction_ccfs
 *
 * handles ccfs page interaction
 *
 * params (array)[(object) vehicle, (string) action, (misc) _value]
 */

params ["_vehicle", "_action", "_value"];

switch (_action) do {
    case 1: { // join
		[_vehicle, _value, 8, true] call vtx_uh60_mfd_fnc_switchPage;
	};
    case 2: { // next
		vtx_uh60_ccfs_roomNumSelected = vtx_uh60_ccfs_roomNumSelected + 1;
	};
    case 3: { // prev
		vtx_uh60_ccfs_roomNumSelected = vtx_uh60_ccfs_roomNumSelected - 1;
	};
    case 4: { // host
		[_vehicle, _value, 8, true] call vtx_uh60_mfd_fnc_switchPage;
	};
};