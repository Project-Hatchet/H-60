// MFOS aft gunner seats (MH-60M DAP fit, Phase: model pass 2026-09-07).
// FFV person turrets anchored on the dedicated aft-seat proxies (cargo03.026/.027
// added to the model for exactly these positions - the shared cabin cargo
// proxies are floor-sitting spots and do not line up with the MFOS seats).
// Turn-out follows the doorgunsFFV window pattern: turned in fires through the
// door arc, turned out leans past the sill for the out-and-below shots.
// Turn limits assume the proxies face outboard like the seats; expect one
// test-fit pass on limits and pose once the proxies are in.
class MFOSAftGunner_L: CargoTurret {
  gunnerName = "Aft Gunner Left";
  gunnerType = "vtx_uh60_doorgunner";
  gunnerCompartments = "Compartment2";
  gunnerAction = vehicle_turnout_2;
  gunnerInAction = passenger_inside_1;
  canHideGunner = 1;
  forceHideGunner = 0;
  hideWeaponsGunner = 0;
  isPersonTurret = 1;
  LODTurnedIn = 1200;
  LODTurnedOut = 1200;
  LODOpticsIn = 1200;
  LODOpticsOut = 1200;
  memoryPointsGetInGunner = "pos Cargo L";
  memoryPointsGetInGunnerDir = "pos Cargo L dir";
  proxyIndex = 26;
  minElev=-80; maxElev=40; initElev=0;
  minTurn=-80; maxTurn=80; initTurn=0;
  minOutElev = -80; maxOutElev = 40; initOutElev = 0;
  minOutTurn = -160; maxOutTurn = 160; initOutTurn = 0;
  class TurnIn {
    limitsArrayTop[] = {{40, 55}, {45, 0}, {40, -95}};
    limitsArrayBottom[] = {{-20, 35}, {-25, 0}, {-20, -20}, {0, -30}};
  };
  class TurnOut: TurnIn {
    limitsArrayTop[] = {{60, 90}, {60, -95}};
    limitsArrayBottom[] = {{-30, 90}, {-80, 20}, {-80, -30}, {0, -95}};
  };
};
class MFOSAftGunner_R: MFOSAftGunner_L {
  gunnerName = "Aft Gunner Right";
  memoryPointsGetInGunner = "pos Cargo R";
  memoryPointsGetInGunnerDir = "pos Cargo R dir";
  proxyIndex = 27;
};
