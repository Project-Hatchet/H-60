// vtx_S70i — the civilian S-70i (unarmed). Lifted verbatim from
// cfgVehicles.hpp into its own file (Phase 1 PR A). Renamed from vtx_S70M
// (dev tester report, Riverman flat-rename ruling 2026-09-07 - no compat
// stub; civilian variant, mission breakage accepted).
class vtx_S70i: vtx_H60_base {
    displayName = "S-70i";
    editorPreview = "z\vtx\addons\UH60\Data\Preview\vtx_S70i.jpg";
    crew = "C_man_pilot_F";
    side = 3;
    faction = "CIV_F";
    lockDetectionSystem = 0;
    incomingMissileDetectionSystem = 0;
    scope = 2;
    forceInGarage = 1;
    cargoAction[] = {};
    cargoProxyIndexes[] = {};
    ace_medical_treatment_patientSeats[] = {};

    hiddenSelectionsTextures[] = {
      "","","","","","","","","","","","","","","","",
      "z\vtx\addons\MH60S\data\mh60s_main_co.paa",
      "z\vtx\addons\MH60S\data\mh60s_misc_co.paa",
      "z\vtx\addons\MH60S\data\mh60s_tail_co.paa",
      "","","","","", // Markings, door numbers L1, L2, R1, R2
      "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
    };
    transportSoldier=0;
    class AnimationSources: AnimationSources {
      ANIM_INIT(GunnerSeats_Hide,1);
      ANIM_INIT(CabinSeats_1_Hide,1);
      ANIM_INIT(CabinSeats_2_Hide,1);
      ANIM_INIT(CabinSeats_3_Hide,1);
      ANIM_INIT(Hoist_hide,0);
      ANIM_INIT(Minigun_Mount_L_hide,1);
      ANIM_INIT(Minigun_Mount_R_hide,1);
      ANIM_INIT(Minigun_L_hide,1);
      ANIM_INIT(Minigun_R_hide,1);
      ANIM_INIT(MAWS_Tubes_Show,0.4);
      ANIM_INIT(window_l,0);
      ANIM_INIT(window_r,0);
    }; // AnimationSources
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
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
    #include "..\vehicleTransportSlick.hpp"
}; // vtx_S70i
