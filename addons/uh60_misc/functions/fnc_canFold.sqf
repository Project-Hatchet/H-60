/*
 * Author: Ampersand
 * Checks if a unit can fold rotors
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [cursorObject, ACE_player] call vtx_uh60_misc_fnc_canFold
 */

params ["_heli", "_unit"];

_heli animationSourcePhase "rpm" == 0
&& {"ToolKit" in (items _unit)}
