#include "script_component.hpp"
/*
 * Author: Ampersand
 * Run animateSource then its onPhaseChanged code
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Unit <OBJECT>
 * 2: Turret <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle, _unit, [1]] call vtx_uh60_config_fnc_handleTurnOut
 */

params ["_vehicle", "_unit", "_turret"];

if !(_turret in [[1], [2]] && {_vehicle isKindOf "vtx_h60_base"}) exitWith {};

[
  ["", ""],
  ["window_l", "window_l_ffv"],
  ["window_r", "window_r_ffv"]
] select (_turret # 0) params ["_windowAnimation", "_ffvSource"];

if (_vehicle animationSourcePhase _windowAnimation < 0.5) then {
  _vehicle animateSource [_windowAnimation, 1];
  _vehicle animateDoor [_ffvSource, 1];
};
