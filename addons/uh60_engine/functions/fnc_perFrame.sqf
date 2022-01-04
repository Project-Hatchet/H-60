/*
 * vtx_uh60_engine_fnc_perFrame
 *
 * handles per frame updates of data
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"
params ["_vehicle", "_frameTime"];

private _rpm = 0.0;
if (!difficultyEnabledRTD) then {
    //RPM
    _rpm = _vehicle getVariable "vtx_uh60_sfmplus_engPctNP";
    _vehicle setUserMFDvalue [19, (_rpm # 0) * 100];
    _vehicle setUserMFDvalue [20, (_rpm # 1) * 100];
    
    //Ng
    _engNg = _vehicle getVariable "vtx_uh60_sfmplus_engPctNG";
    _vehicle setUserMFDvalue [45, (_engNg # 0) * 100];
    _vehicle setUserMFDvalue [46, (_engNg # 1) * 100];

    //Torque
    _engTq = _vehicle getVariable "vtx_uh60_sfmplus_engPctTQ";
    _vehicle setUserMFDvalue [47, (_engTq # 0) * 100];
    _vehicle setUserMFDvalue [48, (_engTq # 1) * 100];
} else {
    _rpm = enginesRpmRTD _vehicle;
    _vehicle setUserMFDvalue [19, (_rpm # 0) / 210];
_   _vehicle setUserMFDvalue [20, (_rpm # 1) / 210];
};
private _power = enginesPowerRTD _vehicle;

if (count _power > 0) then {
    if (GET("ENG1_PWR",100) > 0 || (getUserMFDValue _vehicle) # 21 > 0) then {
        _vehicle setUserMFDvalue [21, ((_rpm # 0) / 60) min 100];
    };
    if (GET("ENG2_PWR",100) > 0 || (getUserMFDValue _vehicle) # 22 > 0) then {
        _vehicle setUserMFDvalue [22, ((_rpm # 1) / 60) min 100];
    };
};
