/*
 * vtx_uh60_cas_fnc_updateCautions
 *
 * updates the cautions list on the EICAS
 * called from events, not continual
 *
 * params (array)[(object) vehicle]
 */
 
/*
16 gen 1
17 hyd 1
18
19 chip 1
20 chip main
21 chip xmsn
22 hull
23 batt
24 start 1
25 gen 2
26 hyd 2
27 egi
28 chip 2
29 tr servo
30 tr quad fail
31 apu fail
32 stab fail
33 start 2
34 stby inst
35 stab fail
36 cmws fail
37
38
39
*/

params ["_vehicle"];
if (!local _vehicle) exitWith {};

_setPylonFn = {
    params ["_index", "_enable"];
    [_vehicle, _index, if (_enable) then [{1}, {0}], true] call vtx_uh60_mfd_fnc_setPylonValue;
    if (_enable) then {
        systemChat str [vehicle player, if (_enable) then [{1}, {0}], _index, true] ;
    }
};

// GEN 1 GEN 2 HYD 1 HYD 2
(_vehicle getVariable ["vtx_uh60_sfmplus_engPctNP", [0,0]]) params ["_np1", "_np2"];
private _np = (_np1 max _np2);
[16, _np < 0.9] call _setPylonFn;
[25, _np < 0.9] call _setPylonFn;
[17, _np < 0.3] call _setPylonFn;
[26, _np < 0.3] call _setPylonFn;


// CHIP ENG 1
private _chipeng1 = (_vehicle getHitPointDamage "hitengine1") > 0.2;
[19, _chipeng1] call _setPylonFn;
// CHIP ENG 2
private _chipeng2 = (_vehicle getHitPointDamage "hitengine2") > 0.2;
[28, _chipeng2] call _setPylonFn;


// TAIL ROTOR
private _trot =
    (_vehicle getHitPointDamage "hitvrotor") + 
    (_vehicle getHitPointDamage "TailGearBox") +
    (_vehicle getHitPointDamage "TailIntermediateGearBox");

[21, _trot > 0.2] call _setPylonFn;
[29, _trot > 0.5] call _setPylonFn;
[30, (_vehicle getHitPointDamage "hitvrotor") > 0.8] call _setPylonFn;

if (_trot > 2) then {
    [_vehicle, "BACKUP PUMP ON", {}, false, false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
    [_vehicle, "T/R SERVO 2 ON", {}, false, false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    [_vehicle, "BACKUP PUMP ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
    [_vehicle, "T/R SERVO 2 ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
};

// HULL
[22, (damage _vehicle) > 0.5] call _setPylonFn;

// STARTER 1 STARTER 2
(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]]) params ["_eng1", "_eng2"];
[24, _eng1 == "STARTING"] call _setPylonFn;
[33, _eng2 == "STARTING"] call _setPylonFn;

// STBY INST
private _stbyInst = (_vehicle animationPhase "switch_stbyinst") > 0;
[34, _stbyInst] call _setPylonFn;

// main rotor
private _mrot = 
    (_vehicle getHitPointDamage "hithrotor") + 
    (_vehicle getHitPointDamage "MainRotorGearBox") +
    (_vehicle getHitPointDamage "MainRotorHub");
[20, _mrot > 0.5] call _setPylonFn;

// flir
[37, (_vehicle getHitPointDamage "FlirHit") > 0.5] call _setPylonFn;