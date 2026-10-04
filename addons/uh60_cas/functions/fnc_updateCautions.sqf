#include "script_component.hpp"
/*
 * vtx_uh60_cas_fnc_updateCautions
 *
 * updates the cautions list on the EICAS from HeliSim
 *
 * params (array)[(object) vehicle]
 */

private _pylonLabels = createHashMapFromArray [
    [USERMFDV_L00, "GEN 1 FAIL"],
    [USERMFDV_L01, "HYD PUMP 1 FAIL"],
    [USERMFDV_L02, "FUEL 1 LOW"],
    [USERMFDV_L10, "CHIP ENG 1"],
    [USERMFDV_L11, "CHIP MAIN MDL SUMP"],
    [USERMFDV_L12, "MAIN XMSN PRES"],
    [USERMFDV_L13, "HULL INTEGRITY CRIT"],
    [USERMFDV_L14, "LEFT STN HANG"],
    [USERMFDV_L15, "ENG 1 STARTER ON"],
    [USERMFDV_L20, "ENG 1 OIL PRESS"],
    [USERMFDV_L21, "ENG 2 OIL PRESS"],
    [USERMFDV_L22, "ROTOR BRAKE ON"],
    [USERMFDV_R00, "GEN 2 FAIL"],
    [USERMFDV_R01, "HYD PUMP 2"],
    [USERMFDV_R02, "FUEL 2 LOW"],
    [USERMFDV_R10, "CHIP ENG 2"],
    [USERMFDV_R11, "T/R SERVO 1 FAIL"],
    [USERMFDV_R12, "T/R QUAD FAIL"],
    [USERMFDV_R13, "APU FAIL"],
    [USERMFDV_R14, "RIGHT STN HANG"],
    [USERMFDV_R15, "ENG 2 STARTER ON"],
    [USERMFDV_R20, "STBY INST NOT ARMD"],
    [USERMFDV_R21, "STAB FAIL"],
    [USERMFDV_R22, "CMWS FAIL"],
    [USERMFDV_R23, "FLIR FAIL"],
    [USERMFDV_R24, "MFD BUS ERR"],
    [USERMFDV_R25, "EGI FAIL"]
];

params ["_vehicle"];
if (!local _vehicle || missionNamespace getVariable ["vtx_uh60_mfd_eicas_testing", false]) exitWith {};

private _setPylonFn = {
    params ["_index", "_enable"];
    private _label  = _pylonLabels getOrDefault [_index, ""];
    private _return = [_vehicle, _index, [0, 1] select _enable, true] call vtx_uh60_mfd_fnc_setPylonValue;
    if (_return == 2) then {
        vtx_uh60_cas_cautionsUnacked = vtx_uh60_cas_cautionsUnacked + 1;
        vtx_uh60_cas_firstAdvisory = vtx_uh60_cas_firstAdvisory + 1;
        vtx_uh60_cas_cautionsLog = [_label] + vtx_uh60_cas_cautionsLog;
    };
    if (_return == 0) then {
        vtx_uh60_cas_cautionsLog deleteAt (vtx_uh60_cas_cautionsLog find _label);
        vtx_uh60_cas_firstAdvisory = vtx_uh60_cas_firstAdvisory - 1;
        vtx_uh60_cas_cautionsUnacked = vtx_uh60_cas_cautionsUnacked min (count vtx_uh60_cas_cautionsLog);
    };
    if (_return > -1) then {
        [_vehicle, (_return > 0)] call vtx_uh60_cas_fnc_updateOverlayList;
    };
};

private _dmg = {[_vehicle, _this] call bmkhs_fnc_damageGet};

// Hydraulics are expected once the accessory drive is turning, or in flight
private _hydExpected = !isTouchingGround _vehicle || {([_vehicle, "ACCESSORY_DRIVE"] call bmkhs_fnc_systemCircuit) >= 0.85};
private _priLow  = _hydExpected && {(_vehicle getVariable ["bmkhs_priHydPsi", 0]) < 1260};
private _utilLow = _hydExpected && {(_vehicle getVariable ["bmkhs_utilHydPsi", 0]) < 1260};

// GEN, HYD PUMP
[USERMFDV_L00, (_vehicle getVariable ["bmkhs_gen1", 0]) < 1] call _setPylonFn;
[USERMFDV_R00, (_vehicle getVariable ["bmkhs_gen2", 0]) < 1] call _setPylonFn;
[USERMFDV_L01, _priLow] call _setPylonFn;
[USERMFDV_R01, _utilLow] call _setPylonFn;

// FUEL LOW
[USERMFDV_L02, (_vehicle getVariable "bmkhs_no1TankMass") < (_vehicle getVariable "bmkhs_no1TankLow")] call _setPylonFn;
[USERMFDV_R02, (_vehicle getVariable "bmkhs_no2TankMass") < (_vehicle getVariable "bmkhs_no2TankLow")] call _setPylonFn;

// ENG OIL PRESS
(_vehicle getVariable "bmkhs_engOilPsiLow") params ["_oil1", "_oil2"];
[USERMFDV_L20, _oil1] call _setPylonFn;
[USERMFDV_L21, _oil2] call _setPylonFn;

// ROTOR BRAKE ON
[USERMFDV_L22, _vehicle getVariable "bmkhs_rotorBrakeOn"] call _setPylonFn;

// CHIP ENG
(_vehicle getVariable ["bmkhs_engChips", [false, false]]) params ["_chip1", "_chip2"];
[USERMFDV_L10, _chip1] call _setPylonFn;
[USERMFDV_R10, _chip2] call _setPylonFn;

// Main transmission
private _xmsn = "transmission" call _dmg;
[USERMFDV_L11, _xmsn >= 0.75] call _setPylonFn;
[USERMFDV_L12, _xmsn >= 0.5] call _setPylonFn;

// Tail rotor - servo 1 is on the primary system, backup pump takes over from the utility reservoir
[USERMFDV_R11, _priLow] call _setPylonFn;
private _tailDrive = selectMax (["intermediateGearbox", "tailRotorGearbox", "tailRotor"] apply {_x call _dmg});
[USERMFDV_R12, _tailDrive >= 0.85] call _setPylonFn;

if (_priLow && {(_vehicle getVariable ["bmkhs_utilLevel_pct", 0]) >= 0.1}) then {
    [_vehicle, "BACKUP PUMP ON", {}, false, false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
    [_vehicle, "T/R SERVO 2 ON", {}, false, false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    [_vehicle, "BACKUP PUMP ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
    [_vehicle, "T/R SERVO 2 ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
};

// APU
private _apuFail = ("apu" call _dmg) > 0.85
    || {(_vehicle getVariable ["bmkhs_apuBtnOn", false]) && {!(_vehicle getVariable ["bmkhs_apuFuelAvail", false])}};
[USERMFDV_R13, _apuFail] call _setPylonFn;

// STAB
[USERMFDV_R21, ("stabilator" call _dmg) >= 0.85] call _setPylonFn;

// STARTER
(_vehicle getVariable ["bmkhs_engState", ["OFF", "OFF"]]) params ["_eng1", "_eng2"];
[USERMFDV_L15, _eng1 == "STARTING"] call _setPylonFn;
[USERMFDV_R15, _eng2 == "STARTING"] call _setPylonFn;

// STBY INST
[USERMFDV_R20, !(_vehicle getVariable ["bmkhs_stbyInstOn", false])] call _setPylonFn;

// Airframe and mission equipment - no HeliSim system
[USERMFDV_L13, (damage _vehicle) > 0.5] call _setPylonFn;
[USERMFDV_R25, (_vehicle getHitPointDamage "EgiComp") > 0.5] call _setPylonFn;
[USERMFDV_R23, (_vehicle getHitPointDamage "FlirHit") > 0.5] call _setPylonFn;
[USERMFDV_R22, (_vehicle getHitPointDamage "hitRWR") > 0.5] call _setPylonFn;
private _mfd = 0;
{_mfd = _mfd + (_vehicle getHitPointDamage _x)} forEach ["MFD1", "MFD2", "MFD3", "MFD4"];
[USERMFDV_R24, _mfd > 0.2] call _setPylonFn;
[USERMFDV_L14, (_vehicle getHitPointDamage "WingStoreL") > 0.3] call _setPylonFn;
[USERMFDV_R14, (_vehicle getHitPointDamage "WingStoreR") > 0.7] call _setPylonFn;
