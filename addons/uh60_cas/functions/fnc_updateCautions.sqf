/*
 * vtx_uh60_cas_fnc_updateCautions
 *
 * updates the cautions list on the EICAS
 * called from events, not continual
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];
if (!local _vehicle) exitWith {};

// set tailrotor damage cautions
private _trot = _vehicle getHitPointDamage "hitvrotor";
[_vehicle, 3, _trot * 10] call vtx_uh60_mfd_fnc_setPylonValue;
// update tailrotor damage advisories
if (_trot > 2) then {
    [_vehicle, "BACKUP PUMP ON", {}, false, false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
    [_vehicle, "T/R SERVO 2 ON", {}, false, false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    [_vehicle, "BACKUP PUMP ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
    [_vehicle, "T/R SERVO 2 ON"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
};

// main rotor
private _mrot = _vehicle getHitPointDamage "hithrotor";
[_vehicle, 4, _mrot * 10] call vtx_uh60_mfd_fnc_setPylonValue;

// set starters
(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]]) params ["_eng1", "_eng2"];
private _starter = 0;
if (_eng1 == "STARTING") then {_starter = 1;};
if (_eng2 == "STARTING") then {_starter = 2;};
if (_eng1 == "STARTING" && _eng2 == "STARTING") then {_starter = 3;};
[_vehicle, 5, _starter] call vtx_uh60_mfd_fnc_setPylonValue;

// set CHIP ENG
private _chipeng1 = (_vehicle getHitPointDamage "hitengine1") > 0.2;
private _chipeng2 = (_vehicle getHitPointDamage "hitengine2") > 0.2;
private _chipeng = 0;
if (_chipeng1) then {_chipeng = 1;};
if (_chipeng2) then {_chipeng = 2;};
if (_chipeng1 && _chipeng2) then {_chipeng = 3;};
[_vehicle, 6,_chipeng] call vtx_uh60_mfd_fnc_setPylonValue;


// TODO:set FUEL PRESS
