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

if (count VTX_JVMF_MESSAGES == 0) exitWith {};

//this function deletes a JVMF at the selected index
VTX_JVMF_MESSAGES deleteAt VTX_JVMF_SELECTED_IDX;
systemChat format ["Deleted Message at index: %1", VTX_JVMF_SELECTED_IDX];

//reset JVMF index after deleting the messages at the index
if (VTX_JVMF_SELECTED_IDX != 0) then {
	VTX_JVMF_SELECTED_IDX = VTX_JVMF_SELECTED_IDX - 1;  
} else {
	VTX_JVMF_SELECTED_IDX = 0; 
};

systemChat format ["New Index is: %1", VTX_JVMF_SELECTED_IDX];

//redraw JVMF if there are more messages remaining, otherwise manually clear the JVMF
if (count VTX_JVMF_MESSAGES > 0) exitWith {
	[_vehicle] call vtx_uh60_jvmf_fnc_drawJVMF;
};

for "_i" from 30 to 42 do {
	[_vehicle, _i, ""] call vtx_uh60_mfd_fnc_setUserText;
};
