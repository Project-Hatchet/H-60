/*
 * vtx_uh60_jvmf_fnc_attemptSendMessage
 *
 * Attempts to send a JVMF message
 *
 * params: (array) a JVMF message
 *
 * returns: (boolean) whether the message was considered valid and was sent
 *
 */

// this part of the message is common no matter what type
params ["_id", "_sender", "_recipient", "_type"];

#define VALIDSTRING(STR) (typeName STR == "STRING")
#define FILLEDSTRING(STR) (typeName STR == "STRING" && count STR > 0)
#define VALIDSIZESTRING(STR,LENGTH) (typeName STR == "STRING" && count STR < LENGTH)

private _isUniqueID = (VTX_JVMF_MESSAGES findIf {_x # 0 == _id}) == -1;
if(!FILLEDSTRING(_sender) || !FILLEDSTRING(_recipient) || !FILLEDSTRING(_id)) exitWith { false };

private _success = switch (_type) do {
    case 0: {
        params ["", "", "", "", "_text", ["_data",[]], ["_replies",[]]];
        if (count _text < 10) exitWith { false };
        private _validTexts = true;
        {if (!VALIDSIZESTRING(_x,50)) then { _validTexts = false; };} forEach _text;
        if (!_validTexts || typeName _data != "array" || typeName _replies != "array") exitWith { false };
        true
    };
    case 2: {
        params ["", "", "", "", "_text", ["_data",[]], ["_replies",[]]];
        if (typeName _data != "array" || typeName _replies != "array") exitWith { false };
        true
    };
    default {
        false
    };
};

if (_success) then {
    private _timestamp = [daytime, "HH:MM"] call BIS_fnc_timeToString;
    _this set [6, [[_timestamp, _sender, "SENT"]]];
    _this remoteExecCall ["vtx_uh60_jvmf_fnc_receiveMessage", 0];diag_log "attemptSend";
};

_success
