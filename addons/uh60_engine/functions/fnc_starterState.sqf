/*
 * vtx_uh60_engine_fnc_starterState
 *
 * manages starter state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */

params ["_vehicle", "_animName", "_animEndState"];

//[_vehicle] call vtx_uh60_cas_fnc_updateCautions;

//SFM+
//private _mikSwitchState = _vehicle getVariable "vtx_uh60_acft_mikSwitchState";
//private _dcBusState     = _vehicle getVariable "vtx_uh60_acft_DCBusState";
//private _eng1PwrCtrlLeverState = _vehicle getVariable "bmkhs_engPwrLvrState" select 0;
//private _eng2PwrCtrlLeverState = _vehicle getVariable "bmkhs_engPwrLvrState" select 1;

//if (_animName == "STARTER1") then {
//    if (_mikSwitchState == "ON" && _dcBusState == "ON" && _eng1PwrCtrlLeverState == "OFF") then {
//        [_vehicle, 0] call bmkhs_interact_fnc_startSwitch;
//    };
//};

//if (_animName == "STARTER2") then {
//    if (_mikSwitchState == "ON" && _dcBusState == "ON" && _eng2PwrCtrlLeverState == "OFF") then {
//        [_vehicle, 1] call bmkhs_interact_fnc_startSwitch;
//    };
//};