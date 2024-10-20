/*
 * Author: Ampersand
 * Handle slew, turret move, pilotCamera move, fov sync
 * Priority: Copilot in gunner view > pilot in gunner view > MFD slew
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * NOTHING
 *
 * Example:
 * [_vehicle] call vtx_uh60_flir_fnc_handleSlew
 */

params ["_vehicle"];

private _isGunnerView = cameraView isEqualTo "GUNNER";
//hintSilent format ["_mouseSlew: %1\n_isGunnerView: %2", "_____", cameraView isEqualTo "GUNNER"];

// fov
if (_isGunnerView) then {
    private _fov = getObjectFOV _vehicle;
    if (vtx_uh60_flir_FOV != _fov) then {
        vtx_uh60_flir_FOV = _fov;
        [_fov] call vtx_uh60_flir_fnc_setFOV;
    };
};

// get current dir
(getPilotCameraRotation _vehicle) params ["_azimuth", "_elevation"];

// check key slew
private _inputX = 0;
private _inputY = 0;
private _keySlew = 0 < (vtx_uh60_flir_up + vtx_uh60_flir_down + vtx_uh60_flir_right + vtx_uh60_flir_left);
private _mouseSlew = false; // also used for pilotCamera update

if _keySlew then {
    _inputX = vtx_uh60_flir_right - vtx_uh60_flir_left;
    _inputY = vtx_uh60_flir_up - vtx_uh60_flir_down;
} else {
    // check mouse slew
    //setMousePosition [5,5]; // can't use map while flir is on, also doesn't seem to be needed.
    _inputX = inputAction "AimRight" - inputAction "AimLeft";
    _inputY = inputAction "AimUp" - inputAction "AimDown";
    _mouseSlew = (_inputX != 0 || {_inputY != 0});
};
vtx_uh60_flir_isSlewing = _keySlew || {vtx_uh60_flir_isInScriptedCamera && {_mouseSlew}} || {vtx_uh60_flir_slewAim && {_mouseSlew}} || {_isGunnerView && {_mouseSlew}};

if (vtx_uh60_flir_isSlewing) then {
    // systemchat str[ "SLEWING", time];
    private _originPos = _vehicle modelToWorldVisualWorld (getPilotCameraPosition _vehicle);
    private _cameraVectorWorld = _vehicle vectorModelToWorld (getPilotCameraDirection _vehicle);
    private _rateY = ([0.04 * vtx_uh60_flir_setting_AimSlewSpeed, 0.08 * vtx_uh60_flir_setting_KeySlewSpeed] select _keySlew) * (vtx_uh60_flir_FOV * 50);
    private _rateX = vtx_uh60_flir_aspectRatio * ([vtx_uh60_flir_setting_AimXFactor, vtx_uh60_flir_setting_KeyXFactor] select _keySlew);
    if (getPilotCameraTarget _vehicle # 0) then {
        _cameraVectorWorld = (_originPos vectorFromTo (getPilotCameraTarget _vehicle # 1));
        private _slewOrigin = (_cameraVectorWorld) call CBA_fnc_vect2Polar;
        private _newDir = [
            (_slewOrigin # 1) + (_inputX * _rateY),
            (_slewOrigin # 2) + (_inputY * _rateY)
        ];

        private _intersect = [_originPos, _newDir # 0, _newDir # 1] call vtx_uh60_flir_fnc_intersectAtPolar;
        if (!isNil "_intersect") then {
            if (!_isGunnerView) then {_vehicle setPilotCameraTarget _intersect};
            [getPilotCameraDirection _vehicle, getPilotCameraTarget _vehicle # 1] call vtx_uh60_flir_fnc_syncPilotCamera;
        } else {
            if (!_isGunnerView) then {_vehicle setPilotCameraTarget objNull};
            [getPilotCameraDirection _vehicle, objNull] call vtx_uh60_flir_fnc_syncPilotCamera;
        };
    } else {
        private _newDirectionVector = (getPilotCameraRotation _vehicle) vectorAdd [
            rad (_inputX * _rateY) * -1,
            rad (_inputY * _rateY) * -1
        ];
        _vehicle setPilotCameraRotation [_newDirectionVector # 0, _newDirectionVector # 1];
        [getPilotCameraDirection _vehicle, objNull] call vtx_uh60_flir_fnc_syncPilotCamera;
    };
};
