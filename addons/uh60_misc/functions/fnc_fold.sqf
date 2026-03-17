#include "script_component.hpp"
/*
 * Author: Ampersand
 * Fold the helicopter's blades and stabilators.
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 * 1: Phase <NUMBER>
 * 2: Speed <BOOLEAN or NUMBER>
 *   true: Instant
 *   -1: Freeze at current position
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject, 1] call vtx_uh60_misc_fnc_fold
 */

params ["_heli", "_phase", ["_speed", 1]];

if (_speed isEqualTo true) exitWith {
  [_heli, _phase] call vtx_uh60_misc_fnc_foldInstant;
};
if (_speed isEqualTo -1) exitWith {
  [_heli] call vtx_uh60_misc_fnc_foldFreeze;
};

private _fnc_getAnimsTime = {
  params ["_heli", "_animInfo"];

  private _cfg = configOf _heli >> "AnimationSources";
  selectMax (_animInfo apply {
    _x params ["_name", "_phase"];
    private _animPeriod = getNumber (_cfg >> _name >> "animPeriod");
    abs ((_heli animationSourcePhase _name) - _phase) * _animPeriod;
  })
};

private _foldTime = switch (_phase) do {
  case 0: {
    ([_heli, [
      ["Fold_Blade1", 0],
      ["Fold_Blade2", 0],
      ["Fold_Stabilator_l", 0],
      ["Fold_Stabilator_r", 0],
      ["Fold_TailRotorRotate", 0]
    ]] call _fnc_getAnimsTime) + ([_heli, [
      ["Fold_Blade3", 0],
      ["Fold_Blade4", 0],
      ["Fold_Stabilator_rotate", 0],
      ["Fold_TailRotorOut", 0]
    ]] call _fnc_getAnimsTime);
  };
  case 1: {
    ([_heli, [
      ["RotorHFold", -((_heli animationSourcePhase "rotorh") mod 1 + 0.125)],
      ["RotorVFold", -((_heli animationSourcePhase "rotorv") mod 1)]
    ]] call _fnc_getAnimsTime) + ([_heli, [
      ["Fold_Blade1", 1],
      ["Fold_Blade2", 1],
      ["Fold_Stabilator_l", 1],
      ["Fold_Stabilator_r", 1],
      ["Fold_TailRotorRotate", 1]
    ]] call _fnc_getAnimsTime) + ([_heli, [
      ["Fold_Blade3", 1],
      ["Fold_Blade4", 1],
      ["Fold_Stabilator_rotate", 1],
      ["Fold_TailRotorOut", 1]
    ]] call _fnc_getAnimsTime);
  };
  default { 15 }
};
systemChat str _foldTime;

private _fnc_onFinish = {
    (_this select 0) params ["_unit", "_heli"];

};
private _fnc_onFailure = {
    (_this select 0) params ["_unit", "_heli"];

    [_heli] call vtx_uh60_misc_fnc_foldFreeze;
};
private _fnc_condition = {
    (_this select 0) params ["_unit"];
    "ToolKit" in (items _unit)
};
[(_foldTime + 0.5), [ACE_player, _heli], _fnc_onFinish, _fnc_onFailure, localize LSTRING(FoldingRotors), _fnc_condition] call ace_common_fnc_progressBar;

// Unfold
if (_phase == 0) exitWith {
  _target = [];
  [
    "Fold_Blade1",
    "Fold_Blade2",
    "Fold_Stabilator_l",
    "Fold_Stabilator_r",
    "Fold_TailRotorRotate"
  ] apply {
    _heli animateSource [_x, _phase, _speed];
    _target pushBack [_x, _phase];
  };

  private _delay = _speed * 10 + 0.5;

  [{
    params ["_args", "_target"];
    _args params ["_heli", "_phase", ["_speed", 1]];

    _target findIf {
      _x params ["_anim", "_phase"];

      (_heli animationSourcePhase _anim) isNotEqualTo _phase
    } == -1
  }, {
    params ["_args", "_target"];
    _args params ["_heli", "_phase", ["_speed", 1]];

    [
      "Fold_Blade3",
      "Fold_Blade4",
      "Fold_Stabilator_rotate",
      "Fold_TailRotorOut"
    ] apply {_heli animateSource [_x, _phase, _speed]};

  }, [_this, _target], _delay, {
    params ["_args", "_target"];
    _args params ["_heli", "_phase", ["_speed", 1]];
    [_heli] call vtx_uh60_misc_fnc_foldFreeze;
  }] call CBA_fnc_waitUntilAndExecute;
};

// Fold
private _delay = 0;
private _target = [];

[
  ["RotorHFold", "rotorh", 0.125],
  ["RotorVFold", "rotorv", 0]
] apply {
  _x params ["_foldAnim", "_rotorAnim", "_phaseOffset"];

  private _rotorAnimPhase = (_heli animationSourcePhase _rotorAnim) mod 1 + _phaseOffset;

  _heli animateSource [_foldAnim, -_rotorAnimPhase, _speed];
  _target pushBack [_foldAnim, -_rotorAnimPhase];

  if (_delay < abs _rotorAnimPhase) then {
    _delay = (abs _rotorAnimPhase) * 5 + 0.5;
  };
};

[{
  params ["_args", "_target"];
  _args params ["_heli", "_phase", ["_speed", 1]];

  _target findIf {
    _x params ["_anim", "_phase"];

    (_heli animationSourcePhase _anim) isNotEqualTo _phase
  } == -1
}, {
  params ["_args", "_target"];
  _args params ["_heli", "_phase", ["_speed", 1]];

  _target = [];
  [
    "Fold_Blade3",
    "Fold_Blade4",
    "Fold_Stabilator_rotate",
    "Fold_TailRotorOut"
  ] apply {
    _heli animateSource [_x, _phase, _speed];
    _target pushBack [_x, _phase];
  };

  private _delay = 5 * _speed;

  [{
    params ["_args", "_target"];
    _args params ["_heli", "_phase", ["_speed", 1]];

    if (_target findIf {
      _x params ["_anim", "_phase"];

      (_heli animationSourcePhase _anim) isNotEqualTo _phase
    } > -1) exitWith {
      [_heli] call vtx_uh60_misc_fnc_foldFreeze;
    };

    [
      "Fold_Blade1",
      "Fold_Blade2",
      "Fold_Stabilator_l",
      "Fold_Stabilator_r",
      "Fold_TailRotorRotate"
    ] apply {_heli animateSource [_x, _phase, _speed]};

  }, [_args, _target], _delay] call CBA_fnc_waitAndExecute;
}, [_this, _target] , _delay, {
  params ["_args", "_target"];
  _args params ["_heli", "_phase", ["_speed", 1]];
  [_heli] call vtx_uh60_misc_fnc_foldFreeze;
}] call CBA_fnc_waitUntilAndExecute;
