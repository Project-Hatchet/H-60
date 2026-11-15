/*
 * hct_h60_ui_fnc_setKeybindText
 *
 * updates keybind related hints in the HUD
 *
 * params (array)[(object) vehicle]
 */

#include "uiDefines.hpp"
params ["_vehicle"];

// CBA keys its keybind registry by the category string exactly as registered
// (the stringtable key, not its text). A keybind that is not registered -
// its addon missing, or the action retired - reads as "-" instead of a script
// error that would leave the rest of the HUD hints unset.
private _fnc_keyName = {
    params ["_category", "_action"];
    private _bind = [_category, _action] call CBA_fnc_getKeybind;
    if (isNil "_bind") exitWith {"-"};
    (_bind # 5) call CBA_fnc_localizeKey
};

private _label = format [localize "STR_hct_h60_ui_PressForHelp", ["STR_hct_h60_main_Category", "hct_h60_c_help"] call _fnc_keyName];
SETTEXT(4001119,_label);

_label = format [localize "STR_hct_h60_ui_InteractionKey", ["Hatchet Interaction Framework", "hct_interaction"] call _fnc_keyName];
SETTEXTGRP(HELP,1,_label);

_label = format [localize "STR_hct_h60_ui_LeverNext", actionKeysNames "nextAction"];
SETTEXTGRP(HELP,2,_label);
_label = format [localize "STR_hct_h60_ui_LeverPrev", actionKeysNames "prevAction"];
SETTEXTGRP(HELP,3,_label);

// line 4 was the Flight Director standby keybind, retired in 0.7.7.3
SETTEXTGRP(HELP,4,"");
