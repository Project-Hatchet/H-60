/*
 * Author: Ampersand
 * check if heli is able to deploy hook
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_canDeployHook
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if !(_hoist_vars isEqualTo []) exitWith{false};
if (_heli animationSourcePhase "hoist_hook_hide" != 0) exitWith {false};

true
