	params ["_vehicle", "_frameTime", "_desiredPitch"];
	(_vehicle call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];
	private _outputForce = -1 * ([_vehicle, "pitch", _frameTime, _desiredPitch, _pitch] call htf_util_fnc_pidRun);
	_vehicle addTorque (_vehicle vectorModelToWorld [_outputForce max (-1*ias_max_pitchTorque) min ias_max_pitchTorque,0,0]);