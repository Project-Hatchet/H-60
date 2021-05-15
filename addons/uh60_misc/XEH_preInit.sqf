#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

["vtx_HH60w", "init", {
  params ["_heli"];
  _heli lockCargo [10, true];
  _heli lockCargo [11, true];
}] call CBA_fnc_addClassEventHandler;
