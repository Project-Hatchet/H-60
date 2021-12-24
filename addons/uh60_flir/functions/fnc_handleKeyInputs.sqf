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
 * [] call vtx_uh60_flir_fnc_handleKeyInputs
 */

// PIP Vision Mode
private _visionMode = inputAction "transportNightVision";
if (_visionMode > 0) then {
  if (vtx_uh60_flir_transportNightVision == 0) then {
    vtx_uh60_flir_transportNightVision = ceil _visionMode;
    [] call vtx_uh60_flir_fnc_keyVisionMode;
  };
} else {
  vtx_uh60_flir_transportNightVision = 0;
};

if (!vtx_uh60_flir_controllable) exitWith {};

// Stabilize enables object tracking anywhere
private _stab = inputAction "vehLockTurretView";
if (_stab > 0) then {
  if (vtx_uh60_flir_inputStabilize == 0) then {
    vtx_uh60_flir_inputStabilize = ceil _stab;
    if (vtx_uh60_flir_isInScriptedCamera) then {
      [
         AGLToASL positionCameraToWorld [0, 0, 0],
         AGLToASL positionCameraToWorld [0, 0, 5000]
      ] call vtx_uh60_flir_fnc_setStabilization;
    } else {
      [] call vtx_uh60_flir_fnc_setStabilization;
    };
  };
} else {
  vtx_uh60_flir_inputStabilize = 0;
}; // Stabilize

if (vtx_uh60_flir_playerIsCopilot) then {
  // Laser
  private _laser = inputAction "fire"; // Ctrl+Click
  if (_laser > 0) then {
    if (vtx_uh60_flir_inputToggleLaser == 0) then {
      vtx_uh60_flir_inputToggleLaser = ceil _laser;
      [_vehicle] call vtx_uh60_flir_fnc_toggleLaser;
    };
  } else {
    vtx_uh60_flir_inputToggleLaser = 0;
  };

  // Copilot Camera
  if (vtx_uh60_flir_isInScriptedCamera) then {
    // Next Weapon
    private _nextWeapon = inputAction "nextWeapon"; // Next Weapon
    if (_nextWeapon > 0) then {
      if (vtx_uh60_flir_inputNextWeapon == 0) then {
        vtx_uh60_flir_inputNextWeapon = ceil _nextWeapon;
        [_vehicle, [0]] call vtx_uh60_flir_fnc_nextWeapon;
      };
    } else {
      vtx_uh60_flir_inputNextWeapon = 0;
    };

    // Fire
    private _fireWeapon = inputAction "defaultAction"; // Click
    if (_fireWeapon > 0) then {
      if (vtx_uh60_flir_inputFireWeapon == 0) then {
        vtx_uh60_flir_inputFireWeapon = ceil _fireWeapon;
        [_vehicle] call vtx_uh60_flir_fnc_fireWeapon;
      };
    } else {
      vtx_uh60_flir_inputFireWeapon = 0;
    };

    // Zoom
    private _in = inputAction "zoomIn";
    private _out = inputAction "zoomOut";
    if (_in > 0 || {_out > 0}) then {
      if (vtx_uh60_flir_inputZoom == 0) then {
        vtx_uh60_flir_inputZoom = (ceil _in) - (ceil _out);
        [vtx_uh60_flir_inputZoom] call vtx_uh60_flir_fnc_keyZoom;
      };
    } else {
      vtx_uh60_flir_inputZoom = 0;
    };

    // Vision Mode
    private _visionMode = inputAction "cameraVisionMode";
    if (_visionMode > 0) then {
      if (vtx_uh60_flir_inputVisionMode == 0) then {
        vtx_uh60_flir_inputVisionMode = ceil _visionMode;
        [] call vtx_uh60_flir_fnc_keyVisionMode;
      };
    } else {
      vtx_uh60_flir_inputVisionMode = 0;
    };

  }; // isInScriptedCamera

}; // playerIsCopilot

true
