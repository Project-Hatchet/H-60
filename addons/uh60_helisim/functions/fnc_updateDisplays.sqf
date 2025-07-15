/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateDisplays

Description:
    ...

Parameters:
    ...

Returns:
    ...

Examples:
    ...

Author:
    BradMick
---------------------------------------------------------------------------- */
params ["_vehicle"];

/////////////////////////////////////////////////////////////////////////////////////////////
// Engine Page          /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//--Ng
private _engNg = _vehicle getVariable "bmkhs_engPctNg";
_vehicle setUserMFDvalue [19, _engNg # 0];
_vehicle setUserMFDvalue [45, _engNg # 1];

//--TGT
private _engTGT = _vehicle getVariable "bmkhs_engTgt";
_vehicle setUserMFDvalue [21, (_engTGT # 0)];
_vehicle setUserMFDvalue [47, (_engTGT # 1)];

//--Np
private _engNp = _vehicle getVariable "bmkhs_engPctNp";
_vehicle setUserMFDvalue [20, (_engNp # 0)];
_vehicle setUserMFDvalue [46, (_engNp # 1)];

//--Torque
private _engTq = _vehicle getVariable "bmkhs_engPctTq";
_vehicle setUserMFDvalue [22, (_engTq # 0)];
_vehicle setUserMFDvalue [48, (_engTq # 1)];

//--Rotor RPM
private _xmsnRpm   = _vehicle getVariable "bmkhs_xmsnRpm";
private _designRpm = _vehicle getVariable "bmkhs_engDesignRpm";
_vehicle setUserMFDvalue [17, (_xmsnRpm / _designRpm) * 100];
/////////////////////////////////////////////////////////////////////////////////////////////
// ESIS                 /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private _esisCount = _vehicle getVariable ["ESIS_COUNTER", 0];
if (!local _vehicle) exitWith {
    _vehicle setUserMFDValue [49, _esisCount];
};

if (_esisCount > -1) then {
    _vehicle setVariable ["ESIS_COUNTER", _esisCount - 1, true];
    _vehicle setUserMFDValue [49, _esisCount];
};
/////////////////////////////////////////////////////////////////////////////////////////////
// OAT Guage            /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private _temp = ((getPosASL player) # 2) call ace_weather_fnc_calculateTemperatureAtHeight;
_vehicle animate ["Gauge_temp_left", 0.5 + (_temp / 100), 2];
_vehicle animate ["Gauge_temp_right", 0.5 + (_temp / 100), 2];