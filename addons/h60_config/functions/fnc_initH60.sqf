#include "script_component.hpp"
/*
 * Author: Ampersand
 * Run animateSource then its onPhaseChanged code
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle] call hct_h60_config_fnc_initH60
 */

params ["_vehicle"];

if !(local _vehicle) exitWith {};

[_vehicle, "l", 1, true] call hct_h60_config_fnc_setWindow;
[_vehicle, "r", 1, true] call hct_h60_config_fnc_setWindow;
