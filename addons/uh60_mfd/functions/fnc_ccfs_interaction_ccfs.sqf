params ["_vehicle", "_action", "_value"];

switch (_action) do {
	case 1: { // join
		[_vehicle] call vtx_uh60_mfd_fnc_ccfs_join;
	};
	case 2: { // next
		[_vehicle, 1] call vtx_uh60_mfd_fnc_ccfs_CyclePlayer;
	};
	case 3: { // prev
		[_vehicle, -1] call vtx_uh60_mfd_fnc_ccfs_CyclePlayer;
	};
	case 4: { // host
		[_vehicle] call vtx_uh60_mfd_fnc_ccfs_host;
	};
	case 5: { // exit
		[_vehicle] call vtx_uh60_mfd_fnc_ccfs_exit;
	};
	case 6: { // pause
		[_vehicle] call vtx_uh60_mfd_fnc_ccfs_play;
	};
};