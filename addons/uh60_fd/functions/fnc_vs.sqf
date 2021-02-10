/*
 * vtx_uh60_fd_fnc_vs
 *
 * vertical speed mode
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime"];

private _vsGoal = TO_MS(GET_VS);
[_vehicle, _frameTime, _verticalVelocityGoal] call vtx_uh60_fd_fnc_verticalVelocity;
