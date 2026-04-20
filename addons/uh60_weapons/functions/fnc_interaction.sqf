#include "script_component.hpp"
params ["_vehicle", "_button", "_var"];

private _cycleWeapon = {
	params ["_vehicle", "_options"];
	private _turret = _vehicle unitTurret hct_player;
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
	//private _laserCodeIndex = _vehicle ammoOnPylon _code;
  private _laserCodeIndex = getUserMFDValue _vehicle select _code;
	if (_laserCodeIndex == -1) then {_laserCodeIndex = 0};
	private _oldIndex = _laserCodeIndex;
  if (_laserCodeIndex < 5) then {_laserCodeIndex = _laserCodeIndex + 1} else {_laserCodeIndex = 0};

	//if (_vehicle ammoOnPylon _alt == _laserCodeIndex) then {[_vehicle, _alt, _oldIndex] call vtx_uh60_mfd_fnc_setPylonValue;	};
  if (getUserMFDValue _vehicle select _alt == _laserCodeIndex) then {_vehicle setUserMFDValue [_alt, _oldIndex]};

	//[_vehicle, _code, _laserCodeIndex] call vtx_uh60_mfd_fnc_setPylonValue;
  _vehicle setUserMFDValue [_code, _laserCodeIndex];
};

private _stationAssign = {
	params ["_vehicle", "_pylon", "_targetOwner"];
	private _pylon = switch (_pylon) do {
		case "LIB": {1};
		case "RIB": {2};
		case "LOB": {3};
		case "ROB": {4};
		default {-1};
	};
	if (_pylon == -1) exitWith {};
	private _turret = [[0], [-1]] select (_targetOwner == "pilot");
  (getAllPylonsInfo _vehicle) # (_pylon - 1) params ["", "", "_currentTurret", "_magazine", "_ammo"];
  if (_currentTurret isEqualTo _turret) exitWith {};
  if (_turret isEqualTo [-1]) then {_turret = []};
  [_vehicle, objNull, _turret, 1, _magazine, _ammo, _pylon] call ace_rearm_fnc_rearmSuccess;
};

switch (_button) do {
	case "LASER": {
		[_vehicle, "Laserdesignator_pilotCamera", "Laserdesignator_pilotCamera"] call vtx_uh60_weapons_fnc_fireAndResetWeapon;
	};
	case "PRI_CHAN": {
		[_vehicle, USERMFDV_PRI_CH, USERMFDV_ALT_CH] call _cycleLaserCodes;
	};
	case "ALT_CHAN": {
		[_vehicle, USERMFDV_ALT_CH, USERMFDV_PRI_CH] call _cycleLaserCodes;
	};
	case "HF_TRAJ": {
		private _launchMode = _vehicle getVariable ["ace_missileguidance_attackProfile", "hellfire"];
		private _nextMode = switch (_launchMode) do {
			case "hellfire_lo": {"hellfire"};
			case "hellfire": {"hellfire_hi"};
			case "hellfire_hi": {"hellfire_lo"};
		};
		_vehicle setVariable ["ace_missileguidance_attackProfile", _nextMode, true];
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
	case "RIB": {_this call _stationAssign};
	case "ROB": {_this call _stationAssign};
	case "LIB": {_this call _stationAssign};
	case "LOB": {_this call _stationAssign};
};

[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;
