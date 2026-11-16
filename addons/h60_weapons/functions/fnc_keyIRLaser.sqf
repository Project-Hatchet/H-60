#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * Key input IR laser
 *
 * Arguments:
 * 0: State <NUMBER> (optional, default -1)
 *    -1: toggle, 0: force off, 1: force on
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call hct_h60_weapons_fnc_keyIRLaser
 * [1] call hct_h60_weapons_fnc_keyIRLaser
 *
 * Public: No
 */

params [["_state", -1]];

if (isNil "hct_vehicle" || {isNull hct_vehicle} || {LACKS_TRAIT(hct_vehicle,"irLaser")}) exitWith {};

switch (hct_vehicle unitTurret hct_player) do {
  case [-1]: {
    ["hct_h60_weapons_irLaser", [hct_vehicle, [0.085828,5.45809,-0.308074], 0, _state]] call CBA_fnc_globalEvent;
  };
  case [0]: {
    ["hct_h60_weapons_irLaser", [hct_vehicle, [-0.0956328,5.45809,-0.308074], 0, _state]] call CBA_fnc_globalEvent;
  };
  case [1]: {
    ["hct_h60_weapons_irLaser", [hct_vehicle, "chamber_1", "muzzle_1", _state]] call CBA_fnc_globalEvent;
  };
  case [2]: {
    ["hct_h60_weapons_irLaser", [hct_vehicle, "chamber_2", "muzzle_2", _state]] call CBA_fnc_globalEvent;
  };
  default {};
};
