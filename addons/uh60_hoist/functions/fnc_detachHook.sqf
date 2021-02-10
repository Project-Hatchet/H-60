/*
 * Author: Yax
 * detach the hook from the player and/or kick the player out of the hook
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value: nil
 *
 * Example:
 * ["_unit"] call vtx_uh60_hoist_fnc_detachHook
 */
params ["_unit"];
private _hook = _unit getVariable "vtx_attachedHook";
if (isNil "_hook") then { false };
private _heli = _hook getVariable "vtx_uh60_hoist_heli";
private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{ false };
_hoist_vars params ["_rope", "_dummy", "_hook"];
if (vehicle _unit == _hook) then {moveOut _unit};
detach _dummy;
