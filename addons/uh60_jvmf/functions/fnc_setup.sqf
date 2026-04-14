if (!vtx_uh60m_enabled_jvmf) exitWith {false};
vtx_uh60_jvmfMessageEventPFHID = nil;
vtx_uh60_jvmfReplyEventPFHID = nil;
vtx_uh60_jvmfMessageEventPFHID = ["vtx_uh60_jvmf_messageSent", {_this call vtx_uh60_jvmf_fnc_receiveMessage}] call CBA_fnc_addEventHandler;
vtx_uh60_jvmfReplyEventPFHID = ["vtx_uh60_jvmf_replySent", {_this call vtx_uh60_jvmf_fnc_receiveReply}] call CBA_fnc_addEventHandler;

true
