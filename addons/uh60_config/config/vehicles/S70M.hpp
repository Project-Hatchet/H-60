// vtx_S70M — the civilian S-70i (unarmed). Lifted verbatim from
// cfgVehicles.hpp into its own file (Phase 1 PR A); include path adjusted
// one level for the vehicles\ folder.
class vtx_S70M: vtx_H60_base {
    displayName = "S-70i";
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
    #include "..\vehicleTransportSlick.hpp"
}; // vtx_S70M
