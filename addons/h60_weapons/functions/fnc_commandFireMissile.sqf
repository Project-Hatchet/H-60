/*
 Used to handle which missile to fire, if any.
	[_vehicle, _weapon, _fireMode] call vtx_uh60_weapons_fnc_commandFireMissile
*/
params ["_vehicle"];

_weapons = weapons _vehicle;

if ("vtx_hellfire_launcher" in _weapons) exitWith {driver _vehicle forceWeaponFire ["vtx_hellfire_launcher", "vtx_hellfire_launcher"];};
if ("vtx_hellfire_launcher_N" in _weapons) exitWith {driver _vehicle forceWeaponFire ["vtx_hellfire_launcher_N", "vtx_hellfire_launcher_N"];};
if ("vtx_apkws" in _weapons) exitWith {driver _vehicle forceWeaponFire ["vtx_apkws", "Medium_AI"];};
