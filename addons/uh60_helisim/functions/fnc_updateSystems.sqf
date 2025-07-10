
#include "\bmkhs_interact\headers\interact.hpp"

params ["_heli"];

/////////////////////////////////////////////////////////////////////////////////////////////
// Battery              /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private _stbyInstSwitchState = _heli getVariable "bmkhs_standbyInsrumentSwitchState";
private _batteryBusOn        = _heli getVariable "bmkhs_batteryBusOn";
private _emergencyBusOn      = _heli getVariable "bmkhs_emergencyBusOn";
private _dcBusOn             = _heli getVariable "bmkhs_dcBusOn";
//Battery bus powers on the following
//--#3 MFD
//--#2 FMS
//--Prime Boost Pump
//--APU Cont Switch
//--APU HT/Start Switch
if (_batteryBusOn) then {
    _heli animate ["PowerOnOff", 1];

    if (_dcBusOn && _stbyInstSwitchState == STBY_INST_STATE_ARM) then {
      _heli animate ["ESIS_hide",  0];
    } else {
      _heli animate ["ESIS_hide",  1];
    };
} else {
    _heli animate ["PowerOnOff", 0];
    _heli animate ["ESIS_hide",  1];
};
/////////////////////////////////////////////////////////////////////////////////////////////
// APU                  /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private _apuOn = _heli getVariable "bmkhs_apuOn";

if (_apuOn) then {
  _heli animateSource ["APUOn", 1];
} else { 
  _heli animateSource ["APUOn", 0];
};
/////////////////////////////////////////////////////////////////////////////////////////////
// AC Bus               /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private _acBusOn = _heli getVariable "bmkhs_acBusOn";

if (_acBusOn) then {
  _heli animate ["GeneratorsOnOff", 1];
} else {
  _heli animate ["GeneratorsOnOff", 0];
};