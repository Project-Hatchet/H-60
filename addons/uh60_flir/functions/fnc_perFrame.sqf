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

if (vtx_uh60_flir_isPipHidden && {!vtx_uh60_flir_isInScriptedCamera}) exitWith {};

[_vehicle] call vtx_uh60_flir_fnc_updateCamera;
_this call vtx_uh60_flir_fnc_updateUIValues;
