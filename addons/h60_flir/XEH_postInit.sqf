#include "script_component.hpp"

hct_h60_flir_tdcWaypointNum = 99;

if (hasInterface) then {
    #include "initKeybinds.inc.sqf"
};

["hct_h60_flir_syncPilots", {
  params ["_vehicle"];
  [_vehicle, false] call hct_h60_flir_fnc_syncPilots;
}] call CBA_fnc_addEventHandler;

["hct_h60_flir_syncFOV", {
  params ["_fov"];
  [_fov, false] call hct_h60_flir_fnc_setFOV;
}] call CBA_fnc_addEventHandler;

["hct_h60_flir_syncVisionMode", {
  params ["_effect"];
  [_effect, false] call hct_h60_flir_fnc_setVisionMode;
}] call CBA_fnc_addEventHandler;

["hct_h60_flir_syncCopilotView", {
  hct_h60_flir_isCopilotInGunnerView = _this;
}] call CBA_fnc_addEventHandler;

