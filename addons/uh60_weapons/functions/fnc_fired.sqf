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

//spaggetti code:  Mix of Yax's ITC Air APKs and HARM Guidence by Donov
if (_ammo == "ammo_Missile_HARM_HL" && vehicle _gunner == _vehicle) then {
	_index = 0;	//reset index to enter while loop
	while {_index < 4} do {
		if ((getPylonMagazines _vehicle # _index) == "PylonMissile_Missile_HARM_x1_HL") then {
			if (_vehicle ammoOnPylon (_index + 1) == 0) then { _vehicle setPylonLoadout [(_index + 1), "", true]; /*systemChat "Reset Pylon"*/};
			//This loop checks for which HARM was fired, and replaces the pylon with nothing.  It removes the missile
		};
		_index = _index + 1;  //python be like
	};
	[{	//start of Yax's ITC APK Code
		(_this select 0) params ["_projectile", "_ammo", "_foundTarget", "_launchTime","_lastFrameTime", "_targetPos"];
		//Target pos needs to get passed as a parameter or this does not work
		private _frameTime = time - _lastFrameTime;
		(_this select 0) set [4, time];

		if (!alive _projectile) exitWith {
			[_this select 1] call CBA_fnc_removePerFrameHandler;
		};

		//Start of Donov HARM Guidence computer
		_missileTgtPos = [getPosASL _projectile, vectorDir _projectile, _projectile, vehicle _gunner] call ace_laser_fnc_shootRay;
		/*  Using Shoot ray to determine a spot in space where the missile is looking in front of it 
		 *  Then using nearestObjects to pull a list of "AllVehicles" from the radius of the seekerhead
		 *  Then sorting through the list of "AllVehicls" and setting the target as the first vehicle (closest) in the list
		 *		Only choosing vehicles that have radar on (turning off radar and moving should save the vehicle (in theory))
		*/
		if (!_foundTarget) then {
			if ((_missileTgtPos # 1) != 0) then {
				_seenObjects = nearestObjects [(_missileTgtPos # 0), ["AllVehicles"], (_missileTgtPos # 1)*5.6712818 + 10];
				_targetPos = (_missileTgtPos # 0);
				for "_i" from 0 to (count _seenObjects) do {
					if (isVehicleRadarOn (_seenObjects # _i)) exitWith {_targetPos = getPosASL (_seenObjects # _i);(_this select 0) set [5, _targetPos];(_this select 0) set [2, true];};
				};
				
				//systemChat format ["MslTgtPos: %1 DisToTgt: %2 TgtPos: %3", (_missileTgtPos # 0), (_missileTgtPos # 1), _targetPos];
				//systemChat format ["Targets in List: %1", (count _seenObjects)];
			} else {
			/*  Backup Function to default to _targetPos 
			*  Adds a point 6000m in the distance and flys to that point 
			*  Todo:  Find a grid 80 degrees down from the missile and search there for targets
			*		As the missile flys, it should check the ground for other targets to try and narrow down the position of the target
			*		Should check missile altitude as well to adjust the radius of the search 
			*/
				_targetPos = _projectile vectorModelToWorld [6000, 0, 0];
				_targetPos set [2, ((getPosATL _projectile) # 2)];		//maintains the same altitude 
				(_this select 0) set [5, _targetPos];
				//systemChat "Cannot See Target";
			};
		} else {
			//systemChat format ["MslTgtPos: %1 DisToTgt: %2 TgtPos: %3", (_missileTgtPos # 0), (_missileTgtPos # 1), _targetPos];

		//End of Donov HARM Guidence Code
			if(time > _launchTime + 1) then {
				_targetCoordinates = _targetPos; //vectorAdd [0,0,1];
				_position = getPosASL _projectile;
				//systemChat format ["_targetCoordinates: %1, _position: %2", _targetCoordinates, _position];
				(_projectile call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];
				_vectToTarget = vectorNormalized (_targetCoordinates vectorDiff _position);
				_vectToTargetDiff = _vectToTarget vectorDiff (vectorNormalized (velocity _projectile));
				_vectorModelSpace = _projectile vectorWorldToModel _vectToTargetDiff;
				//systemChat format ["_vectToTarget: %1, _vectToTargetDiff: %2, _vectorModelSpace: %3", _vectToTarget, _vectToTargetDiff, _vectorModelSpace];
				_angleX = asin (_vectorModelSpace # 0);
				_angleY = asin (_vectorModelSpace # 2);
				_turnRate = 4 * _frameTime;
				_projectile setDir (getDir _projectile) + ((_turnRate * _angleX) min _angleX);
				[_projectile, _pitch + ((_turnRate * _angleY) min _angleY), 0] call BIS_fnc_setPitchBank;
				//systemChat format ["_angleX: %1 _angleY: %2 _turnRate: %3", _angleX, _angleY, _turnRate];
				//systemChat format ["_pitch: %1 _bank: %2", _pitch, _bank];

			};
		};	
	}, 0, [_projectile, _ammo, false, time, time, getPos _projectile]] call CBA_fnc_addPerFrameHandler;
	//End of Yax's ITC APK Code 
	//comment
};

