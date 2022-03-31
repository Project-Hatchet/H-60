/*
 * vtx_uh60_engine_fnc_engineEH
 *
 * engine power eventhandler
 *
 * params (array)[(object) vehicle, (bool) turnedOn]
 */

/*
 diag_log format ["%1: engine EH", time];
*/
params ["_vehicle", "_turnedOn", ["_lever","throttle"], "_animEndState", "_animName"];

(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]]) params ["_eng1State", "_eng2State"];

_vehicle engineOn (_eng1State == "ON" || _eng2State == "ON");