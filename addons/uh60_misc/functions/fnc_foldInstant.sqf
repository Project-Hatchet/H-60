/*
 * Author: Ampersand
 * Fold the helicopter's blades and stabilators.
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Phase <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject, 1] call vtx_uh60_misc_fnc_foldInstant;
 */

params ["_heli", "_phase"];

[
  ["RotorHFold", "rotorh", 0.125],
  ["RotorVFold", "rotorv", 0]
] apply {
  _x params ["_foldAnim", "_rotorAnim", "_phaseOffset"];

  private _rotorAnimPhase = (_heli animationSourcePhase _rotorAnim) mod 1 + _phaseOffset;

  _heli animateSource [_foldAnim, -_rotorAnimPhase, true];
};

[
  "Fold_Blade1",
  "Fold_Blade2",
  "Fold_Blade3",
  "Fold_Blade4",
  "Fold_Stabilator_rotate",
  "Fold_Stabilator_l",
  "Fold_Stabilator_r",
  "Fold_TailRotorOut",
  "Fold_TailRotorRotate"
] apply {_heli animateSource [_x, _phase, true]};
