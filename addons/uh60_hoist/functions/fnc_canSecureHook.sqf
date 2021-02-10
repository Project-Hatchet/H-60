/*
 * Author: Ampersand
 * check if heli is able to secure hook
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_canSecureHook
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

private _hoistPos = [1.405, 2.03, 0.45];
if ((_hook distance (_heli modelToWorld _hoistPos)) > 1.5) exitWith {false};
if !(crew _hook isEqualTo []) exitWith {false};
if !(_dummy in (ropeAttachedObjects _heli)) exitWith {false};

true
