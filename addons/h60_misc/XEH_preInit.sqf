#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// private _mh60 = "hct_MH60S" createVehicle [0,0,0];
// deleteVehicle _mh60;
// ["hct_uh60m", "hct_HH60", "hct_MH60M", ""]

// diag_log str ["STARTING PRE-LOADING of H-60", systemTime];
// {
// 	diag_log str ["LOADING", _x];
// 	private _veh = _x createVehicleLocal [0,0,0];
// 	deleteVehicle _veh;
// } forEach ["HCT_UH60M", "HCT_MH60M", "hct_MH60M_DAP"];
// diag_log str ["FINISHED PRE-LOADING of H-60", systemTime];

// Crew-chief swap handshake (fnc_ccSwap): sent as CBA target events on the
// vehicle, so they land on its owner - and run immediately when that is this
// machine. CBA events need no CfgRemoteExec whitelist
["hct_h60_misc_ccSwapOpen", {
    params ["_veh", "_paths"];
    [_veh, _paths, true] call hct_h60_misc_fnc_ccSwapLocks;
}] call CBA_fnc_addEventHandler;
["hct_h60_misc_ccSwapClose", {
    params ["_veh", "_paths"];
    [_veh, _paths, false] call hct_h60_misc_fnc_ccSwapLocks;
}] call CBA_fnc_addEventHandler;

// Light toggles from a seat whose machine does not own the aircraft
["hct_h60_misc_toggleLights", {_this call hct_h60_misc_fnc_toggleLights}] call CBA_fnc_addEventHandler;

ADDON = true;
