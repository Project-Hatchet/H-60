#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * IR Laser on event
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Laser Start <ARRAY or STRING>
 * 2: Laser Direction <ARRAY or STRING or 0>
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call vtx_uh60_weapons_fnc_onLaserOn
 *
 * Public: No
 */

if (_this in GVAR(laserEmitters)) exitWith {
  GVAR(laserEmitters) = GVAR(laserEmitters) - [_this];
};

GVAR(laserEmitters) pushBackUnique _this;

if (
  GVAR(irLaserPFH) != -1
  || {GVAR(laserEmitters) isEqualTo []}
) exitWith {};

GVAR(irLaserPFH) = [LINKFUNC(irLaserPFH), 0, []] call CBA_fnc_addPerFrameHandler;
