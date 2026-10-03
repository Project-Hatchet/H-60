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
 * [[], [0,0,0]] call vtx_uh60_flir_fnc_syncPilotCamera
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
// vtx_uh60_flir_pilotCameraTarget (the sole writer is below), so the mod-side
// state that handleSlew/updateCamera/setStabilization now treat as
// authoritative went stale on the locker's own machine - fullscreen locks
// were stomped as "rogue" next frame, the copilot's own view never followed,
// and the lock toggle could not release. Only ever exercised with an AI or
// empty other seat before (#538 MP follow-up)
if (_propagate && vtx_uh60_flir_otherPilotIsPlayer) then {
  [_rot_dir, _target, _targetObject, _immediate, false] remoteExecCall ["vtx_uh60_flir_fnc_syncPilotCamera", vtx_uh60_flir_otherPilot, false];
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
vtx_uh60_flir_pilotCameraTarget = getPilotCameraTarget hct_vehicle;
if (vtx_uh60_flir_pilotCameraTarget # 0) then {
  vtx_uh60_flir_pilotCameraTarget set [2, _targetObject];
};

true
