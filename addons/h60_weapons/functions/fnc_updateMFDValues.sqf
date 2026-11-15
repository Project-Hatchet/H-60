#include "script_component.hpp"
/*
 * hct_h60_weapons_fnc_updateMFDValues
 *
 * Weapons/FLIR MFD readouts: target range and grid, LOBL/LOAL constraints box, attack profile.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

if (!([] call hct_h60_mfd_fnc_isAnyFlirOpened)) exitWith {};

(getPilotCameraTarget _vehicle) params ["_stabilized", "_position"];
private _outputString = "";
if (_stabilized) then {
	_outputString = _outputString + format ["%1M       ", round (_vehicle distance _position)];

	private _gridArea = [worldName] call ace_common_fnc_getMGRSdata;
	private _grid = [_position] call ace_common_fnc_getMapGridFromPos;
	private _gridStr = format ["%1    %2    %3    %4", _gridArea select 0, _gridArea select 1, _grid select 0, _grid select 1];
	_outputString = _outputString + _gridStr;
};
private _impactTime = _vehicle getVariable ["hct_h60_hellfire_impactTime", -1];
private _currentTof = if (_impactTime < 0) then {-1} else {(ceil (_impactTime - cba_missionTime)) max -1};
if (_currentTof > -1) then {
	_outputString = _outputString + format["   HF TOF = %1", _currentTof];
} else { // if no hellfire in the air, do the waypoint check
	if (_stabilized) then {
		{
			// systemChat str ["checking", waypointDescription _x];
			if (((waypointPosition _x) distance2D _position) < 30) exitWith {
				_outputString = _outputString + format["   %1", waypointDescription _x];
			};
		} forEach (waypoints group player);
	};
};
if (!(_vehicle getVariable ["hct_h60_flir_stowed", true])) then {
	_vehicle setUserMFDText [10, _outputString];
};

if (!local _vehicle) exitWith {};

private _isLOBL = [_vehicle] call hct_h60_weapons_fnc_isLOBL;
_isLOBL params ["_foundLaser", "_laserPosition"];

private _launchVect = vectorDir _vehicle;
private _direction = getPilotCameraDirection _vehicle;
private _laserVect = _vehicle vectorModelToWorldVisual _direction;
private _dotProd = _launchVect vectorDotProduct _laserVect;
private _angleDiff = acos ((_dotProd min 1) max -1); // float overshoot past 1 is outside acos's domain

private _outOfConstraints = false;
if (_foundLaser && _angleDiff > 20) then {_outOfConstraints = true};
if (!_foundLaser && _angleDiff > 7.5) then {_outOfConstraints = true};

private _constraintsBoxType = 0;
if (_foundLaser) then {
	_constraintsBoxType = if (_angleDiff < 20) then [{0}, {1}];
} else {
	_constraintsBoxType = if (_angleDiff < 7.5) then [{3}, {4}];
};

if (cba_missionTime < (_vehicle getVariable ["hct_h60_hellfire_lastLaunchTime", 0]) + 1.5) then {
	_constraintsBoxType = 6;
};

//[_vehicle, 40, _constraintsBoxType] call hct_h60_mfd_fnc_setPylonValue;
_vehicle setUserMFDValue [USERMFDV_HELLFIRE_BOX, _constraintsBoxType];

private _launchMode = _vehicle getvariable ["ace_missileguidance_attackProfile", "hellfire"];
private _launchNum = switch (_launchMode) do {
	case "hellfire_lo": {0};
	case "hellfire": {1};
	case "hellfire_hi": {2};
	default {-1}; // another mod's attack profile: leave the readout as it is
};

//[_vehicle, 41, _launchNum] call hct_h60_mfd_fnc_setPylonValue;
if (_launchNum >= 0) then {
	_vehicle setUserMFDValue [USERMFDV_HELLFIRE_TRA, _launchNum];
};
