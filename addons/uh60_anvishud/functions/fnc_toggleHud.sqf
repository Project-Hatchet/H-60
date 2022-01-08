/*
 * vtx_uh60_anvishud_fnc_toggleHud
 *
 * Toggles your HMD
 *
 * params ["_value"]
 */

params ["_value"];

vehicle player setUserMFDvalue [15, _value];
