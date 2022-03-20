params ["_vehicle"];

private _battSwitch1State    = _vehicle getVariable "vtx_uh60_acft_batt1SwitchState";
private _battSwitch2State    = _vehicle getVariable "vtx_uh60_acft_batt2SwitchState";
private _battBusState        = _vehicle getVariable "vtx_uh60_acft_battBusState";
private _stbyInstSwitchState = _vehicle getVariable "vtx_uh60_acft_stbyInstSwitchState";

if (_battSwitch1State == "ON" || _battSwitch2State == "ON") then {
    _battBusState = "ON";
} else {
    _battBusState = "OFF";
};
_vehicle setVariable ["vtx_uh60_acft_battBusState", _battBusState];
//Battery bus powers on the following
//--#3 MFD
//--#2 FMS
//--Prime Boost Pump
//--APU Cont Switch
//--APU HT/Start Switch
if (_battBusState == "ON") then {
    _vehicle animate ["PowerOnOff", 1];
    //Stby inst switch
    if (_stbyInstSwitchState == "ON") then {
        _vehicle animate ["ESIS_hide",  0];
    } else { _vehicle animate ["ESIS_hide",  1]; };
} else {
    _vehicle animate ["PowerOnOff", 0];
    _vehicle animate ["ESIS_hide",  1];
};

