/*
 * hct_h60_doorguns_fnc_coverSwitch
 *
 * Door-gun safety cover: lifting it uncovers the master switch; closing it also switches the gun to SAFE.
 *
 * params [(object) vehicle, (bool) cover up, (string) side "l"|"r"]
 */

params ["_vehicle", "_up", "_side"];
if (_up) then {
    _vehicle animateSource ["Switch_minigun_safe_cover_" + _side, 1, true];
} else {
    _vehicle animateSource ["Switch_minigun_safe_cover_" + _side, 0, true];
    _vehicle animateSource ["Switch_minigun_safe_" + _side, 0, true];
    [_vehicle, _side, true] call hct_h60_doorguns_fnc_switchSafety;
};
