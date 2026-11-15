#include "..\script_component.hpp"
/*
 * hct_h60_mfd_fnc_ccfs_CyclePlayer
 *
 * CCFS (MFD pong) lobby: steps the selected opponent through the H-60 pilots in the mission.
 *
 * params [(object) vehicle, (number) direction]
 */

params ["_vehicle", "_direction"];
private _availablePlayers = [player];
{
	private _isIn60 = (vehicle _x) isKindOf QBASE_CLASS;
	private _copilotTurretIndex = [_vehicle] call ace_common_fnc_getTurretCopilot;
	private _isDriver = _x == driver (vehicle _x);
	private _isCopilot = (_vehicle unitTurret _x) isEqualTo _copilotTurretIndex;
	private _isHosting = _x getVariable ["hct_h60_openLobby", false];
	//systemChat str [_isDriver, _isCopilot, _isHosting, (_isDriver || _isCopilot) && _isHosting];
	if ((_isDriver || _isCopilot) && _isHosting) then {
		_availablePlayers pushBack _x;
	};
} forEach allPlayers;
private _curIndex = _availablePlayers find hct_h60_ccfs_playerSelected;
if (_curIndex == -1) exitWith {hct_h60_ccfs_playerSelected = _availablePlayers # 0; hct_h60_ccfs_playerSelected};
if (_curIndex + _direction < 0) exitWith {hct_h60_ccfs_playerSelected = _availablePlayers # ((count _availablePlayers) - 1); hct_h60_ccfs_playerSelected};
if (_curIndex + _direction == count _availablePlayers) exitWith {hct_h60_ccfs_playerSelected = _availablePlayers # 0; hct_h60_ccfs_playerSelected};
hct_h60_ccfs_playerSelected = _availablePlayers # (_curIndex + _direction);
hct_h60_ccfs_playerSelected
