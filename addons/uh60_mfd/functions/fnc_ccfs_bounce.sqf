params ["_center"];
vtx_uh60_ccfs_ballPos params ["_x", "_y"];
private _diff = (_y - _center);
vtx_uh60_ccfs_ballVelocity = [_xVelocity * -1, _diff / 10];