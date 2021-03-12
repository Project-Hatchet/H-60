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
 * [_heli] call vtx_uh60_hoist_fnc_isHookDamaged
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
(_hoist_vars isEqualTo [] || {objNull in _hoist_vars})
&& {_heli animationSourcePhase "hoist_hook_hide" == 1}
&& {_hoist_vars params ["_rope", "_dummy", "_hook"]; !(_dummy in ropeAttachedObjects _heli)}
