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
_vehicle setAmmoOnPylon [3,_trot * 10];
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
_vehicle setAmmoOnPylon [4,_mrot * 10];

// set starters
private _starter1 = _vehicle getVariable ["ENG_START1", false];
private _starter2 = _vehicle getVariable ["ENG_START2", false];
private _starter = 0;
if (_starter1) then {_starter = 1;};
if (_starter2) then {_starter = 2;};
if (_starter1 && _starter2) then {_starter = 3;};
_vehicle setAmmoOnPylon [5,_starter];

// set CHIP ENG
private _chipeng1 = (_vehicle getHitPointDamage "hitengine1") > 0.2;
private _chipeng2 = (_vehicle getHitPointDamage "hitengine2") > 0.2;
private _chipeng = 0;
if (_chipeng1) then {_chipeng = 1;};
if (_chipeng2) then {_chipeng = 2;};
if (_chipeng1 && _chipeng2) then {_chipeng = 3;};
_vehicle setAmmoOnPylon [6,_chipeng];

// TODO:set FUEL PRESS