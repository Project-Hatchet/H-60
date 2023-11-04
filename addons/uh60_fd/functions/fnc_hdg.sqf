params ["_vehicle", "_frameTime", ["_fmsCoupled", false]];
if (vtx_uh60_rotorRPM < 0.04) exitWith {};
private _desiredHeading = (round(((vehicle player) animationSourcePhase "FD_5_ROT")*36));
private _waypointCount = count (waypoints (group player));
private _hasWaypoint = _waypointCount > (currentWaypoint (group player));
if (_fmsCoupled && _hasWaypoint) then {
	_desiredHeading = (getUserMFDValue _vehicle) # 0;
	// _vehicle setUserMFDValue [42, _desiredHeading];
};
private _heading = getDir _vehicle;
_reldir = {
	params ["_dir1", "_dir2"];
	private _reldir = _dir1 - _dir2;
	if (_reldir > 180) exitWith {_reldir - 360};
	if (_reldir < -180) exitWith {_reldir + 360};
	_reldir
};
private _headingDiff = [_desiredHeading, _heading] call _reldir;
private _outputForce = -1 * ([_vehicle, "hdg", _frameTime, 0, _headingDiff] call hatchet_util_fnc_pidRun);
// systemChat str ["running HDG", round _desiredHeading, round _heading, _headingDiff, _outputForce];
_vehicle addTorque (_vehicle vectorModelToWorld [0,0,_outputForce max (-1*ias_max_rudderTorque) min ias_max_rudderTorque]);

private _speedKts = (speed _vehicle) / 1.852;
private _desiredBank = 0;
if (_speedKts > 20) then {
	_desiredBank = _headingDiff;
};

if (abs _headingDiff < 2) then {
	private _drift = ((velocityModelSpace _vehicle) # 0);
	_desiredBank = ([_vehicle, "drift", _frameTime, 0, _drift] call hatchet_util_fnc_pidRun);
	//systemChat format ["CORRECTING DRIF %1 WITH %2", _drift, _desiredBank];
};

(_vehicle call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];
private _bankForce = -1 * ([_vehicle, "roll", _frameTime, _desiredBank max -30 min 30, _bank] call hatchet_util_fnc_pidRun);
// systemChat str ["banking", _desiredBank, _bankForce, _bank];
_vehicle addTorque (_vehicle vectorModelToWorld [0,_bankForce max (-1*ias_max_pitchTorque) min ias_max_pitchTorque,0]);