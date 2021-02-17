#include "\z\ace\addons\main\script_macros.hpp"

// testing, update fncs on the fly
#undef PREP
#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

#include "defines\viewAngleDefines.hpp"
#include "defines\mfdDefines.hpp"
