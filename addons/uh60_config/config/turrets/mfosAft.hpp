// MFOS aft crew-chief seats (MH-60M DAP fit, model pass 2026-09-07/17).
// FFV person turrets anchored on the dedicated aft-seat proxies (cargo03.026/.027
// added to the model for exactly these positions). Side convention learned in
// test-fit pass 1 (2026-09-17): model -x renders as the RIGHT seat in game, so
// the L seat rides proxy 27 (+x) and R rides 26 (-x).
// NO turn-out on these seats: the turned-out FFV pose clips through floor and
// seat back here. canHideGunner 0 removes the turn in/out toggle entirely (the
// MH-47's hoist-operator pattern) and doubles as sound hygiene: a turret with
// canHideGunner 1 pins the driver's camPos and kills interior sound (L04/#510).
// "Turning out" is replaced by the Turn In / Turn Out swap (fnc_ccSwap): ACE
// self-interactions that move the crew chief to the aft-most bench spot on
// their side (proxies 18/19) to see and clear the tail, and back.
class MFOSCrewChief_L: CargoTurret {
  gunnerName = "L Crew Chief";
  gunnerType = "vtx_uh60_doorgunner";
  gunnerCompartments = "Compartment2";
  gunnerAction = passenger_inside_1;
  gunnerInAction = passenger_inside_1;
  canHideGunner = 0;
  forceHideGunner = 0;
  hideWeaponsGunner = 0;
  isPersonTurret = 1;
  LODTurnedIn = 1200;
  LODTurnedOut = 1200;
  LODOpticsIn = 1200;
  LODOpticsOut = 1200;
  memoryPointsGetInGunner = "pos Cargo L";
  memoryPointsGetInGunnerDir = "pos Cargo L dir";
  proxyIndex = 27;
  // test-fit pass 2 (2026-09-17): sides good at +/-90; another 10 down
  minElev=-80; maxElev=40; initElev=0;
  minTurn=-90; maxTurn=90; initTurn=0;
  class TurnIn {
    limitsArrayTop[] = {{40, 65}, {45, 0}, {40, -105}};
    limitsArrayBottom[] = {{-40, 45}, {-45, 0}, {-40, -30}, {-20, -40}};
  };
};
class MFOSCrewChief_R: MFOSCrewChief_L {
  gunnerName = "R Crew Chief";
  memoryPointsGetInGunner = "pos Cargo R";
  memoryPointsGetInGunnerDir = "pos Cargo R dir";
  proxyIndex = 26;
};

// Turned-out spots: door-sill sitting positions in the cargo door - the SAME
// proxies (15/12) the base M's "Door Left 2" / "Door Right 1" seats ride, so
// pose and placement match those seats exactly (passenger_bench_1; the
// inherited passenger_inside_1 sat the player "legs up higher", test-fit 4).
// Test-fit 6 (2026-09-18): moved from the 14/13 pair ("Door Left 1"/"Door
// Right 2") to the 15/12 pair to try tail visibility from the other sill
// spot. Swap-only turn-out replacement targets for the crew chiefs via
// fnc_ccSwap; locked at init (uh60_misc XEH_postInit) so they never appear
// in get-in, scroll seat-change, or ACE Change Seats.
class MFOSCrewChiefOut_L: MFOSCrewChief_L {
  gunnerName = "L Crew Chief (Turned Out)";
  proxyIndex = 15;
  gunnerAction = "passenger_bench_1";
  gunnerInAction = "passenger_bench_1";
  // Walk-in, L SEAT ONLY (Riverman: dial the left in, then mirror to the
  // right): tail side = soldier's left = NEGATIVE azimuth (positive =
  // soldier's right). Test-fit 4: -120 -> -80 (could aim through the tail
  // skin). Test-fit 5: -80 -> -50 (could still turn left far enough to see
  // inside the cabin). Nose side untouched.
  minElev=-50; maxElev=30; initElev=0;
  minTurn=-50; maxTurn=120; initTurn=0;
  class TurnIn {
    limitsArrayTop[] = {{30, 110}, {30, -50}};
    limitsArrayBottom[] = {{-50, 110}, {-50, -50}};
  };
};
class MFOSCrewChiefOut_R: MFOSCrewChiefOut_L {
  gunnerName = "R Crew Chief (Turned Out)";
  memoryPointsGetInGunner = "pos Cargo R";
  memoryPointsGetInGunnerDir = "pos Cargo R dir";
  proxyIndex = 12;
  // R keeps the pre-walk-in arcs until the L numbers are approved; its tail
  // side is the MIRROR (positive azimuth), so the eventual change here is
  // maxTurn/+110 entries down to ~+80, not the minus side.
  minTurn=-120; maxTurn=120;
  class TurnIn {
    limitsArrayTop[] = {{30, 110}, {30, -110}};
    limitsArrayBottom[] = {{-50, 110}, {-50, -110}};
  };
};
