vtx_uh60_ccfs_ballPos = vtx_uh60_ccfs_ballPos vectorAdd vtx_uh60_ccfs_ballVelocity;
vtx_uh60_ccfs_ballPos params ["_x", "_y"];
vtx_uh60_ccfs_ballVelocity params ["_xVelocity", "_yVelocity"];
private _bounced = [] call vtx_uh60_mfd_fnc_ccfs_checkBounce;
if ((_x < 0 || _x > 1)) then {
  if (_x < 0.5) then {
    vtx_uh60_ccfs_score set [0, (vtx_uh60_ccfs_score # 0) + 1];
  } else {
    vtx_uh60_ccfs_score set [1, (vtx_uh60_ccfs_score # 1) + 1];
  };
  vtx_uh60_ccfs_lastScore = time;
  ["SCORE"] call vtx_uh60_mfd_fnc_ccfs_changeGameState;
  if (isPlayer vtx_uh60_ccfs_playerSelected) then {
    ["vtx_uh60_ccfs_score", [vtx_uh60_ccfs_score # 1, vtx_uh60_ccfs_score # 0]] call vtx_uh60_mfd_fnc_setRemoteVariable;
  };
  //vtx_uh60_ccfs_ballVelocity = [_xVelocity * -1, _yVelocity];
};
private _ballSize = 0.015;
private _top = 0.1;
private _bottom = 0.9;
if (_y < _top + _ballSize || _y > _bottom - _ballSize) then {
  vtx_uh60_ccfs_ballVelocity = [_xVelocity, _yVelocity * -1];
};