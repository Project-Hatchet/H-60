/*
 * hct_h60_jvmf_fnc_receiveMessage
 *
 * Receive a message and store it
 */

params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
if (_id == "") exitWith {};


hct_jvmf_messages pushBack _this;

if(hct_h60_devMode) then {systemChat format ["RECEIVED JVMF: %1", _this];};

// systemChat str [_replySender, player];
if ((_replies # 0 # 3) != player) then {
	if(hct_h60_devMode) then {systemChat "REGISTERING ADVISORY";};
	[vehicle player,"NEW JVMF MSG",{},false,false] call hct_h60_cas_fnc_registerCautionAdvisory;
};
[vehicle player] call hct_h60_jvmf_fnc_drawJVMF;
