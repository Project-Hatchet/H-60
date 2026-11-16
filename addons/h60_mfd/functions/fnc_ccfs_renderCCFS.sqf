/*
 * hct_h60_mfd_fnc_ccfs_renderCCFS
 *
 * CCFS: draws the menu or the game (paddles, ball, score) into the MFD values.
 *
 * params [(object) vehicle, (number) frame time]
 */

params ["_vehicle", "_frametime"];
if (hct_h60_ccfs_gameState == "MENU") exitWith {
	private _text = switch (true) do {
		case (isNull hct_h60_ccfs_playerSelected): {"NO PLAYERS"};
		case (hct_h60_ccfs_playerSelected == player): {"AIRCRAFT AI"};
		default {name hct_h60_ccfs_playerSelected};
	};
	_vehicle setUserMFDText [49, _text];
};
if (hct_h60_ccfs_gameState != "MENU") exitWith { // in game
	// MENU
	// WAITING
	// CONNECTED
	// PLAYING
	// PAUSED
	// DISCONNECTED
	// ENDED
	private _text = switch (hct_h60_ccfs_gameState) do {
		case "WAITING": {"Waiting for other player"};
		case "CONNECTED": {
			format ["%1 connected to game, ready to start", hct_h60_ccfs_playerSelected]
		};
		case "PLAYING": {
			format ["%1  %2   PLAYING   %4  %3", name player, hct_h60_ccfs_score # 0, name hct_h60_ccfs_playerSelected, hct_h60_ccfs_score # 1]
		};
		case "PAUSED": {
			format ["%1  %2   PAUSED   %4  %3", name player, hct_h60_ccfs_score # 0, name hct_h60_ccfs_playerSelected, hct_h60_ccfs_score # 1]
		};
		case "SCORE": {
			format ["%1  %2   SCORE   %4  %3", name player, hct_h60_ccfs_score # 0, name hct_h60_ccfs_playerSelected, hct_h60_ccfs_score # 1]
		};
		case "DISCONNECTED": {
			"OPPONENT DISCONNECTED FROM GAME"
		};
		case "ENDED": {
			private _winner = "";
			if (hct_h60_ccfs_score # 0 >= hct_h60_ccfs_winningScore) then {
				_winner = name player;
			};
			if (hct_h60_ccfs_score # 1 >= hct_h60_ccfs_winningScore) then {
				_winner = name hct_h60_ccfs_playerSelected;
			};
			format ["GAME FINISHED - %1 WON", _winner];
		};
		default {""};
	};
	_vehicle setUserMFDText [49, _text];

	// paddles
	_vehicle setUserMFDValue [2, hct_h60_ccfs_paddlePositions # 0];
	_vehicle setUserMFDValue [3, hct_h60_ccfs_paddlePositions # 1];
	_vehicle setUserMFDValue [4, hct_h60_ccfs_ballPos # 0];
	_vehicle setUserMFDValue [5, hct_h60_ccfs_ballPos # 1];
};
