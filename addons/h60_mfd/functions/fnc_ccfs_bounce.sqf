/*
 * hct_h60_mfd_fnc_ccfs_bounce
 *
 * CCFS: reflects the ball off a paddle, angled by where it hit.
 *
 * params [(number) paddle centre]
 */

params ["_center"];
hct_h60_ccfs_ballPos params ["_x", "_y"];
private _diff = (_y - _center);
hct_h60_ccfs_ballVelocity = [(hct_h60_ccfs_ballVelocity # 0) * -1, _diff / 10]; // was the caller's _xVelocity
