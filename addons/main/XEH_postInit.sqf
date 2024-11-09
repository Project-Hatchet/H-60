#include "script_component.hpp"

//Delete if framework ever gets updated
["turret", {
  [ACE_player, vehicle ACE_player] call vxf_core_fnc_handleVehicleChanged;
	[vehicle ACE_player] call vtx_uh60_ui_fnc_setKeybindText;
	[vehicle ACE_player, vtx_uh60_ui_helpEnabled] call vtx_uh60_ui_fnc_showHelp;
}, true] call CBA_fnc_addPlayerEventHandler; 
