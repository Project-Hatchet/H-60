params ["_vehicle"];

private _emergencyBusOn = _vehicle getVariable "bmkhs_emergencyBusOn";
private _acBusOn        = _vehicle getVariable "bmkhs_acBusOn";
//Battery bus powers on the following
//--#3 MFD
//--#2 FMS
//--Prime Boost Pump
//--APU Cont Switch
//--APU HT/Start Switch
if (_emergencyBusOn) then {
    _vehicle animate ["PowerOnOff", 1];

    if (_acBusOn) then {
      _vehicle animate ["ESIS_hide",  0];
    } else { 
      _vehicle animate ["ESIS_hide",  1];
    };
} else {
    _vehicle animate ["PowerOnOff", 0];
    _vehicle animate ["ESIS_hide",  1];
};
