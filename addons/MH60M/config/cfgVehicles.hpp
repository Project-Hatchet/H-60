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
class VTX_MFD_1;
class VTX_MFD_1_CMWS;
class VTX_MFD_1_Monospace;
class VTX_MFD_1_Bold;
class VTX_MFD_2;
class VTX_MFD_2_CMWS;
class VTX_MFD_2_Monospace;
class VTX_MFD_2_Bold;
class VTX_MFD_3;
class VTX_MFD_3_CMWS;
class VTX_MFD_3_Monospace;
class VTX_MFD_3_Bold;
class VTX_MFD_4;
class VTX_MFD_4_CMWS;
class VTX_MFD_4_Monospace;
class VTX_MFD_4_Bold;
class VTX_MFD_1_ARMED;
class VTX_MFD_2_ARMED;
class VTX_MFD_3_ARMED;
class VTX_MFD_4_ARMED;
class ANVISHUD;
class ANVISHUD_COPILOT;
class VTX_CLOCK;
class VTX_ESIS_Horizon;
class VTX_ESIS_Misc;
class VTX_FDRight;
class VTX_FDLeft;
class VTX_FMS_L;
class VTX_FMS_R;
class VTX_ESIS_BOOT;

class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_Transport_01_base_F: Helicopter_Base_H {
        class AnimationSources;
        class Turrets;
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        #include "\z\vtx\addons\UH60\config\CfgAnimationSourcesInherit.hpp"
        class ViewPilot;
        class vtx_templateFLIR;
        class Components;
        class Turrets: Turrets
        {
            class CopilotTurret;
            class MainTurret;
            class RightDoorGun;
        };
        class MFD;
    }; // vtx_H60_base
    class vtx_MH60M: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        scope = 2;
        displayName = "MH-60M";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M.jpg";
        memoryPointDriverOptics = "pilotcamera_flir_pos";

        transportSoldier=0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};

        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        class Components: Components {
            #include "sensors.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            ANIM_INIT(CabinSeats_1_Hide,1);
            ANIM_INIT(CabinSeats_2_Hide,1);
            ANIM_INIT(CabinSeats_3_Hide,1);
            ANIM_INIT(Cockpitdoors_Hide,1);
            ANIM_INIT(RADAR_HIDE,0);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(FuelProbe_show,1);
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
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
        #include "\z\vtx\addons\UH60\config\vehicleTransport.hpp"
        class MFD: MFD {
            class VTX_MFD_1 :           VTX_MFD_1 {};
            class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
            class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
            class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
            class VTX_MFD_2 :           VTX_MFD_2 {};
            class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
            class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
            class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
            class VTX_MFD_3 :           VTX_MFD_3 {};
            class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
            class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
            class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
            class VTX_MFD_4 :           VTX_MFD_4 {};
            class VTX_MFD_4_CMWS :      VTX_MFD_4_CMWS {};
            class VTX_MFD_4_Monospace : VTX_MFD_4_Monospace {};
            class VTX_MFD_4_Bold :      VTX_MFD_4_Bold {};
            class ANVISHUD: ANVISHUD {};
            class VTX_CLOCK: VTX_CLOCK {};
            class VTX_ESIS_Horizon: VTX_ESIS_Horizon {};
            class VTX_ESIS_Misc: VTX_ESIS_Misc {};
            class VTX_FDRight: VTX_FDRight {};
            class VTX_FDLeft: VTX_FDLeft {};
            class VTX_FMS_L: VTX_FMS_L {};
            class VTX_FMS_R: VTX_FMS_R {};
            class VTX_ESIS_BOOT: VTX_ESIS_BOOT {};
        };
    }; // vtx_MH60M
    class vtx_MH60M_DAP : vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        scope = 2;
        displayName = "MH-60M DAP";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M_DAP.jpg";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        transportSoldier=0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class Components: Components {
          #include "Pylons.hpp"
          #include "sensors.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class Gatling_1
            {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Gatling_2
            {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_Flash_M134_L
            {
                source="ammoRandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_Flash_M134_R
            {
                source="ammoRandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class GunnerSeats_Hide: GunnerSeats_Hide {
              initPhase = 1;
              onPhaseChanged = "";
            };
            ANIM_INIT(LASS_show,1);
            ANIM_INIT(MLASS_show,0);
            ANIM_INIT(Minigun_Sight_L_hide,1);
            ANIM_INIT(Minigun_Sight_R_hide,1);
            ANIM_INIT(MH60MMisc_show,1);

            ANIM_INIT(CabinSeats_1_Hide,1);
            ANIM_INIT(CabinSeats_2_Hide,1);
            ANIM_INIT(CabinSeats_3_Hide,1);
            ANIM_INIT(Cockpitdoors_Hide,1);
            ANIM_INIT(FuelProbe_show,1);
            ANIM_INIT(RADAR_HIDE,0);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(MAWS_Tubes_Show,1);
        }; // AnimationSources
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {
                class MFD {
                    class ANVISHUD: ANVISHUD_COPILOT {};
                };
            };
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa","z\vtx\addons\MH60M\Data\Mlass_co.paa"};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera", "vtx_MH60M_M134_minigun"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries", "5000Rnd_762x51_Belt"};
        memoryPointGun[] = {"muzzle_1","muzzle_2"};
        gunBeg[] = {"muzzle_1","muzzle_2"};
        gunEnd[] = {"chamber_1","chamber_2"};
        selectionFireAnim = "zasleh_12";
        class VehicleTransport {};
        class MFD: MFD {
            class VTX_MFD_1 :           VTX_MFD_1_ARMED {};
            class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
            class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
            class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
            class VTX_MFD_2 :           VTX_MFD_2_ARMED {};
            class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
            class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
            class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
            class VTX_MFD_3 :           VTX_MFD_3_ARMED {};
            class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
            class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
            class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
            class VTX_MFD_4 :           VTX_MFD_4_ARMED {};
            class VTX_MFD_4_CMWS :      VTX_MFD_4_CMWS {};
            class VTX_MFD_4_Monospace : VTX_MFD_4_Monospace {};
            class VTX_MFD_4_Bold :      VTX_MFD_4_Bold {};
            class ANVISHUD: ANVISHUD {};
            class VTX_CLOCK: VTX_CLOCK {};
            class VTX_ESIS_Horizon: VTX_ESIS_Horizon {};
            class VTX_ESIS_Misc: VTX_ESIS_Misc {};
            class VTX_FDRight: VTX_FDRight {};
            class VTX_FDLeft: VTX_FDLeft {};
            class VTX_FMS_L: VTX_FMS_L {};
            class VTX_FMS_R: VTX_FMS_R {};
            class VTX_ESIS_BOOT: VTX_ESIS_BOOT {};
        };
    }; // vtx_H60_base
    class vtx_MH60M_DAP_MLASS: vtx_H60_base {
        displayName = "MH-60M DAP MLASS";
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        scope = 2;
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M_DAP.jpg";
        memoryPointDriverOptics = "pilotcamera_flir_pos";
        transportSoldier=0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class Components: Components {
          #include "PylonsMLASS.hpp"
          #include "sensors.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class Gatling_1
            {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Gatling_2
            {
                source="revolving";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_Flash_M134_L
            {
                source="ammoRandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_Flash_M134_R
            {
                source="ammoRandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class GunnerSeats_Hide: GunnerSeats_Hide {
              initPhase = 1;
              onPhaseChanged = "";
            };
            ANIM_INIT(LASS_show,0);
            ANIM_INIT(MLASS_show,1);
            ANIM_INIT(Minigun_Sight_L_hide,1);
            ANIM_INIT(Minigun_Sight_R_hide,1);
            ANIM_INIT(MH60MMisc_show,1);
            
            ANIM_INIT(CabinSeats_1_Hide,1);
            ANIM_INIT(CabinSeats_2_Hide,1);
            ANIM_INIT(CabinSeats_3_Hide,1);
            ANIM_INIT(Cockpitdoors_Hide,1);
            ANIM_INIT(FuelProbe_show,1);
            ANIM_INIT(RADAR_HIDE,0);
            ANIM_INIT(FLIR_HIDE,0);
            ANIM_INIT(MAWS_Tubes_Show,1);
        }; // AnimationSources
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {
                class MFD {
                    class ANVISHUD: ANVISHUD_COPILOT {};
                };
            };
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa","z\vtx\addons\MH60M\Data\Mlass_co.paa"};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera", "vtx_MH60M_M134_minigun"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries", "5000Rnd_762x51_Belt"};
        memoryPointGun[] = {"muzzle_1","muzzle_2"};
        gunBeg[] = {"muzzle_1","muzzle_2"};
        gunEnd[] = {"chamber_1","chamber_2"};
        selectionFireAnim = "zasleh_12";
        class VehicleTransport {};
        class MFD: MFD {
            class VTX_MFD_1 :           VTX_MFD_1_ARMED {};
            class VTX_MFD_1_CMWS :      VTX_MFD_1_CMWS {};
            class VTX_MFD_1_Monospace : VTX_MFD_1_Monospace {};
            class VTX_MFD_1_Bold :      VTX_MFD_1_Bold {};
            class VTX_MFD_2 :           VTX_MFD_2_ARMED {};
            class VTX_MFD_2_CMWS :      VTX_MFD_2_CMWS {};
            class VTX_MFD_2_Monospace : VTX_MFD_2_Monospace {};
            class VTX_MFD_2_Bold :      VTX_MFD_2_Bold {};
            class VTX_MFD_3 :           VTX_MFD_3_ARMED {};
            class VTX_MFD_3_CMWS :      VTX_MFD_3_CMWS {};
            class VTX_MFD_3_Monospace : VTX_MFD_3_Monospace {};
            class VTX_MFD_3_Bold :      VTX_MFD_3_Bold {};
            class VTX_MFD_4 :           VTX_MFD_4_ARMED {};
            class VTX_MFD_4_CMWS :      VTX_MFD_4_CMWS {};
            class VTX_MFD_4_Monospace : VTX_MFD_4_Monospace {};
            class VTX_MFD_4_Bold :      VTX_MFD_4_Bold {};
            class ANVISHUD: ANVISHUD {};
            class VTX_CLOCK: VTX_CLOCK {};
            class VTX_ESIS_Horizon: VTX_ESIS_Horizon {};
            class VTX_ESIS_Misc: VTX_ESIS_Misc {};
            class VTX_FDRight: VTX_FDRight {};
            class VTX_FDLeft: VTX_FDLeft {};
            class VTX_FMS_L: VTX_FMS_L {};
            class VTX_FMS_R: VTX_FMS_R {};
            class VTX_ESIS_BOOT: VTX_ESIS_BOOT {};
        };
    };
}; // CfgVehicles

class cfgNonAIVehicles{
	class ProxyRetex;
	class LASS: ProxyRetex{
		hiddenSelections[] ={"LASS"};
		model = "z\vtx\addons\UH60\LASS.p3d";
	};
};
