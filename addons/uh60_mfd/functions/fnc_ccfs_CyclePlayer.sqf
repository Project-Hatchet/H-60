params ["_vehicle", "_direction"];
private _availablePlayers = [player];
{
	private _isIn60 = (vehicle _x) isKindOf "vtx_h60_base";
	private _copilotTurretIndex = [_vehicle] call ace_common_fnc_getTurretCopilot;
	private _isDriver = _x == driver (vehicle _x);
	private _isCopilot = (_vehicle unitTurret _x) isEqualTo _copilotTurretIndex;
	private _isHosting = _x getVariable ["vtx_uh60_openLobby", false];
	//systemChat str [_isDriver, _isCopilot, _isHosting, (_isDriver || _isCopilot) && _isHosting];
	if ((_isDriver || _isCopilot) && _isHosting) then {
		_availablePlayers pushBack _x;
	};
} forEach allPlayers;
private _curIndex = _availablePlayers find vtx_uh60_ccfs_playerSelected;
if (_curIndex == -1) exitWith {vtx_uh60_ccfs_playerSelected = _availablePlayers # 0; vtx_uh60_ccfs_playerSelected};
if (_curIndex + _direction < 0) exitWith {vtx_uh60_ccfs_playerSelected = _availablePlayers # ((count _availablePlayers) - 1); vtx_uh60_ccfs_playerSelected};
if (_curIndex + _direction == count _availablePlayers) exitWith {vtx_uh60_ccfs_playerSelected = _availablePlayers # 0; vtx_uh60_ccfs_playerSelected};
vtx_uh60_ccfs_playerSelected = _availablePlayers # (_curIndex + _direction);
vtx_uh60_ccfs_playerSelected