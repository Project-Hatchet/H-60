params ["_vehicle", "_button"];

private _cycleWeapon = {
	params ["_vehicle", "_options"];
	private _turret = _vehicle unitTurret player;
	private _currentIdx = _options find (_vehicle currentWeaponTurret _turret);
	if (_currentIdx == -1) exitWith {
		private _allWeapons = _vehicle weaponsTurret _turret;
		private _common = _allWeapons arrayIntersect _options;
		if (count _common > 0) then {
			_vehicle selectWeaponTurret [_common # 0, _turret];
		};
	};
	private _newIdx = if (_currentIdx < (count _options) - 1) then {_currentIdx + 1} else {0};
	_vehicle selectWeaponTurret [_options # _newIdx, _turret];
};

private _cycleLaserCodes = {
	params ["_vehicle", "_code", "_alt"];
	private _laserCodeIndex = _vehicle ammoOnPylon _code;
	if (_laserCodeIndex == -1) then {_laserCodeIndex = 0};
	private _oldIndex = _laserCodeIndex;
	if (_laserCodeIndex < 5) then {_laserCodeIndex = _laserCodeIndex + 1} else {_laserCodeIndex = 0};
	if (_vehicle ammoOnPylon _alt == _laserCodeIndex) then {
		[_vehicle, _alt, _oldIndex] call vtx_uh60_mfd_fnc_setPylonValue;
	};
	[_vehicle, _code, _laserCodeIndex] call vtx_uh60_mfd_fnc_setPylonValue;
};

switch (_button) do {
	case "LASER": {
		[_vehicle, "Laserdesignator_pilotCamera", "Laserdesignator_pilotCamera"] call vtx_uh60_weapons_fnc_fireAndResetWeapon;
	};
	case "PRI_CHAN": {
		[_vehicle, 42, 43] call _cycleLaserCodes;
	};
	case "ALT_CHAN": {
		[_vehicle, 43, 42] call _cycleLaserCodes;
	};
	case "HF_TRAJ": {
		private _launchMode = _vehicle getvariable ["ace_missileguidance_attackProfile", "hellfire"];
		private _nextMode = switch (_launchMode) do {
			case "hellfire_lo": {"hellfire"};
			case "hellfire": {"hellfire_hi"};
			case "hellfire_hi": {"hellfire_lo"};
		};
		_vehicle setvariable ["ace_missileguidance_attackProfile", _nextMode, true];
	};
	case "SEL_GUN": {
		[_vehicle, ["vtx_chaingun_hedp", "vtx_MH60M_M134_minigun"]] call _cycleWeapon;
	};
	case "SEL_RKT": {
		[_vehicle, ["vtx_dagr", "vtx_apkws", "missiles_DAR"]] call _cycleWeapon;
	};
	case "SEL_MSL": {
		[_vehicle, ["vtx_hellfire_launcher", "vtx_hellfire_launcher_N"]] call _cycleWeapon;
	};
};

[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;