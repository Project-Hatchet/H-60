#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
hct_h60_acre_enabled = isClass (configFile >> "cfgPatches" >> "acre_main");

ADDON = true;
