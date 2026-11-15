/*
 * hct_h60_ui_fnc_setup
 *
 * starts up the ui module, handling dialogs
 *
 * params (array)[(object) vehicle, (Display) _display]
 */
params ["_vehicle", "_display"];

uiNamespace setVariable ["hct_h60_ui_hud", _display];
hct_interaction_cursorPos = [0.5,0.5];

hct_h60_ui_keybindUpdateEvent = ["hct_unPause", {
        [vehicle player] call hct_h60_ui_fnc_setKeybindText;
    }] call CBA_fnc_addEventHandler;

hct_h60_ui_helpEnabled = false;
[_vehicle, hct_h60_ui_helpEnabled] call hct_h60_ui_fnc_showHelp;
[_vehicle] call hct_h60_ui_fnc_setKeybindText;

// player hideObject true;

true
