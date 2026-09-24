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
      "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","", // Markings (blank — no military markings), door numbers L1, L2, R1, R2
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
      #include "..\turrets\crewSeatsFFV.hpp"
      // Pendant seat — same "Door Right 1 (hoist controls)" as the military
      // variants (copy of cargoTurretsDoor.hpp CargoTurret_01), so the S-70i
      // gains hoist-operator capability when fix/hoist-control-gate lands.
      // Riverman ruling 2026-09-23: the crew chief never runs the winch from
      // the window seat; the pendant lives at the right cabin door.
      class CargoTurret_01: CargoTurret {
        gunnerAction = "passenger_bench_1";
        gunnerInAction = "passenger_bench_1";
        memoryPointsGetInGunner = "pos Cargo R";
        memoryPointsGetInGunnerDir = "pos Cargo R dir";
        gunnerName = "Door Right 1 (hoist controls)";
        gunnerCompartments = Compartment2;
        proxyIndex = 12;
        isPersonTurret = 2;        /// enables a person to get into the turret from outside
        selectionFireAnim = "";
        disableSoundAttenuation = 0;
        LODTurnedIn = 1200;
        LODTurnedOut = 1200;
        LODOpticsIn = 1200;
        LODOpticsOut = 1200;
        class TurnIn /// limits for gunner turned in
        {
            limitsArrayBottom[] = {[-45,-94.9656],[-45,80.9904],[-31.9033,82.8465],[-31.7935,95]};
            limitsArrayTop[] = {[14.705,-95],[14.1224,-62.859],[12.3049,32.9414],[9.0862,94.948]};
        };
        class TurnOut: TurnIn {}; /// turn out uses the same limits as turn in this time
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
    #include "..\vehicleTransportSlick.hpp"
}; // vtx_S70i
