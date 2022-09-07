params ["_vehicle"];

// private _config        = configFile >> "CfgVehicles" >> typeof _vehicle >> "vtx_SfmPlus";
// private _engSimTime    = getNumber (_config >> "engSimTime") + 12;
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


private _eng1Np    = _vehicle getVariable "vtx_uh60_sfmplus_engPctNP" select 0;
private _eng2Np    = _vehicle getVariable "vtx_uh60_sfmplus_engPctNP" select 1;
private _rpmLimit = missionnamespace getVariable ["vtx_uh60_sfmplus_fnc_limitRPM", false];
private _rpmMultiplier = if (_rpmLimit) then {0.4} else {1};
if (_vehicle animationPhase "Lever_RotorBrake" == 1) then {_rpmMultiplier = 0};

_eng1DesiredRPM = _rtdDesiredRPM * _eng1PwrCtrlLeverPos;
_vehicle setWantedRPMRTD [(_eng1Np * _rpmMultiplier) * 20900, 5, 0];

_eng2DesiredRPM = _rtdDesiredRPM * _eng2PwrCtrlLeverPos;
_vehicle setWantedRPMRTD [(_eng2Np * _rpmMultiplier) * 20900, 5, 1];

// systemChat str [(_eng1Np * _rpmMultiplier) * 20900, (_eng2Np * _rpmMultiplier) * 20900]