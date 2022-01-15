/*
 * vtx_uh60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

private _world_size = [] call BIS_fnc_mapSize;
private _zoomLevel = _vehicle getVariable ["MAP_ZoomMult", 1];
private _coverage = (4000 * _zoomLevel) / ((_world_size / 2) * 1.49);
_vehicle setUserMFDvalue [27, 1 - _coverage];


private _mfdPage = (getUserMFDValue _vehicle) # vtx_uh60_mfd_mfsc_focussedMFD;
// this switch case can come back when we have more functionality
// switch (_mfdPage) do {
// 	case 2: { // TAC
// 		[_vehicle] call vtx_uh60_mfd_fnc_slewTAC;
// 	};
// 	case 7: { // CCFS
// 		[_vehicle] call vtx_uh60_mfd_fnc_slewCCFS;
// 	};
// };
if (_mfdPage == 7) then {
	[_vehicle] call vtx_uh60_mfd_fnc_slewCCFS;
} else {
	[_vehicle] call vtx_uh60_mfd_fnc_slewTAC;
};