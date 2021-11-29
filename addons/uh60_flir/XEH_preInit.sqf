#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
#include "initSettings.sqf";

// stuff to hopefully speed up perFrame
vtx_uh60_flir_aspectRatio = getResolution # 4;
vtx_uh60_flir_featureCamera = "";
vtx_uh60_flir_playerEHs = [];
vtx_uh60_flir_playerCBAEHs = [];
vtx_uh60_flir_vehicleEHs = [];
vtx_uh60_flir_isPipHidden = true;

// inputs
vtx_uh60_flir_inputZoom = 0;
vtx_uh60_flir_inputStabilize = 0;
vtx_uh60_flir_inputVisionMode = 0;
vtx_uh60_flir_isFixed = false; // For Sling cam
vtx_uh60_flir_isSlewing = false;
vtx_uh60_flir_isStabilized = false;
vtx_uh60_flir_slewAim = false;
vtx_uh60_flir_up = 0;
vtx_uh60_flir_down = 0;
vtx_uh60_flir_left = 0;
vtx_uh60_flir_right = 0;

// FLIR state
vtx_uh60_flir_controllable = false;
vtx_uh60_flir_isInScriptedCamera = false;

vtx_uh60_flir_playerIsPilot = false;
vtx_uh60_flir_playerIsCopilot = false;
vtx_uh60_flir_otherPilot = objNull;
vtx_uh60_flir_otherPilotIsPlayer = false;
vtx_uh60_flir_isCopilotInGunnerView = false;
vtx_uh60_flir_lastSyncTimePilotCamera = 0;
vtx_uh60_flir_lastSyncTimeAnimation = 0;

vtx_uh60_flir_pipEffect = [];
vtx_uh60_flir_pipEffectsHashMap = createHashMapFromArray [
  ["Normal", [0]],
  ["NVG", [1]],
  ["Ti", [2]],
  [0, [2]], // thermalMode[] white-hot
  [1, [7]], // thermalMode[] black-hot
  [2, [8]], // thermalMode[] green-hot
  // backwards for getting value for setCamUseTI
  [[2], 0], // thermalMode[] white-hot
  [[7], 1], // thermalMode[] black-hot
  [[8], 2] // thermalMode[] green-hot
];

vtx_uh60_flir_visionModeNamesHashMap = createHashMapFromArray [
  [[0], "DTV"],
  [[1], "NVG"],
  [[2], "WHOT"], // thermalMode[] white-hot
  [[7], "BHOT"], // thermalMode[] black-hot
  [[8], "GHOT"] // thermalMode[] green-hot
];

vtx_uh60_flir_visionModesHashMap = createHashMapFromArray [
  [[0, -1], [0]],
  [[1, -1], [1]],
  [[2, 0], [2]], // thermalMode[] white-hot
  [[2, 1], [7]] // thermalMode[] black-hot
];

ADDON = true;
