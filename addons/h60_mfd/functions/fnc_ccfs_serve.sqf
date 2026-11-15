/*
 * hct_h60_mfd_fnc_ccfs_serve
 *
 * CCFS: puts the ball back in the middle and serves it to the other side.
 *
 * params none
 */

hct_h60_ccfs_ballPos = [0.5,0.5];
hct_h60_ccfs_ballVelocity = [hct_h60_ccfs_serveSide, -1 + (random 2)] vectorMultiply 0.005;
hct_h60_ccfs_serveSide = hct_h60_ccfs_serveSide * -1;
