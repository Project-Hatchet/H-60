/*
 * vtx_uh60_jvmf_fnc_shutdown
 *
 * Removes the JVMF message/reply CBA handlers. Safe to call when they are not
 * registered (setup calls it first so a repeated setup cannot leak them).
 */

if (!isNil "vtx_uh60_jvmfMessageEventPFHID") then {
    ["vtx_uh60_jvmf_messageSent", vtx_uh60_jvmfMessageEventPFHID] call CBA_fnc_removeEventHandler;
    vtx_uh60_jvmfMessageEventPFHID = nil;
};
if (!isNil "vtx_uh60_jvmfReplyEventPFHID") then {
    ["vtx_uh60_jvmf_replySent", vtx_uh60_jvmfReplyEventPFHID] call CBA_fnc_removeEventHandler;
    vtx_uh60_jvmfReplyEventPFHID = nil;
};
true
