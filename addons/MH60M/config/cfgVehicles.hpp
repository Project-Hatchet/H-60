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
    }; // vtx_H60_base
    class vtx_MH60M: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
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
        }; // AnimationSources
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            class MainTurret: MainTurret {};
            class RightDoorGun: RightDoorGun {};
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
        #include "\z\vtx\addons\UH60\config\vehicleTransport.hpp"
    }; // vtx_MH60M
    class vtx_MH60M_DAP : vtx_MH60M {
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        scope = 2;
        displayName = "MH-60M DAP";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M_DAP.jpg";
        cargoProxyIndexes[] = {};
        class Components: Components {
          #include "Pylons.hpp"
          #include "sensors.hpp"
          #include "missileCam.hpp"
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
            ANIM_INIT(Minigun_Sight_L_hide,1);
            ANIM_INIT(Minigun_Sight_R_hide,1);
        }; // AnimationSources
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera", "vtx_MH60M_M134_minigun"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries", "5000Rnd_762x51_Belt"};
        memoryPointGun[] = {"muzzle_1","muzzle_2"};
        gunBeg[] = {"muzzle_1","muzzle_2"};
        gunEnd[] = {"chamber_1","chamber_2"};
        selectionFireAnim = "zasleh_12";
        class VehicleTransport {};
    }; // vtx_H60_base
}; // CfgVehicles

class cfgNonAIVehicles{
	class ProxyRetex;
	class LASS: ProxyRetex{
		hiddenSelections[] ={"LASS"};
		model = "z\vtx\addons\UH60\LASS.p3d";
	};
};
