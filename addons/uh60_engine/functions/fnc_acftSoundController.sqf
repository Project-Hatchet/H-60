#include "defines.hpp"
params ["_vehicle"];

private _apuPwrSwitchState  = _vehicle getVariable "vtx_uh60_acft_apuPwrSwitchState";
private _apuFuelSwitchState = _vehicle getVariable "vtx_uh60_acft_apuFuelSwitchState";
private _apuState           = _vehicle getVariable "vtx_uh60_acft_apuState";

//APU sound controller
switch (_apuState) do {
    case "OFF": {
        if (_apuPwrSwitchState == "ON" && _apuFuelSwitchState == "ON") then {
            systemChat format ["Sound should play!"];
            vtx_uh60_apuSound_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
            vtx_uh60_apuSound_dummy attachTo [_vehicle, [0,-1,1]];
            vtx_uh60_apuSound_dummy say3d    ["VTX_UH60_Start_APU", 50, 1];
        } else {
            if (!isNil "vtx_uh60_apuSound_dummy") then {deleteVehicle vtx_uh60_apuSound_dummy};
        };
    };
    case "ON": {
        if (_apuPwrSwitchState == "OFF" || _apuFuelSwitchState == "OFF") then {
            vtx_uh60_apuSound_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
            vtx_uh60_apuSound_dummy attachTo [_vehicle, [0,-1,1]];
            vtx_uh60_apuSound_dummy say3d    ["VTX_UH60_Stop_APU", 50, 1];
        } else {
            if (!isNil "vtx_uh60_apuSound_dummy") then {deleteVehicle vtx_uh60_apuSound_dummy};
        };
    };
};

//Engine sound controller
//--Engine 1
private _eng1StarterState = _vehicle getVariable "vtx_uh60_acft_eng1StarterState";
if (_eng1StarterState == "ON") then {
    vtx_uh60_start1_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
    vtx_uh60_start1_dummy attachTo [_vehicle, [-1,-1,1]];
    vtx_uh60_start1_dummy say3d    ["VTX_UH60_Start_APU", 50, 2];    
} else {
    if (!isNil "vtx_uh60_apuSound_dummy") then {deleteVehicle vtx_uh60_apuSound_dummy};
};

//--Engine 2
private _eng2StarterState = _vehicle getVariable "vtx_uh60_acft_eng2StarterState";
if (_eng2StarterState == "ON") then {
    vtx_uh60_start2_dummy = "#dynamicsound" createVehicleLocal ASLToAGL getPosWorld vehicle player;
    vtx_uh60_start2_dummy attachTo [_vehicle, [-1,-1,1]];
    vtx_uh60_start2_dummy say3d    ["VTX_UH60_Start_APU", 50, 2];    
} else {
    if (!isNil "vtx_uh60_apuSound_dummy") then {deleteVehicle vtx_uh60_apuSound_dummy};
};