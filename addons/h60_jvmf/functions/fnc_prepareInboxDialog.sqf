/*
 * vtx_uh60_jvmf_fnc_prepareInboxDialog
 */

params ["_display"];
private _ctrl = _display displayCtrl 1337;
if(vtx_uh60_ui_showDebugMessages) then {systemChat str _ctrl;};
private _fixString = {
    params ["_str", "_length"];
    private _str = _str select [0,_length];
    while {count _str < _length} do {_str = _str + " "};
    _str
};

{
    _x params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
    private _str = "";
    //_str = _str + (if (count _replies < 2) then [{">"}, {" "}]);
    private _typeText = switch (_type) do {
        case 0: {"FRTXT "};
        case 1: {"CASREQ"};
        case 2: {"POSRPT"};
        case 3: {"MEDEVC"};
    };
    _str = _str + _typeText + " ";
    _str = _str + ([_sender, 6] call _fixString) + " ";
    _str = _str + ([_recipient, 6] call _fixString) + " ";
	private _lastReply = _replies # ((count _replies) - 1);
    _str = _str + ([_lastReply # 2, 4] call _fixString) + " ";
    if (count _replies > 0) then {
        _str = _str + ((_replies # 0) # 0);
	};
	if(vtx_uh60_ui_showDebugMessages) then {systemChat _str;};
	_ctrl lbAdd _str;
} forEach VTX_JVMF_MESSAGES;

