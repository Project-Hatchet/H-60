/*
 * Author: Ampersand
 * Handle inputs for Zoom and Vision Mode while in scripted camera
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [] call hct_h60_flir_fnc_handleKeyInputs
 */

// PIP Vision Mode
private _visionMode = inputAction "transportNightVision";
if (_visionMode > 0) then {
  if (hct_h60_flir_transportNightVision == 0) then {
    hct_h60_flir_transportNightVision = ceil _visionMode;
    [] call hct_h60_flir_fnc_keyVisionMode;
  };
} else {
  hct_h60_flir_transportNightVision = 0;
};

if (!hct_h60_flir_controllable) exitWith {};

// Stabilize/lock in the scripted camera must be POLLED: vanilla user action
// events do not fire while a cameraEffect camera is active (the cockpit/optics
// path keeps the addUserActionEventHandler in initKeybinds.sqf) (#538)
if (hct_h60_flir_isInScriptedCamera) then {
  private _stab = inputAction "vehLockTurretView";
  if (_stab > 0) then {
    if (hct_h60_flir_inputStabilize == 0) then {
      hct_h60_flir_inputStabilize = ceil _stab;
      [
         AGLToASL positionCameraToWorld [0, 0, 0],
         AGLToASL positionCameraToWorld [0, 0, 5000]
      ] call hct_h60_flir_fnc_setStabilization;
    };
  } else {
    hct_h60_flir_inputStabilize = 0;
  };
}; // Stabilize

if (hct_h60_flir_playerIsCopilot) then {
  // Laser
  private _laser = inputAction "fire"; // Ctrl+Click
  if (_laser > 0) then {
    if (hct_h60_flir_inputToggleLaser == 0) then {
      hct_h60_flir_inputToggleLaser = ceil _laser;
      [hct_vehicle] call hct_h60_flir_fnc_toggleLaser;
    };
  } else {
    hct_h60_flir_inputToggleLaser = 0;
  };

  // Scripted Camera for both pilots
  if (hct_h60_flir_isInScriptedCamera) then {
    // Next Weapon
    private _nextWeapon = inputAction "nextWeapon"; // Next Weapon
    if (_nextWeapon > 0) then {
      if (hct_h60_flir_inputNextWeapon == 0) then {
        hct_h60_flir_inputNextWeapon = ceil _nextWeapon;
        [hct_vehicle, [0]] call hct_h60_flir_fnc_nextWeapon;
      };
    } else {
      hct_h60_flir_inputNextWeapon = 0;
    };

    // Fire
    private _fireWeapon = inputAction "defaultAction"; // Click
    if (_fireWeapon > 0) then {
      if (hct_h60_flir_inputFireWeapon == 0) then {
        hct_h60_flir_inputFireWeapon = ceil _fireWeapon;
        [hct_vehicle, hct_vehicle unitTurret hct_player] call hct_h60_flir_fnc_fireWeapon;
      };
    } else {
      hct_h60_flir_inputFireWeapon = 0;
    };

    // Zoom
    private _in = inputAction "zoomIn";
    private _out = inputAction "zoomOut";
    if (_in > 0 || {_out > 0}) then {
      if (hct_h60_flir_inputZoom == 0) then {
        hct_h60_flir_inputZoom = (ceil _in) - (ceil _out);
        [hct_h60_flir_inputZoom] call hct_h60_flir_fnc_keyZoom;
      };
    } else {
      hct_h60_flir_inputZoom = 0;
    };

    // Vision Mode
    private _visionMode = inputAction "cameraVisionMode";
    if (_visionMode > 0) then {
      if (hct_h60_flir_inputVisionMode == 0) then {
        hct_h60_flir_inputVisionMode = ceil _visionMode;
        [] call hct_h60_flir_fnc_keyVisionMode;
      };
    } else {
      hct_h60_flir_inputVisionMode = 0;
    };

  }; // isInScriptedCamera
}; // playerIsCopilot

true
