/*
 * vtx_uh60_mfd_fnc_ccfs_bounce
 *
 * CCFS: reflects the ball off a paddle, angled by where it hit.
 *
 * params [(number) paddle centre]
 */

params ["_center"];
vtx_uh60_ccfs_ballPos params ["_x", "_y"];
private _diff = (_y - _center);
vtx_uh60_ccfs_ballVelocity = [_xVelocity * -1, _diff / 10];
