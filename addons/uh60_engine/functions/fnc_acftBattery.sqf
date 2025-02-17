#include "\bmkhs_interact\headers\interact.hpp"

params ["_vehicle"];

//private _stbyInstSwitchState = _vehicle getVariable "bmkhs_standbyInsrumentSwitchState";
//private _batteryBusOn        = _vehicle getVariable "bmkhs_batteryBusOn";
//private _emergencyBusOn      = _vehicle getVariable "bmkhs_emergencyBusOn";
//private _dcBusOn             = _vehicle getVariable "bmkhs_dcBusOn";
//Battery bus powers on the following
//--#3 MFD
//--#2 FMS
//--Prime Boost Pump
//--APU Cont Switch
//--APU HT/Start Switch
//if (_batteryBusOn) then {
//    _vehicle animate ["PowerOnOff", 1];
//
//    if (_dcBusOn && _stbyInstSwitchState == STBY_INST_STATE_ARM) then {
//      _vehicle animate ["ESIS_hide",  0];
//    } else {
//      _vehicle animate ["ESIS_hide",  1];
//    };
//} else {
//    _vehicle animate ["PowerOnOff", 0];
//    _vehicle animate ["ESIS_hide",  1];
//};
//if (_batteryBusOn) then {
//    _vehicle animate ["PowerOnOff", 1];
//
//    if (_acBusOn && _emergencyBusOn) then {
//      _vehicle animate ["ESIS_hide",  0];
//    } else { 
//      _vehicle animate ["ESIS_hide",  1];
//    };
//} else {
//    _vehicle animate ["PowerOnOff", 0];
//    _vehicle animate ["ESIS_hide",  1];
//};