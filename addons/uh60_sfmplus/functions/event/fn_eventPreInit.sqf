#include "\z\vtx\addons\uh60_sfmplus\headers\core.hpp"
vtx_uh60_sfmPlusKeyboardOnly = true;

[
	"vtx_uh60_sfmPlusStabilatorEnabled",
	"LIST",
	[localize "STR_VTX_UH60_SFMPLUS_StabilatorSimulation", "STR_VTX_UH60_SFMPLUS_StabilatorSimulation_Description"],
	["UH-60M", "Flight model"],
	[[STABILTOR_MODE_ALWAYSENABLED,STABILTOR_MODE_JOYSTICKONLY,STABILTOR_MODE_ALWAYSDISABLED],[localize "STR_VTX_UH60_SFMPLUS_AlwaysEnabled", "STR_VTX_UH60_SFMPLUS_JoystickOnly","STR_VTX_UH60_SFMPLUS_AlwaysDisabled"],1],
	0
] call CBA_fnc_addSetting;
[
	"vtx_uh60_sfmPlus_showDamageHints",
	"CHECKBOX",
	[localize "STR_VTX_UH60_SFMPLUS_ShowDamageHints", "STR_VTX_UH60_SFMPLUS_ShowDamageHints_Description"],
	["UH-60M", "Debug"],
	[true],
	0
] call CBA_fnc_addSetting;

private _eventTypes = ["Activate", "Deactivate", "Analog"];

{
    addUserActionEventHandler ["HeliCollectiveRaise", _x, {vtx_uh60_sfmPlusKeyboardOnly = true;}];
    addUserActionEventHandler ["HeliCollectiveLower", _x, {vtx_uh60_sfmPlusKeyboardOnly = true;}];
} forEach _eventTypes;

{
    addUserActionEventHandler ["HeliCollectiveRaiseCont", _x, {vtx_uh60_sfmPlusKeyboardOnly = false;}];
    addUserActionEventHandler ["HeliCollectiveLowerCont", _x, {vtx_uh60_sfmPlusKeyboardOnly = false;}];
} forEach _eventTypes;

#include "..\..\XEH_PREP.hpp"
