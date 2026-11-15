/*
 * hct_h60_anvishud_fnc_setup
 *
 * initial setup of ANVIS/HUD-24T
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

_vehicle setUserMFDValue [15, hct_h60_anvishud_defaultMode];

[_vehicle] call hct_h60_anvishud_fnc_configureHMD;

true
