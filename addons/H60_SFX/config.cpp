class CfgPatches
{
	class vtx_uh60_SFX
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"vtx_uh60"
		};
	};
};
class CfgSoundShapes
{
	class vtx_Turbine_Shape
	{
		type="cone";
		innerVolume=1.0;
		outervolume=0.4;
		innerangle=130;
		outerangle=210;
		azimuth=180;
		elevation=0;
	};
	class vtx_Front_Shape
	{
		type="cone";
		innerVolume=1.0;
		outervolume=0.4;
		innerangle=150;
		outerangle=230;
		azimuth=0;
		elevation=0;
	};
	class vtx_TailRotor_Shape: vtx_Turbine_Shape
	{
		outervolume=0.5;
		innerangle=70;
		outerangle=120;
	};
};
class CfgSoundCurves
{
	class vtx_Ext_Base_Curve
	{
		points[]=
		{
			{0.0,1.0},
			{0.4,0.6},
			{0.6,0.4},
			{0.8,0.2},
			{0.9,0.1},
			{1.0,0.0}
		};
	};
};
class CfgSound3DProcessors
{
	class vtx_Close_3DProcessor
	{
		type="panner";
		rangeCurve="Smooth1Curve";
		innerRange=0;
		range=800;
	};
	class vtx_Distant_3DProcessor: vtx_Close_3DProcessor
	{
		innerrange = 2000;
		range = 3000;
	};
	class vtx_TailRotor_3DProcessor: vtx_Close_3DProcessor
	{
		innerrange = 1;
		range = 5;
		rangecurve="LinearCurve";
	};
};
class cfgDistanceFilters
{
	class vtx_Close_Engine_Filter
	{
		type="lowpassfilter";
		mincutofffrequency=100;
		qfactor=1.0;
		innerrange=0;
		range=1200;
		powerfactor=10;
	};
	class vtx_Distant_Engine_Filter: vtx_Close_Engine_Filter
	{
		mincutofffrequency=200;
		innerrange=1000;
		range=4000;
		powerfactor=18;
	};
};
class CfgSoundSets
{
	#include "CfgSoundSets.hpp"
};
class CfgSoundShaders
{
	#include "CfgSoundShaders.hpp"
};

class CfgVehicles
{
	class Helicopter_Base_F;
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class Turrets;
		class CargoTurret;
	};
	class Heli_Transport_01_base_F: Helicopter_Base_H
	{
		class Turrets
		{
			class MainTurret;
		};
		class CargoTurret: CargoTurret
		{
			playerPosition = 4;
		};
	};
	class vtx_H60_base: Heli_Transport_01_base_F
	{
		soundEngineOnInt[] = {"a3\sounds_f\dummysound",2,1};
		soundEngineOffInt[] = {"a3\sounds_f\dummysound",1,1};
		soundEngineOnExt[] = {"a3\sounds_f\dummysound",2,1,600};
		soundEngineOffExt[] = {"a3\sounds_f\dummysound",2,1,600};
		
		/*soundEngineOnInt[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Start_Int",2,1};
		soundEngineOffInt[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Shutdown_Int",1,1};
		soundEngineOnExt[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Start",2,1,600};
		soundEngineOffExt[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Shutdown",2,1,600};*/
		
		vtx_soundEngineOnInt[] = {"vtx_H60_Engine_On_Int"};
		vtx_soundEngineOffInt[] = {"vtx_H60_Engine_Off_Int"};
		vtx_soundEngineOnExt[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Start",2,1,600};
		vtx_soundEngineOffExt[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Shutdown",2,1,600};
		class sounds
		{
			Soundsets[] = 
			{
				"vtx_Empty_SoundSet",
				"vtx_APUSoundLoop_Ext_SoundSet",
				"vtx_APUSoundLoop_Int_Soundet",
				"vtx_EngineInt_SoundSet",
				"vtx_RotorInt_SoundSet",
				"vtx_TransmissionDamage_Int_phase1_SoundSet_Base",
				"vtx_TransmissionDamage_Int_phase2_SoundSet_Base",
				"vtx_TransmissionDamage_Int_phase3_SoundSet_Base",
				"vtx_ScrubLand_Int_SoundSet_Base",
				"vtx_ScrubBuilding_Int_SoundSet_Base",
				"vtx_ScrubTree_Ext_SoundSet_Base",
				"vtx_Rain_Int_SoundSet_Base",
				"vtx_Wind_Int_SoundSet_Base",
				"vtx_WindWash_Int_SoundSet_Base",
				"vtx_WindWash_Int_Transport_SoundSet_Base",
				"vtx_Engine_Transport_SoundSet_Base",
				"vtx_GStress_Int_SoundSet_Base",
				"vtx_FrameStress_Int_SoundSet_Base",
				"vtx_SpeedStress_Int_SoundSet_Base",
				"vtx_EngineExt_SoundSet",
				"vtx_RotorExt_SoundSet",
				//-Alarms
				//"vtx_Alarm_Damage_Ext_SoundSet_Base",
				"vtx_Alarm_Damage_Int_SoundSet_Base",
				//"vtx_Alarm_RotorLow_Ext_SoundSet_Base",
				"vtx_Alarm_RotorLow_Int_SoundSet_Base",
				
				"vtx_Rotor_Distance_SoundSet",
				"vtx_Engine_Distance_SoundSet",
				"vtx_Turbine_Ext_SoundSet",
				"vtx_TailRotor_SoundSet",
				"vtx_Rotor_Stress_Ext_SoundSet_Base",
				"vtx_TransmissionDamage_Ext_phase1_SoundSet_Base",
				"vtx_TransmissionDamage_Ext_phase2_SoundSet_Base",
				"vtx_Rain_Ext_SoundSet_Base",
				"vtx_Wind_Close_Ext_SoundSet_Base"
			};
		};
		class vxf_cargo
		{
			class interaction
			{
				class l_door
				{
					clickSound = "vxf_CabinDoor_Sound";
					//animEnd = "if (((_this # 0) animationPhase (_this # 1)) > 0.5) then {setCustomSoundController [(_this # 0), 'CustomSoundController4', 1];} else {setCustomSoundController [(_this # 0), 'CustomSoundController4', 1];};";
				};
				class r_door
				{
					clickSound = "vxf_CabinDoor_Sound";
					//animEnd = "if (((_this # 0) animationPhase (_this # 1)) > 0.5) then {setCustomSoundController [(_this # 0), 'CustomSoundController4', 1];} else {setCustomSoundController [(_this # 0), 'CustomSoundController4', 1];};";
				};
			};
		};
		//-Set PlayerPOS SoundController and disable SoundAttenuation (Internal Filter)
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				playerPosition = 3;
			};
		};
		class vxf_driver
		{
			class interaction
			{
				class startUp
				{
					class b_ignition
					{
						clickSound = "vxf_Key_Sound";
					};
					//-Engine Sound
					class powerContRFM
					{
						class b_engpowercont1
						{
							animEnd = "[(_this # 0), (_this # 2 != ""OFF""), ""throttle"", (_this # 2), (_this # 1)] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];[_this # 0] remoteExecCall [""vtx_uh60_Sound_fnc_EngineEH""];diag_log ""powercont"";";
						};
					};
					class powerContRTD
					{
						class b_engpowercont1
						{
							animEnd = "[(_this # 0), (_this # 2 != ""OFF""), ""throttle"", (_this # 2), (_this # 1)] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];[_this # 0] remoteExecCall [""vtx_uh60_Sound_fnc_EngineEH""];diag_log ""powercont"";";
						};
					};
				};
			};
		};
		class vxf_copilot
		{
			class interaction
			{
				class startUp
				{
					class b_ignition
					{
						clickSound = "vxf_Key_Sound";
					};
					//-Engine Sound
					class powerContRFM
					{
						class b_engpowercont1
						{
							animEnd = "[(_this # 0), (_this # 2 != ""OFF""), ""throttle"", (_this # 2), (_this # 1)] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];[_this # 0] remoteExecCall [""vtx_uh60_Sound_fnc_EngineEH""];diag_log ""powercont"";";
						};
					};
					class powerContRTD
					{
						class b_engpowercont1
						{
							animEnd = "[(_this # 0), (_this # 2 != ""OFF""), ""throttle"", (_this # 2), (_this # 1)] remoteExecCall [""vtx_uh60_engine_fnc_engineEH"", crew (_this # 0)];[_this # 0] remoteExecCall [""vtx_uh60_Sound_fnc_EngineEH""];diag_log ""powercont"";";
						};
					};
				};
			};
		};
	};
	class vtx_HH60: vtx_H60_base
	{
		class Turrets: Turrets
		{
			class CargoTurret_01: CargoTurret{};
		};
	};
};
class CfgSounds
{
	class vtx_H60_Engine_On_Int
	{
		name = "vtx_H60_Engine_On_Int";
		sound[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Start_Int",2,1};
		titles[] = {};
	};
	class vtx_H60_Engine_Off_Int
	{
		name = "vtx_H60_Engine_Off_Int";
		sound[] = {"H-60\addons\H60_SFX\Sounds\Share\Engine_Shutdown_Int",2,1};
		titles[] = {};
	};
	class vxf_Key_Sound
	{
		name = "vxf_Key_Sound";
		sound[] = {"H-60\addons\H60_SFX\Sounds\Share\Key",1,1};
		titles[] = {};
	};
	class vxf_CabinDoor_Sound
	{
		name = "vxf_CabinDoor_Sound";
		sound[] = {"H-60\addons\H60_SFX\Sounds\Share\Door",3,1};
		titles[] = {};
	};
};
class CfgFunctions
{
	class vtx_uh60_Sound
	{
		class Main
		{
			file="H-60\addons\H60_SFX\functions";
			class engineEH;
		};
	};
};