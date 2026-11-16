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
class CfgVehicles {
    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F {
        class Turrets;
    };
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class AnimationSources;
        class CargoTurret;
        class Turrets: Turrets {
            class CopilotTurret;
        };
    }; // Helicopter_Base_H
    class hct_H60_base: Heli_Transport_01_base_F {
        #include "\z\vtx\addons\uh60_config\config\CfgAnimationSourcesInherit.hpp"
        class hct_templateFLIR;
        class Components;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {
              class Components;
            };
            class MainTurret;
            class RightDoorGun: MainTurret {};
        };
    }; // Heli_Transport_01_base_F
    class hct_MH60S_Pylons_GAU21L: hct_H60_base {
        class pilotCamera: hct_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        displayName = "$STR_hct_mh60s_MH60SKnighthawkPylonsGAU21L";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "doorguns_pylons.hpp"
            #include "gau21L.hpp"
            #include "cargoTurretsGAU21L.hpp"
        };
        class Components: Components {
          #include "Pylons.hpp"
          #include "\z\vtx\addons\uh60_config\config\cfgVehiclesParts\sensors.hpp"
          #include "\z\vtx\addons\uh60_config\config\cfgVehiclesParts\missileCam.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
          ANIM_INIT(CabinSeats_1_Hide,1);
          ANIM_INIT(CabinSeats_2_Hide,1);
          ANIM_INIT(CabinSeats_3_Hide,1);
          ANIM_INIT(ESSS_show,1);
          ANIM_INIT(GAU21_L_Hide,0);
          ANIM_INIT(MAWS_Tubes_Show,1);
          ANIM_INIT(FLIR_HIDE,0);
          class Muzzle_Flash_GAU21_L {
            source="ammoRandom";
            weapon="HCT_HMG_M3M";
          };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {
          "","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa", "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa",
          "", "", "", "", "", "", "", "",
          "z\vtx\addons\uh60\data\esss\uh60m_engine_mev_co.paa"
        };
    }; // hct_MH60S_Pylons_GAU21L
    class hct_MH60S_GAU21L: hct_H60_base {
        class pilotCamera: hct_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        displayName = "$STR_hct_mh60s_MH60SKnighthawkGAU21L";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            class MainTurret: MainTurret {};
            class RightDoorGun: RightDoorGun {};
            #include "gau21L.hpp"
            #include "cargoTurretsGAU21L.hpp"
        };
        class AnimationSources: AnimationSources {
          ANIM_INIT(CabinSeats_1_Hide,1);
          ANIM_INIT(CabinSeats_2_Hide,1);
          ANIM_INIT(CabinSeats_3_Hide,1);
          ANIM_INIT(GAU21_L_Hide,0);
          ANIM_INIT(MAWS_Tubes_Show,1);
          ANIM_INIT(FLIR_HIDE,0);
          class Muzzle_Flash_GAU21_L {
            source="ammoRandom";
            weapon="HCT_HMG_M3M";
          };
        }; // AnimationSources
        hiddenSelectionsTextures[] = {
          "","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa", "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa",
          "", "", "", "", "", "", "", "",
          "z\vtx\addons\uh60\data\esss\uh60m_engine_mev_co.paa"
        };
    }; // hct_MH60S_GAU21L
    class hct_MH60S_Pylons: hct_H60_base {
        class pilotCamera: hct_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        displayName = "$STR_hct_mh60s_MH60SKnighthawkPylons";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S_Pylons.jpg";
        transportSoldier = 0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "doorguns_pylons.hpp"
            #include "\z\vtx\addons\uh60_config\config\turrets\cargoTurrets.hpp"
        };
        class Components: Components {
          #include "Pylons.hpp"
          #include "\z\vtx\addons\uh60_config\config\cfgVehiclesParts\sensors.hpp"
          #include "\z\vtx\addons\uh60_config\config\cfgVehiclesParts\missileCam.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
          ANIM_INIT(CabinSeats_1_Hide,1);
          ANIM_INIT(CabinSeats_2_Hide,1);
          ANIM_INIT(CabinSeats_3_Hide,1);
          ANIM_INIT(ESSS_show,1);
          ANIM_INIT(MAWS_Tubes_Show,1);
          ANIM_INIT(FLIR_HIDE,0);
        }; // AnimationSources
        hiddenSelectionsTextures[] = {
        "","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa", "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa",
          "", "", "", "", "", "", "", "",
          "z\vtx\addons\uh60\data\esss\uh60m_engine_mev_co.paa"};
    }; // hct_MH60S_Pylons_GAU21L
    class hct_MH60S: hct_H60_base {
        class pilotCamera: hct_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        displayName = "$STR_hct_mh60s_MH60SKnighthawk";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S.jpg";
        class Turrets: Turrets
        {
          class CopilotTurret: CopilotTurret {};
          class MainTurret: MainTurret {};
          class RightDoorGun: RightDoorGun {};
          // was patched in by H60_SFX Compat.hpp; the only entry there with any effect
          class CargoTurret_01: CargoTurret {};
        };
        class AnimationSources: AnimationSources {
          ANIM_INIT(MAWS_Tubes_Show,1);
          ANIM_INIT(FLIR_HIDE,0);
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa", "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa"};
    }; // hct_MH60S
}; // CfgVehicles
