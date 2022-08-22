params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
if (player == _gunner && local _gunner) then {
	private _vehicle = vehicle player;
	addCamShake [3, 1, 25];
	vtx_uh60_hellfire_lastLaunchTime = cba_missionTime;
	[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;

	private _targetPoint = ([_vehicle] call vtx_uh60_weapons_fnc_isLOBL) # 1;
	if (!(_targetPoint isEqualTo [0,0,0])) then {
		vtx_uh60_hellfire_currentTof = ceil ((_vehicle distance _targetPoint) / 250);
	};
};