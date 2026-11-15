/*
 * hct_h60_ui_fnc_shutDown
 *
 * stops the ui module, handling dialogs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (!isNil "hct_h60_ui_keybindUpdateEvent") then {
    ["hct_unPause", hct_h60_ui_keybindUpdateEvent] call CBA_fnc_removeEventHandler;
    hct_h60_ui_keybindUpdateEvent = nil;
};

player hideObject false;
