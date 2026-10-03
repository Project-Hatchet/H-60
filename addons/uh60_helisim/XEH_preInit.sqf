#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

//This pack's own airframe, from its own CfgPatches entry. Every installed pack schedules only its
//own aircraft, so this pack and any other loaded alongside it never touch each other's.
GVAR(baseClass) = getText (configFile >> "CfgPatches" >> QUOTE(ADDON) >> "bmkhsBaseClass");

//No event handler is registered: with no systems modelled there are no HeliSim cockpit controls
//or lights for Core's events to drive, so they are ignored for this aircraft. Register one with
//bmkhs_fnc_utilNotifyRegister when there is something to animate or play.

//Every LOCAL H-60, not just the one the player is sitting in - an AI or empty H-60 flies, burns
//fuel and takes damage on the same model as a crewed one.
GVAR(frameHandler) = addMissionEventHandler ["EachFrame", {
    {
        if (alive _x && {_x getVariable ["bmkhs_initialised", false]}) then {
            [_x] call FUNC(perFrame);
        };
    } forEach (vehicles select {local _x && {_x isKindOf GVAR(baseClass)}});
}];

ADDON = true;
