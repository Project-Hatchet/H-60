// vtx_UH60M_MEDEVAC (HH-60M) — the only unarmed military variant.
// Lifted verbatim from cfgVehicles.hpp into its own file (Phase 1 PR A);
// include paths adjusted one level for the vehicles\ folder.
class vtx_UH60M_MEDEVAC: vtx_H60_base {
    scope = 2;
    editorPreview = "z\vtx\addons\UH60\Data\Preview\vtx_UH60M_MEDEVAC.jpg"; // dev tester report 2026-09-07: never had one (verified back to 0.7.9)
    forceInGarage = 1;
    cargoAction[] = {
      "passenger_low01",
      "passenger_generic01_leanleft",
      "passenger_generic01_leanleft",
      "passenger_generic01_leanright"
    };
    cargoProxyIndexes[] = {1, 2, 3, 4, 24, 25, 6, 7, 12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
    ace_medical_treatment_patientSeats[] = {11, 12, 13, 14};
    displayName = "HH-60M MEDEVAC";
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
      #include "..\turrets\doorgunsFFV.hpp"
      #include "..\turrets\cargoTurrets.hpp"
    };
    #include "..\vehicleTransport.hpp"
    class hct_turret_1 {
      class interaction {
        #include "..\hct_window_l.hpp"
      };
    };
    class hct_turret_2 {
      class interaction {
        #include "..\hct_window_r.hpp"
      };
    };
    class MFD: MFD {
      class VTX_MFD_1_NOFLIR :           VTX_MFD_1_NOFLIR {};
      class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
      class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
      class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
      class VTX_MFD_2_NOFLIR :           VTX_MFD_2_NOFLIR {};
      class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
      class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
      class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
      class VTX_MFD_3_NOFLIR :           VTX_MFD_3_NOFLIR {};
      class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
      class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
      class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
      class VTX_MFD_4_NOFLIR :           VTX_MFD_4_NOFLIR {};
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
}; // vtx_UH60M_MEDEVAC
