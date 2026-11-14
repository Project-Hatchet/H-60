#include "script_component.hpp"
/*
 * Author: Ampersand
 * Locks or unlocks config seats blocked by ViV cargo
 *
 * Arguments:
 * 0: Carrier <OBJECT>
 * 1: Lock State <BOOLEAN>
 *
 * Return Value:
 * Unit can configure the aircraft's pylons <BOOL>
 *
 * Example:
 * [_heli] call vtx_ace_viv_fnc_checkBlockedSeats
 *
 * Public: No
 */

params ["_carrier"];

private _blocked = !(getVehicleCargo _carrier isEqualTo []);
[_carrier, _blocked] call FUNC(lockSeats);
