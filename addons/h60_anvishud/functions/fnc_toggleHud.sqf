/*
 * hct_h60_anvishud_fnc_toggleHud
 *
 * Toggles your HMD
 *
 * params ["_value"]
 */

params ["_value"];

vehicle player setUserMFDValue [15, _value];

[vehicle player] call hct_h60_anvishud_fnc_configureHMD;
