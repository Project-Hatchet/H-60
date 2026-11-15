// hct_UH60M — the baseline Army UH-60M. Sole full declaration (Phase 1 PR A):
// merged from UH60's identity half and uh60_config's systems half, 2026-09-05.
// Member order preserved from the pre-merge engine result (config-dump proven).
class hct_UH60M: hct_H60_base {
    scope = 2;
    editorPreview = "z\vtx\addons\uh60m\data\preview\vtx_UH60M.jpg";
    ace_medical_treatment_patientSeats[] = {0, 1, 2, 3};
    hiddenSelectionsTextures[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "z\vtx\addons\uh60_misc\data\textures\UH-60M_US_Army\main_co.paa", // "UH-60M (US Army)" skin (ruling 2026-10-07)
        "z\vtx\addons\UH60\Data\Exterior\Misc_co.paa",
        "z\vtx\addons\uh60_misc\data\textures\UH-60M_US_Army\tail_co.paa",
        "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa", // markings: no overlay (the US Army text is painted into the tail texture)
        "", // "left_num_1",
        "", // "left_num_2",
        "", // "right_num_1",
        "", // "right_num_2",
        "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
    };
    class AnimationSources: AnimationSources {
      ANIM_INIT(FuelProbe_show,0);
      ANIM_INIT(Minigun_Sight_L_hide,1);
      ANIM_INIT(Minigun_Sight_R_hide,1);
      ANIM_INIT(Hoist_hide,1);
      ANIM_INIT(cabindoor_L,1);
      ANIM_INIT(cabindoor_R,1);
      class CabinSeats_1_Hide {
        displayName = "$STR_hct_uh60m_HideCabinSeatsFront";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS3;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 8, 9, 10 };
      };
      class CabinSeats_2_Hide {
        displayName = "$STR_hct_uh60m_HideCabinSeatsMiddle";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS4;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 4, 5, 6, 7 };
        forceAnimatePhase = 0;
        forceAnimate[] = {
          "GAU21_L_Hide", 1,
          "GAU21_R_Hide", 1
        };
      };
      class CabinSeats_3_Hide {
        displayName = "$STR_hct_uh60m_HideCabinSeatsRear";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS4;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 0, 1, 2, 3 };
        forceAnimatePhase = 0;
        forceAnimate[] = {
          "ERFS_show", 0,
          "GAU21_L_Hide", 1,
          "GAU21_R_Hide", 1
        };
      };
    }; // AnimationSources
    class MFD: MFD {
      class HCT_MFD_1_NOFLIR :    HCT_MFD_1_NOFLIR {};
      class HCT_MFD_1_CMWS :      HCT_MFD_1_CMWS {};
      class HCT_MFD_1_Monospace : HCT_MFD_1_Monospace {};
      class HCT_MFD_1_Bold :      HCT_MFD_1_Bold {};
      class HCT_MFD_2_NOFLIR :    HCT_MFD_2_NOFLIR {};
      class HCT_MFD_2_CMWS :      HCT_MFD_2_CMWS {};
      class HCT_MFD_2_Monospace : HCT_MFD_2_Monospace {};
      class HCT_MFD_2_Bold :      HCT_MFD_2_Bold {};
      class HCT_MFD_3_NOFLIR :    HCT_MFD_3_NOFLIR {};
      class HCT_MFD_3_CMWS :      HCT_MFD_3_CMWS {};
      class HCT_MFD_3_Monospace : HCT_MFD_3_Monospace {};
      class HCT_MFD_3_Bold :      HCT_MFD_3_Bold {};
      class HCT_MFD_4_NOFLIR :    HCT_MFD_4_NOFLIR {};
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
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        class MFD {
              class NVGHUD: NVGHUD_COPILOT {};
        };
      };
      class MainTurret: MainTurret {};
      class RightDoorGun: RightDoorGun {};
      #include "\z\vtx\addons\uh60_config\config\turrets\troopCommander.hpp"
    };
  // HeliSim seats (SEATS_* in uh60_helisim bmkhs_config/helisim_seats.hpp)
  class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_UH60M };
}; // hct_UH60M
