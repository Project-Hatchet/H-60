params ["_vehicle"];

//APU
private _apuState           = _vehicle getVariable "vtx_uh60_acft_apuState";
private _apuGenSwitchState  = _vehicle getVariable "vtx_uh60_acft_apuGenSwitchState";
private _apuGenState        = _vehicle getVariable "vtx_uh60_acft_apuGenState";
//Engine 1
private _eng1State          = _vehicle getVariable "vtx_uh60_sfmplus_engState" select 0;
private _eng1PctNP          = _vehicle getVariable "vtx_uh60_sfmplus_engPctNP" select 0;
private _eng1GenSwitchState = _vehicle getVariable "vtx_uh60_acft_eng1GenSwitchState";
private _eng1GenState       = _vehicle getVariable "vtx_uh60_acft_eng1GenState";
//Engine 2
private _eng2State          = _vehicle getVariable "vtx_uh60_sfmplus_engState" select 1;
private _eng2PctNP          = _vehicle getVariable "vtx_uh60_sfmplus_engPctNP" select 1;
private _eng2GenSwitchState = _vehicle getVariable "vtx_uh60_acft_eng2GenSwitchState";
private _eng2GenState       = _vehicle getVariable "vtx_uh60_acft_eng2GenState";

//APU generator
if (_apuState == "ON" && _apuGenSwitchState == "ON") then {
    _apuGenState = "ON";
    [_vehicle, "APU GEN ON", {((_this # 0) getVariable ["vtx_uh60_acft_apuGenState", "OFF"]) == "ON"}, false, true] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else { 
    _apuGenState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_apuGenState", _apuGenState];

//Engine 1 generator
if (_eng1State == "ON" && _eng1GenSwitchState == "ON" && _eng1PctNP > 0.85) then {
    _eng1GenState = "ON";
} else { 
    _eng1GenState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_eng1GenState", _eng1GenState];

//Engine 2 generator
if (_eng2State == "ON" && _eng2GenSwitchState == "ON" && _eng2PctNP > 0.85) then {
    _eng2GenState = "ON";
} else {
    _eng2GenState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_eng2GenState", _eng2GenState];

private _ACBusState = _vehicle getVariable "vtx_uh60_acft_ACBusState";
private _DCBusState = _vehicle getVariable "vtx_uh60_acft_DCBusState";

//AC bus state
if (_apuGenState == "ON" || _eng1GenState == "ON" || _eng2GenState == "ON") then {
    _ACBusState = "ON";
} else { _ACBusState = "OFF"; };
_vehicle setVariable ["vtx_uh60_acft_ACBusState", _ACBusState];
//AC Bus powers on the following
//--Anti-collision lights

//DC bus state
if (_ACBusState == "ON") then {
    _DCBusState = "ON";
} else { _DCBusState = "OFF"; };
_vehicle setVariable ["vtx_uh60_acft_DCBusState", _DCBusState];
//DC Bus powers on the following
//--Stby inst
//--#1,2,3,4 MFDs
//--#1,2 FMS
//--Position lights
//--Eng 1 & 2 Start Switches

if (_ACBusState == "ON") then {
    //Needs to be broken out to individual components
    _vehicle animate ["GeneratorsOnOff", 1];
} else {
    _vehicle animate ["GeneratorsOnOff", 0];
};