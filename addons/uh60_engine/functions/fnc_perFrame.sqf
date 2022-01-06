/*
 * vtx_uh60_engine_fnc_perFrame
 *
 * handles per frame updates of data
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"
params ["_vehicle", "_frameTime"];

private _engNp  = [0,0]; 
private _engNg  = [0,0]; 
private _engTGT = [0,0];
private _engTq  = [0,0];
private _rtrRPM = [0,0];

//Ng
_engNg = _vehicle getVariable "vtx_uh60_sfmplus_engPctNG";
_vehicle setUserMFDvalue [19, (_engNg # 0) * 100];
_vehicle setUserMFDvalue [45, (_engNg # 1) * 100];

//TGT
_engTGT = _vehicle getVariable "vtx_uh60_sfmplus_engTGT";
_vehicle setUserMFDvalue [21, (_engTGT # 0)];
_vehicle setUserMFDvalue [47, (_engTGT # 1)];

if (!difficultyEnabledRTD) then {
    //Np
    _engNp = _vehicle getVariable "vtx_uh60_sfmplus_engPctNP";
    _vehicle setUserMFDvalue [20, (_engNp # 0) * 100];
    _vehicle setUserMFDvalue [46, (_engNp # 1) * 100];
    
    //Torque
    _engTq = _vehicle getVariable "vtx_uh60_sfmplus_engPctTQ";
    _vehicle setUserMFDvalue [22, (_engTq # 0) * 100];
    _vehicle setUserMFDvalue [48, (_engTq # 1) * 100];

    //Rotor RPM
    _rtrRPM = (_engNp select 0) max (_engNp select 1);
    _vehicle setUserMFDvalue [17, _rtrRPM * 100];

    HintSilent format ["SFM+
                        \nNg = %1
                        \nNp = %2
                        \nTGT = %3
                        \nTq = %4
                        \nRPM = %5", _engNg, _engNp, _engTGT, _engTq, _rtrRPM];

} else {
    private _npScalar = 200;
    private _tqScalar = 3.71;

    _engNp = enginesRpmRTD _vehicle;
    if (_engNp isEqualTo []) then {
        _engNp = [0,0];
    };
    _vehicle setUserMFDvalue [20, (_engNp # 0) / _npScalar];
    _vehicle setUserMFDvalue [46, (_engNp # 1) / _npScalar];

    //Torque
    _engTq = enginesTorqueRTD _vehicle;
    if (_engTq isEqualTo []) then {
        _engTq = [0,0];
    };
    _vehicle setUserMFDvalue [22, (_engTq # 0) / _tqScalar];
    _vehicle setUserMFDvalue [48, (_engTq # 1) / _tqScalar];
    //Rotor RPM
    _rtrRPM = (_engNp select 0) max (_engNp select 1);
    _vehicle setUserMFDvalue [17, _rtrRPM / _npScalar];

    HintSilent format ["AFM
                        \nNg = %1
                        \nNp = %2
                        \nTGT = %3
                        \nTq = %4
                        \nRPM = %5", _engNg, _engNp, _engTGT, _engTq, _rtrRPM];
};