/*
 * vtx_uh60_mfd_fnc_ccfs_changeGameState
 *
 * CCFS: sets the game state here and on the opponent's machine.
 *
 * params [(string) state]
 */

params ["_state"];
vtx_uh60_ccfs_gameState = _state;
["vtx_uh60_ccfs_gameState", _state] call vtx_uh60_mfd_fnc_setRemoteVariable;
