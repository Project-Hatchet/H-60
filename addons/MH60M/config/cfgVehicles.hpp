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
        class VTX_H60_HDTS_Common;
        class VTX_H60_HDTS_Copilot;
        class VTX_H60_HDTS_CoPilot_Turret;
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
            #include "copilotTurretSetup.hpp"
            #include "doorguns_free.hpp"
            #include "cargoTurrets.hpp"
        };
        hiddenSelectionsTextures[] = {"","","","","","","","","","","","","","","","","z\vtx\addons\MH60M\data\main_co.paa","z\vtx\addons\MH60M\Data\Misc_co.paa","z\vtx\addons\MH60M\data\tail_co.paa","","","","","","z\vtx\addons\UH60\data\FuelProbe\Fuel_probe_co.paa"};
        class VehicleTransport {
        	class Carrier {
        		cargoBayDimensions[]		= {"VTV_limit_1", "VTV_limit_2"};	// Memory points in model defining cargo space
        		disableHeightLimit			= 0;								// If set to 1 disable height limit of transported vehicles
        		maxLoadMass					= 4100;							// Maximum cargo weight (in Kg) which the vehicle can transport
        		cargoAlignment[]			= {"front", "center"};				// Array of 2 elements defining alignment of vehicles in cargo space. Possible values are left, right, center, front, back. Order is important.
        		cargoSpacing[]				= {0.3, 0.3, 0};						// Offset from X,Y,Z axes (in metres)
        		exits[]						= {"pos Cargo L", "pos Cargo R"};		// Memory points in model defining loading ramps, could have multiple
        		unloadingInterval			= 2;								// Time between unloading vehicles (in seconds)
        		loadingDistance				= 5;								// Maximal distance for loading in exit point (in meters).
        		loadingAngle				= 60;								// Maximal sector where cargo vehicle must be to for loading (in degrees).
        		parachuteClassDefault       = B_Parachute_02_F;					// Type of parachute used when dropped in air. Can be overridden by parachuteClass in Cargo.
        		parachuteHeightLimitDefault = 50;								// Minimal height above terrain when parachute is used. Can be overriden by parachuteHeightLimit in Cargo.
        	};
        };
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
