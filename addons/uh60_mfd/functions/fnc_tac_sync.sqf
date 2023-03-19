params [["_sender", false], "_cursorPos", "_mapPos", "_hookedObject"];

if (_sender) then {
  // systemChat "SENDING TAC SYNC";
  private _targets = (crew _vehicle) - [player];
  [false, vtx_uh60_mfd_tac_cursorPos, vtx_uh60_mfd_tac_mapPos, vtx_uh60_tac_hookedObject] remoteExecCall ["vtx_uh60_mfd_fnc_tac_sync", _targets, false];
} else {
  // systemChat "RECEIVING TAC SYNC";
  vtx_uh60_mfd_tac_mapPos = _mapPos;
  vtx_uh60_mfd_tac_cursorPos = _cursorPos;
  vtx_uh60_tac_hookedObject = _hookedObject;
};
