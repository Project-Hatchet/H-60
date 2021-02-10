/*
 * Author: Yax
 * attach the hook to the player and start the loop that handles getting in and out
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Hook <OBJECT>
 *
 * Return Value: nil
 *
 * Example:
 * ["_unit", "_hook"] call vtx_uh60_hoist_fnc_attachHook
 * [player, getPos player nearestObject "vtx_hook"] call vtx_uh60_hoist_fnc_attachHook
 */
//vtx_uh60_hoist_fnc_attachHook={
params ["_unit", "_hook"];
private _heli = _hook getVariable "vtx_uh60_hoist_heli";
if (isNil "_heli") exitWith { false };

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{ false };
_hoist_vars params ["_rope", "_dummy", "_hook"];

if (vehicle _unit != _hook) then {
    _dummy attachTo [_unit, [0,0.15,0.2],"pelvis"];
};
_unit setVariable ["vtx_attachedHook", _hook];

waitUntil {
    sleep 0.1;
    private _attachedToPlayer = (attachedTo _dummy) == _unit;
    private _playerInHook = vehicle _unit == _hook;
    systemchat str [_unit, _dummy, _hook, _rope, _heli];
    [_unit, _dummy, _hook, _rope, _heli] call vtx_uh60_hoist_fnc_attachedHook;
    systemChat str [round time, "running hook script"];
    //keep this going if
    // 1. player is not in hook
    // 2. player is also not in
    // 3. rope breaks
    !((_attachedToPlayer || _playerInHook) || isNull _hook)
};
