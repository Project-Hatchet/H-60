/*
 * vtx_uh60_ground_fnc_perSecond
 *
 * handles occasional updates of data
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

// SFM parking-brake chains (slope hold + brake-key sync): cheap arm-once
// check, and the re-arm path after locality/seat changes. The key watcher
// runs on the pilot's machine.
[_vehicle] call vtx_uh60_ground_fnc_pbArm;
