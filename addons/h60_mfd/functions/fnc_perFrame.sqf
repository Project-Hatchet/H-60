/*
 * vtx_uh60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle", "_frameTime"];

private _mfdPage = (getUserMFDValue _vehicle) # vtx_uh60_mfd_mfsc_focussedMFD;
if (_mfdPage == 7 || _mfdPage == 8) then {
	_this call vtx_uh60_mfd_fnc_ccfs_slewCCFS;
	_this call vtx_uh60_mfd_fnc_ccfs_runCCFS;
	_this call vtx_uh60_mfd_fnc_ccfs_renderCCFS;
} else {
	[_vehicle] call vtx_uh60_mfd_fnc_slewTAC;
};
