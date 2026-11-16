/*
 * hct_h60_doorguns_fnc_switchSafety
 *
 * Swaps a door gun between the live weapon and the SAFE dummy weapon on its turret.
 *
 * params [(object) vehicle, (string) side "l"|"r", (bool) safe]
 */

params ["_vehicle", "_side", "_on"];
private _weapon = if (_side == "l") then [{"hct_wpn_m134"}, {"hct_wpn_m134_2nd"}];
private _turret = if (_side == "l") then [{[1]}, {[2]}];
if (_on) then {
    _vehicle removeWeaponTurret [_weapon, _turret];
    _vehicle addWeaponTurret ["hct_wpn_m134_safe", _turret];
} else {
    _vehicle addWeaponTurret [_weapon, _turret];
    _vehicle removeWeaponTurret ["hct_wpn_m134_safe", _turret];
    _vehicle loadMagazine [_turret, _weapon, "hct_2000Rnd_65x39_Belt_Tracer_Red"];
};
