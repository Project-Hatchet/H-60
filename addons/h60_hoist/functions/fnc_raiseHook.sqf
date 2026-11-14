#include "script_component.hpp"

params ["_heli", ["_active", true]];

// permission is checked on the initiating client; the hoist owner may be a
// dedicated server where player is objNull
if (_active && {!([player] call vtx_uh60_hoist_fnc_canControlHoist)}) exitWith {};

if !(local _heli) exitWith {[_heli, _active] remoteExecCall ["vtx_uh60_hoist_fnc_raiseHook", _heli]};

// key-held state lives on the vehicle so it exists wherever the loop runs
_heli setVariable ["vtx_uh60_hoist_retracting", _active, true]; // public: the rider-side attach PFH reads it
if !(_active) exitWith {};
if (_heli getVariable ["vtx_uh60_hoist_raiseLoopRunning", false]) exitWith {};
_heli setVariable ["vtx_uh60_hoist_raiseLoopRunning", true];

[_heli, -1] call FUNC(winchTick); // 10 Hz while the key is held
