switch (vtx_uh60_ccfs_gameState) do {
	case "PLAYING": {
		[] call vtx_uh60_mfd_fnc_ccfs_updateBall;
		if (!isPlayer vtx_uh60_ccfs_playerSelected) then {
			[] call vtx_uh60_mfd_fnc_ccfs_runAI;
		};
		{
			if (_x >= vtx_uh60_ccfs_winningScore) then {
				["ENDED"] call vtx_uh60_mfd_fnc_ccfs_changeGameState;
			};
		} forEach vtx_uh60_ccfs_score;
	};
	case "SCORE": {
		if (time > vtx_uh60_ccfs_lastScore + 1) then {
			["PLAYING"] call vtx_uh60_mfd_fnc_ccfs_changeGameState;
			[] call vtx_uh60_mfd_fnc_ccfs_serve;
		};
	};
};