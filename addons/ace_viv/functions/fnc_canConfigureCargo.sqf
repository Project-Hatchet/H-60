#include "script_component.hpp"
/*
 * Author: Ampersand
 * Checks if given unit can access the viv cargo of the given vehicle.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Carrier <OBJECT>
 *
 * Return Value:
 * Unit can configure the vehicle's viv cargo <BOOL>
 *
 * Example:
 * [ace_player, cursorObject] call vtx_ace_viv_fnc_canConfigureCargo
 *
 * Public: No
 */

params ["_unit", "_carrier"];

if ((_unit distanceSqr _carrier) > GVAR(loadDistance)) exitWith {false};

if !(vehicleCargoEnabled _carrier) exitWith {false};

[_unit, _carrier] call ace_common_fnc_canInteractWith
