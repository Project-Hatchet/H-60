#include "script_component.hpp"
/*
 * Author: Ampersand
 * Checks if player can adjust pylon
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Unit <OBJECT>
 * 2: Side <NUMBER> 0: Left, 1: Right
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli, _player, 0] call vtx_uh60_weapons_fnc_canAdjustPylonPosition
 */

params ["_heli", "_player", "_side"];

(
  _heli animationSourcePhase "LASS_show" == 1 ||
  {_heli animationSourcePhase "ESSS_show" == 1}
) &&
{[_player, _target] call ace_pylons_fnc_canConfigurePylons} &&
{getPylonMagazines _target select _actionParams != ""}
