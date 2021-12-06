/*
 * Author: Ampersand
 * Reset state-tracking variables
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * call vtx_uh60_flir_fnc_initVars
 */

// Player state
vtx_uh60_flir_playerIsPilot = false;
vtx_uh60_flir_playerIsCopilot = false;
vtx_uh60_flir_otherPilotIsPlayer = false;
vtx_uh60_flir_otherPilot = objNull;

// Eventhandlers
vtx_uh60_flir_playerEHs = [];
vtx_uh60_flir_playerCBAEHs = [];
vtx_uh60_flir_vehicleEHs = [];

// Inputs
vtx_uh60_flir_inputZoom = 0;
vtx_uh60_flir_inputStabilize = 0;
vtx_uh60_flir_inputVisionMode = 0;
vtx_uh60_flir_isSlewing = false; // Slewing using any input
vtx_uh60_flir_slewAim = false; // Slewing using input Aim Up|Down|Left|Right, mostly mouse
vtx_uh60_flir_up = 0; // Slewing using keys
vtx_uh60_flir_down = 0;
vtx_uh60_flir_left = 0;
vtx_uh60_flir_right = 0;

// FLIR state
vtx_uh60_flir_isPipHidden = true;
vtx_uh60_flir_pipIsFixed = false;
vtx_uh60_flir_featureCamera = "";
vtx_uh60_flir_pilotCameraTarget = [false, [0, 0, 0], objNull]; // Separate variable due to using basegame keybind, which first toggles the basegame stabilization
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
