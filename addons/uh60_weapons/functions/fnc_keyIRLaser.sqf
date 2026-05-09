#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * Key input IR laser
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call vtx_uh60_weapons_fnc_keyIRLaser
 *
 * Public: No
 */

if !(
  hct_vehicle isKindOf "vtx_MH60M" ||
  {hct_vehicle isKindOf "vtx_MH60M_DAP"} ||
  {hct_vehicle isKindOf "vtx_MH60M_DAP_MLASS"}
) exitWith {};

switch (hct_vehicle unitTurret hct_player) do {
  case [-1]: {
    ["vtx_uh60_weapons_irLaser", [hct_vehicle, [0.085828,5.45809,-0.308074], 0]] call CBA_fnc_globalEvent;
  };
  case [0]: {
    ["vtx_uh60_weapons_irLaser", [hct_vehicle, [-0.0956328,5.45809,-0.308074], 0]] call CBA_fnc_globalEvent;
  };
  case [1]: {
    ["vtx_uh60_weapons_irLaser", [hct_vehicle, "chamber_1", "muzzle_1"]] call CBA_fnc_globalEvent;
  };
  case [2]: {
    ["vtx_uh60_weapons_irLaser", [hct_vehicle, "chamber_2", "muzzle_2"]] call CBA_fnc_globalEvent;
  };
  default {};
};
