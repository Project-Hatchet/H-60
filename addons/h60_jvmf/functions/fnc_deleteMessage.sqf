/*
 * vtx_uh60_jvmf_fnc_deleteMessage
 *
 * Deletes JVMF at selected index
 *
 * params: vehicle
 *
 * returns: nothing
 *
 */

params ["_vehicle"];

if (count vtx_jvmf_messages == 0) exitWith {};

//this function deletes a JVMF at the selected index
vtx_jvmf_messages deleteAt vtx_jvmf_selected_idx;

//reset JVMF index after deleting the messages at the index
if (vtx_jvmf_selected_idx != 0) then {
	vtx_jvmf_selected_idx = vtx_jvmf_selected_idx - 1;  
} else {
	vtx_jvmf_selected_idx = 0; 
};

if(vtx_uh60_ui_showDebugMessages) then {
	systemChat format ["Deleted Message at index: %1 and new index is %2.", vtx_jvmf_selected_idx, vtx_jvmf_selected_idx];
};

//redraw JVMF if there are more messages remaining, otherwise manually clear the JVMF
if (count vtx_jvmf_messages > 0) exitWith {
	[_vehicle] call vtx_uh60_jvmf_fnc_drawJVMF;
};

for "_i" from 30 to 42 do {
	[_vehicle, _i, ""] call vtx_uh60_mfd_fnc_setUserText;
};
