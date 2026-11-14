#include "script_component.hpp"
/*
 * Author: Ampersand
 * Stops loading
 *
 * Arguments:
 * 0: Scroll amount <NUMBER>
 *
 * Return Value:
 * Handled or not. <BOOL>
 *
 * Example:
 * [0.1] call vtx_ace_viv_fnc_handleScrollWheel;
 *
 * Public: No
 */

if !(GVAR(isReady)) exitWith {false};

[ACE_player] call FUNC(stopLoading);

true
