#include "script_component.hpp"
/*
 * Author: Ampersand
 * Stop PFH for loading viv cargo
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [ACE_player] call vtx_ace_viv_fnc_stopLoading
 *
 * Public: No
 */

params ["_unit"];

if (!GVAR(isReady)) exitWith {};

[GVAR(carrier)] call vtx_ace_viv_fnc_checkBlockedSeats;
GVAR(isReady) = false;
GVAR(carrier) = objNull;
GVAR(cargo) = objNull;

// enable running again
[_unit, "forceWalk", "VTX_ACE_VIV", false] call ace_common_fnc_statusEffect_set;
[_unit, "blockThrow", "VTX_ACE_VIV", false] call ace_common_fnc_statusEffect_set;

// add mouse button action and hint
[] call ace_interaction_fnc_hideMouseHint;

[_unit, "DefaultAction", _unit getVariable [QGVAR(Load), -1]] call ace_common_fnc_removeActionEventHandler;
[_unit, "zoomtemp", _unit getVariable [QGVAR(Cancel), -1]] call ace_common_fnc_removeActionEventHandler;

_unit setVariable [QGVAR(isLoading), false, true];
