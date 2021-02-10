params ["_vehicle", "_up", "_side"];
if (_up) then {
    _vehicle animateSource ["Switch_minigun_safe_cover_" + _side, 1, true];
} else {
    _vehicle animateSource ["Switch_minigun_safe_cover_" + _side, 0, true];
    _vehicle animateSource ["Switch_minigun_safe_" + _side, 0, true];
    [_vehicle, _side, true] call vtx_uh60_doorguns_fnc_switchSafety;
};
