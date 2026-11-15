/*
 * hct_h60_mfd_fnc_ccfs_runAI
 *
 * CCFS: moves the AI opponent's paddle towards the ball.
 *
 * params none
 */

hct_h60_ccfs_ballPos params ["_x", "_y"];
hct_h60_ccfs_paddlePositions params ["_left", "_right"];
private _maxMoveSpeed = (_y - _right) * 0.05;
private _moveDirection = _maxMoveSpeed;
hct_h60_ccfs_paddlePositions set [1, ((hct_h60_ccfs_paddlePositions # 1) + _moveDirection) max 0.18 min 0.82];
