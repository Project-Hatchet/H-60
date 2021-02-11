/*
 * Author: Ampersand
 * Align the local copilot turret and pilotCamera to straight front
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_shutDown
 */

params ["_vehicle"];
if (!(isEngineOn _vehicle)) then {
    _vehicle setPilotCameraTarget objNull;
    _vehicle setPilotCameraDirection [0,1,0];
    _heli lockCameraTo [objNull, [0]];
};

_this call vtx_uh60_flir_fnc_stopCamera;
