/*
 * vtx_uh60_Sound_fnc_PlayAPUGlobal
 *
 * APU sound, following HeliSim's APU RPM
 *
 * params (array)[(OBJECT) _vehicle, (BOOL) _on - APU CONT switched on]
 */
params ["_vehicle", "_on"];

[{
    params ["_vehicle", "_on", "_started"];

    private _apuRPM_pct = _vehicle getVariable ["bmkhs_apuRPM_pct", 0];
    setCustomSoundController [_vehicle, "CustomSoundController1", _apuRPM_pct * 2];
    setCustomSoundController [_vehicle, "CustomSoundController2", _apuRPM_pct * 2];

    if (_on && {!(_this # 2)} && {_apuRPM_pct > 0.05}) then {
        _this set [2, true];
        [_vehicle, "APU", 8] call vtx_uh60_Sound_fnc_EngineEH;
    };

    !(alive _vehicle)
    || {(_vehicle getVariable ["bmkhs_apuBtnOn", false]) isNotEqualTo _on}
    || {[_apuRPM_pct <= 0.001, _vehicle getVariable ["bmkhs_apuOn", false]] select _on}
}, {
    params ["_vehicle"];
    if ((_vehicle getVariable ["bmkhs_apuRPM_pct", 0]) <= 0.001) then {
        setCustomSoundController [_vehicle, "CustomSoundController1", 0];
        setCustomSoundController [_vehicle, "CustomSoundController2", 0];
    };
}, [_vehicle, _on, false]] call CBA_fnc_waitUntilAndExecute;
