// -APU
class hct_APUSoundLoop_Ext_SoundSet: hct_Standard_External_Base
{
	soundshaders[] =
	{
		"hct_APUSoundLoop_Ext_SoundShader"
	};
	volumefactor=0.25;
};

//External
class hct_Rotor_Distance_SoundSet: hct_External_Base
{
	soundshaders[]=
	{
		"hct_Rotor_Distance_SoundShader"
	};
	volumeFactor=0.8;
	shape="hct_BottomLess_Shape";
	volumecurve="hct_Ext_Distant_Curve";
	distancefilter="hct_Distant_Engine_Filter";
	sound3dprocessingtype="hct_Distant_3DProcessor";
	doppler=1;
};
class hct_Engine_Distance_SoundSet: hct_Rotor_Distance_SoundSet
{
	soundshaders[]=
	{
		"hct_Engine_Distance_SoundShader"
	};
	volumeFactor=1.5;
	shape="hct_Front_Shape";
	doppler=1;
};
class hct_EngineExt_SoundSet: hct_External_Base
{
	soundshaders[]=
	{
		"hct_EngineExt_SoundShader"
	};
	volumefactor=1.25;
	volumecurve="hct_Tail_Rotor_Curve";
	sound3dprocessingtype="hct_TailRotor_3DProcessor";
	posoffset[]={0,0,-10};
	// doppler=1;
};
class hct_RotorExt_SoundSet: hct_External_Base
{
	soundshaders[]=
	{
		"hct_RotorExt_SoundShader"
	};
	volumeFactor=0.75;
	shape="hct_BottomLess_Shape";
	sound3dprocessingtype="hct_Rotor_3DProcessor";
};
class hct_Turbine_Ext_SoundSet: hct_External_Base
{
	soundshaders[]=
	{
		"hct_Turbine_Ext_SoundShader"
	};
	volumeFactor=1;
	shape="hct_Turbine_Shape";
	sound3dprocessingtype="hct_Turbine_3DProcessor";
};

//- Startup + Shutdown
class hct_H60_Startup_Ext_SoundSet: hct_External_Base
{
	soundshaders[]=
	{
		"hct_H60_Startup_Ext_SoundShader"
	};
	playTrigger="CustomSoundController10";
	volumeFactor=1.3;
	loop=0;
	sound3dprocessingtype="hct_ENG_Trigger_3DProcessor";
};
class hct_H60_Shutdown_Ext_SoundSet: hct_H60_Startup_Ext_SoundSet
{
	soundshaders[]=
	{
		"hct_H60_Shutdown_Ext_SoundShader"
	};
	volumeFactor=1.8;
	playTrigger="CustomSoundController11";
};
class hct_H60_APU_Start_Ext_SoundSet: hct_H60_Startup_Ext_SoundSet
{
	soundshaders[]=
	{
		"hct_H60_APU_Start_Ext_SoundShader"
	};
	volumeFactor=0.2;
	playTrigger="CustomSoundController12";
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class hct_H60_Startup_Int_SoundSet: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_H60_Startup_Int_SoundShader"
	};
	volumeFactor=hct_Vol_Multi_Int(0.8);
	playTrigger="CustomSoundController10";
	loop=0;
};
class hct_H60_Shutdown_Int_SoundSet: hct_H60_Startup_Int_SoundSet
{
	soundshaders[]=
	{
		"hct_H60_Shutdown_Int_SoundShader"
	};
	playTrigger="CustomSoundController11";
};
class hct_H60_APU_Start_Int_SoundSet: hct_H60_Startup_Int_SoundSet
{
	soundshaders[]=
	{
		"hct_H60_APU_Start_Int_SoundShader"
	};
	playTrigger="CustomSoundController12";
};

// -APU
class hct_ApuSoundLoop_Int_Soundet: hct_Internal_Base
{
	soundshaders[] =
	{
		"hct_ApuSoundLoop_Int_SoundShader"
	};
	volumefactor=hct_Vol_Multi_Int(0.35);
};

//Internal
class hct_EngineInt_SoundSet: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_EngineInt_SoundShader"
	};
	volumefactor=hct_Vol_Multi_Int(0.8);
};
class hct_RotorInt_SoundSet: hct_EngineInt_SoundSet
{
	soundshaders[]=
	{
		"hct_RotorInt_SoundShader"
	};
};
class hct_Engine_Transport_SoundSet_Base: hct_EngineInt_SoundSet
{
	soundshaders[] =
	{
		"hct_Engine_Transport_SoundShader_Base"
	};
};
