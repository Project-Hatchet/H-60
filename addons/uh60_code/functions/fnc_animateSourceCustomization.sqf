#include "script_component.hpp"
/*
 * Author: Ampersand
 * Run animateSource then its onPhaseChanged code
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Source <STRING>
 * 2: Phase <NUMBER>
 * 3: Speed <NUMBER>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle, "cabindoor_L", 1] call vtx_uh60_hoist_fnc_animateSourceCustomization
 */

params ["_vehicle", "_name", "_phase", ["_speed", 0]];

_vehicle animateSource [_name, _phase, _speed];
private _onPhaseChanged = getText (configOf _vehicle >> "AnimationSources" >> _name >> "onPhaseChanged");
if (_onPhaseChanged == "") exitWith {};
[_vehicle, _phase] call compile _onPhaseChanged;
