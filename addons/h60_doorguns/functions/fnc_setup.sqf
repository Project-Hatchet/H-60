/*
 * vtx_uh60_doorguns_fnc_setup
 */

params ["_vehicle"];

vtx_m134_lastFired = cba_missionTime;
vtx_m134_ppEffects = [];
vtx_m134_ppEffectIntensity = 0;
vtx_m134_firedEh = _vehicle addeventhandler ["fired", {_this call vtx_uh60_doorguns_fnc_fired;}];

private _turret = _vehicle unitTurret player;
private _weapon = if (_turret # 0 == 1) then [{"vtx_wpn_m134"}, {"vtx_wpn_m134_2nd"}];
private _animSide = if (_turret # 0 == 1) then [{"Switch_minigun_safe_l"}, {"Switch_minigun_safe_r"}];
if (_vehicle animationPhase _animSide == 0) then {
    _vehicle removeWeaponTurret [_weapon, _turret];
    _vehicle addWeaponTurret ["vtx_wpn_m134_safe", _turret];
};

true
