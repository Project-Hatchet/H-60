params ["_vehicle", "_frameTime"];
_vehicle setPilotCameraTarget objNull;
private _barTime = 3;
private _transitionTime = 0.5;
private _barTimeTotal = _barTime + _transitionTime;
private _barCount = 4;

private _barHeight = 5;
private _barWidth = 30;

private _startTime = _vehicle getVariable ["vtx_uh60_flir_fnc_lstTrackStartTime", -6];

//track to start position
if (_startTime > cba_missionTime) exitWith {
	private _setupProgress = (5 - (_startTime - cba_missionTime)) / 5;
	systemChat str ["SETTING UP", _setupProgress];
	((getPilotCameraRotation _vehicle) apply {deg _x}) params ["_yaw", "_pitch"];

	([_yaw, _pitch] vectorDiff [_barWidth, 0]) params ["_yawDiff", "_pitchDiff"];
	
	private _yawSpeed = (abs _yawDiff / (_startTime - cba_missionTime)) * _frameTime;
	private _pitchSpeed = abs (_pitchDiff / (_startTime - cba_missionTime)) * _frameTime;
	

	private _newYaw = if (abs _yawDiff < _yawSpeed) then {_barWidth} else {_yaw - (_yawDiff min _yawSpeed max -_yawSpeed)};
	private _newPitch = if (abs _pitchDiff < _pitchSpeed) then {0} else {_pitch - (_pitchDiff min _pitchSpeed max -_pitchSpeed)};

	_vehicle setPilotCameraRotation [
		rad (_newYaw),
		rad (_newPitch)
	];
	// systemChat str ["SETTING UP", round _setupProgress, round _yaw, round _pitch];
};

private _timeElapsed = cba_missionTime - _startTime;
private _bars = _timeElapsed % (_barTimeTotal * _barCount);
private _currentBar = floor (_bars / _barTimeTotal);
private _barProgress = (_bars - (_barTimeTotal * _currentBar));

private _transitionAdjustment = 0;
if (_barProgress > _barTime) then {
	private _transitionProgress = (_barProgress - _barTime) / _transitionTime;
	// systemChat str ["TRANSIT", _transitionProgress];
	_barProgress = _barProgress min _barTime;
	_transitionAdjustment = (_barHeight * _transitionProgress);
	if (_currentBar + 1 == _barCount) then {
		_transitionAdjustment = -((_barHeight * (_barCount-1)) * _transitionProgress);
	};
};

private _barDirection = if ((_currentBar % 2) == 0) then [{-1}, {1}];
private _yaw = _barDirection * (-_barWidth + ((_barProgress / _barTime) * (_barWidth * 2)));
private _pitch = _barHeight * _currentBar;
_vehicle setPilotCameraRotation [
	rad _yaw,
	rad (_pitch + _transitionAdjustment)
];