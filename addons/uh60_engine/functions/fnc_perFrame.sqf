/*
 * vtx_uh60_engine_fnc_perFrame
 *
 * handles per frame updates of data
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"
params ["_vehicle", "_frameTime"];

private _rpm = enginesTorqueRTD _vehicle;
private _power = enginesPowerRTD _vehicle;
_vehicle setUserMFDvalue [19, (_rpm # 0) / 10];
_vehicle setUserMFDvalue [20, (_rpm # 1) / 10];
if (count _power > 0) then {
    if (GET("ENG1_PWR",100) > 0 || (getUserMFDValue _vehicle) # 21 > 0) then {
        _vehicle setUserMFDvalue [21, ((_rpm # 0) / 60) min 100];
    };
    if (GET("ENG2_PWR",100) > 0 || (getUserMFDValue _vehicle) # 22 > 0) then {
        _vehicle setUserMFDvalue [22, ((_rpm # 1) / 60) min 100];
    };
};
