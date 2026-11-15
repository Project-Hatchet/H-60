/*
 * hct_h60_jvmf_fnc_deleteMessage
 *
 * Deletes JVMF at selected index
 *
 * params: vehicle
 *
 * returns: nothing
 *
 */

params ["_vehicle"];

if (count hct_jvmf_messages == 0) exitWith {};

//this function deletes a JVMF at the selected index
hct_jvmf_messages deleteAt hct_jvmf_selected_idx;

//reset JVMF index after deleting the messages at the index
if (hct_jvmf_selected_idx != 0) then {
	hct_jvmf_selected_idx = hct_jvmf_selected_idx - 1;  
} else {
	hct_jvmf_selected_idx = 0; 
};

if(hct_h60_devMode) then {
	systemChat format ["Deleted Message at index: %1 and new index is %2.", hct_jvmf_selected_idx, hct_jvmf_selected_idx];
};

//redraw JVMF if there are more messages remaining, otherwise manually clear the JVMF
if (count hct_jvmf_messages > 0) exitWith {
	[_vehicle] call hct_h60_jvmf_fnc_drawJVMF;
};

for "_i" from 30 to 42 do {
	[_vehicle, _i, ""] call hct_h60_mfd_fnc_setUserText;
};
