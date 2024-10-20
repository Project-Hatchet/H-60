params ["_vehicle", "_pylon", "_magazine", "_ammo", "_turret"];
// systemChat str _this;
_vehicle setPylonLoadout [_pylon, _magazine, true, _turret];
_vehicle setAmmoOnPylon [_pylon, _ammo];