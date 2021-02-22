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

if ((_turretIndex # 0) < 3) exitWith { true }; // doorgunners are 1 and 2

private _config = [configOf _vehicle, _turretIndex] call ace_common_fnc_getTurretConfigPath;
private _gunnerName = getText (_config >> "gunnerName");

["hoist", _gunnerName] call BIS_fnc_inString //finally if you have hoist in your seat name you can use it
