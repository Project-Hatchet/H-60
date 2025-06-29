#include "script_component.hpp"
/*
 * Author: Ampersand
 * Handle the Fire Selected Weapon key.
 *
 * Arguments:
 * 0: Is Key Down <BOOLEAN>
 *
 * Return Value:
 * None
 *
 * Example:
 * [true] call vtx_uh60_weapons_fnc_keyFireSelected
 */

IS_EITHER_PILOT; // Sets _unit and _vehicle
IS_MASTER_ARM;

["vtx_fireSelected", _this + [_vehicle], driver _vehicle] call CBA_fnc_targetEvent;
