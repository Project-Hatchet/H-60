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
        class Turrets;
    }; // Heli_Transport_01_base_F
    class vtx_H60_base: Heli_Transport_01_base_F {
        class ViewPilot;
        class vtx_templateFLIR;
        class Components;
        class AnimationSources;
        class Turrets: Turrets
        {
            class MainTurret;
            class CopilotTurret;
        };
    }; // vtx_H60_base
    class vtx_MH60M: vtx_H60_base {
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_MELB_Turret_UnitInfo";
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
        class ViewPilot: ViewPilot
        {
            initAngleX=0;
        };
        class Components: Components {
            #include "sensors.hpp"
        }; // Components
        class AnimationSources: AnimationSources {
            class Cockpitdoors_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class RADAR_HIDE {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class FLIR_HIDE {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class Fuelprobe_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class ERFS_Show: MAWS_Tubes_Show {
                initPhase=1;
            };
        }; // AnimationSources
        class CargoTurret;
        class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret {};
            #include "\z\vtx\addons\UH60\config\turrets\doorguns.hpp"
            #include "\z\vtx\addons\UH60\config\turrets\cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
        #include "\z\vtx\addons\UH60\config\vehicleTransport.hpp"
    }; // vtx_MH60M
    class vtx_MH60M_DAP : vtx_MH60M {
        class pilotCamera: vtx_templateFLIR {};
        driverWeaponsInfoType = "Rsc_MELB_Turret_UnitInfo";
        scope = 2;
        displayName = "MH-60M DAP";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M_DAP.jpg";
        cargoProxyIndexes[] = {};
        class ViewPilot: ViewPilot
        {
            initAngleX=0;
        };
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
            class Muzzle_flash1
            {
                source="ammorandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Muzzle_flash2
            {
                source="ammorandom";
                weapon="vtx_MH60M_M134_minigun";
            };
            class Cockpitdoors_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class RADAR_HIDE {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class FLIR_HIDE {
                source="user";
                animPeriod=1;
                initPhase=0;
            };
            class LASS_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class Fuelprobe_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class GunnerSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class CabinSeats_Hide {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class MAWS_Tubes_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
            class ERFS_Show: MAWS_Tubes_Show {
                initPhase=1;
            };
        }; // AnimationSources
        class Turrets: Turrets
        {
            //#include "\z\vtx\addons\UH60\config\turrets\doorguns_pylons.hpp"
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
