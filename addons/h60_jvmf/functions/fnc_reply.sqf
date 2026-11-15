/*
 * hct_h60_jvmf_fnc_reply
 *
 * Send a reply to a message
 */

params ["_vehicle", "_reply"];
private _replySender = profileName;
private _timestamp = [daytime, "HH:MM"] call BIS_fnc_timeToString;
if (hct_jvmf_selected_idx < 0 || {hct_jvmf_selected_idx >= count hct_jvmf_messages}) exitWith {}; // empty inbox
private _message = hct_jvmf_messages # hct_jvmf_selected_idx;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];

["hct_h60_jvmf_replySent", [_replySender, _ID, _reply, _timestamp, hct_player]] call CBA_fnc_globalEvent;
if (hct_h60_devMode) then {diag_log "reply";};
