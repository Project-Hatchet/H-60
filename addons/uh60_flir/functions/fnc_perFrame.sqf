#include "script_component.hpp"
// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];

private _inFullScreenCam = (vtx_uh60_flir_isInScriptedCamera || cameraView == "GUNNER");
if (
    _inFullScreenCam &&
    (_vehicle getHitPointDamage "FlirHit") > 0.5
  ) then {
  vtx_uh60_flir_fnc_grain ppEffectEnable true;
} else {
  vtx_uh60_flir_fnc_grain ppEffectEnable false;
};
vtx_uh60_flir_fnc_grain ppEffectCommit 0;

if (!vtx_uh60_flir_isPipHidden || {_inFullScreenCam}) then {
  [_vehicle] call vtx_uh60_flir_fnc_handleKeyInputs;
  [_vehicle] call vtx_uh60_flir_fnc_handleSlew;
};

if (getUserMFDValue _vehicle select USERMFDV_LST_MODE > 0) then {
  _this call vtx_uh60_flir_fnc_laserTrack;
};

private _flirStowed = _vehicle getVariable ["vtx_uh60_flir_stowed", true];
vtx_uh60_flir_blackColor ppEffectEnable (_flirStowed && _inFullScreenCam);
vtx_uh60_flir_blackColor ppEffectCommit 0;
if (_inFullScreenCam && _flirStowed) then {
    hint "Your FLIR payload is stowed, use the MFD to enable your FLIR payload.";
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

if (vtx_uh60_flir_isPipHidden && {!vtx_uh60_flir_isInScriptedCamera}) exitWith {};

[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
_this call vtx_uh60_flir_fnc_updateUIValues;
