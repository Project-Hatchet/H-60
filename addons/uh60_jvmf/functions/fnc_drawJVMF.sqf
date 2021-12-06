/*
 * vtx_uh60_jvmf_fnc_drawJVMF
 *
 * Sets userMFD text and variables
 *
 */
params ["_vehicle"];

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
    _str = _str + (if (_forEachIndex == VTX_JVMF_SELECTED_IDX) then [{"-"}, {" "}]);
    private _typeText = switch (_type) do {
        case 0: {"FRTXT "};
        case 1: {"CASREQ"};
        case 2: {"POSRPT"};
        case 3: {"MEDEVC"};
    };
    _str = _str + _typeText + " ";
    _str = _str + ([_sender, 5] call _fixString) + " ";
    if (count _replies > 0) then {
        _str = _str + ((_replies # 0) # 0);
    };
    _strings set [_foreachIndex, [_str, 20+3] call _fixString];
} forEach VTX_JVMF_MESSAGES;

private _message = VTX_JVMF_MESSAGES # VTX_JVMF_SELECTED_IDX;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];

_vehicle setUserMFDValue [16, _type];
_vehicle setUserMFDText [30, _sender + "/" + _recipient];
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
    _vehicle setUserMFDText [31 + _foreachIndex, _x];
} forEach _strings;

if (count _replies > 0) then {
    private _lastReply = _replies # ((count _replies) - 1);
    _vehicle setUserMFDText [41, format["%1 %2 %3", _lastReply # 0, _lastReply # 1, _lastReply # 2]];
};

private _messageCount = count VTX_JVMF_MESSAGES;
_vehicle setUserMFDText [42, format["%1/%2", VTX_JVMF_SELECTED_IDX + 1, count VTX_JVMF_MESSAGES]];
