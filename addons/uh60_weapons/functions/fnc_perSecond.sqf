params ["_vehicle"];

[_vehicle] call vtx_uh60_weapons_fnc_updateMFDValues;
vtx_uh60_hellfire_currentTof = (vtx_uh60_hellfire_currentTof - 1) max -1;

if (ace_player == driver _vehicle) then {
  if (_vehicle getVariable ["vtx_uh60_weapons_masterArm_isSafe", false]) then {
    // MASTER SAFE
    if (isNil {ace_player getVariable "vtx_masterArm_actionID"}) then {
      // Block firing
      ace_player setVariable ["vtx_masterArm_actionID", [
        ace_player, "DefaultAction", {
          params ["", "_unit"];
          private _vehicle = vehicle _unit;
          if (
            _vehicle == _unit || // Is Not in vehicle
            {_unit != driver _vehicle}
          ) exitWith {
            private _ehID = _unit getVariable "vtx_masterArm_actionID";
            if (!isNil "_ehID") then {
              // Remove block
              [_unit, "DefaultAction", _ehID] call ace_common_fnc_removeActionEventHandler;
              _unit setVariable ["vtx_masterArm_actionID", nil];
              [localize "STR_ace_safemode_TookOffSafety", getText (configOf _vehicle >> "picture")] call ace_common_fnc_displayTextPicture;
            };

            false
          };
          (weaponState [_vehicle, _vehicle unitTurret _unit]) params ["", "_vehicleMuzzle"];
          // Is FFV
          if (currentMuzzle _unit != _vehicleMuzzle) exitWith { false };

          // Block firing
          true
        }, {}
      ] call ace_common_fnc_addActionEventHandler];
      [localize "STR_ace_safemode_PutOnSafety", getText (configOf _vehicle >> "picture")] call ace_common_fnc_displayTextPicture;
    };
  } else {
    // MASTER ARM
    private _ehID = ace_player getVariable "vtx_masterArm_actionID";
    if (!isNil "_ehID") then {
      // Remove block
      [ace_player, "DefaultAction", _ehID] call ace_common_fnc_removeActionEventHandler;
      ace_player setVariable ["vtx_masterArm_actionID", nil];
      [localize "STR_ace_safemode_TookOffSafety", getText (configOf _vehicle >> "picture")] call ace_common_fnc_displayTextPicture;
    };
  };
};
