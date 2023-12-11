/*
 * vtx_uh60_engine_fnc_UpdateAPU_State
 *
 * manages APU state (Global)
 *
 * params (object) vehicle
 */

params ["_vehicle"];
private ["_apuFuelSwitchPos","_apuFuelSwitchState","_apuPwrSwitchPos","_apuPwrSwitchState","_battSwitch1State","_battSwitch2State","_batt1SwitchPos","_batt1SwitchState","_batt2SwitchPos","_batt2SwitchState","_battBusState"];

//APU fuel pump switch
_apuFuelSwitchPos = _vehicle animationPhase "Switch_fuelPump";    //0.5 = OFF, 0.0 = ON

_apuFuelSwitchState = ["OFF","ON"] select (_apuFuelSwitchPos <= 0.1);
_vehicle setVariable ["vtx_uh60_acft_apuFuelSwitchState", _apuFuelSwitchState, true];

//APU power switch
_apuPwrSwitchPos = _vehicle animationPhase "Switch_apucont";      //0.5 = OFF, 0.0 = ON

_apuPwrSwitchState = ["OFF","ON"] select (_apuPwrSwitchPos <= 0.1);
_vehicle setVariable ["vtx_uh60_acft_apuPwrSwitchState", _apuPwrSwitchState, true];

//--- Batteries Switches ---//

//* Battery 1 switch
_batt1SwitchPos = _vehicle animationPhase "Switch_batt1";         //0.5 = OFF, 0.0 = ON

_batt1SwitchState = ["OFF","ON"] select (_batt1SwitchPos <= 0.1);
_vehicle setVariable ["vtx_uh60_acft_batt1SwitchState", _batt1SwitchState];

//* Battery 2 switch
_batt2SwitchPos = _vehicle animationPhase "Switch_batt2";         //0.5 = OFF, 0.0 = ON

_batt2SwitchState = ["OFF","ON"] select (_batt2SwitchPos <= 0.1);
_vehicle setVariable ["vtx_uh60_acft_batt2SwitchState", _batt2SwitchState];

//* Battery bus switch
_battBusState = ["OFF","ON"] select (_batt1SwitchState == "ON" || _batt2SwitchState == "ON");
_vehicle setVariable ["vtx_uh60_acft_battBusState", _battBusState, true];
