params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
// systemchat "HELLFIRE LAUNCHED";
private _vehicle = vehicle player;
if (vehicle _gunner == _vehicle) then {
	addCamShake [3, 1, 25];
	vtx_uh60_hellfire_lastLaunchTime = cba_missionTime;
	
	private _targetPoint = ([_vehicle] call vtx_uh60_weapons_fnc_isLOBL) # 1;
	if (!(_targetPoint isEqualTo [0,0,0])) then {
		vtx_uh60_hellfire_currentTof = ceil ((_vehicle distance _targetPoint) / 250);
	};
};
if (_ammo == "VTX_Hellfire_AGM114K" || _ammo == "VTX_Hellfire_AGM114N") then {
	_this call vtx_uh60_weapons_fnc_hellfireGuidanceInit;
};

if (player == _gunner && local _gunner) then {
	[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;
};

if (_ammo == "ammo_Missile_HARM_HL" && vehicle _gunner == _vehicle) then {
	_index = 0;
	while {_index < 4} do {
		if ((getPylonMagazines _vehicle # _index) == "PylonMissile_Missile_HARM_x1_HL") then {
			if (_vehicle ammoOnPylon (_index + 1) == 0) then { _vehicle setPylonLoadout [(_index + 1), "", true]; /*systemChat "Reset Pylon"*/};
		};
		_index = _index + 1;
	};
	[{
		(_this select 0) params ["_projectile", "_ammo", "_position", "_launchTime","_lastFrameTime"];
		private _frameTime = time - _lastFrameTime;
		(_this select 0) set [5, time];

		if (!alive _projectile) exitWith {
			[_this select 1] call CBA_fnc_removePerFrameHandler;
		};

		_missileTgtPos = [getPosASL _projectile, vectorDir _projectile, _projectile, vehicle _gunner] call ace_laser_fnc_shootRay;
		if ((_missileTgtPos # 1) != 0) then {
			_seenObjects = nearestObjects [(_missileTgtPos # 0), ["AllVehicles"], (_missileTgtPos # 1)*5.6712818];
			_targetPos = (_missileTgtPos # 0);
			for "_i" from 1 to (count _seenObjects) do {
				if (isVehicleRadarOn (_seenObjects # _i)) exitWith {_targetPos = getPos (_seenObjects # _i)};
			};
			systemChat format ["MslTgtPos: %1 DisToTgt: %2 TgtPos: %3", (_missileTgtPos # 0), (_missileTgtPos # 1), _targetPos];
			systemChat format ["Targets in List: %1", (count _seenObjects)];
		} else {
			_targetPos = _projectile vectorModelToWorld [6000, 0, 0];
			_targetPos set [2, 0];
			systemChat "Cannot See Target";
		};
		
		if(!isNil _targetPos && time > _launchTime + 1) then {
			private _targetCoordinates = _targetPos vectorAdd [0,0,1];
			private _position = getPosASL _projectile;
			(_projectile call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];
			private _vectToTarget = _position vectorFromTo _targetCoordinates;
			private _vectToTargetDiff = _vectToTarget vectorDiff (vectorNormalized (velocity _projectile));
			private _vectorModelSpace = _projectile vectorWorldToModel _vectToTargetDiff;
			private _angleX = asin (_vectorModelSpace # 0);
			private _angleY = asin (_vectorModelSpace # 2);
			_turnRate = 1 * _frameTime;
			_projectile setDir (getDir _projectile) + ((_turnRate * _angleX) min _angleX);
			[_projectile, _pitch + ((_turnRate * _angleY) min _angleY), 0] call BIS_fnc_setPitchBank;
		};
	}, 0, [_projectile, _ammo, getPosATL _projectile, time, time]] call CBA_fnc_addPerFrameHandler;
};

