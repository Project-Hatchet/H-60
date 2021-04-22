/*
 *
 * vtx_uh60_engine_fnc_wheelBrakes;
 *
 * shitty function that is used to toggle wheelbrake from interaction and/or update wheel brake advisory
 *
 */
private _isEnabled = false;
if (count _this > 2) then {
    params ["_vehicle", "_animation", "_animationTargetLabel", "_animationTarget"];
    private _state = if (_this # 2 == "OFF") then [{0},{1}];
    [_vehicle, [_state, 3]] remoteExec ["setBrakesRTD", _vehicle]; diag_log "brakes exec";
    _isEnabled = (_this # 2 == "ON");
} else {
    params ["_vehicle"];
    _isEnabled = (_this # 1);
};

if (_isEnabled) then {
    [(_this # 0),"PARKING BRAKE",{
        (((_this # 0) animationPhase "handle_wheelbrake") < 0.5)
    },false,true] call vtx_uh60_cas_fnc_registerCautionAdvisory;
} else {
    [(_this # 0), "PARKING BRAKE"] call vtx_uh60_cas_fnc_removeCautionAdvisory;
};
