#include "script_component.hpp"

if (hasInterface) then {
    #include "ACE_Actions.inc.sqf"
};

[QGVAR(attachHook), FUNC(attachHook)] call CBA_fnc_addEventHandler;
