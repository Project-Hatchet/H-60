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
        class Turrets: Turrets {
            class CopilotTurret;
        };
    }; // Helicopter_Base_H
    class vtx_H60_base: Heli_Transport_01_base_F {
        class vtx_templateFLIR;
        class Components;
        class AnimationSources;
        class Turrets: Turrets
        {
            class MainTurret;
            class RightDoorGun: MainTurret {};
            class CopilotTurret: CopilotTurret {
                class Components;
            };
        };
        class ViewPilot;
    }; // Heli_Transport_01_base_F
    class vtx_MH60S_Pylons_GAU21L: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 1;
        displayName = "MH-60S Knighthawk - Pylons, GAU-21(L)";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "doorguns_pylons.hpp"
            #include "GAU21L.hpp"
            #include "cargoTurretsGAU21L.hpp"
        };
        class Components: Components {
          #include "Pylons.hpp"
          #include "\z\vtx\addons\MH60M\config\sensors.hpp"
          #include "\z\vtx\addons\MH60M\config\missileCam.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            /*
            ANIM_INIT(ESSS_Show,1);
            ANIM_INIT(CabinSeats_Hide,1);
            ANIM_INIT(GAU21_L_Hide,0);
            ANIM_INIT(MAWS_Tubes_Show,1);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(FLIR_BACK,1);
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            }; // ESSS_Show
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GunnerSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class GAU21_L_Hide {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
            */
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_Pylons_GAU21L
    class vtx_MH60S_GAU21L: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk - GAU-21(L)";
        transportSoldier=0;
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\doorguns.hpp"
            #include "gau21L_free.hpp"
            #include "cargoTurretsGAU21L.hpp"
        };
        class AnimationSources: AnimationSources {
            /*
            ANIM_INIT(CabinSeats_Hide,1);
            ANIM_INIT(GAU21_L_Hide,0);
            ANIM_INIT(MAWS_Tubes_Show,1);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(FLIR_BACK,1);
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=0;
            }; // ESSS_Show
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GAU21_L_Hide {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
            */
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_GAU21L
    class vtx_MH60S_Pylons: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk - Pylons";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S_Pylons.jpg";
        transportSoldier = 0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "doorguns_pylons.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        class Components: Components {
          #include "Pylons.hpp"
          #include "\z\vtx\addons\MH60M\config\sensors.hpp"
          #include "\z\vtx\addons\MH60M\config\missileCam.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class Gatling_1 {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Gatling_2 {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_flash1 {
                source="ammorandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_flash2 {
                source="ammorandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            /*
            ANIM_INIT(ESSS_Show,1);
            ANIM_INIT(CabinSeats_Hide,1);
            ANIM_INIT(MAWS_Tubes_Show,1);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(FLIR_BACK,1);
            class ESSS_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            }; // ESSS_Show
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GAU21_L_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
            */
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S_Pylons_GAU21L
    class vtx_MH60S: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60S Knighthawk";
        editorPreview = "z\vtx\addons\MH60S\Data\Preview\vtx_MH60S.jpg";
        class Turrets: Turrets
        {
            #include "\z\vtx\addons\UH60\config\turrets\copilot.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\doorguns.hpp"
        };
        class AnimationSources: AnimationSources {
            /*
            ANIM_INIT(MAWS_Tubes_Show,1);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(FLIR_BACK,1);
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: FLIR_HIDE {
                initPhase=1;
            };
            */
        }; // AnimationSources
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60S\data\mh60s_main_co.paa","z\vtx\addons\MH60S\data\mh60s_misc_co.paa","z\vtx\addons\MH60S\data\mh60s_tail_co.paa"};
    }; // vtx_MH60S
}; // CfgVehicles
