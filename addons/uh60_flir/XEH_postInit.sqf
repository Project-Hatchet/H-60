#include "script_component.hpp"

if (hasInterface) then {
    #include "initKeybinds.sqf"
};

["vtx_uh60_flir_syncPilots", {
  params ["_vehicle"];
  [_vehicle, false] call vtx_uh60_flir_fnc_syncPilots;
}] call CBA_fnc_addEventHandler;

["vtx_uh60_flir_syncFOV", {
  params ["_fov"];
  [_fov, false] call vtx_uh60_flir_fnc_setFOV;
}] call CBA_fnc_addEventHandler;

["vtx_uh60_flir_syncVisionMode", {
  params ["_effect"];
  [_effect, false] call vtx_uh60_flir_fnc_setVisionMode;
}] call CBA_fnc_addEventHandler;

["vtx_uh60_flir_syncCopilotView", {
  vtx_uh60_flir_isCopilotInGunnerView = _this;
}] call CBA_fnc_addEventHandler;

