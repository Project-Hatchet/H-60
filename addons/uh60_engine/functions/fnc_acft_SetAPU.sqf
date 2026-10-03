/*
 * vtx_uh60_engine_fnc_acft_SetAPU
 *
 * manages APU state
 *
 * params (object) Vehicle
 */
params ["_vehicle","_state"];
private ["_deltaTime","_apuRPM_pct","_apuStartDelay_sec"];

_deltaTime = 0.018;
_apuRPM_pct = _vehicle getVariable "vtx_uh60_acft_apuRPM_pct";
_apuStartDelay_sec = _vehicle getVariable "vtx_uh60_acft_apuStartDelay_sec";

_apuRPM_pct = (
  [
    [_apuRPM_pct, 0.0, _deltaTime],
    [_apuRPM_pct, 1.0, (1.0 / _apuStartDelay_sec) * _deltaTime]
  ] select _state
) call BIS_fnc_lerp;
_vehicle setVariable ["vtx_uh60_acft_apuRPM_pct", _apuRPM_pct];


_apuRPM_pct
