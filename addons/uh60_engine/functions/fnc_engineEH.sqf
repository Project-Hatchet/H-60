/*
 * vtx_uh60_engine_fnc_engineEH
 *
 * engine power eventhandler
 *
 * params (array)[(object) vehicle, (bool) turnedOn]
 */

diag_log format ["%1: engine EH", time];

params ["_vehicle", "_turnedOn", ["_lever","throttle"]];

if (!local _vehicle || vtx_uh60m_simpleStartup) exitWith {};

if(
    (_vehicle getHitPointDamage "HitEngine1" > 0.3 && _vehicle getHitPointDamage "HitEngine2" > 0.3) ||
    _vehicle getHitPointDamage "HitHRotor" > 0.5
) exitWith {
    _vehicle setVariable ["ENG1_PWR", 0, true];
    _vehicle setVariable ["ENG2_PWR", 0, true];
    if(vtx_uh60_ui_showDebugMessages) then {systemChat "damage start cancel";};
    _vehicle engineOn false;
};

private _eng1Powered = _vehicle getVariable ["ENG1_PWR",0] > 0;
private _eng2Powered = _vehicle getVariable ["ENG2_PWR",0] > 0;
private _fuelFlow1 = [_vehicle, "Lever_fuelsys1", "Switch_fuelboostpump1"] call vtx_uh60_engine_fnc_hasFuelFlow;
private _fuelFlow2 = [_vehicle, "Lever_fuelsys2", "Switch_fuelboostpump2"] call vtx_uh60_engine_fnc_hasFuelFlow;
private _starter1 = _vehicle getVariable ["ENG_START1", false];
private _starter2 = _vehicle getVariable ["ENG_START2", false];
private _throttle1 = (_vehicle animationPhase "Lever_engpower1") / 0.85 * 100; //0.85 is FLY
if (_throttle1 < 10) then {_throttle1 = 0};
private _throttle2 = (_vehicle animationPhase "Lever_engpower2") / 0.85 * 100; //0.85 is FLY
if (_throttle2 < 10) then {_throttle2 = 0};
private _canStart = false;

private _power = 0;
if (_fuelFlow1 > 0) then {
        if(_vehicle getVariable ["ENG1_PWR",0] == 0) then { // if the engine was not powered, check startup
        if (_starter1) then {
            _power = _power + (_throttle1 / 2);
            _vehicle setVariable ["ENG1_PWR", _throttle1, true];
        };
    } else { // otherwise just update the power state if it was already running anyways
        _power = _power + (_throttle1 / 2);
        _vehicle setVariable ["ENG1_PWR", _throttle1, true];
    };
} else {
    if (_lever == "b_engpowercont1") then { _vehicle setVariable ["ENG1_PWR", 0, true]; };
};

if (_fuelFlow2 > 0) then {
    if(_vehicle getVariable ["ENG2_PWR",0] == 0) then { // if the engine was not powered, check startup
        if (_starter2) then {
            _power = _power + (_throttle2 / 2);
            _vehicle setVariable ["ENG2_PWR", _throttle2, true];
        };
    } else { // otherwise just update the power state if it was already running anyways
        _power = _power + (_throttle2 / 2);
        _vehicle setVariable ["ENG2_PWR", _throttle2, true];
    };
} else {
    if (_lever == "b_engpowercont2") then { _vehicle setVariable ["ENG2_PWR", 0, true]; };
};

_turnedOn = (_power > 0);

_vehicle engineOn _turnedOn;
if(vtx_uh60_ui_showDebugMessages) then {systemChat "ENGINE STATE CHANGE";};
_this call vtx_uh60_engine_fnc_batteryState;
[_vehicle] call vtx_uh60_cas_fnc_updateCautionPanel;
