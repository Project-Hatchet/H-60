#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * IR/IZLID Laser on event
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Laser Start <ARRAY or STRING>
 * 2: Laser Direction <ARRAY or STRING or 0>
 * 3: State <NUMBER> (optional, default -1)
 *    -1: toggle, 0: force off, 1: force on
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call vtx_uh60_weapons_fnc_onIRLaserOn
 *
 * Public: No
 */

params ["_vehicle", "_begSel", "_endSel", ["_state", -1]];
private _emitter = [_vehicle, _begSel, _endSel];
private _isOn = _emitter in GVAR(laserEmitters);
private _turnOn = if (_state == -1) then { !_isOn } else { _state == 1 };

if (_turnOn isEqualTo _isOn) exitWith {};

if (_turnOn) then {
  GVAR(laserEmitters) pushBackUnique _emitter;
} else {
  GVAR(laserEmitters) = GVAR(laserEmitters) - [_emitter];
};

if (
  GVAR(irLaserPFH) != -1
  || {GVAR(laserEmitters) isEqualTo []}
) exitWith {};

GVAR(irLaserPFH) = [LINKFUNC(irLaserPFH), 0, []] call CBA_fnc_addPerFrameHandler;
