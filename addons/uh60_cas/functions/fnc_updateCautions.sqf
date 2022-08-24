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

private _pylonLabels = [
    "","","","","","","","","","","","","","","","" // first 15
    ,"GEN 1 FAIL"
    ,"HYD PUMP 1 FAIL"
    ,""
    ,"CHIP ENG 1"
    ,"CHIP MAIN MDL SUMP"
    ,"MAIN XMSN PRES"
    ,"HULL INTEGRITY CRIT"
    ,"LEFT STN HANG"
    ,"ENG 1 STARTER ON"
    ,"GEN 2 FAIL"
    ,"HYD PUMP 2"
    ,"EGI FAIL"
    ,"CHIP ENG 2"
    ,"T/R SERVO 1 FAIL"
    ,"T/R QUAD FAIL"
    ,"APU FAIL"
    ,"RIGHT STN HANG"
    ,"ENG 2 STARTER ON"
    ,"STBY INST NOT ARMD"
    ,"STAB FAIL"
    ,"CMWS FAIL"
    ,"FLIR FAIL"
    ,"MFD BUS ERR"
    ,""
];

params ["_vehicle"];
if (!local _vehicle || missionNamespace getVariable ["vtx_uh60_mfd_eicas_testing", false]) exitWith {};

_setPylonFn = {
    params ["_index", "_enable"];
    private _return = [_vehicle, _index, if (_enable) then [{1}, {0}], true] call vtx_uh60_mfd_fnc_setPylonValue;
    if (_return == 2) then {
        vtx_uh60_cas_cautionsUnacked = vtx_uh60_cas_cautionsUnacked + 1;
        vtx_uh60_cas_firstAdvisory = vtx_uh60_cas_firstAdvisory + 1;
        vtx_uh60_cas_cautionsLog = [_pylonLabels # _index] + vtx_uh60_cas_cautionsLog;
    };
    if (_return == 0) then {
        private _string = _pylonLabels # _index;
        vtx_uh60_cas_cautionsLog deleteAt (vtx_uh60_cas_cautionsLog find _string);
        vtx_uh60_cas_firstAdvisory = vtx_uh60_cas_firstAdvisory - 1;
        vtx_uh60_cas_cautionsUnacked = vtx_uh60_cas_cautionsUnacked min (count vtx_uh60_cas_cautionsLog);
    };
    if (_return > -1) then {
        [_vehicle,(_return > 0)] call vtx_uh60_cas_fnc_updateOverlayList;
    };
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

// cmws
[36, (_vehicle getHitPointDamage "hitRWR") > 0.5] call _setPylonFn;

// mfd
private _mfd =
    (_vehicle getHitPointDamage "mfd1") + 
    (_vehicle getHitPointDamage "mfd2") +
    (_vehicle getHitPointDamage "mfd3") +
    (_vehicle getHitPointDamage "mfd4");

[38, (_mfd) > 0.2] call _setPylonFn;


[23, (_vehicle getHitPointDamage "WingStores") > 0.3] call _setPylonFn;
[32, (_vehicle getHitPointDamage "WingStores") > 0.7] call _setPylonFn;