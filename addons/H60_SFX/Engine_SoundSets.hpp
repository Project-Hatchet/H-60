// -APU
class vtx_APUSoundLoop_Ext_SoundSet: vtx_Standard_External_Base
{
	soundshaders[] = 
	{
		"vtx_APUSoundLoop_Ext_SoundShader"
	};
	volumefactor=0.25;
};

//External
class vtx_Rotor_Distance_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Rotor_Distance_SoundShader"
	};
	volumeFactor=0.5;
	shape="vtx_BottomLess_Shape";
	distancefilter="vtx_Distant_Engine_Filter";
	sound3dprocessingtype="vtx_Distant_3DProcessor";
	doppler=1;
};
class vtx_Engine_Distance_SoundSet: vtx_Rotor_Distance_SoundSet
{
	soundshaders[]=
	{
		"vtx_Engine_Distance_SoundShader"
	};
	volumeFactor=0.5;
	shape="vtx_Front_Shape";
	doppler=1;
};
class vtx_EngineExt_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_EngineExt_SoundShader"
	};
	volumefactor=1.25;
	// volumecurve="vtx_Tail_Rotor_Curve";
	sound3dprocessingtype="vtx_TailRotor_3DProcessor";
	posoffset[]={0,0,-10};
	doppler=1;
};
class vtx_RotorExt_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_RotorExt_SoundShader"
	};
	volumeFactor=0.75;
	shape="vtx_BottomLess_Shape";
	sound3dprocessingtype="vtx_Rotor_3DProcessor";
};
class vtx_Turbine_Ext_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Turbine_Ext_SoundShader"
	};
	volumeFactor=1;
	shape="vtx_Turbine_Shape";
	sound3dprocessingtype="vtx_Turbine_3DProcessor";
};

//- Startup + Shutdown
class vtx_H60_Startup_Ext_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_H60_Startup_Ext_SoundShader"
	};
	playTrigger="CustomSoundController10";
	volumeFactor=1.3;
	loop=0;
	sound3dprocessingtype="vtx_ENG_Trigger_3DProcessor";
};
class vtx_H60_Shutdown_Ext_SoundSet: vtx_H60_Startup_Ext_SoundSet
{
	soundshaders[]=
	{
		"vtx_H60_Shutdown_Ext_SoundShader"
	};
	volumeFactor=1.8;
	playTrigger="CustomSoundController11";
};
class vtx_H60_APU_Start_Ext_SoundSet: vtx_H60_Startup_Ext_SoundSet
{
	soundshaders[]=
	{
		"vtx_H60_APU_Start_Ext_SoundShader"
	};
	volumeFactor=0.2;
	playTrigger="CustomSoundController12";
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class vtx_H60_Startup_Int_SoundSet: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_H60_Startup_Int_SoundShader"
	};
	volumeFactor=vtx_Vol_Multi_Int(0.8);
	playTrigger="CustomSoundController10";
	loop=0;
};
class vtx_H60_Shutdown_Int_SoundSet: vtx_H60_Startup_Int_SoundSet
{
	soundshaders[]=
	{
		"vtx_H60_Shutdown_Int_SoundShader"
	};
	playTrigger="CustomSoundController11";
};
class vtx_H60_APU_Start_Int_SoundSet: vtx_H60_Startup_Int_SoundSet
{
	soundshaders[]=
	{
		"vtx_H60_APU_Start_Int_SoundShader"
	};
	playTrigger="CustomSoundController12";
};

// -APU
class vtx_ApuSoundLoop_Int_Soundet: vtx_Internal_Base
{
	soundshaders[] = 
	{
		"vtx_ApuSoundLoop_Int_SoundShader"
	};
	volumefactor=vtx_Vol_Multi_Int(0.35);
};

//Internal
class vtx_EngineInt_SoundSet: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_EngineInt_SoundShader"
	};
	volumefactor=vtx_Vol_Multi_Int(0.8);
};
class vtx_RotorInt_SoundSet: vtx_EngineInt_SoundSet
{
	soundshaders[]=
	{
		"vtx_RotorInt_SoundShader"
	};
};
class vtx_Engine_Transport_SoundSet_Base: vtx_EngineInt_SoundSet
{
	soundshaders[] = 
	{
		"vtx_Engine_Transport_SoundShader_Base"
	};
};