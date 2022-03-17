params ["_vehicle"];

private _deltaTime          = ["vtx_uh60_acft_apuDeltaTime"] call BIS_fnc_deltaTime;

private _battBusState       = _vehicle getVariable "vtx_uh60_acft_battBusState";
private _apuPwrSwitchState  = _vehicle getVariable "vtx_uh60_acft_apuPwrSwitchState";
private _apuFuelSwitchState = _vehicle getVariable "vtx_uh60_acft_apuFuelSwitchState";
private _apuState           = _vehicle getVariable "vtx_uh60_acft_apuState";
private _apuStartDelay_sec  = _vehicle getVariable "vtx_uh60_acft_apuStartDelay_sec";
private _apuRPM_pct         = _vehicle getVariable "vtx_uh60_acft_apuRPM_pct";

//Simulate the APU spooling up
if (_apuPwrSwitchState == "ON" && _apuFuelSwitchState == "ON" && _battBusState == "ON") then {
    _apuRPM_pct = [_apuRPM_pct, 1.0, (1.0 / _apuStartDelay_sec) * _deltaTime] call BIS_fnc_lerp;
} else { 
    _apuRPM_pct = [_apuRPM_pct, 0.0, _deltaTime] call BIS_fnc_lerp; 
};
_vehicle setVariable ["vtx_uh60_acft_apuRPM_pct", _apuRPM_pct];

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
_vehicle setVariable ["vtx_uh60_acft_apuState", _apuState];