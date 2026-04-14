/*
 * Author: Ampersand
 * Checks if a helicopter is fully unfolded.
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_misc_fnc_isUnfolded
 */

params ["_heli"];

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
] findIf {_heli animationSourcePhase _x > 0} == -1
