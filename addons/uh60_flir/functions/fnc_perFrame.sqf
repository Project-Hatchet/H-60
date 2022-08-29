// pilotCamera
// zoomIn, zoomOut
// cameraVisionMode
// AimDown, AimLeft, AimRight, AimUp
// vtx_uh60_flir_fnc_perFrame

params ["_vehicle", "_frameTime"];

if (
    (vtx_uh60_flir_isInScriptedCamera || cameraView == "GUNNER") &&
    (_vehicle getHitPointDamage "FlirHit") > 0.5
  ) then {
  vtx_uh60_flir_fnc_grain ppEffectEnable true;
} else {
  vtx_uh60_flir_fnc_grain ppEffectEnable false;
};
vtx_uh60_flir_fnc_grain ppEffectCommit 0;

if (!vtx_uh60_flir_isPipHidden || {vtx_uh60_flir_isInScriptedCamera} || {cameraView == "GUNNER"}) then {
  [_vehicle] call vtx_uh60_flir_fnc_handleKeyInputs;
  [_vehicle] call vtx_uh60_flir_fnc_handleSlew;
};

if (_vehicle ammoOnPylon 47 > 0) then {
  _this call vtx_uh60_flir_fnc_laserTrack;
};

private _bootTime = _vehicle getVariable ["vtx_uh60_flir_boot_time", -1];
if (_bootTime > -1) then {
  private _timeRemaining = (_bootTime + 25) - cba_missionTime;
  if (_timeRemaining > 0) then {
    private _slewProgress = _timeRemaining / 5;
    systemChat str ["DEPLOYING", _timeRemaining, _slewProgress];
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
