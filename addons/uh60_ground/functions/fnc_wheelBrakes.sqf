/*
 *
 * vtx_uh60_ground_fnc_wheelBrakes;
 *
 * shitty function that is used to toggle wheelbrake from interaction and/or update wheel brake advisory
 *
 */
private _isEnabled = false;
if (count _this > 2) then {
    params ["_vehicle", "_animation", "_animationTargetLabel", "_animationTarget"];
    private _state = if (_this # 2 == "OFF") then [{0},{1}];
    if (vtx_uh60_ui_showDebugMessages) then {diag_log "brakes exec";};
    _isEnabled = (_this # 2 == "ON");
} else {
    params ["_vehicle"];
    _isEnabled = (_this # 1);
};

if (_isEnabled) then {
    [(_this # 0),"PARKING BRAKE",{},false,false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    [(_this # 0), "PARKING BRAKE"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
};
