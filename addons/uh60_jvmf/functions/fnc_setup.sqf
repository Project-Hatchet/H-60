if (!vtx_uh60m_enabled_jvmf) exitWith {false};
vtx_uh60_jvmfMessageEventPFHID = nil;
vtx_uh60_jvmfMessageEventPFHID = ["vtx_uh60_jvmf_messageSent", {[_this] call vtx_uh60_jvmf_fnc_receiveMessage}] call CBA_fnc_addEventHandler;

true
