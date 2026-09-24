params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
if (vtx_uh60_ui_showDebugMessages) then {systemchat "HELLFIRE LAUNCHED";};

private _vehicle = vehicle player;
if (vehicle _gunner == _vehicle) then {
	addCamShake [3, 1, 25];
	_vehicle setVariable ["vtx_uh60_hellfire_lastLaunchTime", cba_missionTime, true];

	private _targetPoint = ([_vehicle] call vtx_uh60_weapons_fnc_isLOBL) # 1;
	if (!(_targetPoint isEqualTo [0,0,0])) then {
		_vehicle setVariable ["vtx_uh60_hellfire_impactTime", cba_missionTime + ceil ((_vehicle distance _targetPoint) / 250), true];
	};
};
if (_ammo == "VTX_Hellfire_AGM114K" || _ammo == "VTX_Hellfire_AGM114N") then {
	_this call vtx_uh60_weapons_fnc_hellfireGuidanceInit;
};

if (player == _gunner && local _gunner) then {
	[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;
};
