// hct_S70i — the civilian S-70i (unarmed). Lifted verbatim from
// cfgVehicles.hpp into its own file (Phase 1 PR A). Renamed from hct_S70M
// (dev tester report, Riverman flat-rename ruling 2026-09-07 - no compat
// stub; civilian variant, mission breakage accepted).
class hct_S70i: hct_H60_base {
    displayName = "$STR_hct_s70i_S70i";
    editorPreview = "z\vtx\addons\s70i\data\preview\vtx_S70i.jpg";
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
      #include "\z\vtx\addons\uh60_config\config\turrets\crewSeatsFFV.hpp"
      // Pendant seat — same "Door Right 1 (hoist controls)" as the military
      // variants (copy of cargoTurretsDoor.hpp CargoTurret_01), so the S-70i
      // gains hoist-operator capability when fix/hoist-control-gate lands.
      // Riverman ruling 2026-09-23: the crew chief never runs the winch from
      // the window seat; the pendant lives at the right cabin door.
      class CargoTurret_01: CargoTurret {
        soundAttenuationTurret = "HCT_H60_CabinAttenuation"; // #510: pendant seat is inside the airframe, same as the base M door seats (#617)
        gunnerAction = "passenger_bench_1";
        gunnerInAction = "passenger_bench_1";
        memoryPointsGetInGunner = "pos Cargo R";
        memoryPointsGetInGunnerDir = "pos Cargo R dir";
        gunnerName = "Door Right 1 (hoist controls)";
        gunnerCompartments = "Compartment2";
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
            limitsArrayBottom[] = {{-45,-94.9656},{-45,80.9904},{-31.9033,82.8465},{-31.7935,95}};
            limitsArrayTop[] = {{14.705,-95},{14.1224,-62.859},{12.3049,32.9414},{9.0862,94.948}};
        };
        class TurnOut: TurnIn {}; /// turn out uses the same limits as turn in this time
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
    #include "\z\vtx\addons\uh60_config\config\vehicleTransportSlick.hpp"
  // HeliSim seats (SEATS_* in uh60_helisim bmkhs_config/helisim_seats.hpp)
  class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_S70I };
}; // hct_S70i
