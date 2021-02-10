/*
 * vtx_uh60_ui_fnc_setup
 *
 * starts up the ui module, handling dialogs
 *
 * params (array)[(object) vehicle, (Display) _display]
 */
params ["_vehicle", "_display"];

uiNamespace setVariable ["vtx_uh60_ui_hud", _display];
vxf_interaction_cursorPos = [0.5,0.5];

vtx_uh60_ui_keybindUpdateEvent = ["vxf_unPause", {
        [vehicle player] call vtx_uh60_ui_fnc_setKeybindText;
    }] call CBA_fnc_addEventHandler;

vtx_uh60_ui_helpEnabled = false;
[_vehicle, vtx_uh60_ui_helpEnabled] call vtx_uh60_ui_fnc_showHelp;
[_vehicle] call vtx_uh60_ui_fnc_setKeybindText;

// player hideObject true;

true
