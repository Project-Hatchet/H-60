#include "\z\vtx\addons\uh60_sfmplus\headers\core.hpp"
vtx_uh60_sfmPlusKeyboardOnly = true;

[
	"vtx_uh60_sfmPlusStabilatorEnabled",
	"LIST",
	["Enable stabilator simulation", "The stabilator provides an expanded pitch range allowing for more accurate cruise speeds during flight. The stabilator is optimized for Joysticks and may be more difficult to use with a Keyboard & Mouse."],
	["UH-60M", "Flight model"],
	[[STABILTOR_MODE_ALWAYSENABLED,STABILTOR_MODE_JOYSTICKONLY,STABILTOR_MODE_ALWAYSDISABLED],["Always Enabled", "Joystick Only","Always Disabled"],1],
	0
] call CBA_fnc_addSetting;
[
	"vtx_uh60_sfmPlus_showDamageHints",
	"CHECKBOX",
	["Show Engine Damage Hints", "Show damage hints related to overtorquing of the engines."],
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
