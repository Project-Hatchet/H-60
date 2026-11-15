/*
 * hct_h60_jvmf_fnc_shutdown
 *
 * Removes the JVMF message/reply CBA handlers. Safe to call when they are not
 * registered (setup calls it first so a repeated setup cannot leak them).
 */

if (!isNil "hct_h60_jvmfMessageEventPFHID") then {
    ["hct_h60_jvmf_messageSent", hct_h60_jvmfMessageEventPFHID] call CBA_fnc_removeEventHandler;
    hct_h60_jvmfMessageEventPFHID = nil;
};
if (!isNil "hct_h60_jvmfReplyEventPFHID") then {
    ["hct_h60_jvmf_replySent", hct_h60_jvmfReplyEventPFHID] call CBA_fnc_removeEventHandler;
    hct_h60_jvmfReplyEventPFHID = nil;
};
true
