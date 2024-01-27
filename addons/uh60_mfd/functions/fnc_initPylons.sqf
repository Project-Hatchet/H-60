#include "script_component.hpp"
/*
 * Author: Ampersand
 * Initialize pylon, weapons, and magazines
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [vxf_vehicle] call vtx_uh60_mfd_fnc_initPylons
 */

params ["_vehicle"];

if (local _vehicle) then {
  //_vehicle removeWeapon "vtx_pylon_mfd";
};
