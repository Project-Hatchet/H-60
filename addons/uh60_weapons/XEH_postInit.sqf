#include "script_component.hpp"

if (hasInterface) then {
    #include "ACE_Actions.sqf"
};

["vtx_fireSelected", {call vtx_uh60_weapons_fnc_ehFireSelected}] call CBA_fnc_addEventHandler;
["vtx_nextWeapon", {call vtx_uh60_weapons_fnc_ehNextWeapon}] call CBA_fnc_addEventHandler;
