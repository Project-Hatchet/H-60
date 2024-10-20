#include "script_component.hpp"

/*
 * Author: Donov
 * Checks for suitable targets for the HARM Missile
 *
 * Arguments:
 * 0: Projectile <OBJECT>
 * 1: Projectile's checking distance <NUM>
 * 2: Temporary Projectile's Target Grid (center of where is it looking?) <ARRAY:PositionASL>
 *
 * Return Value:
 * 0: Closest Target (or objNull for no Target) <OBJECT>
 *
 * Example:
 * [_projectile, _projCheckDist, _tempTgtGrid] call vtx_uh60_weapons_fnc_getHARMTarget
 */

params ["_projectile", "_projCheckDist", "_tempTgtGrid"];

_sortList = vehicles;   
_checkPos = _tempTgtGrid; 
_missileDirBA = (getDir _projectile) - 180;  
if (_missileDirBA < 0) then {_missileDirBA = _missileDirBA + 360}; //Thanks A3 campaign
_maxDist = _projCheckDist;  
_chosenOne = objNull;
   
//only checks for vehicles that have the radar on, are within max distance, and are looking at the missile
for "_i" from 0 to (count _sortList) do { 
  	_tempPos = (getPosASL (_sortList # _i)); 
  	_dist = _tempPos distance _checkPos; 
  	if (isVehicleRadarOn (_sortList # _i) && _dist <= _maxDist) then { 
		//https://community.bistudio.com/wiki/Arma_3:_Sensors_config_reference   //look for animDirection
		//For sensor direction, if there is no selection name setup, then there is no direction, so align with vehicle body 
			//This only really happens with radars with 360 degree visibility 
		//What's even worse, is the base game only changes the animDirection to = "mainGun"
		//So it's not like this script does much other than cause headache 
		_lookingDir = getDir (_sortList # _i); 
		_selectionName = (getText (configOf (_sortList # _i)) >> "Components" >> "SensorsManagerComponent" >> "Components" >> "ActiveRadarSensorComponent" >> "angleRangeHorizontal");
		if (_selectionName != "") then {
			_lookingDir = [0,0,0] getdir (getCameraViewDirection  (gunner (_sortList # _i)));
		};
 		_radarOffset = getNumber ((configOf (_sortList # _i)) >> "Components" >> "SensorsManagerComponent" >> "Components" >> "ActiveRadarSensorComponent" >> "angleRangeHorizontal");
 		//checks if the back asimuth of the missile is within the radar's range
		if ((_missileDirBA <= (_lookingDir + _radarOffset)) && (_missileDirBA >= (_lookingDir - _radarOffset))) then { 
			_maxDist = _dist; 
			_chosenOne = (_sortList # _i); 
		};
	}; 
};   
_chosenOne
