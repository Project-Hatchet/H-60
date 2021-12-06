params ["_displayorcontrol", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];
// driver has the real pilotcam
if (player == driver (vehicle player)) exitWith {};
private _standardButtonPressed = (_button == 1) && _ctrl;
if(vtx_uh60_ui_showDebugMessages) then {systemChat str _standardButtonPressed;};
if (!_standardButtonPressed) exitWith {
	!(isNil "vtx_uh60_flir_camera")
};

if (isNil "vtx_uh60_flir_camera") then {
	[vehicle player] call vtx_uh60_flir_fnc_startPilotCamera;
} else {
	[vehicle player] call vtx_uh60_flir_fnc_stopPilotCamera;
};
true