/*
 * hct_h60_mfd_fnc_ccfs_runGame
 *
 * CCFS, per frame: advances the ball and AI while PLAYING, handles scoring.
 *
 * params none
 */

switch (hct_h60_ccfs_gameState) do {
	case "PLAYING": {
		[] call hct_h60_mfd_fnc_ccfs_updateBall;
		if (!isPlayer hct_h60_ccfs_playerSelected) then {
			[] call hct_h60_mfd_fnc_ccfs_runAI;
		};
		{
			if (_x >= hct_h60_ccfs_winningScore) then {
				["ENDED"] call hct_h60_mfd_fnc_ccfs_changeGameState;
			};
		} forEach hct_h60_ccfs_score;
	};
	case "SCORE": {
		if (time > hct_h60_ccfs_lastScore + 1) then {
			["PLAYING"] call hct_h60_mfd_fnc_ccfs_changeGameState;
			[] call hct_h60_mfd_fnc_ccfs_serve;
		};
	};
};
