/*
 * vtx_uh60_jvmf_fnc_openMessage
 */

params ["_ctrl"];
private _display = ctrlParent _ctrl;
private _ctrl = _display displayCtrl 1337;
private _curSel = lbCurSel _ctrl;
private _message = VTX_JVMF_MESSAGES # _curSel;
_message params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
closeDialog 2;
switch (_type) do {
	case 0: {createDialog "vtx_uh60_jvmf_writeDialog";};
	case 2: {createDialog "vtx_uh60_jvmf_positionDialog";};
};
// sleep 0.1;
private _newDisplay = uiNamespace getVariable "vtx_uh60_jvmf_display";
if (isNil "_newDisplay") exitWith {systemChat "NO DISPLAY";};
(_newDisplay displayCtrl 1400) ctrlSetText _recipient;
for "_i" from 0 to 9 do {
    (_newDisplay displayCtrl (1402 + _i)) ctrlSetText (_text # _i);
};
systemChat str [_ctrl, _curSel];