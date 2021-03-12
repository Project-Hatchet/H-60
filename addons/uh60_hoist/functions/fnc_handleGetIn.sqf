/*
 * Author: Ampersand
 *
 *
 * Arguments:
 * 0: Hook <OBJECT>
 * 1: Role <STRING>
 * 2: Unit <OBJECT>
 *
 * Return Value: nil
 *
 * Example:
 * [_hook, "", _unit] call vtx_uh60_hoist_fnc_handleGetIn
 */

params ["_hook", "", "_unit"];

systemChat "getin";

[_hook, _unit] call vtx_uh60_hoist_fnc_attachHook;
