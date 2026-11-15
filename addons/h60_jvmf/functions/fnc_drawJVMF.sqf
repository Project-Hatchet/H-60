/*
 * hct_h60_jvmf_fnc_drawJVMF
 *
 * Sets userMFD text and variables
 *
 */
params ["_vehicle"];

//Do not draw JVMF is there are no JVMF Messages
if (count hct_jvmf_messages == 0) exitWith {
    _vehicle setUserMFDValue [16, -1];  //-1 sets as empty
};

private _fixString = {
    params ["_str", "_length"];
    private _str = _str select [0,_length];
    while {count _str < _length} do {_str = _str + " "};
    _str
};

private _strings = [
    "                       ",
    "                       ",
    "                       ",
    "                       ",
    "                       ",
    "                       ",
    "                       ",
    "                       ",
    "                       ",
    "                       "
];

{
    _x params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
    private _str = "";
    //_str = _str + (if (count _replies < 2) then [{">"}, {" "}]);
    _str = _str + (if (_forEachIndex == hct_jvmf_selected_idx) then [{"-"}, {" "}]);
    private _typeText = switch (_type) do {
        case 0: {"FRTXT "};
        case 1: {"CASREQ"};
        case 2: {"POSRPT"};
        case 3: {"MEDEVC"};
        default {"??????"}; // unknown type: no nil in the string build
    };
    _str = _str + _typeText + " ";
    _str = _str + ([_sender, 5] call _fixString) + " ";
    if (count _replies > 0) then {
        _str = _str + ((_replies # 0) # 0);
    };
    _strings set [_foreachIndex, [_str, 20+3] call _fixString];
} forEach hct_jvmf_messages;

// a stale selection (message deleted) must not index past the end
hct_jvmf_selected_idx = (hct_jvmf_selected_idx max 0) min (count hct_jvmf_messages - 1);
private _message = hct_jvmf_messages # hct_jvmf_selected_idx;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];

_vehicle setUserMFDValue [16, _type];
[_vehicle, 30, _sender + "/" + _recipient] call hct_h60_mfd_fnc_setUserText;
switch (_type) do {
    case 0: {
        {
            _str = _strings # _forEachIndex;
            _strings set [_forEachIndex, [_str + _x, 20 + 3 + 34] call _fixString];
        } forEach _text;
    };
    case 2: {
        for [{_i = 0}, {_i < 8}, {_i = _i + 1}] do {
            _str = _strings # _i;
            if (_i < 4) then {
                _str = _str + "         ";
            };
            _strings set [_i, [_str + (_text # _i), 20 + 3 + 34] call _fixString];
        };
        _strings set [8, _text # 2];
    };
};
{
    [_vehicle, 31 + _foreachIndex, _x] call hct_h60_mfd_fnc_setUserText;
} forEach _strings;

if (count _replies > 0) then {
    private _lastReply = _replies # ((count _replies) - 1);
    [_vehicle, 41, [_lastReply # 0, _lastReply # 1, _lastReply # 2] joinString " "] call hct_h60_mfd_fnc_setUserText;
};

private _messageCount = count hct_jvmf_messages;
[_vehicle, 42, format["%1/%2", hct_jvmf_selected_idx + 1, count hct_jvmf_messages]] call hct_h60_mfd_fnc_setUserText;
