/*
 * vtx_uh60_jvmf_fnc_submitMessage
 *
 * Creates and sends a JVMF message from a creation dialog
 */

params ["", "_type"];

private _sender = profileName;
private _recipient = ctrlText 1400;
private _id = ctrlText 1401;
private _messageContent = [];
for "_i" from 1402 to 1411 do {
        _messageContent pushBack (ctrlText _i);
};

private _message = [_id, _sender, _recipient, _type, _messageContent, [], [[_timestamp, _sender, "SENT"]]];
private _success = _message call vtx_uh60_jvmf_fnc_attemptSendMessage;

if (_success) then {
    closeDialog 2;
};
