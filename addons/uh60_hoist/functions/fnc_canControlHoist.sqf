/*
 * Author: Ampersand
 * check if player is able to control the hoist
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_unit] call vtx_uh60_hoist_fnc_canControlHoist
 */

params ["_unit"];

private _vehicle = vehicle _unit;
if !(typeOf _vehicle isKindOf "vtx_H60_base") exitWith { false };
if (_unit == driver _vehicle) exitWith { true }; // driver can control

private _turretIndex = [_unit] call ace_common_fnc_getTurretIndex;
private _copilotTurretIndex = [_vehicle] call ace_common_fnc_getTurretCopilot;
if((count _copilotTurretIndex) > 0 && (count _turretIndex) > 0 && {(_turretIndex # 0) == (_copilotTurretIndex # 0)}) exitWith { true }; //copilot can control

if (count _turretIndex == 0) exitWith { false }; // at this point if you're not in a turret you can't control

// Cabin side (Riverman rulings 2026-09-23): on the real aircraft only the
// pilots and the crew member holding the hoist pendant run the winch. The
// pendant is the "(hoist controls)" seat - but sitting there is not enough:
// the unit must also be the vehicle's DESIGNATED hoist operator, which only
// the "Enter Hoist Operator" swap from the right crew seat grants (uh60_misc
// fnc_ccSwap / fnc_ccSwapLocks). A passenger who merely takes the seat gets
// no control, and the designation clears when the operator leaves the seat.

private _config = [configOf _vehicle, _turretIndex] call ace_common_fnc_getTurretConfigPath;
private _gunnerName = getText (_config >> "gunnerName");

// DAP (Riverman ruling 2026-10-06): the right crew chief's turned-out spot is
// the same door-sill position the pendant seat occupies on the transports,
// so a turned-out right crew chief runs the hoist. No designation needed -
// that spot is swap-only, nobody but the crew chief can ever be in it.
if (_gunnerName == "R Crew Chief (Turned Out)") exitWith { true };

(["hoist", _gunnerName] call BIS_fnc_inString)
&& {(_vehicle getVariable ["vtx_hoistOperator", objNull]) isEqualTo _unit}
