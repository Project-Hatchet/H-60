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
 * call hct_h60_flir_fnc_initVars
 */

// Player state
hct_h60_flir_playerIsPilot = false;
hct_h60_flir_playerIsCopilot = false;
hct_h60_flir_otherPilotIsPlayer = false;
hct_h60_flir_otherPilot = objNull;
hct_h60_flir_scriptedCameraToMap = false;

// Eventhandlers
hct_h60_flir_playerEHs = [];
hct_h60_flir_playerCBAEHs = [];
hct_h60_flir_vehicleEHs = [];

// Inputs
hct_h60_flir_inputZoom = 0;
hct_h60_flir_inputStabilize = 0;
hct_h60_flir_inputVisionMode = 0;
hct_h60_flir_isSlewing = false; // Slewing using any input
hct_h60_flir_slewAim = false; // Slewing using input Aim Up|Down|Left|Right, mostly mouse
hct_h60_flir_up = 0; // Slewing using keys
hct_h60_flir_down = 0;
hct_h60_flir_left = 0;
hct_h60_flir_right = 0;

// FLIR state
hct_h60_flir_isPipHidden = true;
hct_h60_flir_pipIsFixed = false;
hct_h60_flir_featureCamera = "";
hct_h60_flir_pilotCameraTarget = [false, [0, 0, 0], objNull]; // Separate variable due to using basegame keybind, which first toggles the basegame stabilization
hct_h60_flir_controllable = false;
hct_h60_flir_isInScriptedCamera = false;
hct_h60_flir_playerIsPilot = false;
hct_h60_flir_playerIsCopilot = false;
hct_h60_flir_otherPilot = objNull;
hct_h60_flir_otherPilotIsPlayer = false;
hct_h60_flir_isCopilotInGunnerView = false;
hct_h60_flir_lastSyncTimePilotCamera = 0;
hct_h60_flir_lastSyncTimeAnimation = 0;
hct_h60_flir_pipEffect = [0];
