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

params ["_scrollAmount"];

if (GVAR(isReady)) then {
    [ACE_player] call FUNC(stopLoading);
};

true
