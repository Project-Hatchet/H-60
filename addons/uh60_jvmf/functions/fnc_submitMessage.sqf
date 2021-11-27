/*
 * vtx_uh60_jvmf_fnc_submitMessage
 *
 * Creates and sends a JVMF message from a creation dialog
 */

params ["", "_type"];

private _sender = profileName;
private _recipient = ctrlText 1400;
private _id = _sender + "/" + (str time);
private _messageContent = [];
for "_i" from 1402 to 1411 do {
    _messageContent pushBack (ctrlText _i);
};
private _data = [];
if (_type == 2) then {
    private _pos = [_messageContent # 0] call ace_common_fnc_getMapPosFromGrid;
    _pos set [2, parseNumber (_messageContent # 1)];
    _data = [_pos];
};

private _message = [_id, _sender, _recipient, _type, _messageContent, _data, [[_timestamp, _sender, "SENT"]]];
private _success = _message call vtx_uh60_jvmf_fnc_attemptSendMessage;

if (_success) then {
    closeDialog 2;
};
