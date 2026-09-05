// Phase 1 (WP1): vtx_H60_base's AnimationSources are owned by vtx_UH60
// (UH60/config/cfgAnimationSources.hpp). This file is an honest delta: it only
// ADDS sources or EXTENDS existing ones with properties this addon owns
// (MASS_* weight logic, forceAnimate wiring, onPhaseChanged handlers, the
// blade-fold set, FFV windows, wipers). Re-opened classes carry only the
// added properties; duplicated declarations were removed 2026-09-05 after the
// live merged values were captured in the WP0 config-dump baseline.
class AnimationSources: AnimationSources {
  // owned by UH60; forward-declared so parents resolve at rapify time —
  // referenced below and by the variant blocks' ANIM_INIT re-opens
  class LandingLight_Show;
  class ACCLow;
  class RotorHFold;
  class Hoist_hide;
  class cabindoor_L;
  class cabindoor_R;
  class HH60GRadar_show;
  class HH60GFlir_show;

  class GunnerSeats_Hide {
    displayName = "Hide Gunner Seats";
    mass = -MASS_GUNNERSEATS;
    onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
  };
  class CabinSeats_Hide {
    mass = -MASS_CABINSEATS;
    lockCargoAnimationPhase = 1;
    //lockCargo[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // if forceAnimatePhase is equal to the phase of this animation sources, every sources from forceAnimate will be changed with their given phase
    forceAnimatePhase = 0;
    // animationSource1, phase, animationSource2, phase... No probabilities here, only true or false
    forceAnimate[] = {
      "ERFS_show", 0,
      "GAU21_L_Hide", 1,
      "GAU21_R_Hide", 1
    };
  };
  class CabinSeats_1_Hide {
    mass = -MASS_CABINSEATS3;
    //lockCargoAnimationPhase = 1;
    //lockCargo[] = { 8, 9, 10 };
  };
  class CabinSeats_2_Hide {
    mass = -MASS_CABINSEATS4;
    //lockCargoAnimationPhase = 1;
    //lockCargo[] = { 4, 5, 6, 7 };
    forceAnimatePhase = 0;
    forceAnimate[] = {
      "GAU21_L_Hide", 1,
      "GAU21_R_Hide", 1
    };
  };
  class CabinSeats_3_Hide {
    mass = -MASS_CABINSEATS4;
    //lockCargoAnimationPhase = 1;
    //lockCargo[] = { 0, 1, 2, 3 };
    forceAnimatePhase = 0;
    forceAnimate[] = {
      "ERFS_show", 0,
      "GAU21_L_Hide", 1,
      "GAU21_R_Hide", 1
    };
  };
  class Minigun_Mount_L_hide {
    mass = -MASS_GUNMOUNT;
    forceAnimatePhase = 1;
    forceAnimate[] = { "Minigun_L_hide", 1 };
  };
  class Minigun_Mount_R_hide {
    mass = -MASS_GUNMOUNT;
    forceAnimatePhase = 1;
    forceAnimate[] = { "Minigun_R_hide", 1 };
  };
  class Minigun_L_hide {
    mass = -MASS_MINIGUN;
  };
  class Minigun_R_hide {
    mass = -MASS_MINIGUN;
  };
  class RADAR_HIDE {
    mass = -MASS_RADAR;
  };
  class FLIR_HIDE {
    mass = -MASS_FLIR;
  };
  class PylonForward_L {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class PylonForward_R {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class ERFS_show {
    mass = MASS_ERFS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "CabinSeats_Hide", 1,
      "GAU21_L_Hide", 1,
      "GAU21_R_Hide", 1
    };
  };
  class MAWS_Tubes_Show {
    //mass = MASS_MAWS; // only adjusts position
    onPhaseChanged = "params ['_vehicle', '_phase']; _vehicle animate ['MAWS_Stubs_hide', _phase, true];";
  };
  class LASS_show {
    mass = MASS_LASS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "ESSS", 0,
      "EGMS", 0
    };
  };
  class MLASS_show {
    mass = MASS_LASS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "ESSS", 0,
      "EGMS", 0
    };
  };
  class ESSS_show {
    mass = MASS_ESSS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "EGMS", 0,
      "LASS", 0
    };
  };
  class EGMS_show {
    //displayName = "Show EGMS";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_EGMS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "ESSS", 0,
      "LASS", 0
    };
  };
  class GAU21_L_Hide {
    mass = -MASS_GAU21;
    forceAnimatePhase = 0;
    forceAnimate[] = {
      "CabinSeats_Hide", 1,
      "ERFS_show", 0
    };
  };
  class GAU21_R_Hide {
    mass = -MASS_GAU21;
    forceAnimatePhase = 0;
    forceAnimate[] = {
      "CabinSeats_Hide", 1,
      "ERFS_show", 0
    };
  };
  class Skis_show {
    mass = MASS_SKIS;
  };
  class HH60Flares_show {
    mass = MASS_HH60FLARES;
  };
  class MH60MMisc_show {
    //displayName = "Show MH-60M Exterior parts";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_MH60M_MISC;
  };
  class Fuelprobe_show {
    mass = MASS_PROBE;
  };
  class Cockpitdoors_Hide {
    mass = -MASS_COCKPITDOORS;
  };
  class SearchLight_Show: LandingLight_Show {};
  class window_l: LandingLight_Show {};
  class window_r: LandingLight_Show {};
  class Wipers: ACCLow {};
  class window_l_ffv {
    source = "door";
    animPeriod = 1;
    initPhase = 0;
  };
  class window_r_ffv: window_l_ffv {};
  class Fold_Stabilator_rotate: RotorHFold {};
  class Fold_Stabilator_l: RotorHFold {};
  class Fold_Stabilator_r: RotorHFold {};
  class Fold_TailRotorOut: RotorHFold {};
  class Fold_TailRotorRotate: RotorHFold {};
  class Fold_Blade3: RotorHFold {};
  class Fold_Blade4: RotorHFold {};
  class Fold_Blade1: RotorHFold {animPeriod=10;};
  class Fold_Blade2: Fold_Blade1 {};
};
