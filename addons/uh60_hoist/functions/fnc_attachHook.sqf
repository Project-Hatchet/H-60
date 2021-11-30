#include "script_component.hpp"
/*
 * Author: Yax
 * attach the hook to the player and start the loop that handles getting in and out
 *
 * Arguments:
 * 0: Hook <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_hook, _unit] call vtx_uh60_hoist_fnc_attachHook
 */

params ["_hook", "_unit"];

if (!local _unit) exitWith {[QGVAR(attachHook), _this, _unit] call CBA_fnc_targetEvent;};

if (_unit getVariable [QGVAR(pfhID), -1] != -1) exitWith {false};
if (!isNull (_unit getVariable ["vtx_attachedHook", objNull])) exitWith {false};
if (!isNull (_unit getVariable ["vtx_attachedHelper", objNull])) exitWith {false};
if (!isNull (_hook getVariable ["vtx_attachedUnit", objNull])) exitWith {false};

private _heli = _hook getVariable "vtx_uh60_hoist_heli";
if (isNil "_heli") exitWith { false };

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{ false };
_hoist_vars params ["_rope", "_helper"];

if (vehicle _unit == _unit) then {
  _helper attachTo [_unit, [0,0.15,0.2], "pelvis"];
};
_unit setVariable ["vtx_detachHookActionID", _unit addAction [
  localize LSTRING(DetachHook),
  {
    vtx_uh60_hoist_pfhID = -1;
    detach (_this # 3)
  },
  _helper, // Args
  0, // Priority
  true, // ShowWindow
  true, // HideOnUse
  "GetOut", // Shortcut
  "vehicle player == player"
]];
_unit setVariable ["vtx_attachedHook", _hook, true];
_unit setVariable ["vtx_attachedHelper", _helper, true];
_hook setVariable ["vtx_attachedUnit", _unit, true];

_unit setVariable [QGVAR(pfhID), [{
  params ["_args", "_pfhID"];
  _args params ["_unit", "_hook", "_helper", "_rope", "_heli"];

  private _vehicleUnit = vehicle _unit;
  private _isUnitInHook = _vehicleUnit == _hook;
  private _hookAttachedToUnit = (attachedTo _helper) == _unit;

  // Exit checks
  {
    if (isNull _x) then {
      diag_log _args;
      _unit setVariable [QGVAR(pfhID), -1, true];
    };
  } forEach _args;

  // Unit in other vehicle
  if (_vehicleUnit != _unit && {_vehicleUnit != _hook}) then {
    diag_log "in other vic";
    _unit setVariable [QGVAR(pfhID), -1, true];
  };

  // Unit exited/detached hook
  if (!_isUnitInHook && {!_hookAttachedToUnit}) then {
    diag_log "manual";
    _unit setVariable [QGVAR(pfhID), -1, true];
  };

  // Exit
  if (_pfhID != (_unit getVariable [QGVAR(pfhID), -1])) exitWith {
    diag_log "vtx_uh60_hoist_fnc_attachHook";
    [_pfhID] call CBA_fnc_removePerFrameHandler;
    if (_isUnitInHook) then {
      moveOut _unit;
    };
    if (_hookAttachedToUnit) then {
      detach _helper;
      _hook lockCargo [1, false];
    };
    _hook setVariable ["vtx_attachedUnit", objNull, true];
    _unit setVariable ["vtx_attachedHook", objNull, true];
    _unit setVariable ["vtx_attachedHelper", objNull, true];
    private _actionID = _unit getVariable ["vtx_detachHookActionID", -1];
    if (_actionID > -1) then {
      _unit removeAction _actionID;
    };
    _unit setVariable ["vtx_detachHookActionID", -1];
    _unit setVariable [QGVAR(pfhID), -1, true];
  }; // Exit

  //private _isHookMoving = (speed _helper > 0.1); // Not used
  private _canStand = getPos _hook # 2 < 1;
  private _length = ropeLength _rope;
  private _distance = ((ropeEndPosition _rope) # 0) distance ((ropeEndPosition _rope) # 1);
  private _isRopeStretched = (_distance > _length + 1.5);

  if (_isRopeStretched) then {
    if (!_isUnitInHook) then {
      detach _helper;
      _hook lockCargo [1, false];
      _unit moveInCargo _hook;
    };
  } else {
    if (_canStand) then {
      moveOut _unit;
      _hook lockCargo [1, true];
      _helper attachTo [_unit, [0,0.15,0.2], "pelvis"];
    };
  };
}, 0.1, [_unit, _hook, _helper, _rope, _heli]] call CBA_fnc_addPerFrameHandler, true];

true
