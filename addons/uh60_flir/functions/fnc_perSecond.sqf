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
    _vehicle setUserMFDText [10, "PRESS DEPLOY TO PREPARE FLIR PAYLOAD"];
  } else {
    if (cba_missionTime < _bootTime + 20) then {
      // must be cba_missionTime (and not 'time') to match
      // _vehicle setVariable ["vtx_uh60_flir_boot_time", _vehicle getvariable ["vtx_uh60_flir_boot_time",cba_missionTime], true];
      // in \addons\uh60_flir\functions\fnc_interaction.sqf
      private _timeRemaining = (_bootTime + 20) - cba_missionTime;
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
