/*
 Used to handle which missile to fire, if any.
	[_vehicle, _weapon, _fireMode] call hct_h60_weapons_fnc_commandFireMissile
*/
params ["_vehicle"];

_weapons = weapons _vehicle;

if ("hct_hellfire_launcher" in _weapons) exitWith {driver _vehicle forceWeaponFire ["hct_hellfire_launcher", "hct_hellfire_launcher"];};
if ("hct_hellfire_launcher_N" in _weapons) exitWith {driver _vehicle forceWeaponFire ["hct_hellfire_launcher_N", "hct_hellfire_launcher_N"];};
if ("hct_apkws" in _weapons) exitWith {driver _vehicle forceWeaponFire ["hct_apkws", "Medium_AI"];};
