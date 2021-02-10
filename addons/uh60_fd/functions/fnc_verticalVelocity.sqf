/*
 * vtx_uh60_fd_fnc_verticalVelocity
 *
 * vertical velocity autopilot. Is used by all altitude autopilot modes
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime, (SCALAR) verticalVelocity in MS]
 */

params ["_vehicle", "_frameTime", "_verticalVelocityGoal"];

private _verticalVelocity = (velocity _vehicle) # 2;
if ((collectiveRTD _vehicle == 1 && _verticalVelocityGoal > _verticalVelocity) || (collectiveRTD _vehicle == 0 && _verticalVelocityGoal < _verticalVelocity)) exitWith {};
private _output = [_vehicle, "collective", _frameTime, _verticalVelocityGoal, _verticalVelocity] call vxf_util_fnc_pidRun;
_vehicle setActualCollectiveRTD (_output min 1 max 0);
