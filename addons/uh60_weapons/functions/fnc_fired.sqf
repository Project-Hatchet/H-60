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

//spaggetti code:  Mix of Yax's ITC Air APKs and HARM Guidance by Donov
if (_ammo == "vtx_ammo_Missile_HARM_HL" && vehicle _gunner == _vehicle) then {
	_index = 0;	//reset index to enter while loop
	while {_index < 4} do {
		if ((getPylonMagazines _vehicle # _index) == "PylonMissile_Missile_HARM_x1_HL") then {
			if (_vehicle ammoOnPylon (_index + 1) == 0) then { _vehicle setPylonLoadout [(_index + 1), "", true]; /*systemChat "Reset Pylon"*/};
			//This loop checks for which HARM was fired, and replaces the pylon with nothing.  It removes the missile
		};
		_index = _index + 1;  //python be like
	};
	[_projectile, _ammo] call vtx_uh60_weapons_fnc_HARMGuidance; 

};