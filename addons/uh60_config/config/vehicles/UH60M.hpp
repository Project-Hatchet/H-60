// vtx_UH60M — the baseline Army UH-60M. Sole full declaration (Phase 1 PR A):
// merged from UH60's identity half and uh60_config's systems half, 2026-09-05.
// Member order preserved from the pre-merge engine result (config-dump proven).
class vtx_UH60M: vtx_H60_base {
    scope = 2;
    editorPreview = "z\vtx\addons\UH60\Data\Preview\vtx_UH60M.jpg";
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
        "z\vtx\addons\UH60\Data\Exterior\Hull Main_co.paa",
        "z\vtx\addons\UH60\Data\Exterior\Misc_co.paa",
        "z\vtx\addons\UH60\Data\Exterior\Hull Tail_co.paa",
        "z\vtx\addons\UH60\Data\Exterior\Markings\Markings_ca.paa",
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
        displayName = "Hide Cabin Seats (Front)";
        source="user";
        animPeriod=1;
        initPhase=0;
        mass = -MASS_CABINSEATS3;
        lockCargoAnimationPhase = 1;
        lockCargo[] = { 8, 9, 10 };
      };
      class CabinSeats_2_Hide {
        displayName = "Hide Cabin Seats (Middle)";
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
        displayName = "Hide Cabin Seats (Rear)";
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
      class VTX_MFD_1_NOFLIR :    VTX_MFD_1_NOFLIR {};
      class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
      class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
      class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
      class VTX_MFD_2_NOFLIR :    VTX_MFD_2_NOFLIR {};
      class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
      class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
      class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
      class VTX_MFD_3_NOFLIR :    VTX_MFD_3_NOFLIR {};
      class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
      class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
      class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
      class VTX_MFD_4_NOFLIR :    VTX_MFD_4_NOFLIR {};
      class VTX_MFD_4_CMWS :      VTX_MFD_4_CMWS {};
      class VTX_MFD_4_Monospace : VTX_MFD_4_Monospace {};
      class VTX_MFD_4_Bold :      VTX_MFD_4_Bold {};
      class NVGHUD: NVGHUD {};
      class VTX_CLOCK: VTX_CLOCK {};
      class VTX_ESIS_Horizon: VTX_ESIS_Horizon {};
      class VTX_ESIS_Misc: VTX_ESIS_Misc {};
      class VTX_FDRight: VTX_FDRight {};
      class VTX_FDLeft: VTX_FDLeft {};
      class VTX_FMS_L: VTX_FMS_L {};
      class VTX_FMS_R: VTX_FMS_R {};
      class VTX_ESIS_BOOT: VTX_ESIS_BOOT {};
    };
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        class MFD {
              class NVGHUD: NVGHUD_COPILOT {};
        };
      };
      class MainTurret: MainTurret {};
      class RightDoorGun: RightDoorGun {};
      #include "\z\vtx\addons\UH60\config\turrets\troopCommander.hpp"
    };
}; // vtx_UH60M
