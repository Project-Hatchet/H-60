params ["_vehicle"];
[] call vtx_uh60_mfd_fnc_ccfs_syncCCFS;
if (vtx_uh60_ccfs_gameState == "MENU") exitWith {
	[_vehicle, 8, 7] call vtx_uh60_mfd_fnc_ccfs_pageChangeCCFS;
};
if (vtx_uh60_ccfs_gameState != "MENU") exitWith {
	[_vehicle, 7, 8] call vtx_uh60_mfd_fnc_ccfs_pageChangeCCFS;
	if (vtx_uh60_ccfs_isHost) then {
		_this call vtx_uh60_mfd_fnc_ccfs_runGame;
	};
};