/*
 * vtx_uh60_misc_fnc_animateIncrement
 */

params ["_vehicle", "_animation", "_increment"];

if (isClass (configOf _vehicle >> "AnimationSources" >> "searchlight_turn")) exitWith {
  private _phase = _vehicle animationSourcePhase _animation;
  _vehicle animateSource [_animation, _phase + _increment];
};

if (_animation in animationNames _vehicle) exitWith {
  private _phase = _vehicle animationPhase _animation;
  _vehicle animate [_animation, _phase + _increment];
};

diag_log [
  "vtx_uh60_misc_fnc_animateIncrement: Animation does not exist",
  typeOf _vehicle,
  _animation
];
