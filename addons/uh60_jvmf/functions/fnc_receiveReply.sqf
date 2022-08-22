/*
 * vtx_uh60_jvmf_fnc_receiveReply
 *
 *
 */
params ["_replySender", "_ID", "_reply", "_timestamp"];

private _messageIndex = VTX_JVMF_MESSAGES findIf {_x # 0 == _ID};
if (_messageIndex == -1) exitWith {};
private _message = VTX_JVMF_MESSAGES # _messageIndex;
private _replies = _message # 6;
_replies pushBack [_timestamp, _replySender, _reply];
_message set [6, _replies];
VTX_JVMF_MESSAGES set [_messageIndex, _message];

if (_replySender != player) then {
	[vehicle player,"NEW JVMF REPLY",{},false,false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
};

[vehicle player] call vtx_uh60_jvmf_fnc_drawJVMF;
