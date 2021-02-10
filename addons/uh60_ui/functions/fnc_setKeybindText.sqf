/*
 * vtx_uh60_ui_fnc_setKeybindText
 *
 * updates keybind related hints in the HUD
 *
 * params (array)[(object) vehicle]
 */

#include "uiDefines.hpp"
params ["_vehicle"];

private _keybindHelp = ((["UH-60M Blackhawk","vtx_uh60m_c_help"] call CBA_fnc_getKeybind)# 5) call CBA_fnc_localizeKey;
private _label = format ["Press %1 For Help", _keybindHelp];

SETTEXT(4001119,_label);

private _keybindInteract = ((["VXF Interaction","vxf_interaction"] call CBA_fnc_getKeybind)# 5) call CBA_fnc_localizeKey;
_label = format ["Interaction: %1", _keybindInteract];

SETTEXTGRP(HELP,1,_label);

private _keybindNext = actionKeysNames "nextAction";
private _keybindPrev = actionKeysNames "prevAction";
_label = format ["Lever next & knob increase: %1", _keybindNext];
SETTEXTGRP(HELP,2,_label);
_label = format ["Lever prev & knob decrease: %1", _keybindPrev];
SETTEXTGRP(HELP,3,_label);

private _keybindRemoteStby = ((["UH-60M Blackhawk","vtx_uh60m_c_rmtsby"] call CBA_fnc_getKeybind)# 5) call CBA_fnc_localizeKey;
_label = format ["Flight Director standby: %1", _keybindRemoteStby];
SETTEXTGRP(HELP,4,_label);
