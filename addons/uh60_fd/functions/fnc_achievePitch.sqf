	#include "defines.hpp"

	params ["_vehicle", "_frameTime", "_desiredPitch"];
	(_vehicle call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];
	private _outputForce = -1 * ([_vehicle, "pitch", _frameTime, _desiredPitch, _pitch] call hct_util_fnc_pidRun);
	private _maxPitchTorque = GET("maxPitchTorque",2000);
	_vehicle addTorque (_vehicle vectorModelToWorld [_outputForce max (-1*_maxPitchTorque) min _maxPitchTorque,0,0]);
