#include "script_component.hpp"
// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];

private _inFullScreenCam = (vtx_uh60_flir_isInScriptedCamera || cameraView == "GUNNER");
// post-process effects are switched only when their state changes
private _grainOn = _inFullScreenCam && {(_vehicle getHitPointDamage "FlirHit") > 0.5};
if (isNil "vtx_uh60_flir_grainOn" || {vtx_uh60_flir_grainOn isNotEqualTo _grainOn}) then {
  vtx_uh60_flir_grainOn = _grainOn;
  vtx_uh60_flir_fnc_grain ppEffectEnable _grainOn;
  vtx_uh60_flir_fnc_grain ppEffectCommit 0;
};

if (!vtx_uh60_flir_isPipHidden || {_inFullScreenCam}) then {
  [_vehicle] call vtx_uh60_flir_fnc_handleKeyInputs;
  [_vehicle] call vtx_uh60_flir_fnc_handleSlew;
};

if (getUserMFDValue _vehicle select USERMFDV_LST_MODE > 0) then {
  _this call vtx_uh60_flir_fnc_laserTrack;
};

private _flirStowed = _vehicle getVariable ["vtx_uh60_flir_stowed", true];
private _blackOn = _flirStowed && _inFullScreenCam;
if (isNil "vtx_uh60_flir_blackOn" || {vtx_uh60_flir_blackOn isNotEqualTo _blackOn}) then {
  vtx_uh60_flir_blackOn = _blackOn;
  vtx_uh60_flir_blackColor ppEffectEnable _blackOn;
  vtx_uh60_flir_blackColor ppEffectCommit 0;
};
// tell the player once per entry into stowed fullscreen (was a hint every frame)
if (_blackOn) then {
  if !(missionNamespace getVariable ["vtx_uh60_flir_stowedHintShown", false]) then {
    vtx_uh60_flir_stowedHintShown = true;
    hint "Your FLIR payload is stowed, use the MFD to enable your FLIR payload.";
  };
} else {
  vtx_uh60_flir_stowedHintShown = false;
};

if (_vehicle getVariable ["vtx_uh60_flir_stowed", true]) then {
    _vehicle setPilotCameraTarget objNull;
    _vehicle setPilotCameraRotation [
      rad (180),
      rad (80)
    ];
};

private _bootTime = _vehicle getVariable ["vtx_uh60_flir_boot_time", -1];
if (_bootTime > -1) then {
  private _timeRemaining = (_bootTime + 25) - cba_missionTime;
  if (_timeRemaining > 0) then {
    private _slewProgress = _timeRemaining / 5;
    // systemChat str ["DEPLOYING", _timeRemaining, _slewProgress];
    _vehicle setPilotCameraTarget objNull;
    _vehicle setPilotCameraRotation [
      rad (_slewProgress * 180),
      rad (0)
    ];
  };
};

// Skip the camera/overlay updates only when NO FLIR view is on screen.
if (vtx_uh60_flir_isPipHidden && {!_inFullScreenCam}) exitWith {};

[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
_this call vtx_uh60_flir_fnc_updateUIValues;

