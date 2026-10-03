/*
 * vtx_uh60_jvmf_fnc_receiveMessage
 *
 * Receive a message and store it
 */

params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
if (_id == "") exitWith {};


VTX_JVMF_MESSAGES pushBack _this;

if(vtx_uh60_ui_showDebugMessages) then {systemChat format ["RECEIVED JVMF: %1", _this];};

// systemChat str [_replySender, player];
if ((_replies # 0 # 3) != player) then {
	if(vtx_uh60_ui_showDebugMessages) then {systemChat "REGISTERING ADVISORY";};
	[vehicle player,"NEW JVMF MSG",{},false,false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
};
[vehicle player] call vtx_uh60_jvmf_fnc_drawJVMF;
