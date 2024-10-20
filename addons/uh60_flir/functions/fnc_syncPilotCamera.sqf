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
 * [_vehicle] call vtx_uh60_flir_fnc_syncPilotCamera
 */

params ["_rot_dir", "_target", ["_targetObject", objNull], ["_immediate", false], ["_propagate", true]];
// systemChat str _this;
if (_propagate) then {
  private _targets = (crew _vehicle) - [player];
  [_rot_dir, _target, _targetObject, _immediate, false] remoteExecCall ["vtx_uh60_flir_fnc_syncPilotCamera", _targets, false];
} else {
    params ["_rot_dir", "_target", "_targetObject"];
  switch (count _rot_dir) do {
    case 2: { vxf_vehicle setPilotCameraRotation _rot_dir; };
    case 3: { vxf_vehicle setPilotCameraDirection _rot_dir; };
  };
  if (!isNull _targetObject) then {
    vxf_vehicle setPilotCameraTarget _targetObject;
  } else {
    vxf_vehicle setPilotCameraTarget _target;
  };
  vtx_uh60_flir_pilotCameraTarget = getPilotCameraTarget vxf_vehicle;
  if (vtx_uh60_flir_pilotCameraTarget # 0) then {
    vtx_uh60_flir_pilotCameraTarget set [2, _targetObject];
  };
};
true