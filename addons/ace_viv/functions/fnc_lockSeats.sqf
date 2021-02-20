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
 * [_heli, true] call vtx_ace_viv_fnc_lockSeats
 *
 * Public: No
 */

params ["_carrier", "_lock"];

private _seats = getArray (configOf _carrier >> QGVAR(lockSeats));

{
    _carrier lockTurret [_x, _lock];
} forEach (_seats # 0);
{
    _carrier lockCargo [_x, _lock];
} forEach (_seats # 1);
