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
 * [_vehicle, "ERFS_show", 1] call vtx_uh60_hoist_fnc_animateSourceCustomization
 */

params ["_vehicle", "_name", "_phase", ["_speed", 1]];

_vehicle animateSource [_name, _phase, _speed];
private _cfgAnimSrc = configOf _vehicle >> "AnimationSources" >> _name;

private _onPhaseChanged = getText (_cfgAnimSrc >> "onPhaseChanged");
if (_onPhaseChanged != "") then {
  [_vehicle, _phase] call compile _onPhaseChanged;
};

private _mass = getNumber (_cfgAnimSrc >> "mass");
if (_mass != 0) then {
  // _vehicle setMass (_mass * ([-1, 1] select _phase) + getMass _vehicle);
};
