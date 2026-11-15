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
	// fnc_slewTAC calls this every frame the cursor moves: send at most ten times a
	// second (it was a remoteExec per frame), plus one trailing send so the crew
	// ends up where the cursor stopped
	if (diag_tickTime < (missionNamespace getVariable ["hct_h60_mfd_tacSyncNext", 0])) exitWith {
		if !(missionNamespace getVariable ["hct_h60_mfd_tacSyncPending", false]) then {
			hct_h60_mfd_tacSyncPending = true;
			[{
				hct_h60_mfd_tacSyncPending = false;
				[true] call hct_h60_mfd_fnc_tac_sync;
			}, [], 0.1] call CBA_fnc_waitAndExecute;
		};
	};
	hct_h60_mfd_tacSyncNext = diag_tickTime + 0.1;
	private _targets = (crew vehicle player) - [player]; // was the caller's _vehicle
	if (_targets isEqualTo []) exitWith {}; // alone: no zero-target remoteExec in the RPT
	[false, hct_h60_mfd_tac_cursorPos, hct_h60_mfd_tac_mapPos, hct_h60_tac_hookedObject] remoteExecCall ["hct_h60_mfd_fnc_tac_sync", _targets, false];
} else {
	// systemChat "RECEIVING TAC SYNC";
	hct_h60_mfd_tac_mapPos = _mapPos;
	hct_h60_mfd_tac_cursorPos = _cursorPos;
	hct_h60_tac_hookedObject = _hookedObject;
};
