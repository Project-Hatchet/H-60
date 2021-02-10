/*
 * vtx_uh60_fd_fnc_perFrame
 *
 * runs the per frame updates of the flight director, this is where its active control is done
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime"];

private _altCode = GET("alt_mode",nil);
if (!isNil "_altCode") then {_this call _altCode} else {
    if (vtx_uh60m_simpleCollective) then {
        private _collective = (inputAction "HeliCollectiveRaise") - (inputAction "HeliCollectiveLower");
        if (_collective != 0) then {
            vtx_uh60_fd_collectiveHeld = vtx_uh60_fd_collectiveHeld + _frameTime;
        } else {
            vtx_uh60_fd_collectiveHeld = 1;
        };
        [_vehicle, _frameTime, _collective * 8 * ((vtx_uh60_fd_collectiveHeld / 3) min 3)] call vtx_uh60_fd_fnc_verticalVelocity;
    };
};

_vehicle setUserMFDvalue [37, (velocityModelSpace _vehicle) # 0];
_vehicle setUserMFDvalue [38, (velocityModelSpace _vehicle) # 1];

private _pitchCode = GET("pitch_mode",nil);
if (!isNil "_pitchCode") then {_this call _pitchCode};

private _rollCode = GET("roll_mode",nil);
if (!isNil "_rollCode") then {_this call _rollCode};
