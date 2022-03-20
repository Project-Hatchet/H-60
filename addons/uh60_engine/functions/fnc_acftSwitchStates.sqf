params ["_vehicle"];

//Master igntion key (mik) switch
private _mikSwitchPos   = _vehicle animationPhase "Switch_ignition";         //0.0 = OFF, 1.0 = ON
private _mikSwitchState = _vehicle getVariable "vtx_uh60_acft_mikSwitchState";
if (_mikSwitchPos >= 0.90) then {
    _mikSwitchState = "ON";
} else {
    _mikSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_mikSwitchState", _mikSwitchState];

//Battery 1 switch
private _batt1SwitchPos   = _vehicle animationPhase "Switch_batt1";         //0.5 = OFF, 0.0 = ON
private _batt1SwitchState = _vehicle getVariable "vtx_uh60_acft_batt1SwitchState";
if (_batt1SwitchPos <= 0.10) then {
    _batt1SwitchState = "ON";
} else {
    _batt1SwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_batt1SwitchState", _batt1SwitchState];

//Battery 2 switch
private _batt2SwitchPos   = _vehicle animationPhase "Switch_batt2";         //0.5 = OFF, 0.0 = ON
private _batt2SwitchState = _vehicle getVariable "vtx_uh60_acft_batt2SwitchState";
if (_batt2SwitchPos <= 0.10) then {
    _batt2SwitchState = "ON";
} else {
    _batt2SwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_batt2SwitchState", _batt2SwitchState];

//APU power switch
private _apuPwrSwitchPos   = _vehicle animationPhase "Switch_apucont";      //0.5 = OFF, 0.0 = ON
private _apuPwrSwitchState = _vehicle getVariable "vtx_uh60_acft_apuPwrSwitchState";
if (_apuPwrSwitchPos <= 0.10) then {
    _apuPwrSwitchState = "ON";
} else {
    _apuPwrSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_apuPwrSwitchState", _apuPwrSwitchState];

//APU fuel pump switch
private _apuFuelSwitchPos   = _vehicle animationPhase "Switch_fuelPump";    //0.5 = OFF, 0.0 = ON
private _apuFuelSwitchState = _vehicle getVariable "vtx_uh60_acft_apuFuelSwitchState";
if (_apuFuelSwitchPos <= 0.10) then {
    _apuFuelSwitchState = "ON";
} else {
    _apuFuelSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_apuFuelSwitchState", _apuFuelSwitchState];

//APU generator switch
private _apuGenSwitchPos   = _vehicle animationPhase "Switch_apugen";    //0.5 = OFF, 0.0 = ON
private _apuGenSwitchState = _vehicle getVariable "vtx_uh60_acft_apuGenSwitchState";
if (_apuGenSwitchPos <= 0.10) then {
    _apuGenSwitchState = "ON";
} else {
    _apuGenSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_apuGenSwitchState", _apuGenSwitchState];

//Eng 1 generator switch
private _eng1GenSwitchPos   = _vehicle animationPhase "Switch_gen1";    //0.5 = OFF, 0.0 = ON
private _eng1GenSwitchState = _vehicle getVariable "vtx_uh60_acft_eng1GenSwitchState";
if (_eng1GenSwitchPos <= 0.10) then {
    _eng1GenSwitchState = "ON";
} else {
    _eng1GenSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_eng1GenSwitchState", _eng1GenSwitchState];

//Eng 2 generator switch
private _eng2GenSwitchPos   = _vehicle animationPhase "Switch_gen2";    //0.5 = OFF, 0.0 = ON
private _eng2GenSwitchState = _vehicle getVariable "vtx_uh60_acft_eng2GenSwitchState";
if (_eng2GenSwitchPos <= 0.10) then {
    _eng2GenSwitchState = "ON";
} else {
    _eng2GenSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_eng2GenSwitchState", _eng2GenSwitchState];

//Air source switch
private _airsrceSwitchPos   = _vehicle animationPhase "Switch_airsce";    //1.0 = ENG, 0.5 = OFF,  0.0 = APU
private _airsrceSwitchState = _vehicle getVariable "vtx_uh60_acft_airsrceSwitchState";
if (_airsrceSwitchPos <= 0.1) then {
    _airsrceSwitchState = "APU";
};
if (_airsrceSwitchPos == 0.5) then {
    _airsrceSwitchState = "OFF";
};
if (_airsrceSwitchPos >= 0.9) then {
    _airsrceSwitchState = "ENG"
};
_vehicle setVariable ["vtx_uh60_acft_airsrceSwitchState", _airsrceSwitchState];

//Stby inst switch
private _stbyInstSwitchPos   = _vehicle animationPhase "Switch_stbyinst";    //0.5 = OFF, 0.0 = ON
private _stbyInstSwitchState = _vehicle getVariable "vtx_uh60_acft_stbyInstSwitchState";
if (_stbyInstSwitchPos <= 0.10) then {
    _stbyInstSwitchState = "ON";
} else {
    _stbyInstSwitchState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_stbyInstSwitchState", _stbyInstSwitchState];