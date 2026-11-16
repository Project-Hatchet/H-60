// hct_UH60M_MEDEVAC (HH-60M) — the only unarmed military variant.
// Lifted verbatim from cfgVehicles.hpp into its own file (Phase 1 PR A);
// include paths adjusted one level for the vehicles\ folder.
class hct_UH60M_MEDEVAC: hct_H60_base {
    scope = 2;
    editorPreview = "z\vtx\addons\uh60m\data\preview\vtx_UH60M_MEDEVAC.jpg"; // dev tester report 2026-09-07: never had one (verified back to 0.7.9)
    forceInGarage = 1;
    cargoAction[] = {
      "passenger_low01",
      "passenger_generic01_leanleft",
      "passenger_generic01_leanleft",
      "passenger_generic01_leanright"
    };
    cargoProxyIndexes[] = {1, 2, 3, 4, 24, 25, 6, 7, 12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
    ace_medical_treatment_patientSeats[] = {11, 12, 13, 14};
    displayName = "$STR_hct_uh60m_HH60MMEDEVAC";
    hiddenSelectionsTextures[] = {
      "","","","","","","","","","","","","","","","",
      "z\vtx\addons\uh60_misc\data\textures\UH-60M_US_Army_Medevac\main_co.paa",
      "z\vtx\addons\UH60\Data\Exterior\Misc_co.paa",
      "z\vtx\addons\uh60_misc\data\textures\UH-60M_US_Army_Medevac\tail_co.paa",
      "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","", // Markings, door numbers L1, L2, R1, R2
      "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
    };
    transportSoldier=4;
    class AnimationSources: AnimationSources {
      ANIM_INIT(CabinSeats_1_Hide,1);
      ANIM_INIT(CabinSeats_2_Hide,1);
      ANIM_INIT(Hoist_hide,0);
      ANIM_INIT(Minigun_Mount_L_hide,1);
      ANIM_INIT(Minigun_Mount_R_hide,1);
      ANIM_INIT(Minigun_L_hide,1);
      ANIM_INIT(Minigun_R_hide,1);
      // Door seats
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
      class CopilotTurret: CopilotTurret {
        class MFD {
              class NVGHUD: NVGHUD_COPILOT {};
        };
      };
      //Door guns not fitted - no ammunition aboard
      class MainTurret: MainTurret { magazines[] = {}; };
      class RightDoorGun: RightDoorGun { magazines[] = {}; };
      #include "\z\vtx\addons\uh60_config\config\turrets\doorgunsFFV.hpp"
      #include "\z\vtx\addons\uh60_config\config\turrets\cargoTurrets.hpp"
    };
    #include "\z\vtx\addons\uh60_config\config\vehicleTransport.hpp"
    class hct_turret_1 {
      class interaction {
        #include "\z\vtx\addons\uh60_config\config\hct_window_l.hpp"
      };
    };
    class hct_turret_2 {
      class interaction {
        #include "\z\vtx\addons\uh60_config\config\hct_window_r.hpp"
      };
    };
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
}; // hct_UH60M_MEDEVAC
