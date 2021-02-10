/*
 * Author: Ampersand
 * Handle slew, turret move, pilotCamera move, fov sync
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * NOTHING
 *
 * Example:
 * [_heli] call vtx_uh60_flir_fnc_perFrame
 */
//vtx_uh60_flir_fnc_perFrame={
params ["_heli"];

if (
    isNil "vtx_uh60_flir_camera" || {
    (cameraView isEqualTo "EXTERNAL") || {
    visibleMap || {
    !isNull curatorCamera}}}
) exitWith {};

private _isGunnerView = cameraView isEqualTo "GUNNER";
//hintSilent format ["_mouseSlew: %1\n_isGunnerView: %2", "_____", cameraView isEqualTo "GUNNER"];

// fov
if _isGunnerView then {
    private _fov = getObjectFOV _heli;
    if (vtx_uh60_flir_fov != _fov) then {
        vtx_uh60_flir_fov = _fov;
        [_fov] call vtx_uh60_flir_fnc_syncFOV;
    };
};

// get current dir
(getPilotCameraRotation _heli) params ["_azimuth", "_elevation"];

// check key slew
private _inputX = 0;
private _inputY = 0;
private _keySlew = 0 < (vtx_uh60_flir_up + vtx_uh60_flir_down + vtx_uh60_flir_right + vtx_uh60_flir_left);
private _mouseSlew = false; // also used for pilotCamera update
private _isSlewing = _keySlew;

if _keySlew then {
    _inputX = vtx_uh60_flir_right - vtx_uh60_flir_left;
    _inputY = vtx_uh60_flir_up - vtx_uh60_flir_down;
} else {
    // check mouse slew
    //setMousePosition [5,5]; // can't use map while flir is on, also doesn't seem to be needed.
    _inputX = inputAction "AimRight" - inputAction "AimLeft";
    _inputY = inputAction "AimUp" - inputAction "AimDown";
    _mouseSlew = (_inputX != 0 || {_inputY != 0});
    _isSlewing = _mouseSlew && !_isGunnerView && vtx_uh60_flir_slew == 1;
};

// copilot in gunner view
if (
    vtx_uh60_flir_playerIsCopilot && {
    _isGunnerView && {_mouseSlew}}
) exitWith {
    // unlock copilot camera
    if _mouseSlew then {
        _heli lockCameraTo [objNull, [0]];
    };

    private _azimuth = _heli animationSourcePhase "FLIR_DIRECTION";
    private _elevation = _heli animationSourcePhase "FLIR_ELEVATION";
    _heli setPilotCameraRotation [_azimuth, -_elevation];
    private _flirPos = getPilotCameraPosition _heli;
    private _flirPosWorld = _heli modelToWorldVisual _flirPos;
    private _slewDir = (getPilotCameraDirection _heli) vectorMultiply 5000;
    private _position1 = _heli modelToWorldVisual (_flirPos vectorAdd _slewDir);
    private _intersections = lineIntersectsSurfaces [AGLToASL _flirPosWorld, AGLToASL _position1, _heli];
    private _target = objNull;
    if !((_intersections # 0) isEqualTo []) then {
        (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
        _target = _intersectPosASL;
    };
    _heli setPilotCameraTarget _target;
    [_slewDir, _target] call vtx_uh60_flir_fnc_syncPilotCamera;
    [_heli] call vtx_uh60_flir_fnc_updateCamera;
};

private _pilotCameraTarget = (getPilotCameraTarget _heli);

// if copilot in turret, pilotCamera follows copilot turret
if (vtx_uh60_flir_playerIsPilot && {vtx_uh60_flir_isCopilotInGunnerView}) exitWith {
    if _isGunnerView then {
        if _mouseSlew then {
        _heli setPilotCameraTarget (getPilotCameraTarget _heli # 1);
        };
    } else {
        [_heli] call vtx_uh60_flir_fnc_updateCamera;
    };
};

if ( // pilot is moving pilotCamera
    vtx_uh60_flir_playerIsPilot && {_mouseSlew && {_isGunnerView}}
) exitWith {
//systemChat "pilot gunnerview";
    [getPilotCameraDirection _heli, _pilotCameraTarget] call vtx_uh60_flir_fnc_syncPilotCamera;
    [_heli] call vtx_uh60_flir_fnc_animateTurret;
    [_heli] call vtx_uh60_flir_fnc_updateCamera;
};

if _isSlewing then {
    // check if in turret, apply different zoom-based slew speed
    private _rate = ([0.04 * vtx_uh60_flir_AnalogSlewSpeed, 0.08 * vtx_uh60_flir_KeySlewSpeed] select _keySlew) * vtx_uh60_flir_fov;
    // customize x axis speed for better feel
    private _xFactor = 1.5 * ([vtx_uh60_flir_AnalogXFactor, vtx_uh60_flir_KeyXFactor] select _keySlew);

    private _slewX = _rate * _xFactor * _inputX;
    private _slewY = _rate * _inputY;
    _azimuth = _azimuth - _slewX;
    _elevation = _elevation - _slewY;
    _heli setPilotCameraRotation [_azimuth, _elevation];

    if !(_pilotCameraTarget # 0) then { // not tracking
//systemChat format ["free %1", [[_azimuth, _elevation], objNull]];
        [[_azimuth, _elevation], objNull] call vtx_uh60_flir_fnc_syncPilotCamera;

    } else { // tracking
        private _flirPos = getPilotCameraPosition _heli;
        private _flirPosWorld = _heli modelToWorldVisual _flirPos;
        private _slewDir = (getPilotCameraDirection _heli) vectorMultiply 5000;
        private _position1 = _heli modelToWorldVisual (_flirPos vectorAdd _slewDir);
        private _intersections = lineIntersectsSurfaces [AGLToASL _flirPosWorld, AGLToASL _position1, _heli];
        if !((_intersections # 0) isEqualTo []) then {
            (_intersections # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
            _heli setPilotCameraTarget _intersectPosASL;
            [_intersectPosASL] call vtx_uh60_flir_fnc_syncAnimation;
//systemChat format ["tracking %1", [_slewDir, _intersectPosASL]];
            [_slewDir, _intersectPosASL] call vtx_uh60_flir_fnc_syncPilotCamera;
        };
    };

};

[_heli] call vtx_uh60_flir_fnc_animateTurret;
[_heli] call vtx_uh60_flir_fnc_updateCamera;
