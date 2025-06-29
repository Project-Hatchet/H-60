#include "script_component.hpp"
/*
 * Author: Ampersand
 * Run animateSource then its onPhaseChanged code
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Window <STRING> "l" or "r"
 * 2: Phase <NUMBER> 0 closed, 1 open, -1 toggle
 * 3: Speed <NUMBER> 0 closed, 1 open, -1 toggle
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle, "l", -1] call vtx_uh60_config_fnc_setWindow
 */

params ["_vehicle", "_window", ["_phase", -1], ["_speed", false]];

private _windowAnimation = format ["window_%1", _window];
private _ffvSource = format ["window_%1_ffv", _window];

if (_phase == -1) then {
  _phase = parseNumber (_vehicle animationSourcePhase _windowAnimation < 0.5);
};

_vehicle animateSource [_windowAnimation, _phase, _speed];
_vehicle animateDoor [_ffvSource, _phase, _speed];
