/*
 * hct_h60_mfd_fnc_setUserText
 */

params ["_vehicle", "_index", ["_text", ""]];
if (missionNamespace getVariable ["hct_h60_mfd_allowText", true]) then {
	_vehicle setUserMFDtext [_index, _text];
};
