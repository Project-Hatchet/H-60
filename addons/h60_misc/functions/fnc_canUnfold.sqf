/*
 * Author: Ampersand
 * Checks if a unit can unfold rotors
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [cursorObject, ACE_player] call vtx_uh60_misc_fnc_canUnfold
 */

params ["_heli", "_unit"];

selectMax ([
  "Fold_Blade1",
  "Fold_Blade2",
  "Fold_Blade3",
  "Fold_Blade4",
  "Fold_Stabilator_rotate",
  "Fold_Stabilator_l",
  "Fold_Stabilator_r",
  "Fold_TailRotorOut",
  "Fold_TailRotorRotate"
] apply {
  _heli animationSourcePhase _x
}) > 0
