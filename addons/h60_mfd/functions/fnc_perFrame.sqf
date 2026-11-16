/*
 * hct_h60_mfd_fnc_perFrame
 *
 * handles constant updates of data for MFDs
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle", "_frameTime"];

// The screen's aspect, for the FLIR video's layout (fnc_flirVideo): measured here, as a ui()
// display's own screen commands describe its texture, and each frame so a resolution change follows
hct_h60_mfd_screenAspect = (safeZoneW / pixelW) / (safeZoneH / pixelH);

private _mfdPage = (getUserMFDValue _vehicle) # hct_h60_mfd_mfsc_focussedMFD;
if (_mfdPage == 7 || _mfdPage == 8) then {
	_this call hct_h60_mfd_fnc_ccfs_slewCCFS;
	_this call hct_h60_mfd_fnc_ccfs_runCCFS;
	_this call hct_h60_mfd_fnc_ccfs_renderCCFS;
} else {
	[_vehicle] call hct_h60_mfd_fnc_slewTAC;
};
