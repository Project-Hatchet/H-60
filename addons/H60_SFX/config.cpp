class CfgPatches
{
	class vtx_uh60_SFX
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"vtx_uh60",
			"vtx_uh60_acre",
			"vtx_uh60_config",
			"vtx_uh60_doorguns",
			"vtx_uh60_sfmplus",
			"vtx_mh60m",
			"vtx_mh60s",
			"vtx_ace_viv"
		};
	};
};

#define vtx_Vol_Multi_Int(NUM) __EVAL(0.75*NUM)

class CfgSoundShapes
{
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
  class vtx_Rear_Shape: vtx_Front_Shape
	{
		innerVolume=1.0;
		outervolume=0.65;
		innerangle=120;
		outerangle=240;
		azimuth=180;
	};
  class vtx_Bottom_Shape
	{
		innerVolume=1;
		outervolume=0.8;
		innerangle=140;
		outerangle=160;
		azimuth=0;
    elevation=-90;
	};
  class vtx_BottomLess_Shape: vtx_Bottom_Shape
	{
		innerVolume=0;
		outervolume=1;
		innerangle=140;
		outerangle=160;
	};
  class vtx_Turbine_Shape: vtx_Rear_Shape
	{
    outervolume=0.8;
		innerangle=130;
		outerangle=210;
	};
	class vtx_Distance_Shape: vtx_Rear_Shape
	{
		outervolume=0.45;
		innerangle=65;
		outerangle=100;
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
	class vtx_Tail_Rotor_Curve
	{
		points[]=
		{
			{0.0,1.0},
			{0.1,0.8},
			{0.3,0.75},
			{0.4,0.54},
			{0.6,0.42},
			{0.6,0.256},
			{0.8,0.152},
			{0.9,0.091},
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
		innerRange=100;
		range=300;
	};
  class vtx_ENG_Trigger_3DProcessor: vtx_Close_3DProcessor
	{
		innerRange=3;
		range=20;
	};
	class vtx_WindWash_3DProcessor: vtx_Close_3DProcessor
	{
		innerRange=5;
		range=15;
	};
	class vtx_Distant_3DProcessor: vtx_Close_3DProcessor
	{
		innerrange = 100;
		range = 800;
	};
	class vtx_TailRotor_3DProcessor: vtx_Close_3DProcessor
	{
		innerRange=0;
		range=120;
	};
	class vtx_Rotor_3DProcessor: vtx_Close_3DProcessor
	{
		innerRange=0;
		range=50;
	};
	class vtx_Turbine_3DProcessor: vtx_TailRotor_3DProcessor
	{
		type="emitter";
		innerRange=8;
		range=15;
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
		innerrange=800;
		range=3000;
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
		class CargoTurret;
		class Turrets
		{
			class CopilotTurret;
			class MainTurret;
		};
	};
	class Heli_Transport_01_base_F: Helicopter_Base_H
	{
		class Eventhandlers;
		class ViewPilot;
		class CargoTurret: CargoTurret
		{
			playerPosition = 1;
		};
	};
	class vtx_H60_base: Heli_Transport_01_base_F
	{
		soundEngineOnInt[] = {"a3\sounds_f\dummysound",2,1};
		soundEngineOffInt[] = {"a3\sounds_f\dummysound",1,1};
		soundEngineOnExt[] = {"a3\sounds_f\dummysound",2,1,600};
		soundEngineOffExt[] = {"a3\sounds_f\dummysound",2,1,600};

		/*soundEngineOnInt[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Engine_Start_Int",2,1};
		soundEngineOffInt[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Engine_Shutdown_Int",1,1};
		soundEngineOnExt[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Engine_Start",2,1,600};
		soundEngineOffExt[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Engine_Shutdown",2,1,600};*/

		/*vtx_soundEngineOnInt[] = {"vtx_H60_Engine_On_Int"};
		vtx_soundEngineOffInt[] = {"vtx_H60_Engine_Off_Int"};
		vtx_soundEngineOnExt[] = {"vtx_H60_Engine_On_Ext",1,600};
		vtx_soundEngineOffExt[] = {"vtx_H60_Engine_Off_Ext",1,600};
		
		vtx_soundAPUInt[] = {"vtx_H60_APU_On_Int"};
		vtx_soundAPUExt[] = {"vtx_H60_APU_On_Ext",1,600};*/

    // vtx_Sound_ShutDelay = 40;
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
				"vtx_Alarm_Damage_Int_SoundSet_Base",
				"vtx_Alarm_RotorLow_Int_SoundSet_Base",
        //- Startup + Shutdown
        "vtx_H60_Startup_Ext_SoundSet",
        "vtx_H60_Shutdown_Ext_SoundSet",
        "vtx_H60_APU_Start_Ext_SoundSet",
        "vtx_H60_Startup_Int_SoundSet",
        "vtx_H60_Shutdown_Int_SoundSet",
        "vtx_H60_APU_Start_Int_SoundSet",

				"vtx_Rotor_Distance_SoundSet",
				"vtx_Engine_Distance_SoundSet",
				"vtx_Turbine_Ext_SoundSet",
				"vtx_Rotor_Stress_Ext_SoundSet_Base",
				"vtx_TransmissionDamage_Ext_phase1_SoundSet_Base",
				"vtx_TransmissionDamage_Ext_phase2_SoundSet_Base",
				"vtx_Rain_Ext_SoundSet_Base",
				"vtx_Wind_Close_Ext_SoundSet_Base"
			};
		};
		class soundsext
		{
			class soundevents;
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
					"vtx_Rotor_Stress_Ext_SoundSet_Base",
					"vtx_TransmissionDamage_Ext_phase1_SoundSet_Base",
					"vtx_TransmissionDamage_Ext_phase2_SoundSet_Base",
					"vtx_Rain_Ext_SoundSet_Base",
					"vtx_Wind_Close_Ext_SoundSet_Base"
				};
			};
		};
		//-Set PlayerPOS SoundController and disable SoundAttenuation (Internal Filter)
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				disableSoundAttenuation = 0;
				viewGunnerInExternal = 0;
				soundAttenuationTurret = "HeliAttenuationGunner";
				isPersonTurret = 2;
			};
			class MainTurret: MainTurret
			{
				playerPosition = 2;
			};
		};
	};
	//-Turret Compat
	#include "Compat.hpp"
};
class CfgSounds
{

	class vxf_Key_Sound
	{
		name = "vxf_Key_Sound";
		sound[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Key",1,1};
		titles[] = {};
	};
	class vxf_CabinDoor_Sound
	{
		name = "vxf_CabinDoor_Sound";
		sound[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Door",3,1};
		titles[] = {};
	};
	class vxf_RotorBrake_Sound
	{
		name = "vxf_RotorBrake_Sound";
		sound[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\RotorBrake",3,1};
		titles[] = {};
	};
};
class CfgFunctions
{
	class vtx_uh60_Sound
	{
		class Main
		{
			file="\z\vtx\addons\H60_SFX\functions";
			class engineEH;
		};
	};
};
