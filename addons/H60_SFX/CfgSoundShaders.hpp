//External

// -Empty
class vtx_Empty_SoundShader
{
	samples[]=
	{

		{
			"a3\sounds_f\dummysound",
			1
		}
	};
	frequency=1;
	volume="engineOn*camPos";
	range=10000;
	rangeCurve[]=
	{
		{0,1},
		{10000,1}
	};
};

// -Alarm
class vtx_Alarm_Damage_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"H-60\addons\H60_SFX\Sounds\Alarm\Engine_Out",
			1
		}
	};
	frequency=1;
	volume="CustomSoundController7*(CustomSoundController14+1)";
	//volume="engineOn*(1 - ((transmissionDamage factor [0.61, 0.60])*(motorDamage factor [0.61, 0.60])*(rotorDamage factor [0.70, 0.50])))*(rotorSpeed factor [0, 0.001])";
	range=20;
};
class vtx_Alarm_RotorLow_Ext_SoundShader_Base: vtx_Alarm_Damage_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"H-60\addons\H60_SFX\Sounds\Alarm\Low_Rotor",
			1
		}
	};
	frequency=1;
	volume="CustomSoundController6";
	range=20;
};

// -Scrub Sound
class vtx_ScrubTree_Ext_SoundShader_Base: vtx_Alarm_Damage_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
			1
		}
	};
	frequency=1;
	volume="camPos*((scrubTree) factor [0, 0.01])*(CustomSoundController14+1)";
};

// -Damage
class vtx_TransmissionDamage_Ext_phase1_SoundShader_Base
{
	samples[]=
	{

		{
			"a3\sounds_f\vehicles\air\noises\heli_damage_transmission_ext_1",
			1
		}
	};
	frequency="0.66 + rotorspeed / 3";
	volume="((transmissiondamage factor [0.3, 0.35])*(transmissiondamage factor [0.5, 0.45])*(rotorspeed factor [0.2, 0.5])*(CustomSoundController14+1)";
	range=100;
};
class vtx_TransmissionDamage_Ext_phase2_SoundShader_Base: vtx_TransmissionDamage_Ext_phase1_SoundShader_Base
{
	samples[]=
	{

		{
			"a3\sounds_f\vehicles\air\noises\heli_damage_transmission_ext_2",
			1
		}
	};
	volume="(transmissiondamage factor [0.45, 0.5])*(rotorspeed factor [0.2, 0.5])*(CustomSoundController14+1)";
};

//-SlingLoad
class vtx_SlingLoadDown_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
			1
		}
	};
	frequency=1;
	volume="camPos*(slingLoadActive factor [0,-1])*(CustomSoundController14+1)";
	range=500;
};
class vtx_SlingLoadUp_Ext_SoundShader_Base: vtx_SlingLoadDown_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT",
			1
		}
	};
	frequency=1;
	volume="camPos*(slingLoadActive factor [0,1])*(CustomSoundController14+1)";
};
//-Noise
class vtx_Rain_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\noises\rain1_ext",
			1
		}
	};
	range=100;
	frequency=1;
	volume="camPos*(rain - rotorSpeed/2)*2*(CustomSoundController14+1)";
	rangecurve[]=
	{
		{0,1},
		{50,0.3},
		{100,0}
	};
};
class vtx_Wind_Close_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"H-60\addons\H60_SFX\Sounds\Share\Wind_Ext",
			1
		}
	};
	frequency="rotorSpeed";
	volume="camPos*(0 max (rotorSpeed-0.1)*6)*(CustomSoundController14+1)";
	range=20;
	rangecurve[]=
	{
		{0,1},
		{20,0}
	};
};
class vtx_Rotor_Stress_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"H-60\addons\H60_SFX\Sounds\Share\BladeSlap_ext",
			1
		}
	};
	range=1200;
	frequency="rotorSpeed";
	volume="engineOn*camPos*((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))*(CustomSoundController14+1)";
	rangecurve[]=
	{
		{0,1},
		{1200,0}
	};
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Internal
// -Alarm
class vtx_Alarm_Damage_Int_SoundShader_Base
{
	samples[]=
	{

		{
			//"A3\Sounds_F\vehicles\air\noises\heli_alarm_bluefor",
			"H-60\addons\H60_SFX\Sounds\Alarm\Engine_Out",
			1
		}
	};
	frequency=1;
	//volume="CustomSoundController7*engineOn*(1-camPos)*( 1 - ((motorDamage factor [0.61, 0.60])*(rotorDamage factor [0.51, 0.50])))*(rotorSpeed factor [0.0, 0.001])";
	volume="CustomSoundController7*(1-camPos)*(CustomSoundController16+1)";
};
class vtx_Alarm_RotorLow_Int_SoundShader_Base: vtx_Alarm_Damage_Int_SoundShader_Base
{
	samples[]=
	{

		{
			//"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
			"H-60\addons\H60_SFX\Sounds\Alarm\Low_Rotor",
			1
		}
	};
	//volume="CustomSoundController6*engineOn*(1-camPos)*(rotorSpeed factor [0.9, 0.8999])*(rotorSpeed factor [-0.5, 1])*(speed factor [3, 3.01])";
	volume="CustomSoundController6*(1-camPos)*(CustomSoundController16+1)";
};

// -Scrub Sound
class vtx_ScrubLand_Int_SoundShader_Base: vtx_Alarm_Damage_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\wheelsInt",
			1
		}
	};
	volume="2*(1-camPos)*(scrubLand factor[0.02, 0.05])*(1 - (lateralMovement factor [0.7,1]))*(CustomSoundController16+1)";
};
class vtx_ScrubBuilding_Int_SoundShader_Base: vtx_ScrubLand_Int_SoundShader_Base
{
	volume="(1-camPos)*(scrubBuilding factor[0.02, 0.05])*(1 - (lateralMovement factor [0.7,1]))*(CustomSoundController16+1)";
};
class vtx_ScrubTree_Int_SoundShader_Base: vtx_ScrubLand_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\wheelsInt",
			1
		}
	};
	volume="(1-camPos)*((scrubTree) factor [0, 0.01])*(CustomSoundController16+1)";
};

// -Damage
class vtx_TransmissionDamage_Int_phase1_SoundShader_Base
{
	samples[]=
	{

		{
			"a3\sounds_f\vehicles\air\noises\heli_damage_transmission_int_1",
			1
		}
	};
	frequency = "0.66 + CustomSoundController3 / 3";
	volume = "(1-camPos) * CustomSoundController4 *(CustomSoundController16+1)";
	range=100;
	//frequency="0.66 + rotorspeed / 3";
	//volume="(1-camPos)*(transmissiondamage factor [0.3, 0.35])*(transmissiondamage factor [0.5, 0.45])*(rotorspeed factor [0.2, 0.5])";
};
class vtx_TransmissionDamage_Int_phase2_SoundShader_Base
{
	samples[]=
	{

		{
			"a3\sounds_f\vehicles\air\noises\heli_damage_transmission_int_2",
			1
		}
	};
	frequency = "CustomSoundController3";
	volume = "(1-camPos) * CustomSoundController4 *(CustomSoundController16+1)";
	range=100;
	//frequency="0.66 + rotorspeed / 3";
	//volume="(1-camPos)*(transmissiondamage factor [0.45, 0.5])*(rotorspeed factor [0.2, 0.5])";
};
class vtx_TransmissionDamage_Int_phase3_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\noises\vehicle_stress3",
			1
		}
	};
	frequency = "CustomSoundController3";
	volume = "(1-camPos) * CustomSoundController4 *(CustomSoundController16+1)";
	range=50;
};

//-SlingLoad
class vtx_SlingLoadDown_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT",
			1
		}
	};
	frequency=1;
	volume="(1-camPos)*(slingLoadActive factor [0,-1])*(CustomSoundController16+1)";
	range=500;
};
class vtx_SlingLoadUp_Int_SoundShader_Base: vtx_SlingLoadDown_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT",
			1
		}
	};
	frequency=1;
	volume="(1-camPos)*(slingLoadActive factor [0,1])*(CustomSoundController16+1)";
};

//-Noise
class vtx_Rain_Int_SoundShader_Base: vtx_Rain_Ext_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\noises\rain1_int",
			1
		}
	};
	volume="(1-camPos)*(rain - rotorSpeed/2)*2*(CustomSoundController16+1)";
};

class vtx_Wind_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\air\noises\wind_closed",
			1
		}
	};
	range=50;
	frequency=1;
	volume="(1-camPos)*(speed factor[5, 60])*(speed factor[5, 60])*(CustomSoundController16+1)";
};
class vtx_WindWash_Int_SoundShader_Base: vtx_Wind_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"H-60\addons\H60_SFX\Sounds\Share\Wind_Int",
			1
		}
	};
	volume="(rotorSpeed factor [0.3, 1])*(1-camPos)*CustomSoundController8*(-playerPos + 1)*(CustomSoundController16+1)";
};
class vtx_WindWash_Int_Transport_SoundShader_Base: vtx_WindWash_Int_SoundShader_Base
{
	volume="(rotorSpeed factor [0.3, 1])*(1-camPos)*CustomSoundController9*(playerPos envelope [0,1,1.5,3])*(CustomSoundController16+1)";
};
class vtx_FrameStress_Int_SoundShader_Base: vtx_Wind_Int_SoundShader_Base
{
	samples[]=
	{
		{
			"A3\Sounds_F\vehicles\noises\vehicle_stress2c",
			1
		}
	};
	volume="engineOn*(1-camPos)*(gmeterZ factor[1.0, 2.5])*(CustomSoundController16+1)";
};
class vtx_GStress_Int_SoundShader_Base: vtx_Wind_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"H-60\addons\H60_SFX\Sounds\Share\BladeSlap",
			1
		}
	};
	frequency="rotorSpeed*2";
	volume="engineOn*(1-camPos)*((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))*(CustomSoundController16+1)";
};
class vtx_SpeedStress_Int_SoundShader_Base: vtx_Wind_Int_SoundShader_Base
{
	samples[]=
	{

		{
			"A3\Sounds_F\vehicles\noises\vehicle_stress3",
			1
		}
	};
	volume="(1-camPos)*(speed factor[40,80])*(CustomSoundController16+1)";
};
#include "Engine_SoundShaders.hpp"
