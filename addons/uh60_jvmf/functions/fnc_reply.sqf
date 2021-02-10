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

[_replySender, _ID, _reply, _timestamp] remoteExecCall ["vtx_uh60_jvmf_fnc_receiveReply"];diag_log "reply";
