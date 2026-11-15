/*
 * hct_h60_jvmf_fnc_receiveReply
 *
 *
 */
params ["_replySender", "_ID", "_reply", "_timestamp", "_senderObject"];

private _messageIndex = hct_jvmf_messages findIf {_x # 0 == _ID};
if (_messageIndex == -1) exitWith {};
private _message = hct_jvmf_messages # _messageIndex;
private _replies = _message # 6;
_replies pushBack [_timestamp, _replySender, _reply];
_message set [6, _replies];
hct_jvmf_messages set [_messageIndex, _message];


if (_senderObject != player) then {
	if(hct_h60_ui_showDebugMessages) then {systemChat "REGISTERING ADVISORY";};
	[vehicle player,"NEW JVMF REPLY",{},false,false] call hct_h60_cas_fnc_registerCautionAdvisory;
};

[vehicle player] call hct_h60_jvmf_fnc_drawJVMF;
