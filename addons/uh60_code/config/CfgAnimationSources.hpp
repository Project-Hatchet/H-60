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
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_RADAR;
  };
  class FLIR_HIDE {
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_FLIR;
  };
  class FLIR_BACK {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Fuelprobe_Show {
    // proxy part, garage doesn't work displayName = "Show Fuel Probe";
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
  class ERFS_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_ERFS;
  };
  class MAWS_Tubes_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_MAWS;
  };
  class LASS_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_LASS;
  };
  class ESSS_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_ESSS;
  };
  class GAU21_L_Hide {
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_GAU21;
  };
  class GAU21_R_Hide {
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_GAU21;
  };
};
