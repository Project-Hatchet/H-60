/*
 * vtx_uh60_flir_fnc_perSecond
 *
 * handles occasional updates of data for FLIR
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (vtx_uh60_flir_setting_animateTurret && {local _vehicle}) then {
  [_vehicle] call vtx_uh60_flir_fnc_syncAnimation;
};

if (_vehicle getVariable ["vtx_uh60_flir_stowed", true]) then {
  private _bootTime = _vehicle getVariable ["vtx_uh60_flir_boot_time", -1];
  if (_bootTime == -1) then {
    _vehicle setUserMFDText [10, "PRESS DEPLOY TO BOOT PAYLOAD"];
  } else {
    if (time < _bootTime + 20) then {
      private _timeRemaining = (_bootTime + 20) - time;
      _vehicle setUserMFDText [10, format["PREPARING PAYLOAD %1", floor _timeRemaining]];
    } else {
      _vehicle setVariable ["vtx_uh60_flir_stowed", false, true];
      {
        if ((getUserMFDValue _vehicle) # _x > 5 - 0.99 && (getUserMFDValue _vehicle) # _x < 5 + 0.99) exitWith {
          [_vehicle, _x, 5, true] call vtx_uh60_mfd_fnc_switchPage;
        };
      } forEach [23, 24, 25, 26];
    };
  };
};