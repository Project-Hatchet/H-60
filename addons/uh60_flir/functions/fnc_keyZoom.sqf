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
 * [1] call vtx_uh60_flir_fnc_keyZoom // In
 * [-1] call vtx_uh60_flir_fnc_keyZoom // Out
 */

params ["_change"];

if (vtx_uh60_flir_pipIsFixed && {!vtx_uh60_flir_isInScriptedCamera}) exitWith {false};
private _currStep = vtx_uh60_flir_camFOVLevels findIf {_x == vtx_uh60_flir_FOV};
private _newStep = 0 max (_currStep + _change) min (count vtx_uh60_flir_camFOVLevels - 1);

[vtx_uh60_flir_camFOVLevels # _newStep] call vtx_uh60_flir_fnc_setFOV;

true
