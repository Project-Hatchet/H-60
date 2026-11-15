#include "script_component.hpp"

if (hasInterface) then {
  #include "ACE_Actions.inc.sqf"

  GVAR(irLaserPFH) = -1;
  [QGVAR(irLaser), LINKFUNC(onIRLaserOn)] call CBA_fnc_addEventHandler;
  // Examples
  // ["hct_h60_weapons_irLaser", [cameraOn, [0,0,0], 0]] call CBA_fnc_globalEvent;
  // ["hct_h60_weapons_irLaser", [cameraOn, "pos", "dir"]] call CBA_fnc_globalEvent;

};

["hct_fireSelected", {call hct_h60_weapons_fnc_ehFireSelected}] call CBA_fnc_addEventHandler;
["hct_nextWeapon", {call hct_h60_weapons_fnc_ehNextWeapon}] call CBA_fnc_addEventHandler;
[QGVAR(assignPylonEH), LINKFUNC(assignPylon)] call CBA_fnc_addEventHandler;
[QGVAR(assignPylonLocalEH), LINKFUNC(assignPylonLocal)] call CBA_fnc_addEventHandler;
