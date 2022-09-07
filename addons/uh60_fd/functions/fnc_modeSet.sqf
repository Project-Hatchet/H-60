/*
 * vtx_uh60_fd_fnc_modeSet
 *
 * handles the mode buttons for the flight director
 *
 * params (array)[(object) vehicle]
 */

#include "defines.hpp"

params ["_vehicle", "_mode"];

switch (_mode) do {
    case "STBY": {
        SET_RALT_STATE(false);
        SET_ALT_STATE(false);
        SET_ALTP_STATE(false);
        SET_IAS_STATE(false);
        SET_HDG_STATE(false);
        SET_FMS_STATE(false);
        SET_HVR_STATE(false);
        SET_GLOBAL("alt_mode",nil);
        SET_GLOBAL("pitch_mode",nil);
        SET_GLOBAL("roll_mode",nil);
        SET_GLOBAL("pitch_mode",nil);
    };
    case "RALT": {
        CYCLE_RALT_STATE; 
        if(vtx_uh60_ui_showDebugMessages) then {systemChat str ["RALT", GET_RALT_STATE];};
        SET_ALT_STATE(false);
        SET_ALTP_STATE(false);
        SET_VS_STATE(false);
        if (GET_RALT_STATE) then {SET_GLOBAL("alt_mode",vtx_uh60_fd_fnc_ralt)}else{SET_GLOBAL("alt_mode",nil)};
    };
    case "ALT": {
        CYCLE_ALT_STATE; 
        if(vtx_uh60_ui_showDebugMessages) then {systemChat str ["ALT", GET_ALT_STATE];};
        SET_RALT_STATE(false);
        SET_ALTP_STATE(false);
        SET_VS_STATE(false);
        if (GET_ALT_STATE) then {SET_GLOBAL("alt_mode",vtx_uh60_fd_fnc_alt)}else{SET_GLOBAL("alt_mode",nil)};
    };
    case "ALTP": {
        CYCLE_ALTP_STATE; 
        if(vtx_uh60_ui_showDebugMessages) then {systemChat str ["ALTP", GET_ALTP_STATE];};
        SET_RALT_STATE(false);
        SET_ALT_STATE(false);
        SET_VS_STATE(false);
        if (GET_ALTP_STATE) then {SET_GLOBAL("alt_mode",vtx_uh60_fd_fnc_altp)}else{SET_GLOBAL("alt_mode",nil)};
    };
    case "VS": {
        CYCLE_VS_STATE; 
        if(vtx_uh60_ui_showDebugMessages) then {systemChat str ["ALTP", GET_VS_STATE];};
        SET_RALT_STATE(false);
        SET_ALT_STATE(false);
        SET_ALTP_STATE(false);
        if (GET_VS_STATE) then {SET_GLOBAL("alt_mode",vtx_uh60_fd_fnc_vs)}else{SET_GLOBAL("alt_mode",nil)};
    };
    case "IAS": {
        if (difficultyEnabledRTD) exitWith {["Warning\nFD could not be engaged\nThe Heading autopilot mode is not enabled on advanced flight model\n"] call vtx_uh60_misc_fnc_hint;};
        if (isTouchingGround _vehicle) exitWith {["Warning\nFD could not be engaged\nMode could not be engaged on ground"] call vtx_uh60_misc_fnc_hint;};
        CYCLE_IAS_STATE;
        if (GET_IAS_STATE) then {
            SET_HVR_STATE(false);
            SET_GLOBAL("pitch_mode", vtx_uh60_fd_fnc_ias)
        } else {SET_GLOBAL("pitch_mode", nil)};
    };
    case "HDG": {
        if (difficultyEnabledRTD) exitWith {["Warning\nFD could not be engaged\nThe Heading autopilot mode is not enabled on advanced flight model\n"] call vtx_uh60_misc_fnc_hint;};
        if (isTouchingGround _vehicle) exitWith {["Warning\nFD could not be engaged\nMode could not be engaged on ground"] call vtx_uh60_misc_fnc_hint;};
        CYCLE_HDG_STATE;
        if (GET_HDG_STATE) then {
            SET_FMS_STATE(false);
            SET_GLOBAL("roll_mode", vtx_uh60_fd_fnc_hdg)
        } else {SET_GLOBAL("roll_mode", nil)};
    };
    case "FMS": {
        if (difficultyEnabledRTD) exitWith {["Warning\nFD could not be engaged\nThe FMS coupled mode is not enabled on advanced flight model\n"] call vtx_uh60_misc_fnc_hint;};
        if (isTouchingGround _vehicle) exitWith {["Warning\nFD could not be engaged\nMode could not be engaged on ground"] call vtx_uh60_misc_fnc_hint;};
        CYCLE_FMS_STATE;
        if (GET_FMS_STATE) then {
            SET_HDG_STATE(false);
            SET_GLOBAL("roll_mode", vtx_uh60_fd_fnc_fms)
        } else {SET_GLOBAL("roll_mode", nil)};
    };
    case "HVR": {
        if (difficultyEnabledRTD) exitWith {["Warning\nFD could not be engaged\nThe Heading autopilot mode is not enabled on advanced flight model\n"] call vtx_uh60_misc_fnc_hint;};
        if (isTouchingGround _vehicle) exitWith {["Warning\nFD could not be engaged\nMode could not be engaged on ground"] call vtx_uh60_misc_fnc_hint;};
        CYCLE_HVR_STATE;
        if (GET_HVR_STATE) then {
            SET_IAS_STATE(false);
            SET_GLOBAL("pitch_mode", vtx_uh60_fd_fnc_hvr)
        } else {
            SET_GLOBAL("pitch_mode", nil)
        };
    };
};

[_vehicle] remoteExecCall ["vtx_uh60_fd_fnc_updatePanel", crew _vehicle];diag_log "modeSet";
