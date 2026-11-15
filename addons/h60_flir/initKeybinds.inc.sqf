//addUserActionEventHandler ["transportNightVision", "Activate", hct_h60_flir_fnc_keyVisionMode];
addUserActionEventHandler ["vehLockTurretView", "Activate", {
  // "Fullscreen FLIR" for the DRIVER is the vanilla pilot-camera view, which is
  // cameraView "GUNNER" - so the gunner-view guard must let the pilot and the
  // copilot through and block only real door gunners, whose T key keeps its
  // vanilla turret-lock meaning. The mod's scripted camera has its own hooks
  // (fnc_scriptedCamera) - exit here to avoid double-triggering (#538)
  if (
    !hct_h60_flir_controllable
    || {hct_h60_flir_isInScriptedCamera}
    || {cameraView == "GUNNER" && {!(hct_h60_flir_playerIsCopilot || hct_h60_flir_playerIsPilot)}}
  ) exitWith {};
  if (hct_h60_flir_isInScriptedCamera) then {
    [
        AGLToASL positionCameraToWorld [0, 0, 0],
        AGLToASL positionCameraToWorld [0, 0, 5000]
    ] call hct_h60_flir_fnc_setStabilization;
  } else {
    [] call hct_h60_flir_fnc_setStabilization;
  };
}];

// The pilot's fullscreen FLIR is the ENGINE's gunner view, where the vanilla
// lock action also fires and keeps its own toggle state - desynced from the
// mod's script-set locks: on the second press the mod releases while vanilla,
// believing nothing was locked, immediately re-locks natively and snaps the
// camera away (tester report, #559). Consume the key/button at display level
// there and route it through setStabilization only. Mouse buttons appear in
// actionKeys as 65536 + button, same as the scripted-camera hooks (#538)
hct_h60_flir_lastLockPress = 0;
hct_h60_flir_nativeLockFire = {
  if (diag_tickTime > hct_h60_flir_lastLockPress + 0.3) then {
    hct_h60_flir_lastLockPress = diag_tickTime;
    [] call hct_h60_flir_fnc_setStabilization;
  };
};
hct_h60_flir_nativeLockCondition = {
  cameraView == "GUNNER"
  && {!hct_h60_flir_isInScriptedCamera}
  && {missionNamespace getVariable ["hct_h60_flir_controllable", false]}
  && {hct_h60_flir_playerIsPilot}
};
[{!isNull findDisplay 46}, {
  (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["", "_key"];
    if !(call hct_h60_flir_nativeLockCondition) exitWith {false};
    if (_key in (actionKeys "vehLockTurretView")) then {call hct_h60_flir_nativeLockFire; true} else {false};
  }];
  (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["", "_button"];
    if !(call hct_h60_flir_nativeLockCondition) exitWith {false};
    if ((65536 + _button) in (actionKeys "vehLockTurretView")) then {call hct_h60_flir_nativeLockFire; true} else {false};
  }];
}] call CBA_fnc_waitUntilAndExecute;

addUserActionEventHandler ["showMap", "Activate", {
  if (visibleMap || !hct_h60_flir_isInScriptedCamera) exitWith {};
  hct_h60_flir_scriptedCameraToMap = true;
  [false] call hct_h60_flir_fnc_scriptedCamera;
  [{ openMap true; }] call CBA_fnc_execNextFrame;

}];

addUserActionEventHandler ["hideMap", "Activate", {
  if (!visibleMap || hct_h60_flir_isInScriptedCamera || !hct_h60_flir_scriptedCameraToMap) exitWith {};
  hct_h60_flir_scriptedCameraToMap = false;
  openMap false;
  [true] call hct_h60_flir_fnc_scriptedCamera;
}];

[
    "UH-60M Blackhawk","hct_h60_flir_copilotCamera","Copilot Camera", // Control + Right click
    {
      IS_EITHER_PILOT;
      if (
        hct_h60_flir_isVisibleMap ||
        {!hct_h60_flir_controllable} ||
        {!hct_h60_flir_playerIsCopilot} ||
        {hct_h60_flir_featureCamera != ""}
      ) exitWith {false};
      hct_h60_flir_isInScriptedCamera = !hct_h60_flir_isInScriptedCamera;
      [hct_h60_flir_isInScriptedCamera] call hct_h60_flir_fnc_scriptedCamera;
      false
    },{},
    [241, [false, true, false]],false
] call CBA_fnc_addKeybind;

// FLIR Stabilize (Ctrl+T) and FLIR Camera Mode (T) use the base-game keybinds; the CBA keybinds they replaced are gone.
