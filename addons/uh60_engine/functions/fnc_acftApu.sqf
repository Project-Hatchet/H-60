params ["_vehicle"];

private _apuState = _vehicle getVariable "vtx_uh60_acft_apuState";

/* _battBusState = _vehicle getVariable "vtx_uh60_acft_battBusState";
_apuPwrSwitchState = _vehicle getVariable "vtx_uh60_acft_apuPwrSwitchState";
_apuFuelSwitchState = _vehicle getVariable "vtx_uh60_acft_apuFuelSwitchState";

//Simulate the APU spooling up
_apuRPM_pct = [_vehicle,({_x == "ON"} count [_apuPwrSwitchState, _apuFuelSwitchState, _battBusState]) == 3] call vtx_uh60_engine_fnc_acft_SetAPU;
_vehicle setVariable ["vtx_uh60_acft_apuRPM_pct", _apuRPM_pct]; */

_apuRPM_pct = _vehicle getVariable "vtx_uh60_acft_apuRPM_pct";

//Set the APU state
if (_apuRPM_pct < 0.1) then {
    _apuState = "OFF";
};
if (_apuRPM_pct >= 0.1 && _apuRPM_pct <= 0.85) then {
    _apuState = "STARTING";
};
if (_apuRPM_pct > 0.85) then {
    _apuState = "ON";
};
if (_apuState == "ON") then {
    [_vehicle, "APU ON", {((_this # 0) getVariable ["vtx_uh60_acft_apuState", "OFF"]) == "ON"}, false, true] call vtx_uh60_cas_fnc_registerCautionAdvisory;
};
_vehicle setVariable ["vtx_uh60_acft_apuState", _apuState];
_vehicle animateSource ["APUOn", ([0,1] select (_apuState == "ON"))];
