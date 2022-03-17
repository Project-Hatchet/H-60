params ["_vehicle"];

private _airsrceSwitchState    = _vehicle getVariable "vtx_uh60_acft_airsrceSwitchState";

//Engine 1
private _eng1State             = _vehicle getVariable "vtx_uh60_sfmplus_engState" select 0;
private _eng1StarterState      = _vehicle getVariable "vtx_uh60_acft_eng1StarterState";
private _eng1FuelLeverState    = _vehicle getVariable "vtx_uh60_acft_eng1FuelSysLeverState";
private _eng1PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng1PwrCtrlLeverState";

//Is the starter engaged?
if (_eng1State == "STARTING") then {
    //Do we have fuel?
    if (_eng1FuelLeverState in ["DIR", "XFD"]) then {
        //Do we have an airsource?
        if (_airsrceSwitchState in ["APU", "ENG"]) then {
            if (_eng1PwrCtrlLeverState == "OFF") then {
                [_vehicle, 0, "OFF"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
            };
            if (_eng1PwrCtrlLeverState == "IDLE") then {
                [_vehicle, 0, "IDLE"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
            };
            if (_eng1PwrCtrlLeverState == "FLY") then {
                [_vehicle, 0, "FLY"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
            };
        };//Airsource
    };//Fuel system lever
};//Engine starter

if (_eng1State == "ON") then {
    if (_eng1PwrCtrlLeverState == "OFF") then {
        [_vehicle, 0, "OFF"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
    };
    if (_eng1PwrCtrlLeverState == "IDLE") then {
        [_vehicle, 0, "IDLE"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
    };
    if (_eng1PwrCtrlLeverState == "FLY") then {
        [_vehicle, 0, "FLY"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
    };
};

//Engine 2
private _eng2State             = _vehicle getVariable "vtx_uh60_sfmplus_engState" select 1;
private _eng2StarterState      = _vehicle getVariable "vtx_uh60_acft_eng2StarterState";
private _eng2FuelLeverState    = _vehicle getVariable "vtx_uh60_acft_eng2FuelSysLeverState";
private _eng2PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng2PwrCtrlLeverState";

//Is the starter engaged?
if (_eng2State == "STARTING") then {  
    //Do we have fuel?
    if (_eng2FuelLeverState in ["DIR", "XFD"]) then {
        //Do we have an airsource?
        if (_airsrceSwitchState in ["APU", "ENG"]) then {
            if (_eng2PwrCtrlLeverState == "OFF") then {
                [_vehicle, 1, "OFF"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
            };
            if (_eng2PwrCtrlLeverState == "IDLE") then {
                [_vehicle, 1, "IDLE"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
            };
            if (_eng2PwrCtrlLeverState == "FLY") then {
                [_vehicle, 1, "FLY"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
            };
        };//Airsource
    };//Fuel system lever
};//Engine starter

if (_eng2State == "ON") then {
    if (_eng2PwrCtrlLeverState == "OFF") then {
        [_vehicle, 1, "OFF"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
    };
    if (_eng2PwrCtrlLeverState == "IDLE") then {
        [_vehicle, 1, "IDLE"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
    };
    if (_eng2PwrCtrlLeverState == "FLY") then {
        [_vehicle, 1, "FLY"] call vtx_uh60_sfmplus_fnc_interactPowerLever;
    };
};