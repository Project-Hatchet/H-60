
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
 * call hct_h60_flir_fnc_FlirAimToggle
 */




switch (hct_h60_flir_slewAim) do
{
	case true: {
		if (uiNamespace getVariable ['hct_h60_flir_mouseBlocker', false]) then {
		(findDisplay 86005) closeDisplay 0;
		}; 
		hct_h60_flir_slewAim = false;
	};
	case false: {
		if (hct_h60_flir_isPipHidden || {hct_h60_flir_isInScriptedCamera}) exitWith {false}; 
		hct_h60_flir_slewAim = true; 
		if (hct_h60_flir_setting_AimSlewBlockMouse && {!ace_interact_menu_keyDown}) then {
		(findDisplay 46) createDisplay 'hct_h60_flir_mouseBlocker'; 
		(finddisplay 86005) displayAddEventHandler ['KeyUp', {[_this,'keyup'] call CBA_events_fnc_keyHandler}];
		};
	};
};
