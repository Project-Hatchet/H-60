/*
 * Author: Ampersand
 * Start or stop the the scripted camera
 *
 * The copilot's fullscreen FLIR: the FLIR camera (hct_h60_flir_camera, the same one that
 * feeds the MFDs' picture-in-picture) takes over the main view, with its overlay on a
 * named layer. Stopping hands the camera back to the MFD feed, or destroys it when no
 * MFD shows the FLIR. Safe to call to stop when nothing is running (unit changes, shut
 * down): it then only clears the state.
 *
 * Arguments:
 * 0: Start <BOOLEAN>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [true] call hct_h60_flir_fnc_scriptedCamera
 */
#define OVERLAY_LAYER ("hct_h60_flir_cameraOverlay" call BIS_fnc_rscLayer)

params [["_show", false, [false]]];

if (hct_h60_devMode) then {systemChat format ["SCRIPTED CAMERA %1", ["CLOSE", "OPEN"] select _show];};

if (_show) then {
  if (isNil "hct_h60_flir_camera") then {
    hct_h60_flir_camera = "camera" camCreate [0,0,0];
  };
  // placed now, not on the next frame's fnc_updateCamera: a new camera starts at the map origin
  if (!isNil "hct_vehicle" && {!isNull hct_vehicle}) then {
    [hct_vehicle] call hct_h60_flir_fnc_updateCamera;
  };
  hct_h60_flir_camera cameraEffect ["Internal", "BACK"];
  hct_h60_flir_camera camSetFocus [-1,-1];
  hct_h60_flir_camera camCommit 0;
  // a named layer: a bare layer number (it was 15) is shared with every other mod that picks it
  OVERLAY_LAYER cutRsc ["hct_h60_flir_cameraOverlay", "PLAIN"];
  showCinemaBorder false;

  hct_h60_flir_isInScriptedCamera = true;
  [hct_h60_flir_pipEffect, false] call hct_h60_flir_fnc_setVisionMode;

  // Vanilla user actions do not fire (and inputAction reads 0) while a
  // cameraEffect camera is active, so hook the raw input and map it through
  // the player's actual binding for the lock action. Mouse buttons appear in
  // actionKeys as 65536 + button, so both device paths are needed (#538)
  if (isNil "hct_h60_flir_fullscreenKeyEH") then {
    // (fnc_lockPress debounces this against the per-frame poll in fnc_handleKeyInputs)
    hct_h60_flir_fullscreenLockFire = {
      [
        AGLToASL positionCameraToWorld [0, 0, 0],
        AGLToASL positionCameraToWorld [0, 0, 5000]
      ] call hct_h60_flir_fnc_lockPress;
    };
    hct_h60_flir_fullscreenKeyEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
      params ["", "_key"];
      if (!hct_h60_flir_isInScriptedCamera) exitWith {false};
      if (missionNamespace getVariable ["hct_h60_devMode", false]) then {
        systemChat format ["FS KeyDown %1 (lock keys %2)", _key, actionKeys "vehLockTurretView"];
      };
      if (_key in (actionKeys "vehLockTurretView")) then {call hct_h60_flir_fullscreenLockFire; true} else {false};
    }];
    hct_h60_flir_fullscreenMouseEH = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
      params ["", "_button"];
      if (!hct_h60_flir_isInScriptedCamera) exitWith {false};
      if (missionNamespace getVariable ["hct_h60_devMode", false]) then {
        systemChat format ["FS MouseDown %1 -> %2 (lock keys %3)", _button, 65536 + _button, actionKeys "vehLockTurretView"];
      };
      if ((65536 + _button) in (actionKeys "vehLockTurretView")) then {call hct_h60_flir_fullscreenLockFire; true} else {false};
    }];
    if (missionNamespace getVariable ["hct_h60_devMode", false]) then {
      systemChat format ["FS lock hooks installed: key EH %1, mouse EH %2, lock keys %3",
        hct_h60_flir_fullscreenKeyEH, hct_h60_flir_fullscreenMouseEH, actionKeys "vehLockTurretView"];
    };
  };
} else {
  OVERLAY_LAYER cutText ["", "PLAIN"];

  if (!isNil "hct_h60_flir_camera") then {
    hct_h60_flir_camera cameraEffect ["terminate", "back"];
    if (!isNil "hct_vehicle" && {!isNull hct_vehicle} && {call hct_h60_mfd_fnc_isAnyFlirOpened}) then {
      // back to the MFD feed (else the PiP stays black)
      hct_h60_flir_camera cameraEffect ["internal", "BACK", "hct_h60_flir_feed"];
      "hct_h60_flir_feed" setPiPEffect hct_h60_flir_pipEffect;
    } else {
      camDestroy hct_h60_flir_camera;
      hct_h60_flir_camera = nil;
    };
  };
  // camUseNVG / setCamUseTI are global camera state: leave none behind for the next camera
  camUseNVG false;
  false setCamUseTI 0;

  if (!isNil "hct_h60_flir_fullscreenKeyEH") then {
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", hct_h60_flir_fullscreenKeyEH];
    hct_h60_flir_fullscreenKeyEH = nil;
  };
  if (!isNil "hct_h60_flir_fullscreenMouseEH") then {
    (findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", hct_h60_flir_fullscreenMouseEH];
    hct_h60_flir_fullscreenMouseEH = nil;
  };

  hct_h60_flir_isInScriptedCamera = false;
};
call hct_h60_flir_fnc_setIsPipHidden;

true
