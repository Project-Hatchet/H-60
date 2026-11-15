class VehicleSystemsTemplateLeftPilot;
class VehicleSystemsTemplateRightPilot;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class HCT_MFD_1;
class HCT_MFD_1_CMWS;
class HCT_MFD_1_Monospace;
class HCT_MFD_1_Bold;
class HCT_MFD_2;
class HCT_MFD_2_CMWS;
class HCT_MFD_2_Monospace;
class HCT_MFD_2_Bold;
class HCT_MFD_3;
class HCT_MFD_3_CMWS;
class HCT_MFD_3_Monospace;
class HCT_MFD_3_Bold;
class HCT_MFD_4;
class HCT_MFD_4_CMWS;
class HCT_MFD_4_Monospace;
class HCT_MFD_4_Bold;
class HCT_MFD_1_ARMED;
class HCT_MFD_2_ARMED;
class HCT_MFD_3_ARMED;
class HCT_MFD_4_ARMED;
class ANVISHUD;
class ANVISHUD_COPILOT;
class HCT_CLOCK;
class HCT_ESIS_Horizon;
class HCT_ESIS_Misc;
class HCT_FDRight;
class HCT_FDLeft;
class HCT_FMS_L;
class HCT_FMS_R;
class HCT_FMS_L2;
class HCT_FMS_R2;
class HCT_ESIS_BOOT;

class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class AnimationSources;
        class Turrets;
    }; // Heli_Transport_01_base_F
    class hct_H60_base: Heli_Transport_01_base_F {
        #include "\z\vtx\addons\uh60_config\config\CfgAnimationSourcesInherit.hpp"
        class ViewPilot;
        class hct_templateFLIR;
        class Components;
        class Turrets: Turrets
        {
            class CopilotTurret;
            class MainTurret;
            class RightDoorGun;
        };
        class MFD;
        class BMKHS_HeliSim {
            class Seats;
        };
    }; // hct_H60_base
    class hct_MH60M: hct_H60_base {
        hct_trait_flirTurretAnimated = 1;
        hct_trait_irLaser = 1;
        hct_trait_erfsService = 1;
        class pilotCamera: hct_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        scope = 2;
        forceInGarage = 1;
        displayName = "$STR_hct_mh60m_MH60M";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M.jpg";
        memoryPointDriverOptics = "pilotcamera_flir_pos";

        transportSoldier=0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        ace_medical_treatment_patientSeats[] = {4, 5, 7, 8};
        cargoAction[] = {};

        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        class Components: Components {
            #include "\z\vtx\addons\uh60_config\config\cfgVehiclesParts\sensors.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            ANIM_INIT(CabinSeats_1_Hide,1);
            ANIM_INIT(CabinSeats_2_Hide,1);
            ANIM_INIT(CabinSeats_3_Hide,1);
            ANIM_INIT(Door_RF_Hide,1);
            ANIM_INIT(Door_LF_Hide,1);
            ANIM_INIT(Cockpitdoors_Hide,1);
            ANIM_INIT(Minigun_Sight_L_hide,1);
            ANIM_INIT(Minigun_Sight_R_hide,1);
            ANIM_INIT(RADAR_HIDE,0);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(FuelProbe_show,1);
            ANIM_INIT(MITAS_show,1);
            ANIM_INIT(MAWS_Tubes_Show,1);
            ANIM_INIT(ERFS_show,1);
            ANIM_INIT(MH60MMisc_show,1);
        }; // AnimationSources
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {
                class MFD {
                    class ANVISHUD: ANVISHUD_COPILOT {};
                };
            };
            class MainTurret: MainTurret {};
            class RightDoorGun: RightDoorGun {};
            #include "\z\vtx\addons\uh60_config\config\turrets\cargoTurrets.hpp"
            #include "\z\vtx\addons\uh60_config\config\turrets\troopCommander_mh60.hpp"
            // (base MH-60M keeps the cabin cargo turrets; the DAP variants below
            // carry no passengers and mount the MFOS aft gunners instead)
        };
        class hct_turret_12 {
            projectPrefix = "hct_h60";
            class modules {
                class ui {
                    startOnEnter = 0;
                };
            }; // modules
        }; //TC Seat
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\Hull_Main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\Hull_Tail_co.paa","a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","","z\vtx\addons\MH60M\data\Fuel_probe_co.paa","z\vtx\addons\mh60m\data\mlass_co.paa","z\vtx\addons\uh60\data\lass\lass_co.paa","z\vtx\addons\mh60m\data\full60m_co.paa"};
        #include "\z\vtx\addons\uh60_config\config\vehicleTransport.hpp"
        class MFD: MFD {
            class HCT_MFD_1 :           HCT_MFD_1 {};
            class HCT_MFD_1_CMWS :      HCT_MFD_1_CMWS {};
            class HCT_MFD_1_Monospace : HCT_MFD_1_Monospace {};
            class HCT_MFD_1_Bold :      HCT_MFD_1_Bold {};
            class HCT_MFD_2 :           HCT_MFD_2 {};
            class HCT_MFD_2_CMWS :      HCT_MFD_2_CMWS {};
            class HCT_MFD_2_Monospace : HCT_MFD_2_Monospace {};
            class HCT_MFD_2_Bold :      HCT_MFD_2_Bold {};
            class HCT_MFD_3 :           HCT_MFD_3 {};
            class HCT_MFD_3_CMWS :      HCT_MFD_3_CMWS {};
            class HCT_MFD_3_Monospace : HCT_MFD_3_Monospace {};
            class HCT_MFD_3_Bold :      HCT_MFD_3_Bold {};
            class HCT_MFD_4 :           HCT_MFD_4 {};
            class HCT_MFD_4_CMWS :      HCT_MFD_4_CMWS {};
            class HCT_MFD_4_Monospace : HCT_MFD_4_Monospace {};
            class HCT_MFD_4_Bold :      HCT_MFD_4_Bold {};
            class ANVISHUD: ANVISHUD {};
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
        class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MH60M };
    }; // hct_MH60M
    class hct_MH60M_DAP : hct_H60_base {
        hct_trait_flirTurretAnimated = 1;
        hct_trait_irLaser = 1;
        hct_trait_erfsService = 1;
        hct_trait_crewChiefTurnOut = 1;
        class pilotCamera: hct_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        scope = 2;
        forceInGarage = 1;
        displayName = "$STR_hct_mh60m_MH60MDAP";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M_DAP.jpg";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        transportSoldier=0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class Components: Components {
          #include "Pylons.hpp"
          #include "\z\vtx\addons\uh60_config\config\cfgVehiclesParts\sensors.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class Gatling_1
            {
                source="revolving";
                weapon="hct_MH60M_M134_minigun";
            };
            class Gatling_2
            {
                source="revolving";
                weapon="hct_MH60M_M134_minigun";
            };
            class Muzzle_Flash_M134_L
            {
                source="ammoRandom";
                weapon="hct_MH60M_M134_minigun";
            };
            class Muzzle_Flash_M134_R
            {
                source="ammoRandom";
                weapon="hct_MH60M_M134_minigun";
            };
            class GunnerSeats_Hide: GunnerSeats_Hide {
              initPhase = 1;
              onPhaseChanged = "";
            };
            ANIM_INIT(LASS_show,1);
            ANIM_INIT(MLASS_show,0); // hides the baked-in MLASS mesh - dies with the new model
            ANIM_INIT(Minigun_Sight_L_hide,1);
            ANIM_INIT(Minigun_Sight_R_hide,1);
            ANIM_INIT(MH60MMisc_show,1);
            ANIM_INIT(mfos_fwd_hide,1);
            ANIM_INIT(mfos_aft_hide,0);

            ANIM_INIT(CabinSeats_1_Hide,1);
            ANIM_INIT(CabinSeats_2_Hide,1);
            ANIM_INIT(CabinSeats_3_Hide,1);
            ANIM_INIT(Door_RF_Hide,1);
            ANIM_INIT(Door_LF_Hide,1);
            ANIM_INIT(Cockpitdoors_Hide,1);
            ANIM_INIT(FuelProbe_show,1);
            ANIM_INIT(MITAS_show,1);
            ANIM_INIT(RADAR_HIDE,0);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(MAWS_Tubes_Show,1);
            ANIM_INIT(ERFS_show,1); // DAP spawns with the ERFS tanks fitted (Riverman ruling 2026-09-20)
        }; // AnimationSources
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {
                class MFD {
                    class ANVISHUD: ANVISHUD_COPILOT {};
                };
            };
            // DAP cabin (Riverman rulings 2026-09-07/18): the base M's cabin cargo
            // turrets removed; MFOS aft crew chiefs + two full-time emergency
            // pax door seats (downed-aircrew pickup) are the only rear positions
            #include "\z\vtx\addons\uh60_config\config\turrets\mfosAft.hpp"
            #include "\z\vtx\addons\uh60_config\config\turrets\dapPaxSeats.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\Hull_Main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\Hull_Tail_co.paa","a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","","z\vtx\addons\MH60M\data\Fuel_probe_co.paa","z\vtx\addons\mh60m\data\mlass_co.paa","z\vtx\addons\uh60\data\lass\lass_co.paa","z\vtx\addons\mh60m\data\full60m_co.paa"};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera", "hct_MH60M_M134_minigun"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries", "5000Rnd_762x51_Belt"};
        memoryPointGun[] = {"muzzle_1","muzzle_2"};
        gunBeg[] = {"muzzle_1","muzzle_2"};
        gunEnd[] = {"chamber_1","chamber_2"};
        selectionFireAnim = "zasleh_12";
        class VehicleTransport {};
        class MFD: MFD {
            class HCT_MFD_1 :           HCT_MFD_1_ARMED {};
            class HCT_MFD_1_CMWS :      HCT_MFD_1_CMWS {};
            class HCT_MFD_1_Monospace : HCT_MFD_1_Monospace {};
            class HCT_MFD_1_Bold :      HCT_MFD_1_Bold {};
            class HCT_MFD_2 :           HCT_MFD_2_ARMED {};
            class HCT_MFD_2_CMWS :      HCT_MFD_2_CMWS {};
            class HCT_MFD_2_Monospace : HCT_MFD_2_Monospace {};
            class HCT_MFD_2_Bold :      HCT_MFD_2_Bold {};
            class HCT_MFD_3 :           HCT_MFD_3_ARMED {};
            class HCT_MFD_3_CMWS :      HCT_MFD_3_CMWS {};
            class HCT_MFD_3_Monospace : HCT_MFD_3_Monospace {};
            class HCT_MFD_3_Bold :      HCT_MFD_3_Bold {};
            class HCT_MFD_4 :           HCT_MFD_4_ARMED {};
            class HCT_MFD_4_CMWS :      HCT_MFD_4_CMWS {};
            class HCT_MFD_4_Monospace : HCT_MFD_4_Monospace {};
            class HCT_MFD_4_Bold :      HCT_MFD_4_Bold {};
            class ANVISHUD: ANVISHUD {};
            class HCT_CLOCK: HCT_CLOCK {};
            class HCT_ESIS_Horizon: HCT_ESIS_Horizon {};
            class HCT_ESIS_Misc: HCT_ESIS_Misc {};
            class HCT_FDRight: HCT_FDRight {};
            class HCT_FDLeft: HCT_FDLeft {};
            class HCT_FMS_L2: HCT_FMS_L2 {};
            class HCT_FMS_R2: HCT_FMS_R2 {};
            class HCT_ESIS_BOOT: HCT_ESIS_BOOT {};
        };
        // HeliSim seats (SEATS_* in uh60_helisim bmkhs_config/helisim_seats.hpp)
        class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_DAP };
    }; // hct_MH60M_DAP
    // MLASS variant retired (Riverman rulings 2026-09-09 / 2026-09-30). The
    // CLASSNAME stays for good as a compatibility stub so missions that placed
    // an MLASS keep loading: it spawns a regular DAP under the old name,
    // hidden from Eden, Zeus and the Virtual Garage. NEVER delete this class
    // and never give it scope = 2. Its 4-station pylon rack, MFD pages and
    // editor preview are gone; saved MLASS pylon loadouts log harmless
    // unknown-magazine warnings. The MLASS mesh, MLASS_show animations and
    // texture slots stay until the new model: the mesh is baked into
    // vtx_uh60.p3d and would SHOW on every variant without them.
    // Traits and HeliSim seats are inherited from the DAP.
    class hct_MH60M_DAP_MLASS: hct_MH60M_DAP {
        scope = 1;
        scopeCurator = 0;
        forceInGarage = 0;
    }; // hct_MH60M_DAP_MLASS

}; // CfgVehicles

class CfgNonAIVehicles {
  class ProxyRetex;
  class ProxyLASS: ProxyRetex {
    hiddenSelections[] ={HIDDENSELECTIONS};
    model = "\z\vtx\addons\UH60\LASS.p3d";
  };
};
