/*
 * Author: Ampersand
 * Check if unit can hook-on to hook.
 *
 * Arguments:
 * 0: Hook <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_hook, _unit] call hct_h60_hoist_fnc_canAttachHook
 */

params ["_hook", "_unit"];

hct_h60_hoist_setting_useAttachScript
&& {isNull (_unit getVariable ["hct_attachedHook", objNull])}
&& {isNull (_hook getVariable ["hct_attachedUnit", objNull])}
&& {isNull objectParent _unit}
&& {_hook emptyPositions "cargo" > 0}
