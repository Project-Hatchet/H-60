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

// fov
if (_isGunnerView) then {
    private _fov = getObjectFOV _vehicle;
    if (vtx_uh60_flir_FOV != _fov) then {
        vtx_uh60_flir_FOV = _fov;
        [_fov] call vtx_uh60_flir_fnc_setFOV;
    };
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
    _inputX = inputAction "AimRight" - inputAction "AimLeft";
    _inputY = inputAction "AimUp" - inputAction "AimDown";
    _mouseSlew = (_inputX != 0 || {_inputY != 0});
};
vtx_uh60_flir_isSlewing = _keySlew || {vtx_uh60_flir_isInScriptedCamera && {_mouseSlew}} || {vtx_uh60_flir_slewAim && {_mouseSlew}} || {_isGunnerView && {_mouseSlew}};

// Deliberate FLIR movement: key slew always counts; mouse only above a small
// deadzone so an accidental mouselook twitch cannot demote a vehicle follow
private _hasSlewInput = vtx_uh60_flir_isSlewing && {_keySlew || {(abs _inputX + abs _inputY) > 5}}; // 5 Is when you can notice some sort of deadzoning.

// Tracking state machine (per design spec):
//   FREE    - camera moves freely
//   GEOLOCK - holds a ground point; slew input DRAGS the point, which stays
//             locked where the user leaves it
//   FOLLOW  - tracks a live vehicle; slew input demotes to GEOLOCK at the
//             current aim; the lock key releases (fnc_setStabilization)
// NOTE: the engine's getPilotCameraTarget does NOT return the object - the mod
// patches it into element 2 of its own state variable in fnc_syncPilotCamera,
// which is the only valid source (#538)
private _trackedObj = vtx_uh60_flir_pilotCameraTarget param [2, objNull];
private _inNativeGunnerView = _isGunnerView && {!vtx_uh60_flir_isInScriptedCamera};

// FOLLOW + deliberate input -> GEOLOCK at the point the camera is looking at
// (the followed vehicle's current position); the slew block below then drags it
if (!isNull _trackedObj && {_hasSlewInput}) then {
  private _aimPos = getPosASLVisual _trackedObj;
  _vehicle setPilotCameraTarget _aimPos;
  [[], _aimPos] call vtx_uh60_flir_fnc_syncPilotCamera;
  _trackedObj = objNull;
};

// Enforcement while NOT receiving deliberate input. The native gunner view
// (the pilot's fullscreen) renders the ENGINE camera, which neither steers
// script-set locks nor honors setPilotCameraDirection while a target is
// assigned - re-asserting the target every frame turns the engine's one-time
// snap into a follow/hold. Every copilot view renders the mod camera, which
// fnc_updateCamera aims each frame.
if (!_hasSlewInput) then {
  if (!isNull _trackedObj) then {
    if (_inNativeGunnerView) then {
      _vehicle setPilotCameraTarget _trackedObj;
    } else {
      private _trackOrigin = _vehicle modelToWorldVisualWorld (getPilotCameraPosition _vehicle);
      _vehicle setPilotCameraDirection (_vehicle vectorWorldToModelVisual (_trackOrigin vectorFromTo getPosASLVisual _trackedObj));
    };
  } else {
    if (_inNativeGunnerView) then {
      if (vtx_uh60_flir_pilotCameraTarget param [0, false]) then {
        // Held ground point: re-assert the position captured at lock time (or
        // by the last drag) from the mod's own state. Re-asserting the
        // engine's live readback compounded a get/set frame-of-reference
        // offset every frame and the point drifted away
        _vehicle setPilotCameraTarget (vtx_uh60_flir_pilotCameraTarget param [1, [0,0,0]]);
      } else {
        // Mod state is authoritative: the VANILLA lock action fires on any
        // input device with its own desynced toggle state - stomp any rogue
        // engine lock it set, restoring the direction our own release chose
        // if the rogue lock snapped the camera within the same press
        if ((getPilotCameraTarget _vehicle) # 0) then {
          _vehicle setPilotCameraTarget objNull;
          if (diag_tickTime < (missionNamespace getVariable ["vtx_uh60_flir_lastReleaseTime", -99]) + 1) then {
            _vehicle setPilotCameraDirection vtx_uh60_flir_lastReleaseDir;
          };
        };
      };
    };
  };
};

if (vtx_uh60_flir_isSlewing) then {
    private _originPos = _vehicle modelToWorldVisualWorld (getPilotCameraPosition _vehicle);
    private _cameraVectorWorld = _vehicle vectorModelToWorld (getPilotCameraDirection _vehicle);
    private _rateY = ([0.04 * vtx_uh60_flir_setting_AimSlewSpeed, 0.08 * vtx_uh60_flir_setting_KeySlewSpeed] select _keySlew) * (vtx_uh60_flir_FOV * 50);
    private _rateX = vtx_uh60_flir_aspectRatio * ([vtx_uh60_flir_setting_AimXFactor, vtx_uh60_flir_setting_KeyXFactor] select _keySlew);
    if (getPilotCameraTarget _vehicle # 0) then {

        // Sub-deadzone mouselook twitch while following: keep the follow.
        // Deliberate input was already demoted to GEOLOCK above (#538)
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
            // GEOLOCK drag re-targets in EVERY view: the native gunner view is
            // safe now that the mod's state is authoritative there (it was
            // excluded before, which is why the pilot could not move a held
            // point without unlocking first - tester report)
            _vehicle setPilotCameraTarget _intersect;
            [getPilotCameraDirection _vehicle, _intersect] call vtx_uh60_flir_fnc_syncPilotCamera;
        } else {
            _vehicle setPilotCameraTarget objNull;
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
