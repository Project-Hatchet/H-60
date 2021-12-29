#include "script_component.hpp"

if (hasInterface) then {
    #include "initKeybinds.sqf"
};

["vtx_H60_base", "Reloaded", {call FUNC(restorePylons)}, true, [], true] call CBA_fnc_addClassEventHandler;

vtx_uh60_mfd_marks = 0;
