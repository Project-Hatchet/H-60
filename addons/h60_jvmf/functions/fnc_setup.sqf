/*
 * hct_h60_jvmf_fnc_setup
 *
 * Hatchet module hook: registers the JVMF message and reply event handlers (removing any left over first).
 *
 * params [(object) vehicle]
 */

if (!hct_h60_enabled_jvmf) exitWith {false};
// remove handlers a setup without a shutdown left behind (they were set to nil
// here first, so a second setup made them unremovable and doubled every message)
call hct_h60_jvmf_fnc_shutdown;
hct_h60_jvmfMessageEventPFHID = ["hct_h60_jvmf_messageSent", {_this call hct_h60_jvmf_fnc_receiveMessage}] call CBA_fnc_addEventHandler;
hct_h60_jvmfReplyEventPFHID = ["hct_h60_jvmf_replySent", {_this call hct_h60_jvmf_fnc_receiveReply}] call CBA_fnc_addEventHandler;

true
