private _vehicle = vehicle player;
{
  _x params ["_pylon", "_position", "_damageThreshold"];
  private _ammo = _vehicle ammoOnPylon _pylon;
  private _magazine = (getPylonMagazines _vehicle) # (_pylon - 1);
  if (_magazine != "" && _magazine != "VTX_M230_Chaingun_R" && _magazine != "VTX_M230_Chaingun_L") then {
  private _pylonDummy = "vtx_pylon" createVehicle [0,0,0];
    _pylonDummy setPylonLoadOut [1, _magazine, false, []];
    _pylonDummy setAmmoOnPylon [1, _ammo];
    _pylonDummy attachTo [_vehicle, _position];
    _pylonDummy disableCollisionWith _vehicle;
    _pylonDummy allowDamage false;
    _vehicle setPylonLoadout [_pylon, "", false, []];
    _pylonDummy spawn {
      sleep random 2;
      detach _this;
      _this addTorque [-5 + random 10, -5 + random 10, -5 + random 10];
    };
  };
} forEach [
  [1, [-2, 2.4, -1.4], 0.5],
  [2, [ 2, 2.4, -1.4], 0.5],
  [48, [-2.8, 2.3, -1.4], 0.5],
  [49, [ 2.8, 2.3, -1.4], 0.5]
];