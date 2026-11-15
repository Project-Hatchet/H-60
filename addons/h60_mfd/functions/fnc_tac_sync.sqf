/*
 * hct_h60_mfd_fnc_tac_sync
 *
 * TAC page: sends this pilot's cursor, map position and hook to the other crew, or applies the received ones.
 *
 * params [(bool) sender, (array) cursor pos, (array) map pos, (array) hooked object]
 *
 * NOTE: the sender branch reads the caller's _vehicle (SQF dynamic scope) - pass it explicitly when this is next touched
 */

params [["_sender", false], "_cursorPos", "_mapPos", "_hookedObject"];

if (_sender) then {
	// systemChat "SENDING TAC SYNC";
	private _targets = (crew _vehicle) - [player];
	[false, hct_h60_mfd_tac_cursorPos, hct_h60_mfd_tac_mapPos, hct_h60_tac_hookedObject] remoteExecCall ["hct_h60_mfd_fnc_tac_sync", _targets, false];
} else {
	// systemChat "RECEIVING TAC SYNC";
	hct_h60_mfd_tac_mapPos = _mapPos;
	hct_h60_mfd_tac_cursorPos = _cursorPos;
	hct_h60_tac_hookedObject = _hookedObject;
};
