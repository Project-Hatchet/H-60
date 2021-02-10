/*
 * Author: Ampersand
 * check if close enough for heli crew to pull rescuee in the hook into the helicopter
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_canRecoverPerson
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

private _hoistPos = [1.405, 2.03, 0.45];
if ((_hook distance (_heli modelToWorld _hoistPos)) > 1.5) exitWith {false};
if (crew _hook isEqualTo []) exitWith {false};

true
