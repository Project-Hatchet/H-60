/*
 * Author: Ampersand
 * can unit move from heli to hook?
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_unit] call vtx_uh60_hoist_fnc_canMoveHeliToHook
 */

params ["_unit"];

if !(local _unit) exitWith {[_unit] remoteExecCall ["vtx_uh60_hoist_fnc_canMoveHeliToHook", _unit]};

private _heli = vehicle _unit;
if (_heli animationPhase "cabindoor_R" == 1) exitWith {false};
if (_unit == driver _heli) exitWith {false};

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

private _hoistPos = [1.405, 2.03, 0.45];
if ((_hook distance (_heli modelToWorld _hoistPos)) > 1.5) exitWith {false};

if !(crew _hook isEqualTo []) exitWith {false};

true
