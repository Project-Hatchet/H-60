#include "defines.hpp"

/*
 * vtx_uh60_fd_fnc_ralt
 *
 * barometric altitude mode
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */
params ["_vehicle", "_frameTime"];

private _altGoal = TO_M(GET_RALT);
private _alt = (getPos _vehicle) # 2;
private _altDiff = _altGoal - _alt;
private _verticalVelocity = (velocity _vehicle) # 2;
private _verticalVelocityGoal = (_altDiff max -1 min 1) *0.3048;
if ((abs _altDiff) > 3) then {
    if (vtx_uh60_fd_lastAltMatch) then {
        vtx_uh60_fd_lastAltChangeTime = cba_missionTime;
    };
    vtx_uh60_fd_lastAltMatch = false;
    private _timeSinceChange = cba_missionTime - vtx_uh60_fd_lastAltChangeTime;
    _verticalVelocityGoal = (_altDiff max -1 min 1) * (if (_timeSinceChange < 5) then [{1.21}, {4.87}]);
} else {
    vtx_uh60_fd_lastAltMatch = true;
};

if (_altGoal > _alt) then {
    _verticalVelocityGoal = _verticalVelocityGoal max vtx_uh60_fd_terrainSlope;
};

[_vehicle, _frameTime, _verticalVelocityGoal] call vtx_uh60_fd_fnc_verticalVelocity;
