/*
 * vtx_uh60_mfd_fnc_slewCCFS
 *
 * handles slewing the CCFS
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

vtx_uh60_ccfs_paddlePositions = [
	((vtx_uh60_ccfs_paddlePositions # 0) + vtx_uh60_mfd_slewY) max 0 min 1,
	((vtx_uh60_ccfs_paddlePositions # 1) + vtx_uh60_mfd_slewY) max 0 min 1
];