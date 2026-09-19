class troop_commander: CargoTurret {
  gunnerForceOptics = 0;
  gunnerAction = "passenger_low01";
  gunnerInAction = "passenger_low01";
  memoryPointsGetInGunner = "pos Cargo R";
  memoryPointsGetInGunnerDir = "pos Cargo R dir";
  gunnerName = "Troop Commander";
  gunnerCompartments = Compartment2;
  proxyIndex = 20;
  isPersonTurret = 0;        // #510: =1 hands the TC a personal FFV weapon and buys nothing acoustically - see uh60_config/config/turrets/troopCommander.hpp
  selectionFireAnim = "";
  disableSoundAttenuation = 0;
  soundAttenuationTurret = "VTX_H60_CabinAttenuation"; // #510: was unfiltered - this seat is camera-external like all CargoTurret children
  LODTurnedIn = 1200;
  LODTurnedOut = 1200;
};
