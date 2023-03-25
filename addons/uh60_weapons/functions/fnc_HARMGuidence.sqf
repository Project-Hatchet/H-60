#include "script_component.hpp"

/*
 * Author: Donov & Yax
 * Flies the missile to a target, or scans for targets to hit
 *
 * Arguments:
 * 0: Projectile <OBJECT>
 * 1: Ammo <OBJECT>
 * 
 * Return Value:
 * 0: Closest Target (or objNull for no Target) <OBJECT>
 *
 * Example:
 * [_projectile, _ammo] call vtx_uh60_weapons_fnc_getHARMTarget
 */

params ["_projectile", "_ammo"];

[{	//start of Yax's ITC APK Code
		(_this select 0) params ["_projectile", "_ammo", "_foundTarget", "_launchTime","_lastFrameTime", "_targetPos"];
		//Target pos needs to get passed as a parameter or this does not work
		private _frameTime = time - _lastFrameTime;
		(_this select 0) set [4, time];

		if (!alive _projectile) exitWith {
			[_this select 1] call CBA_fnc_removePerFrameHandler;
		};

		//Start of Donov HARM Guidence computer
		//systemChat "Missile Alive";
		_missileTgtPos = [getPosASL _projectile, vectorDir _projectile, _projectile, vehicle _gunner] call ace_laser_fnc_shootRay;
		/*  Using Shoot ray to determine a spot in space where the missile is looking in front of it 
		 *  Then using nearestObjects to pull a list of "AllVehicles" from the radius of the seekerhead
		 *  Then sorting through the list of "AllVehicls" and setting the target as the first vehicle (closest) in the list
		 *		Only choosing vehicles that have radar on (turning off radar and moving should save the vehicle (in theory))
		*/
		if (!_foundTarget) then {
			if ((_missileTgtPos # 1) != 0) then {
				_target = [_projectile, ((_missileTgtPos # 1)*5.6712818 + 10), (_missileTgtPos # 0)] call vtx_uh60_weapons_fnc_HARMGuidence; 
				if (_target != objNull) then {
					_targetPos = getPosASL _target;
				} else {
					_targetPos = (_missileTgtPos # 0);
				};
			} else {
			/*  Backup Function to default to _targetPos 
			*  Adds a point 6000m in the distance and flys to that point 
			*  Finds a grid 30 degrees down from the missile and search there for targets
			*		As the missile flys, it should check the ground for other targets to try and narrow down the position of the target
			*		Should check missile altitude as well to adjust the radius of the search 
			*/	
				_vecDir = [6000 + ((getPosATL _projectile) # 2), getDir _projectile, -30] call CBA_fnc_polar2vect;
				_vecDir = vectorNormalized _vecDir;
				_missileTgtPos = [getPosASL _projectile, _vecDir, _projectile, blockey] call ace_laser_fnc_shootRay;
				if ((_missileTgtPos # 1) != 0) then {
					_target = [_projectile, ((_missileTgtPos # 1)*5.6712818 + 10), (_missileTgtPos # 0)] call vtx_uh60_weapons_fnc_HARMGuidence; 
					if (_target != objNull) then {
						_targetPos = getPosASL _target;
					} else {
						_targetPos = (_missileTgtPos # 0);
					};
				} else {
					_targetPos = _projectile vectorModelToWorld [6000, 0, 0];
					_targetPos set [2, 0];
				};
			};
		} else {

		//End of Donov HARM Guidence Code
			if(time > _launchTime + 1 && _targetPos != objNull) then {
				_targetCoordinates = _targetPos vectorAdd [0,0,0.2];
				_position = getPosASL _projectile;
				(_projectile call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];
				_vectToTarget = vectorNormalized (_targetCoordinates vectorDiff _position);
				_vectToTargetDiff = _vectToTarget vectorDiff (vectorNormalized (velocity _projectile));
				_vectorModelSpace = _projectile vectorWorldToModel _vectToTargetDiff;
				_angleX = asin (_vectorModelSpace # 0);
				_angleY = asin (_vectorModelSpace # 2);
				_turnRate = 4 * _frameTime;
				_projectile setDir (getDir _projectile) + ((_turnRate * _angleX) min _angleX);
				[_projectile, _pitch + ((_turnRate * _angleY) min _angleY), 0] call BIS_fnc_setPitchBank;
			};
		};	
	}, 0, [_projectile, _ammo, false, time, time, getPos _projectile]] call CBA_fnc_addPerFrameHandler;
	//End of Yax's ITC APK Code 






