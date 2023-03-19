#include "uiDefines.hpp"

/*
 * vtx_uh60_doorguns_fnc_showHelp
 *
 * toggles the help display for the ui module
 *
 * params (array)[(object) vehicle, (bool) show]
 */
params ["_vehicle", "_show"];

CTRL(4001121) ctrlShow (_show);
HELPCTRL(4) ctrlShow (false);
HELPCTRL(5) ctrlShow (false);
HELPCTRL(6) ctrlShow (false);
HELPCTRL(7) ctrlShow (false);
HELPCTRL(8) ctrlShow (false);
HELPCTRL(9) ctrlShow (false);
HELPCTRL(10) ctrlShow (false);
HELPCTRL(11) ctrlShow (false);
HELPCTRL(12) ctrlShow (false);
