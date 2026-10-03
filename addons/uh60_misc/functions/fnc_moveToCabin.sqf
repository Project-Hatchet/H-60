/*
 * Author: Ampersand
 * Move to a cabin seat
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [hct_vehicle] call vtx_uh60_misc_fnc_moveToCabin
 */

params ["_vehicle"];

private _allTurrets = allturrets [_vehicle, true];
_allTurrets deleteAt 0; // Remove copilot seat

private _tcTurret = [];
{
  if (getText (_x >> "gunnerName") == "Troop Commander") exitWith {
    _tcTurret = [_forEachIndex];
  };
} forEach ("true" configClasses (configOf _vehicle >> "Turrets"));

private _doorGunTurrets = [[1], [2]] select {_x in _allTurrets};
private _remainingTurrets = (_allTurrets - _doorGunTurrets) - [_tcTurret];
private _priorityTurrets = _doorGunTurrets + (if (_tcTurret in _allTurrets) then {[_tcTurret]} else {[]}) + _remainingTurrets;

scopeName "main";

{
  private _isDoorGunTurret = _x in [[1], [2]];
  if (!(_isDoorGunTurret && {(_vehicle weaponsTurret _x) isEqualTo []}) && {isNull (_vehicle turretUnit _x)}) then {
    player action ["moveToTurret", hct_vehicle, _x];
    true breakOut "main";
  };
} count _priorityTurrets;

false
