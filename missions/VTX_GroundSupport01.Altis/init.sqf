if (hasInterface) then {
  vtx_uh60_doorguns_fnc_prepareAIGunners = {
    private _heli = vehicle player;
    {
      private _u = _heli turretUnit _x;
      if (isNull _u) then {
        _u = group player createUnit ["B_Helicrew_F", [0,0,0], [], 0, "NONE"];
        [_u] joinSilent player;
        _u moveInTurret [_heli, _x];
      };
      if !(isPlayer _u) then {
          _u setSkill 1;
          private _turretWeapons = _heli weaponsTurret _x;
          if ("vtx_wpn_m134_safe" in _turretWeapons) then {
            _heli removeWeaponTurret ["vtx_wpn_m134_safe", _x];
          };
          if !("vtx_wpn_m134" in _turretWeapons) then {
            _heli addWeaponTurret ["vtx_wpn_m134", _x];
          };
      };
    } forEach [[1], [2]];
    hint "Ctrl + LMB to fire";
  };

  private _action = ["vtx_prepareAIGunners","AI Doorgunners","",vtx_uh60_doorguns_fnc_prepareAIGunners,{
    true
  }] call ace_interact_menu_fnc_createAction;
  {
    [_x, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToClass;
  } forEach ["vtx_UH60M_O","vtx_MH60M_O","vtx_HH60_O","vtx_MH60S_Pylons_GAU21L_O","vtx_MH60S_GAU21L_O"];

  vtx_uh60_doorguns_fnc_forceAIGunnerFire = {
    private _heli = vehicle player;
    {
      private _unit = _heli turretUnit _x;
      if !(isPlayer _unit) then {
          private _targetPos = getPos getAttackTarget _unit;
          ([_heli, _x] call ace_common_fnc_getTurretDirection) params ["_gunPos", "_gunDir"];
          private _cameraDir = positionCameraToWorld [0,0,0] vectorFromTo positionCameraToWorld [0,0,1];
          private _los = _gunPos vectorFromTo _targetPos;
          //private _aim = _gunDir vectorDotProduct _los;
          //systemChat str [_x, _aim];
          //if (_aim > 0.997) then {
          private _cameraAngle = acos ((_gunDir vectorDotProduct _cameraDir) / (vectorMagnitude _gunDir * vectorMagnitude _cameraDir));
          private _targetAngle = acos ((_gunDir vectorDotProduct _los) / (vectorMagnitude _gunDir * vectorMagnitude _los));
          //systemChat str [_x, round _cameraAngle];
          if (_cameraAngle < 10 || {_targetAngle < 10}) then {
              weaponState [_heli, _x] params ["", "_muzzle", "_firemode"];
              _unit forceWeaponFire [_muzzle, _firemode];
          };
      };
    } forEach [[1], [2]];
  };

  [
    "UH-60M Blackhawk","vtx_uh60_doorguns_forceAIGunnerFire","AI Gunner Fire",
    {call vtx_uh60_doorguns_fnc_forceAIGunnerFire}, {},
    [240,[false,true,false]]                                       // Ctrl + Left Mouse
  ] call CBA_fnc_addKeybind;
};
