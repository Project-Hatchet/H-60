/*
 * vtx_uh60_fd_fnc_verticalVelocity
 *
 * vertical velocity autopilot. Is used by all altitude autopilot modes
 *
 * params (array)[(object) vehicle, (SCALAR) frameTime, (SCALAR) verticalVelocity in MS]
 */

params ["_vehicle", "_frameTime", "_verticalVelocityGoal"];

private _verticalVelocity = (velocity _vehicle) # 2;
if (difficultyEnabledRTD) then {
	if ((collectiveRTD _vehicle == 1 && _verticalVelocityGoal > _verticalVelocity) || (collectiveRTD _vehicle == 0 && _verticalVelocityGoal < _verticalVelocity)) exitWith {};
	private _output = [_vehicle, "collective", _frameTime, _verticalVelocityGoal, _verticalVelocity] call hatchet_util_fnc_pidRun;
	_vehicle setActualCollectiveRTD (_output min 1 max 0);
} else {
	if (vtx_uh60_rotorRPM < 0.04) exitWith {};
	private _output = [_vehicle, "collectiveSFM", _frameTime, _verticalVelocityGoal, _verticalVelocity] call hatchet_util_fnc_pidRun;
	private _force = (_output max (-1*vs_max_collectiveForce) min vs_max_collectiveForce);
	// systemchat str [round _verticalVelocityGoal, round _verticalVelocity, round _force, round _output];
	_vehicle addForce [(_vehicle vectorModelToWorld [0,0,_force]), (getCenterOfMass _vehicle)];
};