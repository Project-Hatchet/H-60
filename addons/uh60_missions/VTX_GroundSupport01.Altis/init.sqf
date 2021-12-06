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
            private _turretPath = _x;
            private _unit = _heli turretUnit _turretPath;
            if !(isPlayer _unit) then {
                ([_heli, _turretPath] call ace_common_fnc_getTurretDirection) params ["_gunPos", "_gunDir"];
                private _cameraDir = positionCameraToWorld [0,0,0] vectorFromTo positionCameraToWorld [0,0,1];
                private _aimTarget = objNull;
                {
                    if (isNull _aimTarget) then {
                        //_x params ["_target", "_side", "_type", "_position", "_age"];
                        _x params ["", "_target"];
                        private _targetPos = getPosASL _target;
                        private _los = _gunPos vectorFromTo _targetPos;
                        private _targetAngle = acos ((_gunDir vectorDotProduct _los) / (vectorMagnitude _gunDir * vectorMagnitude _los));
                        if (_targetAngle < 10) then {
                            _aimTarget = _target;
                        };
                        //systemChat format ["%1 | %2", _target, _targetAngle];
                    };
                } forEach (_unit targetsQuery [objNull, sideUnknown, "", [], 0]);
                //private _aim = _gunDir vectorDotProduct _los;
                //systemChat str [_x, _aim];
                //if (_aim > 0.997) then {
                //private _cameraAngle = acos ((_gunDir vectorDotProduct _cameraDir) / (vectorMagnitude _gunDir * vectorMagnitude _cameraDir));
                if !(isNull _aimTarget) then {
                    weaponState [_heli, _x] params ["", "_muzzle", "_firemode"];
                {
                    _x params ["_xMagazine", "_xTurret", "_xAmmo", "_id", "_owner"];
                    if (_xTurret isEqualTo _turretPath) exitWith {
                        _heli action ["UseMagazine", _heli, _unit, _owner, _id];
                    };
                } forEach magazinesAllTurrets _heli;
                    if(vtx_uh60_ui_showDebugMessages) then {systemChat str _aimTarget;};
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
