/*
 * vtx_uh60_fd_fnc_psync
 *
 * psync functionality for the fd
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
        SET_RALT(TO_FT(_ralt));
    };
    case "ALT": {
        SET_ALT(TO_FT(_alt));
    };
    case "ALTP": {
        SET_ALTP(TO_FT(_alt));
    };
    case "IAS": {
        SET_IAS(TO_KTS(_ias));
    };
    case "HDG": {
        SET_HDG(_hdg);
    };
};

[_vehicle] remoteExecCall ["vtx_uh60_fd_fnc_updatePanel", crew _vehicle];
if (vtx_uh60_ui_showDebugMessages) then {diag_log "psync";};
