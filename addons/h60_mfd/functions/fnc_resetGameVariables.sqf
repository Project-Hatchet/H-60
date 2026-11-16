/*
 * hct_h60_mfd_fnc_resetGameVariables
 *
 * CCFS: resets score, paddles and ball for a new game.
 *
 * params none
 */

hct_h60_ccfs_score = [0,0];
hct_h60_ccfs_paddleMoved = false;
hct_h60_ccfs_paddlePositions = [0.5,0.5];
hct_h60_ccfs_ballPos = [0.5,0.5];
hct_h60_ccfs_serveSide = -1;
hct_h60_ccfs_ballVelocity = [hct_h60_ccfs_serveSide, -1 + (random 2)] vectorMultiply 0.005;
