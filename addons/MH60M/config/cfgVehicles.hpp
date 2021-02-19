#include "customInfo.hpp"
class VehicleSystemsTemplateLeftPilot;
class vtx_VehicleSystemsTemplateLeftPilot: VehicleSystemsTemplateLeftPilot {
    class Components;
};
class VehicleSystemsTemplateRightPilot;
class vtx_VehicleSystemsTemplateRightPilot: VehicleSystemsTemplateRightPilot {
    class Components;
};

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
        class Components;
        class AnimationSources;
        class Turrets: Turrets
        {
            class MainTurret;
            class CopilotTurret: CopilotTurret {
                class Components;
            };
        };
        class ViewPilot;
    }; // Heli_Transport_01_base_F

    class vtx_MH60M: vtx_H60_base {
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_Pilot;
        scope = 2;
        displayName = "MH-60M";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M.jpg";
        memoryPointDriverOptics = "pilotcamera_flir_pos";

        transportSoldier=0;
        cargoProxyIndexes[] = {};
        cargoAction[] = {};

        weapons[]={
            "CMFlareLauncher"
        };
        magazines[]={
            "60Rnd_CMFlareMagazine"
        };
        class ViewPilot: ViewPilot
        {
            initAngleX=0;
        };
        class Components: Components {
            #include "sensors.hpp"

            class VehicleSystemsDisplayManagerComponentLeft: vtx_VehicleSystemsTemplateLeftPilot {
                class Components: Components {
                    ADDGUNNER
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: vtx_VehicleSystemsTemplateRightPilot {
                class Components: Components {
                    ADDGUNNER
                };
            };
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
        class vtx_templateFLIR;
        class pilotCamera: vtx_templateFLIR {};
        class CargoTurret;
        class Turrets: Turrets
        {
            #include "copilot.hpp"
            #include "doorguns_free.hpp"
            #include "cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
    }; // vtx_MH60M
    class vtx_MH60M_DAP : vtx_MH60M {
        scope = 2;
        displayName = "MH-60M DAP";
        editorPreview = "z\vtx\addons\MH60M\Data\Preview\vtx_MH60M_DAP.jpg";
        class vtx_templateFLIR;
        class pilotCamera: vtx_templateFLIR {};
        class ViewPilot: ViewPilot
        {
            initAngleX=0;
        };
        class Components: Components {
            #include "Pylons.hpp"
            #include "sensors.hpp"

            class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsDisplayManagerComponentLeft {
                class Components: Components {
                    ADDMISSILE
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsDisplayManagerComponentRight {
                class Components: Components {
                    ADDMISSILE
                };
            };
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
            #include "copilotTurretSetup.hpp"
            #include "cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
        weapons[] = {"CMFlareLauncher","vtx_MH60M_M134_minigun"};
        magazines[] = {"60Rnd_CMFlareMagazine","5000Rnd_762x51_Belt"};
        memoryPointGun[] = {"muzzle_1","muzzle_2"};
        gunBeg[] = {"muzzle_1","muzzle_2"};
        gunEnd[] = {"chamber_1","chamber_2"};
        selectionFireAnim = "zasleh_12";
    }; // vtx_H60_base
}; // CfgVehicles

class cfgNonAIVehicles{
	class ProxyRetex;
	class LASS: ProxyRetex{
		hiddenSelections[] ={"LASS"};
		model = "z\vtx\addons\UH60\LASS.p3d";
	};
};
