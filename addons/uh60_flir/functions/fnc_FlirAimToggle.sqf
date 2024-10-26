
/*
 * Author: lost
 * Toggle on Flir Slew aiming
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * call vtx_uh60_flir_fnc_FlirAimToggle
 */




switch (vtx_uh60_flir_slewAim) do
{
	case true: {
		if (uiNamespace getVariable ['vtx_uh60_flir_mouseBlocker', false]) then {
		(findDisplay 86005) closeDisplay 0;
		}; 
		vtx_uh60_flir_slewAim = false;
	};
	case false: {
		if (vtx_uh60_flir_isPipHidden || {vtx_uh60_flir_isInScriptedCamera}) exitWith {false}; 
		vtx_uh60_flir_slewAim = true; 
		if (vtx_uh60_flir_setting_AimSlewBlockMouse && {!ace_interact_menu_keyDown}) then {
		(findDisplay 46) createDisplay 'vtx_uh60_flir_mouseBlocker'; 
		(finddisplay 86005) displayAddEventHandler ['KeyUp', {[_this,'keyup'] call CBA_events_fnc_keyHandler}];
		};
	};
};