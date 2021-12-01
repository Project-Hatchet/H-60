class AnimationSources {
  class GAU21_L_Hide {
    source="user";
    animPeriod=1;
    initPhase=1;
  };
  class GAU21_R_Hide {
    source="user";
    animPeriod=1;
    initPhase=1;
  };
  class RADAR_HIDE {
    source="user";
    animPeriod=1;
    initPhase=1;
  };
  class FLIR_HIDE {
    source="user";
    animPeriod=1;
    initPhase=1;
  };
  class Fuelprobe_Show {
    displayName = "Show Fuel Probe";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Cockpitdoors_Hide {
    displayName = "Hide Cockpit doors";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class ERFS_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MAWS_Tubes_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class LASS_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class ESSS_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  //exterior parts
  class GunnerSeats_Hide {
    displayName = "Hide Gunner Seats";
    source="user";
    animPeriod=1;
    initPhase=0;
    onPhaseChanged = "params ['_vehicle', '_phase']; _vehicle lockTurret [[1], _phase == 1];  _vehicle lockTurret [[2], _phase == 1];";
  };
  class CabinSeats_Hide {
    displayName = "Hide Cabin Seats";
    source="user";
    animPeriod=1;
    initPhase=0;
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
  };
  class Minigun_L_hide {
    displayName = "Hide Minigun (L)";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Minigun_R_hide {
    displayName = "Hide Minigun (R)";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class cabindoor_L {
    source="user";
    animPeriod=1;
    initPhase=0;
    onPhaseChanged = "systemChat str _this";
  };
  class cabindoor_R {
    source="user";
    animPeriod=1;
    initPhase=0;
    onPhaseChanged = "systemChat str _this";
  };
};
