#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
vtx_uh60_acre_enabled = isClass (configFile >> "cfgPatches" >> "acre_main");

ADDON = true;
