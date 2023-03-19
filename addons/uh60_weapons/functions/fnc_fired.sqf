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
};