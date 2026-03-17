/*
 * Author: Ampersand
 * Freeze the folding animation
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject] call vtx_uh60_misc_fnc_foldFreeze;
 */

params ["_heli"];

[
  "RotorHFold",
  "RotorVFold",
  "Fold_Blade1",
  "Fold_Blade2",
  "Fold_Blade3",
  "Fold_Blade4",
  "Fold_Stabilator_rotate",
  "Fold_Stabilator_l",
  "Fold_Stabilator_r",
  "Fold_TailRotorOut",
  "Fold_TailRotorRotate"
] apply {_heli animateSource [_x, _heli animationSourcePhase _x, true]};
