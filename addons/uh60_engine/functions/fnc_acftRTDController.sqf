params ["_vehicle"];

private _config        = configFile >> "CfgVehicles" >> typeof _vehicle >> "vtx_SfmPlus";
private _engSimTime    = getNumber (_config >> "engSimTime") + 12;
private _rtdDesiredRPM = _vehicle getVariable "vtx_uh60_acft_rtdDesiredRPM";

//Engine 1
private _eng1PwrCtrlLeverPos   = 0.0;
private _eng1PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng1PwrCtrlLeverState";
switch (_eng1PwrCtrlLeverState) do {
    case "OFF": {
        _eng1PwrCtrlLeverPos = 0.0;
    };
    case "IDLE": {
        _eng1PwrCtrlLeverPos = 0.52;
    };
    case "FLY": {
        _eng1PwrCtrlLeverPos = 1.0;
    };
};

//Engine 2
private _eng2PwrCtrlLeverPos   = 0.0;
private _eng2PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng1PwrCtrlLeverState";
switch (_eng2PwrCtrlLeverState) do {
    case "OFF": {
        _eng2PwrCtrlLeverPos = 0.0;
    };
    case "IDLE": {
        _eng2PwrCtrlLeverPos = 0.52;
    };
    case "FLY": {
        _eng2PwrCtrlLeverPos = 1.0;
    };
};

_eng1DesiredRPM = _rtdDesiredRPM * _eng1PwrCtrlLeverPos;
_vehicle setWantedRPMRTD [_eng1DesiredRPM, _engSimTime, 0];

_eng2DesiredRPM = _rtdDesiredRPM * _eng2PwrCtrlLeverPos;
_vehicle setWantedRPMRTD [_eng2DesiredRPM, _engSimTime, 1];