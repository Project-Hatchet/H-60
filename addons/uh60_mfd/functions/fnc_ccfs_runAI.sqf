vtx_uh60_ccfs_ballPos params ["_x", "_y"];
vtx_uh60_ccfs_paddlePositions params ["_left", "_right"];
private _maxMoveSpeed = (_y - _right) * 0.05;
private _moveDirection = _maxMoveSpeed;
vtx_uh60_ccfs_paddlePositions set [1, ((vtx_uh60_ccfs_paddlePositions # 1) + _moveDirection) max 0 min 1];