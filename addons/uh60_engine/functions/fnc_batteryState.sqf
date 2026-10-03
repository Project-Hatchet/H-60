/*
 * vtx_uh60_engine_fnc_batteryState
 *
 * manages battery state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */

#include "defines.hpp"
params ["_vehicle", ["_animName", ""], ["_animEndState", ""]];

_vehicle call vtx_uh60_engine_fnc_UpdateAPU_State;
[_vehicle] call vtx_uh60_cas_fnc_updateCautionPanel;
