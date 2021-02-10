#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_main"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

class CfgWorlds
{
	class Altis;
	class AltisFlooded : Altis
	{
		description = "Altis (Flooded)";
		class Sea
		{
			MinTide = 30; // Minimum: How much above Main Sea level?
			MaxTide = 30; // Maximum: How much under Main Sea level?
            MaxWave = 1;
            seaMaterial = "#water";
            seaTexture = "a3\data_f\seatexture_co.paa";
            SeaWaveHScale = 1;
            SeaWaveXDuration = 5000;
            SeaWaveXScale = "2.0/50";
            SeaWaveZDuration = 10000;
            SeaWaveZScale = "1.0/50";
            shoreFoamMaterial = "#shorefoam";
            shoreMaterial = "#shore";
            shoreWetMaterial = "#shorewet";
            WaterGrid = 50;
            WaterMapScale = 20;
		};
	};
};

class CfgWorldList
{
    class AltisFlooded {};
};

class cfgVehicles
{
	class Land_TowBar_01_F;
	class vtx_uh60_watertank_physx: Land_TowBar_01_F {
		displayName = "Water Tank (Large)";
		model = "\A3\Structures_F_Exp\Infrastructure\WaterSupply\WaterTank_01_F.p3d";
	};
};
