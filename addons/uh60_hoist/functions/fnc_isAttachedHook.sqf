/*
 * Author: Yax
 * check if the player is attached to a hook or a hook is attached to a player
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value: nil
 *
 * Example:
 * ["_unit"] call vtx_uh60_hoist_fnc_isAttachedHook
 */

params ["_unit"];
private _hook = _unit getVariable "vtx_attachedHook";
if (isNil "_hook") exitWith { false };
private _heli = _hook getVariable "vtx_uh60_hoist_heli";
if (isNil "_heli") exitWith { false };
private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{ false };
_hoist_vars params ["_rope", "_dummy", "_hook"];
(alive _hook && (_hook == vehicle _unit || attachedTo _dummy == _unit))
