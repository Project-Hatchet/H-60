#include "script_component.hpp"

class CfgPatches
{
	class ADDON
	{
		units[]={};
		weapons[]={};
		name = COMPONENT_NAME;
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[]=
		{
			"hct_uh60",
			"hct_h60_config",
			"hct_h60_doorguns",
			"hct_h60_ace_viv"
		};
		VERSION_CONFIG;
	};
};

#define hct_Vol_Multi_Int(NUM) __EVAL(0.75*NUM)

class CfgSoundShapes
{
	class hct_Front_Shape
	{
		type="cone";
		innerVolume=1.0;
		outervolume=0.4;
		innerangle=150;
		outerangle=230;
		azimuth=0;
		elevation=0;
	};
  class hct_Rear_Shape: hct_Front_Shape
	{
		innerVolume=1.0;
		outervolume=0.65;
		innerangle=120;
		outerangle=240;
		azimuth=180;
	};
  class hct_Bottom_Shape
	{
		innerVolume=1;
		outervolume=0.8;
		innerangle=140;
		outerangle=160;
		azimuth=0;
    elevation=-90;
	};
  class hct_BottomLess_Shape: hct_Bottom_Shape
	{
		innerVolume=0;
		outervolume=1;
		innerangle=140;
		outerangle=160;
	};
  class hct_Turbine_Shape: hct_Rear_Shape
	{
    outervolume=0.8;
		innerangle=130;
		outerangle=210;
	};
	class hct_Distance_Shape: hct_Rear_Shape
	{
		outervolume=0.45;
		innerangle=65;
		outerangle=100;
	};
};
class CfgSoundCurves
{
	class hct_Ext_Base_Curve
	{
		points[]=
		{
			{0.0,1.0},
			{0.3,0.6},
			{0.6,0.2},
			{0.9,0.1},
			{1.0,0.0}
		};
	};
  class hct_Ext_Distant_Curve
	{
		points[]=
		{
			{0.0,0.2},
			{0.8,0.4},
			{0.9,0.6},
			{1.0,1.0}
		};
	};
	class hct_Tail_Rotor_Curve
	{
		points[]=
		{
			{0.0,1.0},
			{0.1,0.8},
			{0.3,0.75},
			{0.4,0.54},
			{0.6,0.42},
			{0.8,0.152},
			{0.9,0.091},
			{1.0,0.0}
		};
	};
};
class CfgSound3DProcessors
{
	class hct_Close_3DProcessor
	{
		type="panner";
		rangeCurve="Smooth1Curve";
		innerRange=100;
		range=300;
	};
  class hct_ENG_Trigger_3DProcessor: hct_Close_3DProcessor
	{
		innerRange=3;
		range=20;
	};
	class hct_WindWash_3DProcessor: hct_Close_3DProcessor
	{
		innerRange=5;
		range=15;
	};
	class hct_Distant_3DProcessor: hct_Close_3DProcessor
	{
		innerrange = 100;
		range = 800;
	};
	class hct_TailRotor_3DProcessor: hct_Close_3DProcessor
	{
		innerRange=10;
		range=120;
	};
	class hct_Rotor_3DProcessor: hct_Close_3DProcessor
	{
		innerRange=0;
		range=50;
	};
	class hct_Turbine_3DProcessor: hct_TailRotor_3DProcessor
	{
		type="emitter";
		innerRange=8;
		range=15;
	};
};
class cfgDistanceFilters
{
	class hct_Close_Engine_Filter
	{
		type="lowpassfilter";
		mincutofffrequency=100;
		qfactor=1.0;
		innerrange=0;
		range=1200;
		powerfactor=10;
	};
	class hct_Distant_Engine_Filter: hct_Close_Engine_Filter
	{
		mincutofffrequency=200;
		innerrange=800;
		range=3000;
		powerfactor=18;
	};
};
class AttenuationsEffects
{
	// #510 cabin attenuation (2026-09-07). Turret-family seats never get the
	// pre-filtered interior sound channels; a soundAttenuationTurret profile
	// filtering what the seat hears is the vanilla route (Mohawk ramp seats),
	// and the stock profiles are too mild for an enclosed cabin. Values are the
	// MH-47G reference's post-tuning moderate set. Door-gun and window turrets
	// pair the profile with disableSoundAttenuation=0: the engine natively
	// drops the filter when the gunner turns out (raw slipstream).
	//
	// KNOWN LIMIT (#510, 2026-09-07 builds 1-7): the profile only engages on
	// seats the engine considers "inside". Turret seats WITHOUT turn-out
	// machinery (copilot, troop commander) fail the engine's geometric interior
	// test against this model's View Geometry LOD (no canopy above the
	// glareshield; open side band at the TC) and stay unfiltered. Config space
	// is exhausted - the fix is model-side and lands with the new model's LOD
	// rebuild (View Geometry must be airtight around every crew position).
	class HCT_H60_CabinAttenuation
	{
		class Equalizer0
		{
			center[]={100,250,1000,5000};
			bandwidth[]={2,2,2,2};
			gain[]={0.89,0.84,0.5,0.28};
		};
		class Equalizer1
		{
			center[]={50,500,2500,10000};
			bandwidth[]={2,2,2,2};
			gain[]={1,0.94,0.63,0.4};
		};
		class Echo
		{
			WetDryMix=0.1;
			Feedback=0.1;
			Delay=30;
		};
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
		class CargoTurret: CargoTurret
		{
			playerPosition = 1;
		};
	};
	class hct_H60_base: Heli_Transport_01_base_F
	{
		soundEngineOnInt[] = {"a3\sounds_f\dummysound",2,1};
		soundEngineOffInt[] = {"a3\sounds_f\dummysound",1,1};
		soundEngineOnExt[] = {"a3\sounds_f\dummysound",2,1,600};
		soundEngineOffExt[] = {"a3\sounds_f\dummysound",2,1,600};

    // hct_Sound_ShutDelay = 40;
		class sounds
		{
			Soundsets[] =
			{
				"hct_Empty_SoundSet",
				"hct_APUSoundLoop_Ext_SoundSet",
				"hct_APUSoundLoop_Int_Soundet",
				"hct_EngineInt_SoundSet",
				"hct_RotorInt_SoundSet",
				"hct_TransmissionDamage_Int_phase1_SoundSet_Base",
				"hct_TransmissionDamage_Int_phase2_SoundSet_Base",
				"hct_TransmissionDamage_Int_phase3_SoundSet_Base",
				"hct_ScrubLand_Int_SoundSet_Base",
				"hct_ScrubBuilding_Int_SoundSet_Base",
				"hct_ScrubTree_Ext_SoundSet_Base",
				"hct_Rain_Int_SoundSet_Base",
				"hct_Wind_Int_SoundSet_Base",
				"hct_WindWash_Int_SoundSet_Base",
				"hct_WindWash_Int_Transport_SoundSet_Base",
				"hct_Engine_Transport_SoundSet_Base",
				"hct_GStress_Int_SoundSet_Base",
				"hct_FrameStress_Int_SoundSet_Base",
				"hct_SpeedStress_Int_SoundSet_Base",
				"hct_EngineExt_SoundSet",
				"hct_RotorExt_SoundSet",
				//-Alarms
				"hct_Alarm_Damage_Int_SoundSet_Base",
				"hct_Alarm_RotorLow_Int_SoundSet_Base",
        //- Startup + Shutdown
        "hct_H60_Startup_Ext_SoundSet",
        "hct_H60_Shutdown_Ext_SoundSet",
        "hct_H60_APU_Start_Ext_SoundSet",
        "hct_H60_Startup_Int_SoundSet",
        "hct_H60_Shutdown_Int_SoundSet",
        "hct_H60_APU_Start_Int_SoundSet",

				"hct_Rotor_Distance_SoundSet",
				"hct_Engine_Distance_SoundSet",
				"hct_Turbine_Ext_SoundSet",
				"hct_Rotor_Stress_Ext_SoundSet_Base",
				"hct_TransmissionDamage_Ext_phase1_SoundSet_Base",
				"hct_TransmissionDamage_Ext_phase2_SoundSet_Base",
				"hct_Rain_Ext_SoundSet_Base",
				"hct_Wind_Close_Ext_SoundSet_Base"
			};
		};
		class soundsext
		{
			class soundevents; // materialises an empty soundevents class in the vehicle config - keep
			class sounds
			{
				Soundsets[] =
				{
					"hct_Empty_SoundSet",
					"hct_APUSoundLoop_Ext_SoundSet",
					"hct_APUSoundLoop_Int_Soundet",
					"hct_EngineInt_SoundSet",
					"hct_RotorInt_SoundSet",
					"hct_TransmissionDamage_Int_phase1_SoundSet_Base",
					"hct_TransmissionDamage_Int_phase2_SoundSet_Base",
					"hct_TransmissionDamage_Int_phase3_SoundSet_Base",
					"hct_ScrubLand_Int_SoundSet_Base",
					"hct_ScrubBuilding_Int_SoundSet_Base",
					"hct_ScrubTree_Ext_SoundSet_Base",
					"hct_Rain_Int_SoundSet_Base",
					"hct_Wind_Int_SoundSet_Base",
					"hct_WindWash_Int_SoundSet_Base",
					"hct_WindWash_Int_Transport_SoundSet_Base",
					"hct_Engine_Transport_SoundSet_Base",
					"hct_GStress_Int_SoundSet_Base",
					"hct_FrameStress_Int_SoundSet_Base",
					"hct_SpeedStress_Int_SoundSet_Base",
					"hct_EngineExt_SoundSet",
					"hct_RotorExt_SoundSet",
					//-Alarms
					//"hct_Alarm_Damage_Ext_SoundSet_Base",
					"hct_Alarm_Damage_Int_SoundSet_Base",
					//"hct_Alarm_RotorLow_Ext_SoundSet_Base",
					"hct_Alarm_RotorLow_Int_SoundSet_Base",

					"hct_Rotor_Distance_SoundSet",
					"hct_Engine_Distance_SoundSet",
					"hct_Turbine_Ext_SoundSet",
					"hct_Rotor_Stress_Ext_SoundSet_Base",
					"hct_TransmissionDamage_Ext_phase1_SoundSet_Base",
					"hct_TransmissionDamage_Ext_phase2_SoundSet_Base",
					"hct_Rain_Ext_SoundSet_Base",
					"hct_Wind_Close_Ext_SoundSet_Base"
				};
			};
		};
	};
};
class CfgSounds
{

	class hct_Key_Sound
	{
		name = "hct_Key_Sound";
		sound[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Key",1,1};
		titles[] = {};
	};
	class hct_CabinDoor_Sound
	{
		name = "hct_CabinDoor_Sound";
		sound[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\Door",3,1};
		titles[] = {};
	};
	class hct_RotorBrake_Sound
	{
		name = "hct_RotorBrake_Sound";
		sound[] = {"\z\vtx\addons\H60_SFX\Sounds\Share\RotorBrake",3,1};
		titles[] = {};
	};
};

#include "CfgEventHandlers.hpp"
