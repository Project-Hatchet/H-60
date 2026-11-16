/*
 * hct_h60_doorguns_fnc_setup
 */

params ["_vehicle"];

hct_m134_lastFired = cba_missionTime;
hct_m134_ppEffectIntensity = 0;
if (isNil "hct_m134_blurWatching") then { hct_m134_blurWatching = false; };

// one Fired handler per vehicle: replace any left by a setup without a shutdown
// (the id used to sit in a single mission global and the old handler leaked)
private _oldEH = _vehicle getVariable ["hct_h60_doorguns_firedEH", -1];
if (_oldEH != -1) then { _vehicle removeEventHandler ["Fired", _oldEH]; };
_vehicle setVariable ["hct_h60_doorguns_firedEH", _vehicle addEventHandler ["Fired", {_this call hct_h60_doorguns_fnc_fired;}]];

private _turret = _vehicle unitTurret player;
if (_turret isEqualTo []) exitWith {true}; // not in a turret seat: no gun to safe
private _weapon = if (_turret # 0 == 1) then [{"hct_wpn_m134"}, {"hct_wpn_m134_2nd"}];
private _animSide = if (_turret # 0 == 1) then [{"Switch_minigun_safe_l"}, {"Switch_minigun_safe_r"}];
if (_vehicle animationPhase _animSide == 0) then {
    _vehicle removeWeaponTurret [_weapon, _turret];
    _vehicle addWeaponTurret ["hct_wpn_m134_safe", _turret];
};

true
