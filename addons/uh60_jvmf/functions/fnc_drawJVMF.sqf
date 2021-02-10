/*
 * vtx_uh60_jvmf_fnc_drawJVMF
 *
 * Sets userMFD text and variables
 *
 */
params ["_vehicle"];

private _message = VTX_JVMF_MESSAGES # VTX_JVMF_SELECTED_IDX;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];

_vehicle setUserMFDValue [16, _type];
_vehicle setUserMFDText [30, format["%1 TO %2: %3", _sender, _recipient, _ID]];
{
    _vehicle setUserMFDText [31 + _foreachIndex, _x];
} forEach _text;

if (count _replies > 0) then {
    private _lastReply = _replies # ((count _replies) - 1);
    _vehicle setUserMFDText [41, format["%1 %2 %3", _lastReply # 0, _lastReply # 1, _lastReply # 2]];
};

private _messageCount = count VTX_JVMF_MESSAGES;
_vehicle setUserMFDText [42, format["JVMF INBOX %1/%2", VTX_JVMF_SELECTED_IDX + 1, count VTX_JVMF_MESSAGES]];
