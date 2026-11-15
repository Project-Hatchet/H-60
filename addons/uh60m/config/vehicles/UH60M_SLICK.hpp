// hct_UH60M_SLICK — the armed ViV-cargo variant (miniguns SHOWN for
// self-defense; Riverman's 2026-08-17 armament ruling). Sole full declaration
// (Phase 1 PR A): merged from UH60's identity half and uh60_config's systems
// half. UH60's five overridden hide-lines (GunnerSeats/Minigun/Mount = 1) were
// dead values the later loader always beat — the live 0s below are the ruling.
// Member order preserved from the pre-merge engine result (config-dump proven).
class hct_UH60M_SLICK: hct_H60_base {
  scope = 2;
  editorPreview = "z\vtx\addons\uh60m\data\preview\vtx_UH60M_SLICK.jpg"; // dev tester report 2026-09-07: never had one (verified back to 0.7.9)
  forceInGarage = 1;
  displayName = "$STR_hct_uh60m_UH60MSlick";
  transportSoldier=0;
  cargoProxyIndexes[] = {};
  cargoAction[] = {};

  class AnimationSources: AnimationSources {
    ANIM_INIT(Hoist_hide,1);
    class GunnerSeats_Hide: GunnerSeats_Hide {
      initPhase = 0;
      onPhaseChanged = "";
    };
    // Guns shown (armament ruling)
    ANIM_INIT(Minigun_L_hide,0);
    ANIM_INIT(Minigun_R_hide,0);
    ANIM_INIT(Minigun_Mount_L_hide,0);
    ANIM_INIT(Minigun_Mount_R_hide,0);
    ANIM_INIT(Minigun_Sight_L_hide,1);
    ANIM_INIT(Minigun_Sight_R_hide,1);
    // Seats
    ANIM_INIT(CabinSeats_1_Hide,1);
    ANIM_INIT(CabinSeats_2_Hide,1);
    ANIM_INIT(CabinSeats_3_Hide,1);
    // Door seats
    // Turret paths on the SLICK tree: [0] copilot, [1]/[2] door gunners,
    // [3]/[4] Door Right 1/2, [5]/[6] Door Left 1/2 (cargoTurretsDoor order).
    // Pre-fix these locked [[3],[4]] (right seats) from the LEFT door and
    // [[1],[2]] — the DOOR GUNNERS — from the right door (dev tester report
    // 2026-09-23: "crew seats not enterable"). Now mirrors the MEDEVAC pattern.
    class cabindoor_L: cabindoor_L {
      initPhase = 1;
      onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[5], [6]] ;";
    };
    class cabindoor_R: cabindoor_R {
      initPhase = 1;
      onPhaseChanged = "params ['_vehicle', '_phase']; {_vehicle lockTurret [_x, _phase == 1]} forEach [[3], [4]] ;";
    };
  }; // AnimationSources
  class Turrets: Turrets {
#define COPILOT_MOUNT_NVGHUD
    #include "\z\vtx\addons\uh60_config\config\turrets\copilot.hpp"
#undef COPILOT_MOUNT_NVGHUD
    class MainTurret: MainTurret {};
    class RightDoorGun: RightDoorGun {};
    #include "\z\vtx\addons\uh60_config\config\turrets\cargoTurretsDoor.hpp"
  };
  #include "\z\vtx\addons\uh60_config\config\vehicleTransportSlick.hpp"
  class MFD: MFD {
    class HCT_MFD_1_NOFLIR :           HCT_MFD_1_NOFLIR {};
    class HCT_MFD_1_CMWS :      HCT_MFD_1_CMWS {};
    class HCT_MFD_1_Monospace : HCT_MFD_1_Monospace {};
    class HCT_MFD_1_Bold :      HCT_MFD_1_Bold {};
    class HCT_MFD_2_NOFLIR :           HCT_MFD_2_NOFLIR {};
    class HCT_MFD_2_CMWS :      HCT_MFD_2_CMWS {};
    class HCT_MFD_2_Monospace : HCT_MFD_2_Monospace {};
    class HCT_MFD_2_Bold :      HCT_MFD_2_Bold {};
    class HCT_MFD_3_NOFLIR :           HCT_MFD_3_NOFLIR {};
    class HCT_MFD_3_CMWS :      HCT_MFD_3_CMWS {};
    class HCT_MFD_3_Monospace : HCT_MFD_3_Monospace {};
    class HCT_MFD_3_Bold :      HCT_MFD_3_Bold {};
    class HCT_MFD_4_NOFLIR :           HCT_MFD_4_NOFLIR {};
    class HCT_MFD_4_CMWS :      HCT_MFD_4_CMWS {};
    class HCT_MFD_4_Monospace : HCT_MFD_4_Monospace {};
    class HCT_MFD_4_Bold :      HCT_MFD_4_Bold {};
    class NVGHUD: NVGHUD {};
    class HCT_CLOCK: HCT_CLOCK {};
    class HCT_ESIS_Horizon: HCT_ESIS_Horizon {};
    class HCT_ESIS_Misc: HCT_ESIS_Misc {};
    class HCT_FDRight: HCT_FDRight {};
    class HCT_FDLeft: HCT_FDLeft {};
    class HCT_FMS_L: HCT_FMS_L {};
    class HCT_FMS_R: HCT_FMS_R {};
    class HCT_ESIS_BOOT: HCT_ESIS_BOOT {};
  };
  // HeliSim seats (SEATS_* in uh60_helisim bmkhs_config/helisim_seats.hpp)
  class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_SLICK };
}; // hct_UH60M_SLICK
