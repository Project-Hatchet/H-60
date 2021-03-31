#include "script_component.hpp"

if (hasInterface) then {
    #include "ACE_Actions.sqf"
    #include "initKeybinds.sqf"
};

[QGVAR(attachHook), FUNC(attachHook)] call CBA_fnc_addEventHandler;
