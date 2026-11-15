/*
 * hct_h60_jvmf_fnc_openMessage
 */

params ["_ctrl"];
private _display = ctrlParent _ctrl;
private _ctrl = _display displayCtrl 1337;
private _curSel = lbCurSel _ctrl;
private _message = hct_jvmf_messages # _curSel;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
closeDialog 2;
switch (_type) do {
	case 0: {createDialog "hct_h60_jvmf_writeDialog";};
	case 2: {createDialog "hct_h60_jvmf_positionDialog";};
};
// sleep 0.1;
private _newDisplay = uiNamespace getVariable "hct_h60_jvmf_display";
if (isNil "_newDisplay") exitWith {if(hct_h60_devMode) then {systemChat "NO DISPLAY";}};
(_newDisplay displayCtrl 1400) ctrlSetText _recipient;
for "_i" from 0 to 9 do {
    (_newDisplay displayCtrl (1402 + _i)) ctrlSetText (_text # _i);
};

if (count _replies > 0) then {
    private _lastReply = _replies # ((count _replies) - 1);
	private _status = format["%1 %2 %3", _lastReply # 0, _lastReply # 1, _lastReply # 2];
    (_newDisplay displayCtrl (1101)) ctrlSetText _status;
};

(_newDisplay displayCtrl (1600)) ctrlShow false;
(_newDisplay displayCtrl (1601)) ctrlShow false;
