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
vtx_uh60_flir_isSlewing = _keySlew || {vtx_uh60_flir_isInScriptedCamera && {_mouseSlew}} || {vtx_uh60_flir_slewAim && {_mouseSlew} && {!_isGunnerView}};

// Player is copilot in gunner view
if (
    vtx_uh60_flir_playerIsCopilot && {
    _isGunnerView && {_mouseSlew}}
) exitWith {
    // unlock copilot camera
    if _mouseSlew then {
        _vehicle lockCameraTo [objNull, [0]];
    };

    private _azimuth = _vehicle animationSourcePhase "FLIR_DIRECTION";
    private _elevation = _vehicle animationSourcePhase "FLIR_ELEVATION";
    _vehicle setPilotCameraRotation [_azimuth, -_elevation];
    private _flirPosWorld = _vehicle modelToWorldVisualWorld vtx_uh60_flir_camPos;
    private _slewDir = (getPilotCameraDirection _vehicle) vectorMultiply 5000;
    private _position1 = _vehicle modelToWorldVisual (vtx_uh60_flir_camPos vectorAdd _slewDir);
    private _intersections = lineIntersectsSurfaces [_flirPosWorld, AGLToASL _position1, _vehicle];
    private _target = objNull;
    if !((_intersections # 0) isEqualTo []) then {
        (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
        _target = _intersectPosASL;
    };
    _vehicle setPilotCameraTarget _target;
    [_slewDir, _target] call vtx_uh60_flir_fnc_syncPilotCamera;
    //[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
};

private _pilotCameraTarget = (getPilotCameraTarget _vehicle);

// if copilot in turret, pilotCamera follows copilot turret
if (vtx_uh60_flir_playerIsPilot && {vtx_uh60_flir_isCopilotInGunnerView}) exitWith {
    if _isGunnerView then {
        if _mouseSlew then {
        _vehicle setPilotCameraTarget (getPilotCameraTarget _vehicle # 1);
        };
    } else {
        //[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
    };
};

if ( // pilot is moving pilotCamera
    vtx_uh60_flir_playerIsPilot && {_mouseSlew && {_isGunnerView}}
) exitWith {
//systemChat "pilot gunnerview";
    [getPilotCameraDirection _vehicle, _pilotCameraTarget] call vtx_uh60_flir_fnc_syncPilotCamera;
    //[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
};

if (vtx_uh60_flir_isSlewing) then {
    // check if in turret, apply different zoom-based slew speed
    private _rate = ([0.04 * vtx_uh60_flir_setting_AimSlewSpeed, 0.08 * vtx_uh60_flir_setting_KeySlewSpeed] select _keySlew) * vtx_uh60_flir_FOV;
    // customize x axis speed for better feel
    private _xFactor = vtx_uh60_flir_aspectRatio * ([vtx_uh60_flir_setting_AimXFactor, vtx_uh60_flir_setting_KeyXFactor] select _keySlew);

    private _slewX = _rate * _xFactor * _inputX;
    private _slewY = _rate * _inputY;
    _azimuth = _azimuth - _slewX;
    if (-pi < vtx_uh60_flir_minTurn || {vtx_uh60_flir_maxTurn < pi}) then {
      _azimuth = vtx_uh60_flir_minTurn max _azimuth min vtx_uh60_flir_maxTurn;
    };
    _elevation = _elevation - _slewY;
    if (-pi < vtx_uh60_flir_minElev || {vtx_uh60_flir_maxElev < pi}) then {
      _elevation = vtx_uh60_flir_minElev max _elevation min vtx_uh60_flir_maxElev;
    };
    _vehicle setPilotCameraRotation [_azimuth, _elevation];

    if !(_pilotCameraTarget # 0) then { // not tracking
//systemChat format ["free %1", [[_azimuth, _elevation], objNull]];
      [[_azimuth, _elevation], objNull] call vtx_uh60_flir_fnc_syncPilotCamera;

    } else { // tracking
        private _flirPosWorld = _vehicle modelToWorldVisualWorld vtx_uh60_flir_camPos;
        private _slewDir = (getPilotCameraDirection _vehicle) vectorMultiply worldSize;
        private _position1 = _vehicle modelToWorldVisual (vtx_uh60_flir_camPos vectorAdd _slewDir);
        private _intersections = lineIntersectsSurfaces [_flirPosWorld, AGLToASL _position1, _vehicle];
        if (_intersections isEqualTo []) then {
            private _target = terrainIntersectAtASL [_flirPosWorld, _position1];
            if (_target isEqualTo [0,0,0]) then {
                _target = _position1;
            };
            _vehicle setPilotCameraTarget _target;
            [_slewDir, _intersectPosASL] call vtx_uh60_flir_fnc_syncPilotCamera;
        } else {
            (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
            _vehicle setPilotCameraTarget _intersectPosASL;
//systemChat format ["tracking %1", [_slewDir, _intersectPosASL]];
            [_slewDir, _intersectPosASL] call vtx_uh60_flir_fnc_syncPilotCamera;
        };
    };

};
