/*
 * vtx_uh60_cas_fnc_updateCautionPanel
 *
 * Warning panel lamps and tones, from HeliSim.
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if !(local _vehicle) exitWith {};

private _engines = _vehicle getVariable ["bmkhs_engines", []];
private _ng      = _vehicle getVariable ["bmkhs_engPctNg", [0, 0]];
private _levers  = _vehicle getVariable ["bmkhs_engPowerLeverState", ["OFF", "OFF"]];
private _failed  = _vehicle getVariable ["bmkhs_engFailed", [false, false]];
private _state   = _vehicle getVariable ["bmkhs_engState", ["OFF", "OFF"]];
private _ran     = _vehicle getVariable ["vtx_uh60_cas_engRan", [false, false]];

// ENG OUT - Ng below idle with the lever in FLY once the engine has run, or failed
private _engOut = [0, 0];
{
    private _ngMin = if (_forEachIndex < count _engines) then {(_engines # _forEachIndex) getOrDefault ["ngMin", 0.63]} else {0.63};
    private _lever = _levers # _forEachIndex;
    if (_lever == "OFF") then {_ran set [_forEachIndex, false]};
    if ((_state # _forEachIndex) == "ON" && {(_ng # _forEachIndex) >= _ngMin}) then {_ran set [_forEachIndex, true]};
    _engOut set [_forEachIndex, parseNumber ((_failed # _forEachIndex) || {(_ran # _forEachIndex) && {_lever == "FLY"} && {(_ng # _forEachIndex) < _ngMin}})];
} forEach _ran;
_vehicle setVariable ["vtx_uh60_cas_engRan", _ran];

_vehicle animate ["CautionEng1Out", _engOut # 0];
_vehicle animate ["CautionEng2Out", _engOut # 1];

// LOW ROTOR RPM
private _nr      = _vehicle getVariable ["bmkhs_rtrRpm", 0];
private _nrLow   = (_vehicle getVariable ["bmkhs_nrLimits", [0.95]]) # 0;
private _rpmWarn = parseNumber (_nr > 0.01 && {_nr < _nrLow});
_vehicle animate ["CautionLowRpm", _rpmWarn];

// APU panel
private _apuFail = ([_vehicle, "apu"] call bmkhs_fnc_damageGet) > 0.85
    || {(_vehicle getVariable ["bmkhs_apuBtnOn", false]) && {!(_vehicle getVariable ["bmkhs_apuFuelAvail", false])}};
_vehicle animate ["APUFail", parseNumber _apuFail];
_vehicle animate ["ACCLow", parseNumber ((_vehicle getVariable ["bmkhs_accHydPsi", 0]) < 2600)];

// Tones - airborne, battery bus powered
if (_vehicle != vehicle player) exitWith {};
private _toneMod = parseNumber ((_vehicle getVariable ["bmkhs_battBusOn", false]) && {!([_vehicle] call bmkhs_fnc_stateOnGround)});
setCustomSoundController [_vehicle, "CustomSoundController7", _toneMod * ((_engOut # 0) + (_engOut # 1))];
setCustomSoundController [_vehicle, "CustomSoundController6", _toneMod * _rpmWarn];
