params ["_vehicle", "_on", "_side"];
if (_on) then {
    _vehicle animateSource ["Switch_minigun_safe_" + _side, 1, true];
    [_vehicle, _side, false] call vtx_uh60_doorguns_fnc_switchSafety;
} else {
    _vehicle animateSource ["Switch_minigun_safe_" + _side, 0, true];
    [_vehicle, _side, true] call vtx_uh60_doorguns_fnc_switchSafety;
};
