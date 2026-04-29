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

if (_propagate && vtx_uh60_flir_otherPilotIsPlayer) then {
  [_rot_dir, _target, _targetObject, _immediate, false] remoteExecCall ["vtx_uh60_flir_fnc_syncPilotCamera", vtx_uh60_flir_otherPilot, false];
} else {
    params ["_rot_dir", "_target", "_targetObject"];
  switch (count _rot_dir) do {
    case 0: {};
    case 2: {
      hct_vehicle setPilotCameraRotation _rot_dir;

#ifdef DEBUG_MODE_FULL
  if !(getPilotCameraTarget hct_vehicle # 0) then {
    //systemChat str "Rotation";
  };
#endif

    };
    case 3: {
      hct_vehicle setPilotCameraDirection _rot_dir;

#ifdef DEBUG_MODE_FULL
  if !(getPilotCameraTarget hct_vehicle # 0) then {
    //systemChat str "Direction";
  };
#endif

      };
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
};
true
