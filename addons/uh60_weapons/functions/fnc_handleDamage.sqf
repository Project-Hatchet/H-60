vtx_uh60_weapons_fnc_handleDamage = {
  params ["_vehicle"];
  if (!local _vehicle) exitWith {};
  private _damage = (_vehicle getHitPointDamage "WingStores");
  {
    _x params ["_pylon", "_position", "_damageThreshold"];
    hint str ["CHECKING", _damage];
    if (_damage > _damageThreshold) then {
      hint str ["DROPPING", _pylon];
      private _ammo = _vehicle ammoOnPylon _pylon;
      private _magazine = (getPylonMagazines _vehicle) # (_pylon - 1);
      if (_magazine != "" && _magazine != "VTX_M230_Chaingun_R" && _magazine != "VTX_M230_Chaingun_L") then {
      private _pylonDummy = "vtx_pylon" createVehicle [0,0,0];
        _pylonDummy setPylonLoadOut [1, _magazine, false, []];
        _pylonDummy setAmmoOnPylon [1, _ammo];
        _pylonDummy attachTo [_vehicle, _position];
        _pylonDummy disableCollisionWith _vehicle;
        _vehicle setPylonLoadout [_pylon, "", false, []];
        _pylonDummy spawn {
          sleep random 2;
          detach _this;
          _this addTorque [-5 + random 10, -5 + random 10, -5 + random 10];
        };
      };
    };
  } forEach [
    [1, [-2, 2.4, -1.4], 0.5],
    [2, [ 2, 2.4, -1.4], 0.5]
  ];
};
[] spawn {
  vehicle player setPylonLoadOut [1, "VTX_PylonRack_M261_M229", false, []];
  vehicle player setPylonLoadOut [2, "VTX_4Rnd_ACE_Hellfire_AGM114K", false, []];
  [vehicle player] call vtx_uh60_weapons_fnc_handleDamage;
};