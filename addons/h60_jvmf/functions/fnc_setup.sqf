/*
 * vtx_uh60_jvmf_fnc_setup
 *
 * Hatchet module hook: registers the JVMF message and reply event handlers (removing any left over first).
 *
 * params [(object) vehicle]
 */

if (!vtx_uh60m_enabled_jvmf) exitWith {false};
// remove handlers a setup without a shutdown left behind (they were set to nil
// here first, so a second setup made them unremovable and doubled every message)
call vtx_uh60_jvmf_fnc_shutdown;
vtx_uh60_jvmfMessageEventPFHID = ["vtx_uh60_jvmf_messageSent", {_this call vtx_uh60_jvmf_fnc_receiveMessage}] call CBA_fnc_addEventHandler;
vtx_uh60_jvmfReplyEventPFHID = ["vtx_uh60_jvmf_replySent", {_this call vtx_uh60_jvmf_fnc_receiveReply}] call CBA_fnc_addEventHandler;

true
