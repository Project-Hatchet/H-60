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

//redraw JVMF if there are more messages remaining, otherwise manually clear the JVMF
if (count VTX_JVMF_MESSAGES > 0) exitWith {
	[_vehicle] call vtx_uh60_jvmf_fnc_drawJVMF;
};

{
	[_vehicle, _x, ""] call vtx_uh60_mfd_fnc_setUserText;
} forEach [30, 31, 41, 42];