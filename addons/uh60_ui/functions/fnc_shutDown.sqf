/*
 * vtx_uh60_ui_fnc_shutDown
 *
 * stops the ui module, handling dialogs
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

["hatchet_unPause", vtx_uh60_ui_keybindUpdateEvent] call CBA_fnc_removeEventHandler;

player hideObject false;
