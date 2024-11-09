#include "script_component.hpp"

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_lowerHook", _heli]};       

private _heli = vehicle player;
if !([player] call vtx_uh60_hoist_fnc_canControlHoist) exitWith {};

while {vtx_uh60_cable_Extending} do { 
 private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []]; 
 _hoist_vars params ["_rope", "_dummy", "_hook"]; 
 private _ropeLength = ropeLength _rope; 
 ropeUnwind [ 
   _rope, 
   [MAX_HOIST_SPEED, NEAR_END_SPEED] select (MAX_ROPE_LENGTH - _ropeLength < NEAR_END_THRESHOLD), // slow speed near cable extreme 
   (_ropeLength + 0.1) min MAX_ROPE_LENGTH 
  ]; 
};