/*
 * Author: Yax
 * Disable the pip camera
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_vehicle] call hct_h60_flir_fnc_pipStop
 */

//params ["_vehicle"];

if (isNil "hct_h60_flir_camera") exitWith {true};
camDestroy hct_h60_flir_camera;
hct_h60_flir_camera cameraEffect ["terminate", "back", "hct_h60_flir_feed"];
hct_h60_flir_camera = nil;

true
