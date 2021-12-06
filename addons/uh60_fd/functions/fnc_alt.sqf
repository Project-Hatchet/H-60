/*
 * vtx_uh60_fd_fnc_alt
 *
 * barometric altitude mode
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime"];

private _altGoal = TO_M(GET_ALT);
private _alt = (getPosASL _vehicle) # 2;
private _altDiff = _altGoal - _alt;
private _verticalVelocity = (velocity _vehicle) # 2;
private _verticalVelocityGoal = (_altDiff max -1 min 1) *0.3048;
if ((abs _altDiff) > 3) then {
    if (vtx_uh60_fd_lastAltMatch) then {
        vtx_uh60_fd_lastAltChangeTime = cba_missionTime;
    };
    vtx_uh60_fd_lastAltMatch = false;
    private _timeSinceChange = cba_missionTime - vtx_uh60_fd_lastAltChangeTime;
    if(vtx_uh60_ui_showDebugMessages) then {systemChat str _timeSinceChange;};
    _verticalVelocityGoal = (_altDiff max -1 min 1) * (if (_timeSinceChange < 5) then [{1.21}, {4.87}]);
} else {
    vtx_uh60_fd_lastAltMatch = true;
};

[_vehicle, _frameTime, _verticalVelocityGoal] call vtx_uh60_fd_fnc_verticalVelocity;
