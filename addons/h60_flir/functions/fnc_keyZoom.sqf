/*
 * Author: Ampersand
 * Change the zoom level
 *
 * Arguments:
 * 0: Change <NUMBER>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [1] call hct_h60_flir_fnc_keyZoom // In
 * [-1] call hct_h60_flir_fnc_keyZoom // Out
 */

params ["_change"];

if (hct_h60_flir_isPipHidden) exitWith {false};

if (hct_h60_flir_pipIsFixed && {!hct_h60_flir_isInScriptedCamera}) exitWith {false};
private _currStep = hct_h60_flir_camFOVLevels findIf {_x == hct_h60_flir_FOV};
private _newStep = 0 max (_currStep + _change) min (count hct_h60_flir_camFOVLevels - 1);

[hct_h60_flir_camFOVLevels # _newStep] call hct_h60_flir_fnc_setFOV;

true
