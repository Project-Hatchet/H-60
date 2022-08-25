params ["_vehicle"];

(getPilotCameraTarget _vehicle) params ["_stabilized", "_position"];
private _outputString = "";
if (_stabilized) then {
	_outputString = _outputString + format ["%1M       ", round (_vehicle distance _position)];

	private _gridArea = [worldName] call ace_common_fnc_getMGRSdata;
	private _grid = [_position] call ace_common_fnc_getMapGridFromPos;
	private _gridStr = format ["%1    %2    %3    %4", _gridArea select 0, _gridArea select 1, _grid select 0, _grid select 1];
	_outputString = _outputString + _gridStr;
};
if (vtx_uh60_hellfire_currentTof > -1) then {
	_outputString = _outputString + format["   HF TOF = %1", vtx_uh60_hellfire_currentTof];
} else { // if no hellfire in the air, do the waypoint check
	if (_stabilized) then {
		{
			systemChat str ["checking", waypointDescription _x];
			if (((waypointPosition _x) distance2D _position) < 30) exitWith {
				_outputString = _outputString + format["   %1", waypointDescription _x];
			};
		} forEach (waypoints group player);
	};
};
if (!(_vehicle getVariable ["vtx_uh60_flir_stowed", true])) then {
	_vehicle setUserMFDText [10, _outputString];
};

if (!local _vehicle) exitWith {};

private _isLOBL = [_vehicle] call vtx_uh60_weapons_fnc_isLOBL;
_isLOBL params ["_foundLaser", "_laserPosition"];
private _targetPosition = if (_foundLaser) then {_laserPosition};

private _launchVect = vectorDir _vehicle;
private _direction = getPilotCameraDirection _vehicle;
private _laserVect = _vehicle vectorModelToWorldVisual _direction;
private _dotProd = _launchVect vectorDotProduct _laserVect;
private _angleDiff = acos _dotProd;

private _outOfConstraints = false;
if (_foundLaser && _angleDiff > 20) then {_outOfConstraints = true};
if (!_foundLaser && _angleDiff > 7.5) then {_outOfConstraints = true};

private _constraintsBoxType = 0;
if (_foundLaser) then {
	_constraintsBoxType = if (_angleDiff < 20) then [{0}, {1}];
} else {
	_constraintsBoxType = if (_angleDiff < 7.5) then [{3}, {4}];
};

if (cba_missionTime < vtx_uh60_hellfire_lastLaunchTime + 1.5) then {
	_constraintsBoxType = 6;
};

[_vehicle, 40, _constraintsBoxType] call vtx_uh60_mfd_fnc_setPylonValue;

private _launchMode = _vehicle getvariable ["ace_missileguidance_attackProfile", "hellfire"];
private _launchNum = switch (_launchMode) do {
	case "hellfire_lo": {0};
	case "hellfire": {1};
	case "hellfire_hi": {2};
};

[_vehicle, 41, _launchNum] call vtx_uh60_mfd_fnc_setPylonValue;

// [_vehicle, 42, _vehicle getVariable ["vtx_uh60_hellfire_laserCodeIndex", 0]] call vtx_uh60_mfd_fnc_setPylonValue;