#include "..\script_component.hpp"
/*
 * Author: Ampersand
 * Assign pylon.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Turret Path <ARRAY>
 * 2: Magazine Classname <STRING>
 * 3: Number of rounds <NUMBER>
 * 4: Pylon Index <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cameraOn, [0], "VTX_M230_Chaingun_L",298, 1] call vtx_uh60_weapons_fnc_assignPylon
 *
 * Public: No
 */

params ["_vehicle", "_turretPath", "_magazineClass", "_numRounds", "_pylon"];
TRACE_5("assignPylon",_vehicle,_turretPath,_magazineClass,_numRounds,_pylon);

if (!alive _vehicle) exitWith {WARNING("vehicle dead/null");};

if (isServer) then {
  private _turretOwnerID = _vehicle turretOwner _turretPath;
  if (_turretOwnerID == 0) then {
    [QGVAR(assignPylonLocalEH), _this, [_vehicle]] call CBA_fnc_targetEvent;
  } else {
    [QGVAR(assignPylonLocalEH), _this, _turretOwnerID] call CBA_fnc_ownerEvent;
  };
} else {
  [QGVAR(assignPylonEH), _this] call CBA_fnc_serverEvent;
};
