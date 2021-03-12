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
 * [_hook, _unit] call vtx_uh60_hoist_fnc_canAttachHook
 */

params ["_hook", "_unit"];

isNull (_unit getVariable ["vtx_attachedHook", objNull])
&& {isNull (_hook getVariable ["vtx_attachedUnit", objNull])}
&& {vehicle _unit == _unit}
&& {_hook emptyPositions "cargo" > 0}
