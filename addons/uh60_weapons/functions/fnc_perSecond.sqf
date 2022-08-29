params ["_vehicle"];

[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;
vtx_uh60_hellfire_currentTof = (vtx_uh60_hellfire_currentTof - 1) max -1;

// {

// } foreach [
// 	[]
// ];