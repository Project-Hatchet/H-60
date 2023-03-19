#include "defines.hpp"

/*
 * vtx_uh60_fd_fnc_altp
 *
 * planned barometric altitude mode
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */
params ["_vehicle", "_frameTime"];

private _altp = TO_M(GET_ALTP);
private _alt = (getPosASL _vehicle) # 2;

if (abs(_alt - _altp) < 10) then {
    SET_ALT(GET_ALTP);
    [_vehicle, "ALT"] call vtx_uh60_fd_fnc_modeSet;
    [_vehicle] remoteExecCall ["vtx_uh60_fd_fnc_updatePanel", crew _vehicle];diag_log "altp";
};
