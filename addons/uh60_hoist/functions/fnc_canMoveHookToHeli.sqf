/*
 * Author: Ampersand
 * can unit move from hook to heli?
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_unit] call vtx_uh60_hoist_fnc_canMoveHookToHeli
 */

params ["_unit"];

if !(local _unit) exitWith {[_unit] remoteExecCall ["vtx_uh60_hoist_fnc_canMoveHookToHeli", _unit]};

private _hook = vehicle _unit;
private _heli = _hook getVariable ["vtx_uh60_hoist_heli", objNull];
if (_heli == objNull) exitWith {false};

private _hoistPos = [1.405, 2.03, 0.45];
if ((_hook distance (_heli modelToWorld _hoistPos)) > 1.5) exitWith {false};

/*
// not pilot or co-pilot
private _fullCrew = fullCrew [_heli, "", true];
(
    _fullCrew select (_fullCrew findIf {_unit == _x select 0})
) params ["", "_role", "_cargoIndex", "_turretPath"];
if (_cargoIndex < 0) exitWith {false};
*/

true
