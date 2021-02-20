#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.sqf"
GVAR(isReady) = false;
GVAR(carrier) = objNull;
GVAR(cargo) = objNull;

ADDON = true;
