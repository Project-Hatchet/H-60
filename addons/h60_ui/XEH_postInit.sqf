#include "script_component.hpp"

if !(hasInterface) exitWith {};

// Moved from main (the core addon must not call into a leaf addon). Re-runs
// Hatchet's vehicle-change handling on a turret switch so the seat's modules,
// keybind text and help overlay follow the player. Delete if the framework
// ever handles turret changes itself.
["turret", {
    [ACE_player, vehicle ACE_player] call hct_core_fnc_handleVehicleChanged;
    [vehicle ACE_player] call FUNC(setKeybindText);
    [vehicle ACE_player, GVAR(helpEnabled)] call FUNC(showHelp);
}, true] call CBA_fnc_addPlayerEventHandler;

#include "initKeybinds.inc.sqf"

call hct_h60_ui_fnc_toggleCursor;
["cameraView", hct_h60_ui_fnc_toggleCursor] call CBA_fnc_addPlayerEventHandler;
["featureCamera", hct_h60_ui_fnc_toggleCursor] call CBA_fnc_addPlayerEventHandler;
