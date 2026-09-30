class troop_commander: CargoTurret {
  gunnerForceOptics = 0;
  gunnerAction = "passenger_low01";
  gunnerInAction = "passenger_low01";
  memoryPointsGetInGunner = "pos Cargo R";
  memoryPointsGetInGunnerDir = "pos Cargo R dir";
  gunnerName = "Troop Commander";
  gunnerCompartments = Compartment2;
  proxyIndex = 11;
  // #510 (2026-09-07, builds 1-7): every config permutation exhausted - this
  // seat matched the vanilla attenuating cargo seats (Mohawk ramp, Ghost Hawk
  // rear bench) line-for-line and stayed loud. Root cause is the MODEL: turret
  // listeners without turn-out machinery get the GEOMETRIC interior test, and
  // the View Geometry LOD has holes at this seat (open side band z -2.55..-1.71
  // both sides) and over the cockpit (no canopy above y~0.3). The profile lines
  // below are correct and engage once the View Geometry is made airtight
  // (model branch). Do NOT add canHideGunner/forceHideGunner (builds 4-5: no
  // effect here) or isPersonTurret=1 (builds 6-7: no acoustic effect, and it
  // hands the TC a personal FFV weapon - inGunnerMayFire=0 does not cage it).
  isPersonTurret = 0;
  selectionFireAnim = "";
  disableSoundAttenuation = 0;
  soundAttenuationTurret = "VTX_H60_CabinAttenuation"; // #510: was unfiltered - this seat is camera-external like all CargoTurret children
  // 1200 = View Cargo (47G MP-MFD law: point at a LOD that EXISTS); the =0
  // vanilla-parity probe (build 7) had no acoustic effect either way
  LODTurnedIn = 1200;
  LODTurnedOut = 1200;
};
