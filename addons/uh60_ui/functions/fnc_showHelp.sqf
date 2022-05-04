/*
 * vtx_uh60_ui_fnc_showHelp
 *
 * toggles the help display for the ui module
 *
 * params (array)[(object) vehicle, (bool) show]
 */

#include "uiDefines.hpp"

params ["_vehicle", "_show"];

if ([_vehicle, "doorguns"] call htf_core_fnc_hasModule) exitWith {
    _this call vtx_uh60_doorguns_fnc_showHelp;
    CTRL(4001122) ctrlShow (_show);
    CTRL(4001121) ctrlShow false;
};

CTRL(4001122) ctrlShow false;
CTRL(4001121) ctrlShow (_show);
