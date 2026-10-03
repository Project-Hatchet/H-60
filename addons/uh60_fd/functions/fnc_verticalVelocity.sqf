/*
 * vtx_uh60_fd_fnc_verticalVelocity
 *
 * vertical velocity autopilot. Is used by all altitude autopilot modes
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime, (SCALAR) verticalVelocity in MS]
 */

#include "defines.hpp"

params ["_vehicle", "_frameTime", "_verticalVelocityGoal"];

private _verticalVelocity = (velocity _vehicle) # 2;
if (GET("rotorRPM",0) < 0.04) exitWith {};
private _output = [_vehicle, "collectiveSFM", _frameTime, _verticalVelocityGoal, _verticalVelocity] call hct_util_fnc_pidRun;
private _maxCollectiveForce = GET("maxCollectiveForce",3000);
private _force = (_output max (-1*_maxCollectiveForce) min _maxCollectiveForce);
// systemchat str [round _verticalVelocityGoal, round _verticalVelocity, round _force, round _output];
_vehicle addForce [(_vehicle vectorModelToWorld [0,0,_force]), (getCenterOfMass _vehicle)];
