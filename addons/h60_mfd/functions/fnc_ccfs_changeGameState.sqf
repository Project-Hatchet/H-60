/*
 * hct_h60_mfd_fnc_ccfs_changeGameState
 *
 * CCFS: sets the game state here and on the opponent's machine.
 *
 * params [(string) state]
 */

params ["_state"];
hct_h60_ccfs_gameState = _state;
["hct_h60_ccfs_gameState", _state] call hct_h60_mfd_fnc_setRemoteVariable;
