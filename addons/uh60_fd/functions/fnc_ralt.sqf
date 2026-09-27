/*
 * vtx_uh60_fd_fnc_ralt
 *
 * barometric altitude mode
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime"];

private _altGoal = TO_M(GET_RALT);
private _alt = (getPos _vehicle) # 2;
private _altDiff = _altGoal - _alt;
private _verticalVelocity = (velocity _vehicle) # 2;
private _verticalVelocityGoal = (_altDiff max -1 min 1) *0.3048;
if ((abs _altDiff) > 3) then {
    if (GET("lastAltMatch",true)) then {
        SET("lastAltChangeTime", cba_missionTime);
    };
    SET("lastAltMatch", false);
    private _timeSinceChange = cba_missionTime - GET("lastAltChangeTime",cba_missionTime);
    _verticalVelocityGoal = (_altDiff max -1 min 1) * (if (_timeSinceChange < 5) then [{1.21}, {4.87}]);
} else {
    SET("lastAltMatch", true);
};

if (_altGoal > _alt) then {
    _verticalVelocityGoal = _verticalVelocityGoal max GET("terrainSlope",0);
};

[_vehicle, _frameTime, _verticalVelocityGoal] call vtx_uh60_fd_fnc_verticalVelocity;
