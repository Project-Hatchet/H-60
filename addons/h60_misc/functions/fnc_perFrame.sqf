/*
 * vtx_uh60_misc_fnc_perFrame
 */

params ["_vehicle", "_frameTime"];

if (!local _vehicle) exitWith {};

if (inputAction "headlights" > 0 && !vtx_uh60_misc_btn_hold) then {
    vtx_uh60_misc_btn_hold = true;
    // next frame, as the old spawn+sleep did - without a script per key press
    [vtx_uh60_misc_fnc_toggleLights, [_vehicle, "landing"]] call CBA_fnc_execNextFrame;
} else {
    if (inputAction "headlights" == 0) then {
        vtx_uh60_misc_btn_hold = false;
    };
};

private _attachedBoat = _vehicle getVariable ["vtx_crrc_attached", nil];
if (!isNil "_attachedBoat") then {
    if (!isNull (getSlingLoad _vehicle)) then {
        _vehicle setSlingLoad objNull;
    };
    if (inputAction "HeliRopeAction" > 0 && (_vehicle getVariable ["bmkhs_radAlt", 0]) > 2) then {
        _attachedBoat attachTo [_vehicle, [0,1.5,-1.5]];
        detach _attachedBoat;
        _attachedBoat lock false;
        _attachedBoat setVelocity (_vehicle getVariable ["bmkhs_velWorldSpaceNoWind", velocity _vehicle]);
        _vehicle setVariable ["vtx_crrc_attached", nil, true];
        _attachedBoat enableRopeAttach true;
    };
};
