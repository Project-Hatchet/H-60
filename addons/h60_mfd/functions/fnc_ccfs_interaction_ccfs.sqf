/*
 * hct_h60_mfd_fnc_ccfs_interaction_ccfs
 *
 * CCFS: handles the game page's MFD buttons (join, next/previous player, host, play/pause, exit).
 *
 * params [(object) vehicle, (number) action, (any) value]
 */

params ["_vehicle", "_action", "_value"];

switch (_action) do {
	case 1: { // join
		[_vehicle] call hct_h60_mfd_fnc_ccfs_join;
	};
	case 2: { // next
		[_vehicle, 1] call hct_h60_mfd_fnc_ccfs_CyclePlayer;
	};
	case 3: { // prev
		[_vehicle, -1] call hct_h60_mfd_fnc_ccfs_CyclePlayer;
	};
	case 4: { // host
		[_vehicle] call hct_h60_mfd_fnc_ccfs_host;
	};
	case 5: { // exit
		[_vehicle] call hct_h60_mfd_fnc_ccfs_exit;
	};
	case 6: { // pause
		[_vehicle] call hct_h60_mfd_fnc_ccfs_play;
	};
};
