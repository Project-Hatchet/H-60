/*
 * Author: Ampersand
 * action on the hook to move rescuee into heli
 *
 * Arguments:
 * 0: Hook <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_hook] call vtx_uh60_hoist_fnc_getInHeliHook
 */

params ["_hook"];
private _heli = _hook getVariable ["vtx_uh60_hoist_heli", objNull];
if (_heli == objNull) exitWith {false};

private _crew = crew _hook;
if (_crew isEqualTo []) exitWith {false};
private _rescuee = _crew select 0;

[_rescuee] call vtx_uh60_hoist_fnc_getInHeli;

true
