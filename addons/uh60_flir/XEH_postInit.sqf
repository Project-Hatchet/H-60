#include "script_component.hpp"

if (hasInterface) then {
    #include "initKeybinds.sqf"
};

["vtx_h60_base","GetIn",vtx_uh60_flir_fnc_updatePilots,true,[]] call CBA_fnc_addClassEventHandler;
["vtx_h60_base","GetOut",vtx_uh60_flir_fnc_updatePilots,true,[]] call CBA_fnc_addClassEventHandler;
["vtx_h60_base","SeatSwitched",vtx_uh60_flir_fnc_updatePilots,true,[]] call CBA_fnc_addClassEventHandler;

["vtx_uh60_flir_syncFOV", {
    vtx_uh60_flir_fov = _this # 0;
}] call CBA_fnc_addEventHandler;

["vtx_uh60_flir_syncCameraMode", {
    vtx_uh60m_flir_c_cameraMode = _this # 0;
    "vtx_uh60_flir_feed" setPiPEffect [vtx_uh60m_flir_c_cameraMode];
}] call CBA_fnc_addEventHandler;

["vtx_uh60_flir_syncCopilotView", {
    vtx_uh60_flir_isCopilotInGunnerView = _this;
}] call CBA_fnc_addEventHandler;

["vtx_uh60_flir_syncPilotCamera", {
    params ["_rot_dir", "_target"];
    private _heli = vehicle player;
    switch (count _rot_dir) do {
        case 2: { _heli setPilotCameraRotation _rot_dir; };
        case 3: { _heli setPilotCameraDirection _rot_dir; };
    };
    _heli setPilotCameraTarget _target;
}] call CBA_fnc_addEventHandler;
