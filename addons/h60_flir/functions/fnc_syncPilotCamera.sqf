#include "script_component.hpp"
/*
 * Author: Ampersand
 * Sync the rotation/direction and tracking target of the pilotCamera to the other player pilot
 *
 * Arguments:
 * 0: Rotation <ARRAY> || Direction <ARRAY>
 * 1: Target <OBJECT> || Position ASL <ARRAY>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [[], [0,0,0]] call hct_h60_flir_fnc_syncPilotCamera
 */

params ["_rot_dir", "_target", ["_targetObject", objNull], ["_immediate", false], ["_propagate", true]];

#ifdef DEBUG_MODE_FULL
  if !(getPilotCameraTarget hct_vehicle # 0) then {
    //systemChat str _this;
  };
#endif

// Apply locally ALWAYS, then forward to the other pilot when they are a
// player. This used to be either/or: with a human in the other seat the
// originating client only sent and never updated its own
// hct_h60_flir_pilotCameraTarget (the sole writer is below), so the mod-side
// state that handleSlew/updateCamera/setStabilization now treat as
// authoritative went stale on the locker's own machine - fullscreen locks
// were stomped as "rogue" next frame, the copilot's own view never followed,
// and the lock toggle could not release. Only ever exercised with an AI or
// empty other seat before (#538 MP follow-up)
//
// Slewing and laser tracking call this every frame, which was one network
// message per frame to the other pilot. Forwarding is now at most 10 Hz:
// skipped frames are coalesced and the LATEST state is sent at the next slot,
// so the other pilot always ends on the final position (<= 0.1 s late).
// _immediate syncs still go out at once.
if (_propagate && hct_h60_flir_otherPilotIsPlayer) then {
  private _args = [_rot_dir, _target, _targetObject, _immediate, false];
  private _next = missionNamespace getVariable ["hct_h60_flir_nextPropagate", 0];
  if (_immediate || {diag_tickTime >= _next}) then {
    hct_h60_flir_nextPropagate = diag_tickTime + 0.1;
    hct_h60_flir_pendingPropagate = nil;
    _args remoteExecCall ["hct_h60_flir_fnc_syncPilotCamera", hct_h60_flir_otherPilot, false];
  } else {
    if (isNil "hct_h60_flir_pendingPropagate") then {
      [{
        if (isNil "hct_h60_flir_pendingPropagate") exitWith {};
        private _pending = hct_h60_flir_pendingPropagate;
        hct_h60_flir_pendingPropagate = nil;
        hct_h60_flir_nextPropagate = diag_tickTime + 0.1;
        if (hct_h60_flir_otherPilotIsPlayer) then {
          _pending remoteExecCall ["hct_h60_flir_fnc_syncPilotCamera", hct_h60_flir_otherPilot, false];
        };
      }, [], (_next - diag_tickTime) max 0] call CBA_fnc_waitAndExecute;
    };
    hct_h60_flir_pendingPropagate = _args;
  };
};

switch (count _rot_dir) do {
  case 0: {};
  case 2: {hct_vehicle setPilotCameraRotation _rot_dir};
  case 3: {hct_vehicle setPilotCameraDirection _rot_dir};
};
if (!isNull _targetObject) then {
  hct_vehicle setPilotCameraTarget _targetObject;
} else {
  hct_vehicle setPilotCameraTarget _target;
};
hct_h60_flir_pilotCameraTarget = getPilotCameraTarget hct_vehicle;
if (hct_h60_flir_pilotCameraTarget # 0) then {
  hct_h60_flir_pilotCameraTarget set [2, _targetObject];
};

true
