/*
 * hct_h60_mfd_fnc_ccfs_runCCFS
 *
 * CCFS, per frame: syncs with the opponent and shows the menu or game page.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
[] call hct_h60_mfd_fnc_ccfs_syncCCFS;
if (hct_h60_ccfs_gameState == "MENU") exitWith {
	[_vehicle, 8, 7] call hct_h60_mfd_fnc_ccfs_pageChangeCCFS;
};
if (hct_h60_ccfs_gameState != "MENU") exitWith {
	[_vehicle, 7, 8] call hct_h60_mfd_fnc_ccfs_pageChangeCCFS;
	if (hct_h60_ccfs_isHost) then {
		_this call hct_h60_mfd_fnc_ccfs_runGame;
	};
};
