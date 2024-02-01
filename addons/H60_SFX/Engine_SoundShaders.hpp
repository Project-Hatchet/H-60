//External
// -APU
class vtx_APUSoundLoop_Ext_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\share\apu_ext_loop",
			1
		}
	};
	frequency="CustomSoundController1";
	volume="camPos*CustomSoundController2*(CustomSoundController14+1)";
	range=200;
	rangecurve[]=
	{
		{0,1},
		{100,0.6},
		{200,0}
	};
};
class vtx_Rotor_Distance_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Ext\Distant_Rotor",
			1
		}
	};
	frequency="rotorspeed * (1-rotorthrust/15) * 1";
	volume="(CustomSoundController14+1)*camext*(0 max (rotorspeed-0.1))*(1 + rotorthrust)";
	range=1300;
	rangecurve[]=
	{
		{0,0},
		{100,0},
		{600,1},
		{1000,0.15},
		{1300,0}
	};
};
class vtx_Engine_Distance_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Ext\Distant_Engine",
			1
		}
	};
	frequency="1.25*rotorspeed*(1-rotorthrust/15)";
	volume="camext*((rotorspeed-0.72)*4)*(CustomSoundController14+1)";
	range=1300;
	rangecurve[]=
	{
		{0,0},
		{300,1},
		{1000,0.3},
		{1300,0}
	};
};
class vtx_EngineExt_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Ext\Engine_Ext",
			1
		}
	};
	frequency="rotorSpeed*(1+rotorThrust/6)";
	volume="camext*(rotorSpeed factor [0.3, 1])*(CustomSoundController14+1)";
	range=1000;
	rangecurve[]=
	{
		{0,1},
		{300,0.8},
		{800,0.3},
		{1000,0}
	};
};
class vtx_RotorExt_SoundShader: vtx_EngineExt_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Ext\Rotor_Ext",
			1
		}
	};
	frequency="(rotorSpeed factor [0.3, 0.7])*(1 - rotorThrust/10)";
	volume="camext*(rotorSpeed factor [0.3, 1])*(1 + rotorThrust)*(CustomSoundController14+1)";
	range=1200;
	rangecurve[]=
	{
		{0,0.2},
		{150,1},
		{1000,0.4},
		{1200,0}
	};
};
class vtx_Turbine_Ext_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Ext\Turbine_Ext",
			1
		}
	};
	frequency="rotorSpeed";
	volume="(CustomSoundController14+1)*camext*(0 max (rotorSpeed-0.4))";
	range=200;
	rangecurve[]=
	{
		{0,0},
		{30,1},
		{100,0.65},
		{200,0}
	};
};
class vtx_TailRotor_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Ext\tail_rotor",
			1
		}
	};
	frequency="rotorspeed * (1-rotorthrust/15) * 1.25";
	volume="camext*0.25*(0 max (rotorspeed-0.5))*(1 + rotorthrust)*(CustomSoundController14+1)";
	range=150;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Internal

// -APU
class vtx_ApuSoundLoop_Int_SoundShader: vtx_ApuSoundLoop_Ext_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\share\apu_int_loop",
			1
		}
	};
	volume="camInt*CustomSoundController2*(CustomSoundController16+1)";
};

class vtx_EngineInt_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Int\Engine_Int",
			1
		}
	};
	frequency="rotorSpeed*(1+rotorThrust/6)*0.8";
	volume="camInt*(rotorSpeed factor [0.3, 1])*(CustomSoundController16+1)";
};
class vtx_RotorInt_SoundShader
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Int\Rotor_Int",
			1
		}
	};
	frequency="rotorSpeed*(1-rotorThrust/5)*1.2";
	volume="camInt*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)*(rotorSpeed factor [0.3, 1])*((playerPos interpolate [0,1,1,4]) max 1)*(CustomSoundController16+1)";
};
class vtx_Engine_Transport_SoundShader_Base
{
	samples[]=
	{
		
		{
			"\z\vtx\addons\H60_SFX\Sounds\Int\Engine_Transport",
			1
		}
	};
	frequency="rotorSpeed";
	volume="camInt*(rotorSpeed factor [0.3, 1])*playerPos*(CustomSoundController16+1)";
};