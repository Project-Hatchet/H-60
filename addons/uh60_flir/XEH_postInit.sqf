#include "script_component.hpp"

if (hasInterface) then {
    #include "initKeybinds.sqf"
};

// move to framework
["vtx_h60_base","GetIn",{call vtx_uh60_flir_fnc_setup},true,[]] call CBA_fnc_addClassEventHandler;
["vtx_h60_base","GetOut",{call vtx_uh60_flir_fnc_setup},true,[]] call CBA_fnc_addClassEventHandler;
["vtx_h60_base","SeatSwitched",{call vtx_uh60_flir_fnc_setup},true,[]] call CBA_fnc_addClassEventHandler;

["vtx_uh60_flir_syncFixedPIP", {
  _this set [5, false]; // don't sync again
  _this call vtx_uh60_flir_fnc_setFixedPIP;
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

["vtx_uh60_flir_syncPilotCamera", {
  params ["_rot_dir", "_target"];
  private _vehicle = vehicle player;
  switch (count _rot_dir) do {
    case 2: { _vehicle setPilotCameraRotation _rot_dir; };
    case 3: { _vehicle setPilotCameraDirection _rot_dir; };
  };
  _vehicle setPilotCameraTarget _target;
}] call CBA_fnc_addEventHandler;
