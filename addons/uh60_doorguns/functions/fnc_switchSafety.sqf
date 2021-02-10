params ["_vehicle", "_side", "_on"];
private _weapon = if (_side == "l") then [{"vtx_wpn_m134"}, {"vtx_wpn_m134_2nd"}];
private _turret = if (_side == "l") then [{[1]}, {[2]}];
if (_on) then {
    _vehicle removeWeaponTurret [_weapon, _turret];
    _vehicle addWeaponTurret ["vtx_wpn_m134_safe", _turret];
} else {
    _vehicle addWeaponTurret [_weapon, _turret];
    _vehicle removeWeaponTurret ["vtx_wpn_m134_safe", _turret];
    _vehicle loadMagazine [_turret, _weapon, "vtx_2000Rnd_65x39_Belt_Tracer_Red"];
};
