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

["vtx_uh60_flir_syncPilotCamera", {
  params ["_rot_dir", "_target", "_targetObject"];
  switch (count _rot_dir) do {
    case 2: { vxf_vehicle setPilotCameraRotation _rot_dir; };
    case 3: { vxf_vehicle setPilotCameraDirection _rot_dir; };
  };
  vxf_vehicle setPilotCameraTarget _target;
  vtx_uh60_flir_pilotCameraTarget = getPilotCameraTarget vxf_vehicle;
  if (vtx_uh60_flir_pilotCameraTarget # 0) then {
    vtx_uh60_flir_pilotCameraTarget set [2, _targetObject];
  };
}] call CBA_fnc_addEventHandler;
