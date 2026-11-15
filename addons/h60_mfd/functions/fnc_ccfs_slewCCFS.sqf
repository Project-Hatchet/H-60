/*
 * hct_h60_mfd_fnc_ccfs_slewCCFS
 *
 * CCFS: moves this player's paddle with the MFD slew input.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

if (hct_h60_mfd_slewY != 0 && hct_h60_ccfs_gameState == "PLAYING" || hct_h60_ccfs_gameState == "SCORE") then {
	hct_h60_ccfs_paddleMoved = true;
	hct_h60_ccfs_paddlePositions set [0,
		((hct_h60_ccfs_paddlePositions # 0) + (hct_h60_mfd_slewY / 50)) max 0.18 min 0.82
	];
};
