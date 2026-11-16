/*
 * Author: Ampersand
 * check if heli's hook is deployed
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call hct_h60_hoist_fnc_isHoistReady
 */

params ["_heli"];

private _hoist_vars = _heli getVariable ["hct_h60_hoist_vars", []];
_hoist_vars isNotEqualTo []
