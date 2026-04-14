/*
 * vtx_uh60_jvmf_fnc_reply
 *
 * Send a reply to a message
 */

params ["_vehicle", "_reply"];
private _replySender = profileName;
private _timestamp = [daytime, "HH:MM"] call BIS_fnc_timeToString;
private _message = VTX_JVMF_MESSAGES # VTX_JVMF_SELECTED_IDX;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];

["vtx_uh60_jvmf_replySent", [_replySender, _ID, _reply, _timestamp, hct_player]] call CBA_fnc_globalEvent;
if (vtx_uh60_ui_showDebugMessages) then {diag_log "reply";};
