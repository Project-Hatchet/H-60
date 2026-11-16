/*
 * Author: Ampersand
 * Deploy hoist hook
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call hct_h60_hoist_fnc_deployHook
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["hct_h60_hoist_fnc_deployHook", _heli]};

private _hoist_vars = _heli getVariable ["hct_h60_hoist_vars", []];
if (_hoist_vars isNotEqualTo []) exitWith {};

_heli animateSource ["hoist_hook_hide", 1];
private _hoistPos = [1.405, 2.03, 0.45]; // this memorypoint needs to be set in UH60 model
private _dummy = "hct_hook_helper" createVehicle [0, 0, 0]; //local to pilot for reliability
_dummy setMass 1;
_dummy attachTo [_heli, [1.405, 2.031, 0.49]];
_dummy allowDamage false;
private _hook = "hct_hook" createVehicle [0, 0, 0];
private _hookSP = _hook selectionPosition "sling_point";
_hook attachTo [_dummy, _hookSP vectorMultiply -1];
_hook allowDamage false;
detach _dummy;
_dummy setVelocity (_heli getVariable ["bmkhs_velWorldSpaceNoWind", velocity _heli]);
private _rope = ropeCreate [_heli, _hoistPos, _dummy, [0,0,0], 0.5];

_heli setVariable ["hct_h60_hoist_vars", [_rope, _dummy, _hook], true];
_hook setVariable ["hct_h60_hoist_heli", _heli, true];

// handle rope break - one handler per helicopter: replace any left by an earlier
// deploy (resetHook removes it too), so they no longer pile up per cycle
private _oldEH = _heli getVariable ["hct_h60_hoist_ropeBreakEH", -1];
if (_oldEH != -1) then { _heli removeEventHandler ["RopeBreak", _oldEH]; };
_heli setVariable ["hct_h60_hoist_ropeBreakEH", _heli addEventHandler ["RopeBreak",{
  params ["_heli", "_ropeEH", "_dummyEH"];
  (_heli getVariable ["hct_h60_hoist_vars", []]) params [
    ["_rope", objNull], ["_dummy", objNull], ["_hook", objNull]
  ];
  if (_ropeEH != _rope) exitWith {};
  _heli removeEventHandler ["RopeBreak", _thisEventHandler];
  _heli setVariable ["hct_h60_hoist_ropeBreakEH", -1];
  //systemChat "Rope broke";
  //systemChat str _this;

  if (isNull _hook && {!isNull _dummy}) then { _hook = (attachedObjects _dummy) param [0, objNull]; };
  if (!isNull _hook) then {
    detach _hook;
    _hook setVariable ["hct_h60_hoist_heli", nil, true];
    (crew _hook) apply {moveOut _x};
    deleteVehicle _hook;
  };
  deleteVehicle _dummy;
  ropeDestroy _rope;
  _heli setVariable ["hct_h60_hoist_vars", [], true];
}]];

true
