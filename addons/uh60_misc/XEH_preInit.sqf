#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// private _mh60 = "vtx_MH60S" createVehicle [0,0,0];
// deleteVehicle _mh60;
// ["vtx_uh60m", "vtx_HH60", "vtx_MH60M", ""]

// diag_log str ["STARTING PRE-LOADING of H-60", systemTime];
// {
// 	diag_log str ["LOADING", _x];
// 	private _veh = _x createVehicleLocal [0,0,0];
// 	deleteVehicle _veh;
// } forEach ["VTX_UH60M", "VTX_MH60M", "vtx_MH60M_DAP", "vtx_MH60M_DAP_MLASS"];
// diag_log str ["FINISHED PRE-LOADING of H-60", systemTime];

// Crew-chief seat swaps (fnc_ccSwap / fnc_ccLockSeats): ONE table for every
// swap pair in the fleet, matched by gunnerName so no turret path is ever
// hardcoded and a vehicle only offers the pairs whose seats it actually has.
//   [seated name, counterpart name, kind, extra condition (vehicle, unit)]
// kinds:
//   "out"/"in"       DAP aft crew chief <-> door-sill turned-out spot. The
//                    spot is swap-only (always locked); the vacated seat is
//                    reserved while the spot is occupied.
//   "hoist"/"unhoist" right crew seat <-> the "(hoist controls)" pendant seat
//                    (hoist operator role, Riverman ruling 2026-09-23). The
//                    pendant seat stays an ordinary pax seat - what the swap
//                    adds is the DESIGNATION (vtx_hoistOperator on the
//                    vehicle, set by the owner at the end of the swap) that
//                    fnc_canControlHoist requires; a pax who merely sits
//                    there gets no winch. The crew seat is reserved while the
//                    operator is on the pendant (on armed birds the right
//                    minigun sits unmanned and locked during hoisting -
//                    accepted). Requires the right cabin door open (the
//                    pendant seat is a door seat, #612 locks it with the
//                    door) and a hoist fitted.
vtx_uh60_misc_ccHoistSeat = "Door Right 1 (hoist controls)";
vtx_uh60_misc_ccPairs = [
    ["L Crew Chief", "L Crew Chief (Turned Out)", "out", {true}],
    ["R Crew Chief", "R Crew Chief (Turned Out)", "out", {true}],
    ["L Crew Chief (Turned Out)", "L Crew Chief", "in", {true}],
    ["R Crew Chief (Turned Out)", "R Crew Chief", "in", {true}]
];
private _hoistReady = {
    params ["_veh"];
    (_veh animationPhase "cabindoor_R") < 0.5             // 1 = closed
    && {(_veh animationSourcePhase "Hoist_hide") < 0.5}   // 0 = hoist fitted
};
// the way back is only offered to the designated operator - anyone can board
// the pendant seat from outside as a passenger, and a passenger has nothing
// to exit (test report 2026-10-06)
private _isOperator = {
    params ["_veh", "_unit"];
    (_veh getVariable ["vtx_hoistOperator", objNull]) isEqualTo _unit
};
// one "unhoist" row per crew-seat name: fnc_ccSwap takes the first row whose
// target seat exists on the vehicle and is empty
{
    vtx_uh60_misc_ccPairs pushBack [_x, vtx_uh60_misc_ccHoistSeat, "hoist", _hoistReady];
    vtx_uh60_misc_ccPairs pushBack [vtx_uh60_misc_ccHoistSeat, _x, "unhoist", _isOperator];
} forEach ["Right Door Gunner", "Right Crew Chief", "Right Window"];

// Swap handshake: sent as CBA target events on the vehicle, so they land on
// its owner - and run immediately when that is this machine. CBA events need
// no CfgRemoteExec whitelist
["vtx_uh60_misc_ccSwapOpen", {
    params ["_veh", "_paths"];
    [_veh, _paths, true] call vtx_uh60_misc_fnc_ccSwapLocks;
}] call CBA_fnc_addEventHandler;
["vtx_uh60_misc_ccSwapClose", {
    params ["_veh", "_paths", ["_unit", objNull], ["_kind", ""]];
    [_veh, _paths, false, _unit, _kind] call vtx_uh60_misc_fnc_ccSwapLocks;
}] call CBA_fnc_addEventHandler;

ADDON = true;
