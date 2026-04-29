#include "script_component.hpp"

if (hasInterface) then {
  #include "ACE_Actions.sqf"

  GVAR(irLaserPFH) = -1;
  [QGVAR(irLaser), LINKFUNC(onLaserOn)] call CBA_fnc_addEventHandler;
  // Examples
  // ["vtx_uh60_weapons_irLaser", [cameraOn, [0,0,0], 0]] call CBA_fnc_globalEvent;
  // ["vtx_uh60_weapons_irLaser", [cameraOn, "pos", "dir"]] call CBA_fnc_globalEvent;

};

["vtx_fireSelected", {call vtx_uh60_weapons_fnc_ehFireSelected}] call CBA_fnc_addEventHandler;
["vtx_nextWeapon", {call vtx_uh60_weapons_fnc_ehNextWeapon}] call CBA_fnc_addEventHandler;
[QGVAR(assignPylonEH), LINKFUNC(assignPylon)] call CBA_fnc_addEventHandler;
[QGVAR(assignPylonLocalEH), LINKFUNC(assignPylonLocal)] call CBA_fnc_addEventHandler;
