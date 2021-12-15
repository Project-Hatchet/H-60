class VehicleSystemsTemplateLeftPilot;
class VehicleSystemsTemplateRightPilot;
class SensorTemplatePassiveRadar;
class SensorTemplateDataLink;
class CfgVehicles
{
    #include "crew.hpp"
    class Helicopter_Base_H;
    class Heli_Transport_01_base_F: Helicopter_Base_H
    {
    	#include "cfgUVAnimations.hpp"
        class Turrets
        {
            class MainTurret;
            class CopilotTurret;
        };
        class Attributes;
        class Eventhandlers;
        class Viewoptics;
        class ViewPilot;
        class RotorLibHelicopterProperties;
        class CargoTurret;
        class Components;
        class Sounds;
        class HitPoints;
        class UserActions;
    };

    class vtx_H60_base: Heli_Transport_01_base_F
    {
        #include "CfgUserActions.hpp"
        #include "edenAttributes.hpp"
        author = "Project Hatchet Studio";
        class VTX_H60_HDTS_Copilot;
        #include "cfgVxf.hpp"
        memoryPointDriverOptics = "slingcam";
        // driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        class vtx_templateFLIR {
            #include "turrets\pilotCamera.hpp"
        };
        scope=1;
        category = "Air";
        editorSubcategory = "vtx_h60";
        side = 1;
        faction = "BLU_F";
        //armor = 500;
        altFullForce = 1500;	/// in what height do the engines still have full thrust
        altNoForce = 4000;		/// thrust of the engines interpolates to zero between altFullForce and altNoForce
        maxSpeed = 300;			/// what is the maximum speed of the vehicle
        maxFordingDepth = 0.55;	/// how deep could the vehicle be in water without getting some damage
        mainBladeRadius = 7.0;	/// describes the radius of main rotor - used for collision detection
        fuelConsumptionRate = 0;
        //multiplier of lift force
        liftForceCoef = 1.1;
        //multiplier of body friction
        bodyFrictionCoef = 0.7;
        //multiplier of bank force
        cyclicAsideForceCoef = 1.0;
        //multiplier of dive force
        cyclicForwardForceCoef = 1.0;
        //multiplier of back rotor force
        backRotorForceCoef = 1.0;
        simulation = "helicopterRTD";
        #include "cfgVehiclesParts\RotorLibHelicopterProperties.hpp"
        #include "cfgVehiclesParts\sounds.hpp"
        #include "cfgVehiclesParts\slingload.hpp"
        #include "cfgVehiclesParts\UI.hpp"
        #include "cfgVehiclesParts\components.hpp"
        #include "cfgVehiclesParts\reflectors.hpp"
        #include "cfgVehiclesParts\fries.hpp"
        #include "cfgVehiclesParts\hitPoints.hpp"
        //#include "cfgVehiclesParts\vehicleCustomization.hpp"
        
        reportOwnPosition = 1;
        reportRemoteTargets = 1;
        receiveRemoteTargets = 1;

        irTargetSize = 1.2;
        radarTargetSize = 1.2;

        hiddenSelections[] = {
            "emmisive_overhead",
            "emmisive_frontDash",
            "emmisive_pedestal",
            "emmisive_ralt",
            "emmisive_altp",
            "emmisive_alt",
            "emmisive_ias",
            "emmisive_hdg",
            "MAP_MFD1",
            "MAP_MFD2",
            "MAP_MFD3",
            "MAP_MFD4",
            "MAP_OVERLAY1",
            "MAP_OVERLAY2",
            "MAP_OVERLAY3",
            "MAP_OVERLAY4",
            "Exterrior_Hull",
            "Exterrior_Misc",
            "Exterrior_Tail",
            "markings",
            "left_num_1",
            "left_num_2",
            "right_num_1",
            "right_num_2",
            "Fuel_Probe"
        };
        hiddenSelectionsTextures[] = {
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "z\vtx\addons\UH60\Data\Exterior\Hull Main_co.paa",
            "z\vtx\addons\UH60\Data\Exterior\Misc_co.paa",
            "z\vtx\addons\UH60\Data\Exterior\Hull Tail_co.paa",
            "z\vtx\addons\UH60\Data\Exterior\Markings\Markings_ca.paa",
            "", // "left_num_1",
            "", // "left_num_2",
            "", // "right_num_1",
            "", // "right_num_2",
            "z\vtx\addons\UH60\Data\FuelProbe\Fuel_probe_co.paa"
        };
        hiddenSelectionsMaterials[] = {
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "z\vtx\addons\UH60\data\exterior\hull main.rvmat",
            "z\vtx\addons\UH60\data\exterior\misc.rvmat",
            "z\vtx\addons\UH60\data\exterior\hull tail.rvmat",
            ""
        };
        A3TI_ThermalSelections[] = {16, 17, 18};
        accuracy = 0.5;
        model = "\z\vtx\addons\UH60\vtx_UH60.p3d";
        displayName = "$STR_VTX_UH60_UHMBlackhawk";



        icon = "z\vtx\addons\UH60\Data\UI\Map_vtx_UH60_CA.paa";	/// icon in map/editor
        picture = "z\vtx\addons\UH60\Data\UI\vtx_UH60_CA.paa";	/// small picture in command menu

        driverInAction = UH60_Pilot;
        driverAction = UH60_Pilot;
        driverRightHandAnimName="Cyclic_right";
    	driverLeftHandAnimName="Collective_right";
    	driverLeftLegAnimName="Pedal_Left_P";
    	driverRightLegAnimName="Pedal_Right_P";
        precisegetinout = 0;
        transportSoldier = 11;

        crew = vtx_uh60_pilot;
        typicalCargo[]={vtx_uh60_doorgunner,vtx_uh60_doorgunner,vtx_uh60_doorgunner};
        gunnerAction = UH60_Gunner;
        gunnerInAction = UH60_Gunner;
        transportMaxBackpacks = 11;
		cargoAction[] = {"passenger_low01", "passenger_generic01_leanleft", "passenger_generic01_leanleft", "passenger_generic01_leanright", "passenger_generic01_foldhands", "passenger_mantisrear", "passenger_mantisrear", "passenger_generic01_foldhands"};

        cargoIsCoDriver[]={0,0};
        memoryPointsGetInDriver    = "pos Driver";
        memoryPointsGetInDriverDir    = "pos Driver dir";

		memoryPointsGetInGunner[] = {"pos Cargo L","pos Cargo R"};
		memoryPointsGetInGunnerDir[] = {"pos Cargo L dir","pos Cargo R dir"};
		memoryPointsGetInCargo[] = {
      "pos Cargo L5",
      "pos Cargo L5",
      "pos Cargo R5",
      "pos Cargo R5",
      "pos Cargo R3",
      "pos Cargo R3",
      "pos Cargo L3",
      "pos Cargo L3",
      "pos Cargo L",
      "pos Cargo R",
      "pos Cargo R"
    };
		memoryPointsGetInCargoDir[] = {
      "pos Cargo L5 dir",
      "pos Cargo L5 dir",
      "pos Cargo R5 dir",
      "pos Cargo R5 dir",
      "pos Cargo R3 dir",
      "pos Cargo R3 dir",
      "pos Cargo L3 dir",
      "pos Cargo L3 dir",
      "pos Cargo L dir",
      "pos Cargo R dir",
      "pos Cargo R dir"
    };
        hideWeaponsCargo = 1;
        cargoCanEject = 1;
        driverCanEject = 0;
        selectionHRotorStill	="rotorBlades";
		selectionHRotorMove		="rotorBlurred";
        selectionVRotorStill	="VrotorBlades";
		selectionVRotorMove		="VrotorBlurred";
        mainRotorSpeed = 1.0;
	    backRotorSpeed = 1.5;

        #include "MFD\MFDConfig.hpp"
        class MarkerLights{
            class CollisionRedTailLower{
                activeLight = 0;
                ambient[] = {100,0,0};
                blinking = 1;
                blinkingPattern[] = {0.2,1.3};
                blinkingPatternGuarantee = 0;
                color[] = {0.9,0.15,0.1};
                dayLight = 0;
                drawLight = 1;
                drawLightCenterSize = 0.08;
                drawLightSize = 0.5;
                intensity = 500;
                name = "light_collision_tail_lower";
                    useFlare = 1;
            };
            class CollisionRedTailUpper{
                activeLight = 0;
                ambient[] = {100,0,0};
                blinking = 1;
                blinkingPattern[] = {0.2,1.3};
                blinkingPatternGuarantee = 0;
                color[] = {0.9,0.15,0.1};
                dayLight = 0;
                drawLight = 1;
                drawLightCenterSize = 0.08;
                drawLightSize = 0.5;
                intensity = 500;
                name = "light_collision_tail_upper";
                useFlare = 1;
            };
        };

        class ViewPilot: ViewPilot { // Describes what does the pilot see using bare eyes
            #include "turrets\ViewPilot.hpp"
        };

		LODDriverOpticsIn = 1100;

    	class TransportBackpacks
    	{
    		class _xx_B_Parachute
    		{
    			backpack = "B_AssaultPack_rgr"; // For repairs
    			count = 2;
    		};
    	};
    	class TransportItems
    	{
    		class _xx_FirstAidKit
    		{
    			name = "FirstAidKit";
    			count = 8;
    		};
    		class _xx_Toolkit
    		{
    			name = "Toolkit";
    			count = 1;
    		};
    		class _xx_Medikit
    		{
    			name = "Medikit";
    			count = 1;
    		};
    		class _xx_ItemGPS
    		{
    			name = "ACE_microDAGR"; // For wayopints
    			count = 2;
    		};
    	};
        class TransportMagazines
        {
            mag_xx(SmokeShellGreen,2);
            mag_xx(SmokeShell,2);
            mag_xx(DemoCharge_Remote_Mag,1); // For destroying crashed heli
        };

        class TransportWeapons{};
        radarType = 4;

        weapons[]={CMFlareLauncher};
        magazines[]={60Rnd_CMFlareMagazine};
        lockDetectionSystem = CM_Lock_Radar + CM_Lock_Laser;
        incommingMisslieDetectionSystem = CM_none; // or CM_Missile;

        class Damage
        {
            tex[]={};
            mat[]={
             // "z\vtx\addons\UH60\Data\uh60m_dust_filter.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_dust_filter.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_dust_filter_destruct.rvmat",

             // "z\vtx\addons\UH60\Data\uh60m_engine.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_engine.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_engine_destruct.rvmat",

             // "z\vtx\addons\UH60\Data\uh60m_fuselage.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_fuselage.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_fuselage_destruct.rvmat",

             //    "z\vtx\addons\UH60\Data\uh60m_interior.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_interior.rvmat",
             //    "z\vtx\addons\UH60\Data\uh60m_interior_destruct.rvmat",

             // "z\vtx\addons\UH60\Data\uh60m_navijak.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_navijak.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_navijak_destruct.rvmat",

             // "z\vtx\addons\UH60\Data\uh60m_glass.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_glass_damage.rvmat",
             // "z\vtx\addons\UH60\Data\uh60m_glass_damage.rvmat",

            };
        };
        class Turrets: Turrets
        {
            #include "turrets\copilot.hpp"
            #include "turrets\doorguns.hpp"
        };
        class Exhausts
        {
            class ExhaustEngineLeft
            {
                position = "exh_leng_pos";
                direction = "exh_leng_dir";
                effect = "ExhaustsEffectHeliMed";
            };
            class ExhaustEngineRight
            {
                position = "exh_reng_pos";
                direction = "exh_reng_dir";
                effect = "ExhaustsEffectHeliMed";
            };
        };
        #include "cfgAnimationSources.hpp"
        gearRetracting		= 0;
        gearMinAlt			= 999999;

        turnCoef			= 4; // Rolling Friction, higher stops more quickly
        terrainCoef 		= 1;
        damperSize 			= 1;
        damperForce 		= 10;
        damperDamping 		= 100;
        wheelWeight 		= 30;

        driveOnComponent[]=
        {
            wheels
        };
        minOmega	= 0;
        maxOmega=2000;
        class Wheels
        {
            class Wheel_1
            {
                steering					= false;
                side						= "left";
                boneName					= "wheel_1_1";
                suspForceAppPointOffset		= "wheel_1_1_center";
                tireForceAppPointOffset		= "wheel_1_1_center";
                center						= "wheel_1_1_center";
                boundary					= "wheel_1_1_rim";
                width						= 0.3;
                mass						= 15;
                MOI							= 30;

                dampingRate					= 0.1;
                dampingRateDamaged			= 1.0;
                dampingRateDestroyed		= 1000.0;
                suspTravelDirection[]		= {0, -1, 0};

                maxBrakeTorque				= 2500;
                maxHandBrakeTorque			= 4000;

                maxCompression				= 0.2;
                maxDroop					= 0.05;

                sprungMass					= 6000;
                springStrength				= 90000;
                springDamperRate			= 4000;

                longitudinalStiffnessPerUnitGravity	= 10000;
                latStiffX					= 2.5;
                latStiffY					= 18.0;
                frictionVsSlipGraph[]=
                {
                    {0,1},
                    {0.5,1},
                    {1,1}
                };
            };
            class Wheel_2: Wheel_1
            {
                boneName					= "wheel_1_2";
                suspForceAppPointOffset		= "wheel_1_2_center";
                tireForceAppPointOffset		= "wheel_1_2_center";
                center						= "wheel_1_2_center";
                boundary					= "wheel_1_2_rim";
                sprungMass					= 8500;
            };
            class Wheel_3: Wheel_2
            {
                steering					= true;
                side						= "right";
                boneName					= "wheel_2_1";
                suspForceAppPointOffset		= "wheel_2_1_center";
                tireForceAppPointOffset		= "wheel_2_1_center";
                center						= "wheel_2_1_center";
                boundary					= "wheel_2_1_rim";

                width						= 0.12;
                maxCompression				= 0.2;
                maxDroop					= 0.05;
                maxBrakeTorque				= 1000;
                suspTravelDirection[]		= {0, -1.0, 0.0};

                sprungMass					= 500;
                springStrength				= 1000;
                springDamperRate			= 2000;
            };
        };

    };
    class vtx_UH60M : vtx_H60_base
    {
        scope = 2;
        editorPreview = "z\vtx\addons\UH60\Data\Preview\vtx_UH60M.jpg";
    };
    class vtx_UH60M_Probe : vtx_UH60M
    {
        scope = 1;
        displayName = "$STR_VTX_UH60_UHMBlackhawkProbe";
        class AnimationSources: AnimationSources
        {
            class Fuelprobe_Show {
                source="user";
                animPeriod=1;
                initPhase=1;
            };
        };
    };
    class vtx_HH60 : vtx_UH60M
    {
        scope = 2;
        editorPreview = "z\vtx\addons\UH60\Data\Preview\vtx_HH60.jpg";
        displayName = "$STR_VTX_UH60_HHGMPavehawk";
        memoryPointDriverOptics = "pilotcamera_flir_pos";

        hiddenSelectionsTextures[] = {
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "z\vtx\addons\UH60\Data\JLorion_HH60\Hull Main_co.paa",
                "z\vtx\addons\UH60\Data\JLorion_HH60\Misc_co.paa",
                "z\vtx\addons\UH60\Data\JLorion_HH60\Hull Tail_co.paa",
                "", // "markings",
                "", // "left_num_1",
                "", // "left_num_2",
                "", // "right_num_1",
                "", // "right_num_2",
                "z\vtx\addons\UH60\Data\JLorion_HH60\Fuel_probe_co.paa"
        };
        class pilotCamera: vtx_templateFLIR {};
        weapons[]={"CMFlareLauncher", "Laserdesignator_pilotcamera"};
        magazines[]={"60Rnd_CMFlareMagazine", "Laserbatteries"};
        driverWeaponsInfoType = "Rsc_vtx_MELB_Turret_UnitInfo";
        class Turrets: Turrets
        {
            #include "turrets\copilot.hpp"
            #include "turrets\doorguns.hpp"
            #include "turrets\cargoTurrets.hpp"
        };

        transportSoldier=0;
        cargoProxyIndexes[] = {12, 13, 14, 15, 16, 17, 20, 21, 22, 23};
        cargoAction[] = {};
        class AnimationSources: AnimationSources
        {
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
            class HH60Flares_Show {
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
            class FLIR_HIDE: MAWS_Tubes_Show {
                initPhase=0;
            };
            class FLIR_BACK: MAWS_Tubes_Show {
                initPhase=1;
            };
        };
        #include "vehicleTransport.hpp"
    };
    class vtx_UH60M_SLICK : vtx_H60_base {
      scope = 2;
      displayName = "UH-60M Slick";
      transportSoldier=0;
      cargoProxyIndexes[] = {};
      cargoAction[] = {};
      typicalCargo[] = {"vtx_uh60_doorgunner"};

      class AnimationSources: AnimationSources {
        //#define ANIMSRC(name,src,per,init)
        ANIMSRC(CabinSeats_Hide,user,1,1);
        ANIMSRC(GunnerSeats_Hide,user,1,1);
        ANIMSRC(Minigun_Mount_L_hide,user,1,1);
        ANIMSRC(Minigun_Mount_R_hide,user,1,1);
        ANIMSRC(Minigun_L_hide,user,1,1);
        ANIMSRC(Minigun_R_hide,user,1,1);
      };
      class Turrets: Turrets {
        class CopilotTurret: CopilotTurret {};
        #include "turrets\cargoTurretsDoor.hpp"
      };
      #include "vehicleTransportSlick.hpp"
    };
};

class cfgNonAIVehicles{
	class ProxyRetex;
	class Fuel_Probe: ProxyRetex{
		hiddenSelections[] ={"Fuel_Probe"};
		model = "\z\vtx\addons\UH60\Data\FuelProbe\Fuel_Probe.p3d";
	};
};
