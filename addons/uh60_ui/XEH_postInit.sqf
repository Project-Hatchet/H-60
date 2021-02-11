#include "script_component.hpp"

if !(hasInterface) exitWith {};

#include "initKeybinds.sqf"

call vtx_uh60_ui_fnc_toggleCursor;
["cameraView", vtx_uh60_ui_fnc_toggleCursor] call CBA_fnc_addPlayerEventHandler;
["featureCamera", vtx_uh60_ui_fnc_toggleCursor] call CBA_fnc_addPlayerEventHandler;
