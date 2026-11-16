/*
 * Author: Ampersand
 * check if heli's hook is damaged
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call hct_h60_hoist_fnc_isHookDamaged
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["hct_h60_hoist_vars", []];
(_hoist_vars isEqualTo [] || {objNull in _hoist_vars})
&& {_heli animationSourcePhase "hoist_hook_hide" == 1}
&& {!((_hoist_vars param [1, objNull]) in ropeAttachedObjects _heli)} // vars are [] after a rope break
