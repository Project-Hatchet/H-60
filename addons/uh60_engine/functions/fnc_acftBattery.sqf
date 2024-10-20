params ["_vehicle"];

private _battBusState        = _vehicle getVariable "vtx_uh60_acft_battBusState";
private _stbyInstSwitchState = _vehicle getVariable "vtx_uh60_acft_stbyInstSwitchState";
private _ACBusState          = _vehicle getVariable "vtx_uh60_acft_ACBusState";
private _stbyInstBatt        = _vehicle getVariable "vtx_uh60_acft_stbyInstBatt"; //1800

//Battery bus powers on the following
//--#3 MFD
//--#2 FMS
//--Prime Boost Pump
//--APU Cont Switch
//--APU HT/Start Switch
if (_battBusState == "ON") then {
    _vehicle animate ["PowerOnOff", 1];
    //Stby inst switch
    //eng on or apu on or switch on
    if ((_stbyInstSwitchState == "ON" || _ACBusState == "ON") && _stbyInstBatt > 0) then {
        _vehicle animate ["ESIS_hide",  0];
    } else { _vehicle animate ["ESIS_hide",  1]; };
} else {
    _vehicle animate ["PowerOnOff", 0];
    _vehicle animate ["ESIS_hide",  1];
};
