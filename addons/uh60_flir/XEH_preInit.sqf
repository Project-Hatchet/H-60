#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"
#include "initSettings.sqf";

vtx_uh60_flir_fov = 0.3;
vtx_uh60_flir_fovLevels = [0.3, 0.2, 0.1, 0.022, 0.0092]; // should match turret configs
vtx_uh60m_flir_c_cameraMode = 0; // DTV/TI/NV
vtx_uh60_flir_up = 0;
vtx_uh60_flir_down = 0;
vtx_uh60_flir_left = 0;
vtx_uh60_flir_right = 0;

// stuff to hopefully speed up perFrame
vtx_uh60_flir_playerIsPilot = false;
vtx_uh60_flir_playerIsCopilot = false;
vtx_uh60_flir_otherPilot = objNull;
vtx_uh60_flir_otherPilotIsPlayer = false;
vtx_uh60_flir_isCopilotInGunnerView = false;
vtx_uh60_flir_lastSyncTimePilotCamera = 0;
vtx_uh60_flir_lastSyncTimeAnimation = 0;

ADDON = true;
