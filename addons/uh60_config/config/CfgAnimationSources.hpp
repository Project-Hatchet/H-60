class AnimationSources {
  class GunnerSeats_Hide {
    displayName = "Hide Gunner Seats";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_GUNNERSEATS;
    onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
  };
  class CabinSeats_Hide {
    displayName = "Hide Cabin Seats";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_CABINSEATS;
    lockCargoAnimationPhase = 1;
    lockCargo[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // if forceAnimatePhase is equal to the phase of this animation sources, every sources from forceAnimate will be changed with their given phase
    forceAnimatePhase = 0;
    // animationSource1, phase, animationSource2, phase... No probabilities here, only true or false
    forceAnimate[] = { "ERFS", 0 };
  };
  class Minigun_Mount_L_hide {
    displayName = "Hide Gun Mount (L)";
    // if forceAnimatePhase is equal to the phase of this animation sources, every sources from forceAnimate will be changed with their given phase
    forceAnimatePhase = 1;
    // animationSource1, phase, animationSource2, phase... No probabilities here, only true or false
    forceAnimate[] = { "Minigun_L_hide", 1 };
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_GUNMOUNT;
  };
  class Minigun_Mount_R_hide {
    displayName = "Hide Gun Mount (R)";
    // if forceAnimatePhase is equal to the phase of this animation sources, every sources from forceAnimate will be changed with their given phase
    forceAnimatePhase = 1;
    // animationSource1, phase, animationSource2, phase... No probabilities here, only true or false
    forceAnimate[] = { "Minigun_R_hide", 1 };
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_GUNMOUNT;
  };
  class Minigun_L_hide {
    displayName = "Hide Minigun (L)";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_MINIGUN;
  };
  class Minigun_R_hide {
    displayName = "Hide Minigun (R)";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_MINIGUN;
  };
  class cabindoor_L {
    displayName = "Close Cabin Door (L)";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class cabindoor_R {
    displayName = "Close Cabin Door (R)";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class RADAR_HIDE {
    displayName = "Hide Radar";
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_RADAR;
    // if forceAnimatePhase is equal to the phase of this animation sources, every sources from forceAnimate will be changed with their given phase
    forceAnimatePhase = 1;
    // animationSource1, phase, animationSource2, phase... No probabilities here, only true or false
    forceAnimate[] = { "FLIR_BACK", 1 };
  };
  class FLIR_HIDE {
    displayName = "Hide FLIR";
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_FLIR;
  };
  class FLIR_BACK {
    displayName = "FLIR Off Radar";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Fuelprobe {
    displayName = "Show Fuel Probe";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_PROBE;
  };
  class Cockpitdoors_Hide {
    displayName = "Hide Cockpit doors";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_COCKPITDOORS;
  };
  class ERFS {
    displayName = "Show ERFS";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_ERFS;
    // if forceAnimatePhase is equal to the phase of this animation sources, every sources from forceAnimate will be changed with their given phase
    forceAnimatePhase = 1;
    // animationSource1, phase, animationSource2, phase... No probabilities here, only true or false
    forceAnimate[] = { "CabinSeats_Hide", 1 };
  };
  class MAWS_Tubes_Show {
    displayName = "Show MAWS";
    source="user";
    animPeriod=1;
    initPhase=0;
    //mass = MASS_MAWS; // only adjusts position
    onPhaseChanged = "params ['_vehicle', '_phase']; _vehicle animate ['MAWS_Stubs_hide', _phase, true];";
  };
  class LASS_Show {
    //displayName = "Show LASS";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_LASS;
  };
  class ESSS_Show {
    //displayName = "Show ESSS";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_ESSS;
  };
  class GAU21_L_Hide {
    displayName = "Hide GAU-21 (L)";
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_GAU21;
  };
  class GAU21_R_Hide {
    displayName = "Hide GAU-21 (R)";
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_GAU21;
  };
  class Skis {
    displayName = "Show Skis";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_SKIS;
  };
  class HH60Flares {
    displayName = "Show HH-60 Flares";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_HH60FLARES;
  };
};
