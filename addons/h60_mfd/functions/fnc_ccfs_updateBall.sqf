/*
 * hct_h60_mfd_fnc_ccfs_updateBall
 *
 * CCFS: moves the ball, bounces it and scores when it leaves the field.
 *
 * params none
 */

hct_h60_ccfs_ballPos = hct_h60_ccfs_ballPos vectorAdd hct_h60_ccfs_ballVelocity;
hct_h60_ccfs_ballPos params ["_x", "_y"];
hct_h60_ccfs_ballVelocity params ["_xVelocity", "_yVelocity"];
private _bounced = [] call hct_h60_mfd_fnc_ccfs_checkBounce;
if ((_x < 0 || _x > 1)) then {
	if (_x < 0.5) then {
		hct_h60_ccfs_score set [0, (hct_h60_ccfs_score # 0) + 1];
	} else {
		hct_h60_ccfs_score set [1, (hct_h60_ccfs_score # 1) + 1];
	};
	hct_h60_ccfs_lastScore = time;
	["SCORE"] call hct_h60_mfd_fnc_ccfs_changeGameState;
	if (isPlayer hct_h60_ccfs_playerSelected) then {
		["hct_h60_ccfs_score", [hct_h60_ccfs_score # 1, hct_h60_ccfs_score # 0]] call hct_h60_mfd_fnc_setRemoteVariable;
	};
	//vtx_uh60_ccfs_ballVelocity = [_xVelocity * -1, _yVelocity];
};
private _ballSize = 0.015;
private _top = 0.1;
private _bottom = 0.9;
if (_y < _top + _ballSize || _y > _bottom - _ballSize) then {
	hct_h60_ccfs_ballVelocity = [_xVelocity, _yVelocity * -1];
};
