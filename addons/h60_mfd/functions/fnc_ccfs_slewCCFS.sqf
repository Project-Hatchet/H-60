/*
 * vtx_uh60_mfd_fnc_ccfs_slewCCFS
 *
 * CCFS: moves this player's paddle with the MFD slew input.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];

if (vtx_uh60_mfd_slewY != 0 && vtx_uh60_ccfs_gameState == "PLAYING" || vtx_uh60_ccfs_gameState == "SCORE") then {
	vtx_uh60_ccfs_paddleMoved = true;
	vtx_uh60_ccfs_paddlePositions set [0,
		((vtx_uh60_ccfs_paddlePositions # 0) + (vtx_uh60_mfd_slewY / 50)) max 0.18 min 0.82
	];
};
