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

// Active follow: a target set while already inside the gunner view / scripted
// camera is not steered by the engine, so aim the pilot camera at the tracked
// object ourselves every frame. NOTE: the engine's getPilotCameraTarget does
// NOT return the object - the mod patches it into element 2 of its own state
// variable in fnc_syncPilotCamera, which is the only valid source (#538)
private _trackedObj = vtx_uh60_flir_pilotCameraTarget param [2, objNull];
if (!isNull _trackedObj) then {
  private _trackOrigin = _vehicle modelToWorldVisualWorld (getPilotCameraPosition _vehicle);
  _vehicle setPilotCameraDirection (_vehicle vectorWorldToModelVisual (_trackOrigin vectorFromTo getPosASLVisual _trackedObj));
};

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
//systemchat str ["SLEWING", time];
    private _originPos = _vehicle modelToWorldVisualWorld (getPilotCameraPosition _vehicle);
    private _cameraVectorWorld = _vehicle vectorModelToWorld (getPilotCameraDirection _vehicle);
    private _rateY = ([0.04 * vtx_uh60_flir_setting_AimSlewSpeed, 0.08 * vtx_uh60_flir_setting_KeySlewSpeed] select _keySlew) * (vtx_uh60_flir_FOV * 50);
    private _rateX = vtx_uh60_flir_aspectRatio * ([vtx_uh60_flir_setting_AimXFactor, vtx_uh60_flir_setting_KeyXFactor] select _keySlew);
    if (getPilotCameraTarget _vehicle # 0) then {

        // Object track: in gunner view / scripted camera every mouselook twitch
        // registers as slew, and retargeting here replaced the object lock with
        // a ground position each frame - the camera never followed. Only
        // deliberate key slew (or pressing lock again) may break a follow.
        // Tracked object must come from the mod's own state variable - the
        // engine's getPilotCameraTarget does not expose it (#538)
        if (!isNull (vtx_uh60_flir_pilotCameraTarget param [2, objNull]) && {!_keySlew}) exitWith {};

        _cameraVectorWorld = (_originPos vectorFromTo (getPilotCameraTarget _vehicle # 1));
        private _slewOrigin = (_cameraVectorWorld) call CBA_fnc_vect2Polar;
        private _newDir = [
            (_slewOrigin # 1) + (_inputX * _rateY),
            (_slewOrigin # 2) + (_inputY * _rateY)
        ];

        private _intersectResult = [_originPos, _newDir # 0, _newDir # 1] call vtx_uh60_flir_fnc_intersectAtPolar;
        if (!isNil "_intersectResult") then {
            private _intersect = _intersectResult # 0; // slew stays a position lock; object tracking is setStabilization's job
            if (!_isGunnerView || vtx_uh60_flir_playerIsCopilot) then {_vehicle setPilotCameraTarget _intersect};
            [getPilotCameraDirection _vehicle, getPilotCameraTarget _vehicle # 1] call vtx_uh60_flir_fnc_syncPilotCamera;
        } else {
            if (!_isGunnerView || vtx_uh60_flir_playerIsCopilot) then {_vehicle setPilotCameraTarget objNull};
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
// (turret-optics animation sync removed with the Use Scripted Camera setting -
// the copilot optics mode is disabled until the model gains a View - Gunner
// LOD, #560; restore both together with the optics)
