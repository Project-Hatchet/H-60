/*
 * vtx_uh60_mfd_fnc_setUserText
 */

params ["_vehicle", "_index", "_text"];
if (missionNamespace getVariable ["vtx_uh60_mfd_allowText", true]) then {
	_vehicle setUserMFDtext [_index, _text];
};
