#include "script_component.hpp"
/*
 * Author: Ampersand
 * Handle the Master Arm key.
 *
 * Arguments:
 * 0: Is Key Down <BOOLEAN>
 *
 * Return Value:
 * None
 *
 * Example:
 * [true] call hct_h60_weapons_fnc_keyMasterArm
 */

IS_EITHER_PILOT; // Sets _unit and _vehicle

private _isSafe = hct_vehicle getVariable ["hct_h60_weapons_masterArm_isSafe", true];
hct_vehicle setVariable ["hct_h60_weapons_masterArm_isSafe", !_isSafe, true];
