/*
 * hct_h60_mfd_fnc_ccfs_checkBounce
 *
 * CCFS: bounces the ball off whichever paddle it reached.
 *
 * params none
 *
 * returns (bool) bounced
 */

hct_h60_ccfs_ballPos params ["_x", "_y"];
hct_h60_ccfs_paddlePositions params ["_right", "_left"];
private _paddleHeight = 0.1;
private _bounce = false;	
if (_y < _left + _paddleHeight && _y > _left - _paddleHeight) then {
	// hct_h60_ccfs_ballVelocity = [_xVelocity * -1, _yVelocity];
	//systemChat str ["LEFT", _x];
	if (_x < 0.05) then {
		[_left] call hct_h60_mfd_fnc_ccfs_bounce;
		_bounce = true;
	};
};
if (_y < _right + _paddleHeight && _y > _right - _paddleHeight) then {
		// hct_h60_ccfs_ballVelocity = [_xVelocity * -1, _yVelocity];
	//systemChat str ["RIGHT", _x];
	if (_x > (1-0.05)) then {
		[_right] call hct_h60_mfd_fnc_ccfs_bounce;
		_bounce = true;
	};
};
_bounce
