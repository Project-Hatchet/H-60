class AnimationSources: AnimationSources {
  class GunnerSeats_Hide {
    displayName = "Hide Gunner Seats";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_GUNNERSEATS;
    onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[1], [2]] ;";
  };
  class CabinSeats_Hide {
    //displayName = "Hide Cabin Seats";
    source="user";
    animPeriod=1;
    initPhase=0;
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
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_CABINSEATS3;
    //lockCargoAnimationPhase = 1;
    //lockCargo[] = { 8, 9, 10 };
  };
  class CabinSeats_2_Hide {
    source="user";
    animPeriod=1;
    initPhase=0;
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
    source="user";
    animPeriod=1;
    initPhase=0;
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
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_GUNMOUNT;
    forceAnimatePhase = 1;
    forceAnimate[] = { "Minigun_L_hide", 1 };
  };
  class Minigun_Mount_R_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_GUNMOUNT;
    forceAnimatePhase = 1;
    forceAnimate[] = { "Minigun_R_hide", 1 };
  };
  class Minigun_L_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_MINIGUN;
  };
  class Minigun_R_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = -MASS_MINIGUN;
  };
  class Minigun_Sight_L_hide {
    displayName = "Hide Minigun Sight (L)";
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Minigun_Sight_R_hide {
    displayName = "Hide Minigun Sight (R)";
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
  class FLIR_DIRECTION {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class FLIR_ELEVATION {
    source="user";
    animPeriod=1;
    initPhase=0;
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
  class Fuelprobe_show {
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
  class ERFS_show {
    displayName = "Show ERFS";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_ERFS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "CabinSeats_Hide", 1,
      "GAU21_L_Hide", 1,
      "GAU21_R_Hide", 1
    };
  };
  class MAWS_Tubes_Show {
    displayName = "Show MAWS";
    source="user";
    animPeriod=1;
    initPhase=0;
    //mass = MASS_MAWS; // only adjusts position
    onPhaseChanged = "params ['_vehicle', '_phase']; _vehicle animate ['MAWS_Stubs_hide', _phase, true];";
  };
  class LASS_show {
    //displayName = "Show LASS";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_LASS;
    forceAnimatePhase = 1;
    forceAnimate[] = {
      "ESSS", 0,
      "EGMS", 0
    };
  };
  class ESSS_show {
    //displayName = "Show ESSS";
    source="user";
    animPeriod=1;
    initPhase=0;
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
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_GAU21;
    forceAnimatePhase = 0;
    forceAnimate[] = {
      "CabinSeats_Hide", 1,
      "ERFS_show", 0
    };
  };
  class GAU21_R_Hide {
    source="user";
    animPeriod=1;
    initPhase=1;
    mass = -MASS_GAU21;
    forceAnimatePhase = 0;
    forceAnimate[] = {
      "CabinSeats_Hide", 1,
      "ERFS_show", 0
    };
  };
  class Skis_show {
    displayName = "Show Skis";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_SKIS;
  };
  class HH60Flares_show {
    displayName = "Show HH-60 Flares";
    source="user";
    animPeriod=1;
    initPhase=0;
    mass = MASS_HH60FLARES;
  };
  class cabindoor_L {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class cabindoor_R {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Stabilator_rotate_user {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class LandingLight_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  ANIMSRC(hoist_hide,user,1,0);
  ANIMSRC(hoist_hook_hide,user,1,0);
  //interriorparts
  ANIMSRC(cockpitlight_show,user,1,0);
  class CabinLight_Show {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MAP_X {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MAP_Y {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MAP_Rotation {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MAP1_Scale {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class COMM1_ROT {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class COMM2_ROT:COMM1_ROT{};
  class COMM3_ROT:COMM1_ROT{};
  class COMM4_ROT:COMM1_ROT{};
  class MVOL_ROT {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class TX_ROT {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class FD_1_ROT {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class FD_2_ROT:FD_1_ROT{};
  class FD_3_ROT:FD_1_ROT{};
  class FD_4_ROT:FD_1_ROT{};
  class FD_5_ROT:FD_1_ROT{};
  class ACCLow {
    source="user";
    animPeriod=0.00001;
    initPhase=0;
  };
  class APUFail:ACCLow{};
  class APUOn:ACCLow{};
  class BattGood:ACCLow{};
  class BattLow:ACCLow{};
  class EmerRlse:ACCLow{};
  class OilHot:ACCLow{};
  class TestLte:ACCLow{};
  class CautionEng1Out:ACCLow{};
  class CautionEng2Out:ACCLow{};
  class CautionFire:ACCLow{};
  class CautionMasterCaution:ACCLow{
    initPhase = 0;
  };
  class Gauge_temp {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Lever_RotorBrake {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Knob_LightInstPanel {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Knob_LightLowerConsole {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Knob_LightUpperConsole {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Knob_Lights_Formation {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Switch_lights_position {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_lights_collision {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_lights_cockpit {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class MFD1_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MFD2_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MFD3_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class MFD4_hide {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class ESIS_hide {
    source="user";
    animPeriod=1;
    initPhase=1;
  };
  class PowerOnOff {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class GeneratorsOnOff {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Switch_fuelboostpump1 {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_fuelboostpump2 {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_batt1 {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_batt2 {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_stbyinst {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_airsce {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Lever_fuelsys1 {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Lever_fuelsys2 {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Lever_engpower1 {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Lever_engpower2 {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Switch_ignition {
    source="user";
    animPeriod=1;
    initPhase=0;
  };
  class Switch_gen1 {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Handle_wheelbrake {
    source="user";
    animPeriod=1;
    initPhase=1;
  };
  class Switch_gen2 {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_apugen {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_apucont {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class Switch_fuelpump {
    source="user";
    animPeriod=1;
    initPhase=0.5;
  };
  class wheel_dumper_l {
    source="damper";
    wheel="Wheel_1";
  };
  class wheel_dumper_r {
    source="damper";
    wheel="Wheel_2";
  };
  class wheel_dumper_rear {
    source="damper";
    wheel="Wheel_3";
  };
  class Wheel_l_source {
    source="wheel";
    wheel="Wheel_1";
  };
  class Wheel_r_source {
    source="wheel";
    wheel="Wheel_2";
  };
  class Wheel_rear_source {
    source="wheel";
    wheel="Wheel_3";
  };
  class Gatling_1 {
    source="revolving";
    weapon="vtx_wpn_m134";
  };
  class Gatling_2 {
    source="revolving";
    weapon="vtx_wpn_m134_2nd";
  };
  class Muzzle_Flash_M134_L {
    source="ammoRandom";
    weapon="vtx_wpn_m134";
  };
  class Muzzle_Flash_M134_R {
    source="ammoRandom";
    weapon="vtx_wpn_m134_2nd";
  };
  class Switch_minigun_safe_cover_l {
    source="user";
    animPeriod=0.2;
    initPhase=0;
  };
  class Switch_minigun_safe_cover_r: Switch_minigun_safe_cover_l {};
  class Switch_minigun_safe_l: Switch_minigun_safe_cover_l {};
  class Switch_minigun_safe_r: Switch_minigun_safe_cover_l {};
};
