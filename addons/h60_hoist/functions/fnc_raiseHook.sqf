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

[_heli] spawn {
    params ["_heli"];
    while {_heli getVariable ["vtx_uh60_hoist_retracting", false]} do {
        private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
        if (_hoist_vars isEqualTo []) exitWith {};
        _hoist_vars params ["_rope", "_dummy", "_hook"];
        private _ropeLength = ropeLength _rope;
        private _speed = [MAX_HOIST_SPEED, NEAR_END_SPEED] select (_ropeLength < NEAR_END_THRESHOLD); // slow speed near cable extreme
        ropeUnwind [
            _rope,
            _speed,
            (_ropeLength - _speed * 0.3) max 0 // keep the target ahead of the winch so _speed governs
        ];
        _dummy awake true; // the 10 Hz winch cadence lets the rope-end body fall asleep in PhysX
        sleep 0.1;
    };
    _heli setVariable ["vtx_uh60_hoist_raiseLoopRunning", false];
};
