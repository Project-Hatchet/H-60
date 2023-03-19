/*
 * vtx_uh60_fd_fnc_spinKnob
 *
 * params (array)[(object) vehicle, (string) mode]
 */

#include "defines.hpp"

params ["_vehicle", "_mode"];

private _ralt = (getPos _vehicle) # 2;
private _alt = (getPosASL _vehicle) # 2;
private _ias = speed _vehicle;
private _hdg = getDir _vehicle;

switch (_mode) do {
    case "RALT": {
        _vehicle setUserMFDValue [12, GET_RALT];
    };
    case "ALTP": {
        _vehicle setUserMFDValue [13, GET_ALTP];
    };
    case "ALT": {
        _vehicle setUserMFDValue [14, GET_ALT];
    };
    case "IAS": {
        _vehicle setUserMFDValue [41, GET_IAS];
    };
    case "HDG": {
    private _heading = GET_HDG;
    if (_heading < 0) then {
      SET_HDG(360);
    };
    if (_heading > 360) then {
      SET_HDG(0);
    };
        _vehicle setUserMFDValue [42, GET_HDG];
    (_this # 0) setUserMFDValue [42, GET_HDG];
    };
};

[_vehicle] remoteExecCall ["vtx_uh60_fd_fnc_updatePanel", crew _vehicle];
